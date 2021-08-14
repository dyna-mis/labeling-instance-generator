#pragma once
#include "uniform.h"

class uniform_rect : public uniform{
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
