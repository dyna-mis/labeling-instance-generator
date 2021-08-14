/*
 * Instance.h
 *
 *  Created on: Oct 7, 2019
 *      Author: guangping
 */

#ifndef uniform_H_
#define uniform_H_
#include <iostream>
#include <set>
#include <assert.h>
#include <fstream>
#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
#include "miscellaneous.h"
#include "square.h"


class uniform: public square{
public:
	uniform() {};
	void set() override;
protected:
	void test() override;
};




#endif /* uniform_H_ */
