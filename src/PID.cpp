#include "PID.h"
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	// assign the PID coefficients
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;

	// initialize the all error team as zero
	p_error = 0;
	i_error = 0;
	d_error = 0;

	last_cte = 0;
	return;
}

void PID::UpdateError(double cte) {
	p_error = Kp * cte;
	i_error += Ki * cte;
	d_error = Kd * (cte - last_cte);

	last_cte = cte;
	return;
}

double PID::TotalError() {
	return p_error + i_error + d_error;
}

