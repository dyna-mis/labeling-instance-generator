#pragma once
#include "prac.h"

class prac_rect : public prac {
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
