SaladStepper Library
===
Library for Arduino, allowing you to control a unipolar stepper motor *(so far only unipolar)*.

What can do
---
SaladStepper *name*(*in1*,*in2*,*in3*,*in4*);

*name*.begin();

*name*.stepLeft(*mode*);

*name*.stepRight(*mode*);

Modes
---
**HALFSTEP** - half-step mode
* 1000
* 1100
* 0100
* ...

**FULLSTEP** - full-step mode
* 1100
* 0110
* 0011
* ...
