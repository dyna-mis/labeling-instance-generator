#pragma once
#include "gaussian.h"

class gaussian_rect :public gaussian {
public:
	void set() override;
	void output(const char* fileName) override;
protected:
	void test() override;
	//xPRINT+++++++++++++++PRINT+++++++++++++++++++++++++
#ifdef GENERATOR_PRINT
	void print() override;
#endif
	//xPRINT---------------PRINT-------------------------
};