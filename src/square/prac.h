/*
 * Instance.h
 *
 *  Created on: Oct 7, 2019
 *      Author: guangping
 */

#ifndef prac_H_
#define prac_H_
#include <iostream>
#include <set>
#include <assert.h>
#include <fstream>
#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
#include "miscellaneous.h"
#include "square.h"


class prac : public square {
public:
	prac() {};
	void set() override;
protected:
	void test() override;
};




#endif /* prac_H_ */
