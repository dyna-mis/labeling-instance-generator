/*
 * instance.cpp
 *
 *  Created on: Oct 7, 2019
 *      Author: guangping
 */
#include "prac.h"

void prac::set() {
	std::mt19937 gen(rand()); //Standard mersenne_twister_engine seeded with rd()
	ifstream fp;
	//fp.open("Debug/instance.cnf",std::ios::in);
	fp.open(prac_file, std::ios::in);
	if (!fp.is_open()) {
		std::cout << prac_file << std::endl;
		perror("read file fails");
		exit(EXIT_FAILURE);
	}
	string buff;
	char head;
	getline(fp, buff);
	getline(fp, buff);
	while (!fp.eof()) {
		if (buff.empty()) continue;
		head = buff.at(0);
		if (head == 'p') {
			break;
		}
		getline(fp, buff);
	}
	//std::cout<< buff<< std::endl;
	// Parse the p line
	char* str = strdup(buff.c_str());
	const char s[2] = " ";
	strtok(str, s);
	strtok(NULL, s);
	size_t point_size = (size_t)atoi(strtok(NULL, s));

	width = atof(strtok(NULL, s));
	height = atof(strtok(NULL, s));
	for (unsigned int i = 0; i < point_size; i++) {
		getline(fp, buff);
		if (buff.empty()) continue;
		str = strdup(buff.c_str());
		strtok(str, " ");
		double x = atof(strtok(NULL, " "));
		double y = atof(strtok(NULL, " "));
		points.push_back(Point_2(x, y));
	}
	assert(points.size() == point_size);
	//TODO: unique points
	number_each[0] = points.size();
	//xPRINT+++++++++++++++PRINT+++++++++++++++++++++++++
#ifdef GENERATOR_PRINT
	print();
#endif
	//xPRINT---------------PRINT-------------------------
};
// n= size of elements in vector
// valid elements
void prac::test() {
	//square::test();
	assert((unsigned)number_each[0] == points.size());
}





