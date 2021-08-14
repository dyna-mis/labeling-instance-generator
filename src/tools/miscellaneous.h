/*
 * miscellaneous.h
 *
 *  Created on: Oct 7, 2019
 *      Author: guangping
 */

#ifndef MISCELLANEOUS_H_
#define MISCELLANEOUS_H_
using namespace std;
#define _USE_MATH_DEFINES
#include <math.h>
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#include <set>
#include <iostream>
#include <CGAL/Simple_cartesian.h>
#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_2 Point_2;
#include <random>
#include "cxxopts.hpp"
extern  cairo_surface_t* surface;
extern  cairo_t *cr;

extern double label_height;
extern double label_width;

extern std::string type;
extern double width;
extern double height;
extern vector<size_t> number_each;
extern int seed;
extern double p_x;
extern double p_y;

extern std::string result_folder;
extern std::string prac_file;
extern bool is_rectangle;
extern size_t total_number;
extern vector<double> letter_dis;


inline size_t get_letter_index(double v) {
	size_t i = 0;
	for (const auto& t : letter_dis) {
		if (v < t) {
			return i;
		}
		else i++;
	}



}

inline string get_file_name(const std::string& file) {
	const std::size_t found = file.find_last_of("/\\");
	return  file.substr(found + 1);
}

//xPRINT+++++++++++++++PRINT+++++++++++++++++++++++++
#ifdef GENERATOR_PRINT
void startDrawing(const char* fileName);
void finishDrawing();
#endif
//xPRINT---------------PRINT-------------------------
void parseInitOptions(int argc, char* argv[]);

void printInitOptions();
void printInitUsage();
bool check_valid(const Point_2& p);
#endif /* MISCELLANEOUS_H_ */
