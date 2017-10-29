// threebees.cpp STK tutorial program

#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include "Note.h"
#include "Clarinet.h"
#include "Drummer.h"
#include "Plucked.h"
#include "Stochastic.h"

#include "BeeThree.h"
#include "RtAudio.h"
#include "Messager.h"
#include "Voicer.h"
#include "SKINImsg.h"

#include <algorithm>
using std::min;

using namespace stk;

// The TickData structure holds all the class instances and data that
// are shared by the various processing functions.
struct TickData {
  Voicer voicer;
  Messager messager;
  Skini::Message message;
  int counter;
  bool haveMessage;
  bool done;

  // Default constructor.
  TickData()
    : counter(0), haveMessage(false), done( false ) {}
};

#define DELTA_CONTROL_TICKS 64 // default sample frames between control input checks

// The processMessage() function encapsulates the handling of control
// messages.  It can be easily relocated within a program structure
// depending on the desired scheduling scheme.
void processMessage( TickData* data )
{
  register StkFloat value1 = data->message.floatValues[0];
  register StkFloat value2 = data->message.floatValues[1];

  switch( data->message.type ) {

  case __SK_Exit_:
    data->done = true;
    return;

  case __SK_NoteOn_:
    if ( value2 == 0.0 ) // velocity is zero ... really a NoteOff
      data->voicer.noteOff( value1, 64.0 );
    else { // a NoteOn
      data->voicer.noteOn( value1, value2 );
    }
    break;

  case __SK_NoteOff_:
    data->voicer.noteOff( value1, value2 );
    break;

  case __SK_ControlChange_:
    data->voicer.controlChange( (int) value1, value2 );
    break;

  case __SK_AfterTouch_:
    data->voicer.controlChange( 128, value1 );

  case __SK_PitchChange_:
    data->voicer.setFrequency( value1 );
    break;

  case __SK_PitchBend_:
    data->voicer.pitchBend( value1 );

  } // end of switch

  data->haveMessage = false;
  return;
}

// This tick() function handles sample computation and scheduling of
// control updates.  It will be called automatically when the system
// needs a new buffer of audio samples.
int tick( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *dataPointer )
{
  TickData *data = (TickData *) dataPointer;
  register StkFloat *samples = (StkFloat *) outputBuffer;
  int counter, nTicks = (int) nBufferFrames;

  while ( nTicks > 0 && !data->done ) {

    if ( !data->haveMessage ) {
      data->messager.popMessage( data->message );
      if ( data->message.type > 0 ) {
        data->counter = (long) (data->message.time * Stk::sampleRate());
        data->haveMessage = true;
      }
      else
        data->counter = DELTA_CONTROL_TICKS;
    }

    counter = min( nTicks, data->counter );
    data->counter -= counter;

    for ( int i=0; i<counter; i++ ) {
      *samples++ = data->voicer.tick();
      nTicks--;
    }
    if ( nTicks == 0 ) break;

    // Process control messages.
    if ( data->haveMessage ) processMessage( data );
  }

  return 0;
}


// ���m���łP���|�P��Ԃ�
int pos_or_nega(double p_of_pos)
{
	int value = -1;

	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rnd100(1, 100);

	if ( rnd100(mt) <= p_of_pos * 100 )
	{
		value = 1;
	}

	return value;
}


int main()
{
  // Set the global sample rate and rawwave path before creating class instances.
  Stk::setSampleRate( 44100.0 );
  Stk::setRawwavePath( "../../rawwaves/" );

  int i;
  //int root = 60;
  int currentChord = 0;
  static const int BPM = 120;
  static const auto TIME_OF_BEAT = 60 * 1000 / BPM; // �P���̊Ԋu�ims�j
  static const int polyphony = 8; // �ő哯��������
  static const int OCTAVE = 12;
  Note note; // ���֌W�̃N���X
  auto start_time = std::chrono::system_clock::now();
  std::vector<int> chordTone; // ���t����a��
  std::vector<long> tags; // ���t���̃m�[�g�̃��j�[�N�ȃ^�O���i�[����
  // ����������
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> rnd(0, 3);
  std::uniform_int_distribution<int> rnd12(0, 11);

  TickData data;
  RtAudio dac;
  Instrmnt *instrument[polyphony];
  for ( i=0; i<polyphony; i++ ) instrument[i] = 0;

  // Figure out how many bytes in an StkFloat and setup the RtAudio stream.
  RtAudio::StreamParameters parameters;
  parameters.deviceId = dac.getDefaultOutputDevice();
  parameters.nChannels = 1;
  RtAudioFormat format = ( sizeof(StkFloat) == 8 ) ? RTAUDIO_FLOAT64 : RTAUDIO_FLOAT32;
  unsigned int bufferFrames = RT_BUFFER_SIZE;
  try {
    dac.openStream( &parameters, NULL, format, (unsigned int)Stk::sampleRate(), &bufferFrames, &tick, (void *)&data );
  }
  catch ( RtAudioError &error ) {
    error.printMessage();
    goto cleanup;
  }

  try {
	// �y��̐ݒ�B
	  instrument[0] = new Drummer();
	  instrument[1] = new Clarinet();
	  instrument[2] = new Clarinet();
	  instrument[3] = new Clarinet();
	  instrument[4] = new Clarinet();
	  instrument[5] = new Plucked();
	  instrument[6] = new Plucked();
	  instrument[7] = new Plucked();
  }
  catch ( StkError & ) {
    goto cleanup;
  }

  // "Add" the instruments to the voicer.
  // voicer�Ɋy���ǉ��B
  data.voicer.addInstrument(instrument[0], 0);
  data.voicer.addInstrument(instrument[1], 1);
  data.voicer.addInstrument(instrument[2], 1);
  data.voicer.addInstrument(instrument[3], 1);
  data.voicer.addInstrument(instrument[4], 1);
  data.voicer.addInstrument(instrument[5], 2);
  data.voicer.addInstrument(instrument[6], 2);
  data.voicer.addInstrument(instrument[7], 2);

  /*
  if ( data.messager.startStdInput() == false )
    goto cleanup;
	*/
	
  // �T�E���h�f�o�C�X�֏o�͊J�n�B
  try {
    dac.startStream();
  }
  catch ( RtAudioError &error ) {
    error.printMessage();
    goto cleanup;
  }

  // ���t
  while (true)
  {
	  auto current_time = std::chrono::system_clock::now();
	  auto elpsed_time = current_time - start_time;

	  for (int i = 0; i < 16; i++)
	  {
		  if (i % 16 == 0)
		  {
			  // Chord
			  if (currentChord == 0)
			  {
				  chordTone = note.getChord(note.C_4, "Major7");
			  }
			  else if (currentChord == 1)
			  {
				  chordTone = note.getChord(note.G_4, "7");
			  }
			  else if (currentChord == 2)
			  {
				  chordTone = note.getChord(note.A_4, "Minor7");
			  }
			  else if (currentChord == 3)
			  {
				  chordTone = note.getChord(note.E_4, "Minor7");
			  }
			  else
			  {
				  chordTone = note.getChord(note.F_4, "Major7");
			  }
			  // Play Chord
			  for (auto tone = chordTone.begin(); tone != chordTone.end(); tone++)
			  {
				  tags.push_back(data.voicer.noteOn(*tone, 20, 1));
			  }
		  }
		  if (i % 4 == 0)
		  {
			  // Drum
			  data.voicer.noteOn(36, 100);
		  }
		  // Melody
		  data.voicer.noteOn(chordTone.at(rnd(mt)) + OCTAVE * pos_or_nega(0.8), 60, 2);
		  Stk::sleep(TIME_OF_BEAT / 4);
	  }

	  // �m�[�g���~����
	  for (auto itr = tags.begin(); itr != tags.end(); itr++)
	  {
		  data.voicer.noteOff(*itr, 0);
	  }
	  tags.clear();

	  // Update Chord
	  currentChord = select_next_code(currentChord);
	  //std::cout << currentChord << std::endl;


	  //root = 60 + chordTone.at(rnd(mt)) % 12; // �R�[�h�̍\�������玟�̃��[�g����I��

	  /*	  	  
	  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(elpsed_time).count() << std::endl;	  
	  */
  }

  // Block waiting until callback signals done.
  while ( !data.done )
    Stk::sleep( 100 );	
  
  // Shut down the callback and output stream.
  try {
    dac.closeStream();
  }
  catch ( RtAudioError &error ) {
    error.printMessage();
  }

 cleanup:
  for ( i=0; i<polyphony; i++ ) delete instrument[i];

  return 0;
}
