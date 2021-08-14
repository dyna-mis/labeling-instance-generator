#include "prac_rect.h"

void prac_rect::set() {
	prac::set();
	label_widths = vector<size_t>(number_each[0], 0);
	get_length();

	//TODO: unique points
	//xPRINT+++++++++++++++PRINT+++++++++++++++++++++++++
#ifdef GENERATOR_PRINT
	print();
#endif
	//xPRINT---------------PRINT-------------------------
};
void prac_rect::test() {
	prac::test();
	for (size_t i = 0; i < number_each[0]; i++) {
		assert(label_widths[i] >= 1);
		assert(label_widths[i] < 21);
	}
}
//xPRINT+++++++++++++++PRINT+++++++++++++++++++++++++
#ifdef GENERATOR_PRINT
void prac_rect::print() {
	prac::print();
	for (const auto& e : label_widths) {
		std::cout << "label_width:" << e << std::endl;
	}
};
#endif
//xPRINT---------------PRINT-------------------------
void prac_rect::output(const char* fileName) {
	std::ofstream myfile;
	myfile.open(fileName);
	myfile.precision(5);
	myfile << std::fixed;
	myfile << "c " << fileName << std::endl;
	myfile << "p rectangle " << points.size()<< " " << width << " " << height << std::endl;
	size_t i = 0;
	for (auto e : points) {
		myfile << "e " << e.x() << " " << e.y() << " " << label_widths[i] << std::endl;
		i++;
	}
	myfile.close();

};

