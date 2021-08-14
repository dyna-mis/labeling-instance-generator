#pragma once

#include <iostream>
#include <set>
#include <assert.h>
#include <fstream>
#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
#include "miscellaneous.h"



struct cmp_tol {
	bool operator() (const double& a, const double& b) const {
		return (a - b) < -0.00003;
	};
};

class square {
public:
	std::vector<Point_2> points;
	square() {};
	virtual void set() {};

	virtual void output(const char* fileName);

	void get_length();

	//xPRINT+++++++++++++++PRINT+++++++++++++++++++++++++
#ifdef GENERATOR_PRINT
	virtual void print();
	void drawPoints(cairo_t* cr);
#endif
	//xPRINT---------------PRINT-------------------------


protected:
	vector<size_t> label_widths;
	virtual void test();

	std::set<double, ::cmp_tol> points_x;
	std::set<double, ::cmp_tol> points_y;
	bool look_up_y(double y);
	bool look_up_x(double x);
};
