#include <random>
#include <iostream>

static const int NUM_OF_CANDIDATE = 5;


double candidate_array[][NUM_OF_CANDIDATE]
{
  {0.2, 0.5, 0.1, 0.1, 0.1},
  {0.1, 0.2, 0.5, 0.1, 0.1},
  {0.1, 0.1, 0.2, 0.5, 0.1},
  {0.1, 0.1, 0.1, 0.2, 0.5},
  {0.3, 0.3, 0.1, 0.1, 0.2}
};


int select_next_code(int code_num)
{
  int next_code_num = 0;
  double threthold = 0;

  std::random_device rd;
  std::mt19937 mt( rd() );
  std::uniform_real_distribution<double> rnd( 0.0, 1.0 );


  for ( int i = 0; i < NUM_OF_CANDIDATE; i++ )
  {
    threthold += candidate_array[code_num][i];

    if ( threthold > rnd(mt) )
	{
        next_code_num = i;
        break;
    }
  }

  return next_code_num;
}
