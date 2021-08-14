//============================================================================
// Name        : InputGenerator.cpp
// Author      : GPL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "inputGenerator.h"

// "uniform", width, height, number,model
template <typename T>
void instance_generate(){
	T instance;
	instance.set();
	//instance.print();
	std::string  os = result_folder+"/output/";
	if (is_rectangle) {
		os +="rectangle/"+ type +"/"+type;
	}
	else{
		os += "square/" + type + "/"+type;
	}
	if (type.compare("prac") == 0) {
		os.append("-");
		if (is_rectangle) {
			os.append("rectangle");
			os.append("-");
		}
		os.append(get_file_name(prac_file));
	}
	else {
		os.append("-");
		if (is_rectangle) {
			os.append("rectangle");
			os.append("-");
		}
		os.append(std::to_string(seed));
		os.append("-");
		os.append(std::to_string(total_number));
	}
	instance.output(os.c_str());
//xPRINT+++++++++++++++PRINT+++++++++++++++++++++++++
#ifdef GENERATOR_PRINT

	startDrawing("../../test.pdf");
	instance.drawPoints(cr);
	finishDrawing();
#endif
//xPRINT---------------PRINT-------------------------
}



int main(int argc, char *argv[]){
	std::cout.precision(5);
	std::cout << std::fixed;
	parseInitOptions(argc, argv);
	srand(seed);
	if (is_rectangle) {
		if (type.compare("uniform") == 0) {
			instance_generate<uniform_rect>();

		}
		if (type.compare("gaussian") == 0) {
			instance_generate<gaussian_rect>();
		}
		if (type.compare("prac") == 0) {
			instance_generate<prac_rect>();
		}
	}
	else {
		if (type.compare("uniform") == 0) {
			instance_generate<uniform>();
		}
		if (type.compare("gaussian") == 0) {
			instance_generate<gaussian>();
		}
		if (type.compare("prac") == 0) {
			instance_generate<prac>();
		}
	}
	return 0;
}


