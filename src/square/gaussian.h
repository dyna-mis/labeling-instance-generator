/*
 * gaussian.h
 *
 *  Created on: Nov 18, 2019
 *      Author: guangping
 */

#ifndef gaussian_H_
#define gaussian_H_
#include <iostream>
#include <set>
#include <assert.h>
#include <fstream>
#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
#include <vector>
#include "miscellaneous.h"
#include "square.h"
class gaussian:public square{
protected:
	std::set<Point_2> means;
public:
	gaussian(){};
	void set() override;
	//xPRINT+++++++++++++++PRINT+++++++++++++++++++++++++
#ifdef GENERATOR_PRINT
	void print() override;
#endif
	//xPRINT---------------PRINT-------------------------
};
#endif /* gaussian_H_ */
