#include "SaladStepper.h"
#include "Arduino.h"
SaladStepper::SaladStepper(int in1, int in2, int in3, int in4) {
	_in1 = in1;
	_in2 = in2;
	_in3 = in3;
	_in4 = in4;
}

void SaladStepper::begin() {
	pinMode(_in1, OUTPUT);
	pinMode(_in2, OUTPUT);
	pinMode(_in3, OUTPUT);
	pinMode(_in4, OUTPUT);
}

void SaladStepper::stepLeft(int mode) {
	if (mode) {
		_fullStepCounter++;
		if (_fullStepCounter >= 4) _fullStepCounter = 0;
		digitalWrite(_in1, _fullStepMap[_fullStepCounter][0]);
		digitalWrite(_in2, _fullStepMap[_fullStepCounter][1]);
		digitalWrite(_in3, _fullStepMap[_fullStepCounter][2]);
		digitalWrite(_in4, _fullStepMap[_fullStepCounter][3]);
	}
	else {
		_halfStepCounter++;
		if (_halfStepCounter >= 8) _halfStepCounter = 0;
		digitalWrite(_in1, _halfStepMap[_halfStepCounter][0]);
		digitalWrite(_in2, _halfStepMap[_halfStepCounter][1]);
		digitalWrite(_in3, _halfStepMap[_halfStepCounter][2]);
		digitalWrite(_in4, _halfStepMap[_halfStepCounter][3]);
	}
}

void SaladStepper::stepRight(int mode) {
	if (mode) {
		_halfStepCounter--;
		if (_halfStepCounter <= -1) _halfStepCounter = 7;
		digitalWrite(_in1, _fullStepMap[_fullStepCounter][0]);
		digitalWrite(_in2, _fullStepMap[_fullStepCounter][1]);
		digitalWrite(_in3, _fullStepMap[_fullStepCounter][2]);
		digitalWrite(_in4, _fullStepMap[_fullStepCounter][3]);
	}
	else {
		_halfStepCounter--;
		if (_halfStepCounter <= -1) _halfStepCounter = 7;
		digitalWrite(_in1, _halfStepMap[_halfStepCounter][0]);
		digitalWrite(_in2, _halfStepMap[_halfStepCounter][1]);
		digitalWrite(_in3, _halfStepMap[_halfStepCounter][2]);
		digitalWrite(_in4, _halfStepMap[_halfStepCounter][3]);
	}
}