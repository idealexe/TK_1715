#include <vector>

class Note
{
public:
	static const int C_0 = 12;
	static const int Db_0 = 13;
	static const int D_0 = 14;
	static const int Eb_0 = 15;
	static const int E_0 = 16;
	static const int F_0 = 17;
	static const int Gb_0 = 18;
	static const int G_0 = 19;
	static const int Ab_0 = 20;
	static const int A_0 = 21;
	static const int Bb_0 = 22;
	static const int B_0 = 23;
	static const int C_1 = 24;
	static const int Db_1 = 25;
	static const int D_1 = 26;
	static const int Eb_1 = 27;
	static const int E_1 = 28;
	static const int F_1 = 29;
	static const int Gb_1 = 30;
	static const int G_1 = 31;
	static const int Ab_1 = 32;
	static const int A_1 = 33;
	static const int Bb_1 = 34;
	static const int B_1 = 35;
	static const int C_2 = 36;
	static const int Db_2 = 37;
	static const int D_2 = 38;
	static const int Eb_2 = 39;
	static const int E_2 = 40;
	static const int F_2 = 41;
	static const int Gb_2 = 42;
	static const int G_2 = 43;
	static const int Ab_2 = 44;
	static const int A_2 = 45;
	static const int Bb_2 = 46;
	static const int B_2 = 47;
	static const int C_3 = 48;
	static const int Db_3 = 49;
	static const int D_3 = 50;
	static const int Eb_3 = 51;
	static const int E_3 = 52;
	static const int F_3 = 53;
	static const int Gb_3 = 54;
	static const int G_3 = 55;
	static const int Ab_3 = 56;
	static const int A_3 = 57;
	static const int Bb_3 = 58;
	static const int B_3 = 59;
	static const int C_4 = 60;
	static const int Db_4 = 61;
	static const int D_4 = 62;
	static const int Eb_4 = 63;
	static const int E_4 = 64;
	static const int F_4 = 65;
	static const int Gb_4 = 66;
	static const int G_4 = 67;
	static const int Ab_4 = 68;
	static const int A_4 = 69;
	static const int Bb_4 = 70;
	static const int B_4 = 71;
	static const int C_5 = 72;
	static const int Db_5 = 73;
	static const int D_5 = 74;
	static const int Eb_5 = 75;
	static const int E_5 = 76;
	static const int F_5 = 77;
	static const int Gb_5 = 78;
	static const int G_5 = 79;
	static const int Ab_5 = 80;
	static const int A_5 = 81;
	static const int Bb_5 = 82;
	static const int B_5 = 83;
	static const int C_6 = 84;
	static const int Db_6 = 85;
	static const int D_6 = 86;
	static const int Eb_6 = 87;
	static const int E_6 = 88;
	static const int F_6 = 89;
	static const int Gb_6 = 90;
	static const int G_6 = 91;
	static const int Ab_6 = 92;
	static const int A_6 = 93;
	static const int Bb_6 = 94;
	static const int B_6 = 95;
	static const int C_7 = 96;
	static const int Db_7 = 97;
	static const int D_7 = 98;
	static const int Eb_7 = 99;
	static const int E_7 = 100;
	static const int F_7 = 101;
	static const int Gb_7 = 102;
	static const int G_7 = 103;
	static const int Ab_7 = 104;
	static const int A_7 = 105;
	static const int Bb_7 = 106;
	static const int B_7 = 107;
	static const int C_8 = 108;
	static const int Db_8 = 109;
	static const int D_8 = 110;
	static const int Eb_8 = 111;
	static const int E_8 = 112;
	static const int F_8 = 113;
	static const int Gb_8 = 114;
	static const int G_8 = 115;
	static const int Ab_8 = 116;
	static const int A_8 = 117;
	static const int Bb_8 = 118;
	static const int B_8 = 119;
	static const int C_9 = 120;
	static const int Db_9 = 121;
	static const int D_9 = 122;
	static const int Eb_9 = 123;
	static const int E_9 = 124;
	static const int F_9 = 125;
	static const int Gb_9 = 126;
	static const int G_9 = 127;


	double freq[128] = {
		8.18,
		8.66,
		9.18,
		9.72,
		10.3,
		10.91,
		11.56,
		12.25,
		12.98,
		13.75,
		14.57,
		15.43,
		16.35,
		17.32,
		18.35,
		19.45,
		20.6,
		21.83,
		23.12,
		24.5,
		25.96,
		27.5,
		29.14,
		30.87,
		32.7,
		34.65,
		36.71,
		38.89,
		41.2,
		43.65,
		46.25,
		49.0,
		51.91,
		55.0,
		58.27,
		61.74,
		65.41,
		69.3,
		73.42,
		77.78,
		82.41,
		87.31,
		92.5,
		98.0,
		103.83,
		110.0,
		116.54,
		123.47,
		130.81,
		138.59,
		146.83,
		155.56,
		164.81,
		174.61,
		185.0,
		196.0,
		207.65,
		220.0,
		233.08,
		246.94,
		261.63,
		277.18,
		293.66,
		311.13,
		329.63,
		349.23,
		369.99,
		392.0,
		415.3,
		440.0,
		466.16,
		493.88,
		523.25,
		554.37,
		587.33,
		622.25,
		659.26,
		698.46,
		739.99,
		783.99,
		830.61,
		880.0,
		932.33,
		987.77,
		1046.5,
		1108.73,
		1174.66,
		1244.51,
		1318.51,
		1396.91,
		1479.98,
		1567.98,
		1661.22,
		1760.0,
		1864.66,
		1975.53,
		2093.0,
		2217.46,
		2349.32,
		2489.02,
		2637.02,
		2793.83,
		2959.96,
		3135.96,
		3322.44,
		3520.0,
		3729.31,
		3951.07,
		4186.01,
		4434.92,
		4698.64,
		4978.03,
		5274.04,
		5587.65,
		5919.91,
		6271.93,
		6644.88,
		7040.0,
		7458.62,
		7902.13,
		8372.02,
		8869.84,
		9397.27,
		9956.06,
		10548.08,
		11175.3,
		11839.82,
		12543.85
	};

	std::vector<int> getChord(int root, std::string name)
	{
		std::vector<int> chordTone;

		if (name == "7")
		{
			chordTone = getChord7(root);
		}
		else if (name == "Major7")
		{
			chordTone = getChordMajor7(root);
		}
		else if (name == "Minor7")
		{
			chordTone = getChordMinor7(root);
		}
		else if (name == "6")
		{
			chordTone = getChord6(root);
		}

		return chordTone;
	}

	std::vector<int> getChordMajor(int root)
	{
		std::vector<int> chordTone = {root, root + 4, root + 7};
		return chordTone;
	}

	std::vector<int> getChordMinor(int root)
	{
		std::vector<int> chordTone = { root, root + 3, root + 7 };
		return chordTone;
	}

	std::vector<int> getChord7(int root)
	{
		std::vector<int> chordTone = { root, root + 4, root + 7, root + 10 };
		return chordTone;
	}

	std::vector<int> getChordMajor7(int root)
	{
		std::vector<int> chordTone = { root, root + 4, root + 7, root + 11 };
		return chordTone;
	}

	std::vector<int> getChordMinor7(int root)
	{
		std::vector<int> chordTone = { root, root + 3, root + 7, root + 10 };
		return chordTone;
	}

	std::vector<int> getChordMajorMinor7(int root)
	{
		std::vector<int> chordTone = { root, root + 3, root + 7, root + 11 };
		return chordTone;
	}

	std::vector<int> getChord6(int root)
	{
		std::vector<int> chordTone = { root, root + 4, root + 7, root + 9 };
		return chordTone;
	}
};