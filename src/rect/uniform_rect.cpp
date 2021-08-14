#include "uniform_rect.h"

void uniform_rect::set() {
	uniform::set();
	label_widths = vector<size_t>(points.size(), 0);
	get_length();
	//xPRINT+++++++++++++++PRINT+++++++++++++++++++++++++
#ifdef GENERATOR_PRINT
	print();
#endif
	//xPRINT---------------PRINT-------------------------
};
void uniform_rect::test() {
	uniform::test();
	assert(number_each[0] == points.size());
	for (size_t i = 0; i < points.size(); i++) {
		assert(label_widths[i] >= 1);
		assert(label_widths[i] < 21);
	}
}
//xPRINT+++++++++++++++PRINT+++++++++++++++++++++++++
#ifdef GENERATOR_PRINT
void uniform_rect::print() {
	uniform::print();
	for (const auto& e : label_widths) {
		std::cout << "label_width:" << e << std::endl;
	}
};
#endif
//xPRINT---------------PRINT-------------------------
void uniform_rect::output(const char* fileName) {
	std::ofstream myfile;
	myfile.open(fileName);
	myfile.precision(5);
	myfile << std::fixed;
	myfile << "c " << fileName << std::endl;
	myfile << "p rectangle " << points.size() << " " << width << " " << height << std::endl;
	size_t i = 0;
	for (auto e : points) {
		myfile << "e " << e.x() << " " << e.y() << " "<< label_widths[i] << std::endl;
		i++;
	}
	myfile.close();

};

