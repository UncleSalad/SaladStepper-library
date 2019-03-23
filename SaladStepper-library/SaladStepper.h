#ifndef _SaladStepper_h
#define _SaladStepper_h
#include "Arduino.h"
#define HALFSTEP 0
#define FULLSTEP  1
	class SaladStepper {
	public:
		SaladStepper(int in1, int in2, int in3, int in4);
		void begin();
		void stepLeft(int mode);
		void stepRight(int mode);
	private:
		int _in1, _in2, _in3, _in4, _fullStepCounter, _halfStepCounter;
		int _fullStepMap[4][4] = {
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 1},
			{1, 0, 0, 1},
		};
		int _halfStepMap[8][4] = {
			{1, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 1, 0},
			{0, 0, 1, 1},
			{0, 0, 0, 1},
			{1, 0, 0, 1}
		};
	};
#endif

