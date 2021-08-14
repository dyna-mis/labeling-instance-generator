#include "square.h"
void square::output(const char* fileName){
	std::ofstream myfile;
	myfile.open(fileName);
	myfile.precision(5);
	myfile << std::fixed;
	myfile << "c " << fileName << std::endl;
	myfile << "p square " << number_each[0] << " " << width << " " << height << std::endl;
	for (auto e : points) {
		myfile << "e " << e.x() << " " << e.y() << std::endl;
	}
	myfile.close();

};

void square::get_length() {
	std::mt19937 gen(seed * 4); // seed the generator
	std::uniform_real_distribution<> distr(0, 100); // define the range
	auto rand_v_gen = std::bind(distr, std::ref(gen));
	double rand_v = rand_v_gen();

	for (size_t i = 0; i < points.size(); i++) {
		size_t candidate_len = 0;
		while (true) {
			size_t candidate_len = get_letter_index(distr(gen));
			double r = points[i].x() + candidate_len * label_width;
			if (look_up_y(r == true)) continue;
			else {
				points_x.insert(r);
				break;
			}
		}
		label_widths[i] = get_letter_index(distr(gen));
	}
}



void square::test() {
	std::set<double> x_s;
	std::set<double> y_s;
	for (auto e : points) {
		assert(e.x() <= width);
		assert(e.y() <= height);
		assert(e.x() >= 0);
		assert(e.y() >= 0);
		x_s.insert(e.x());
		y_s.insert(e.y());
	}
	assert(x_s.size() == points.size());
	assert(y_s.size() == points.size());




};
//xPRINT+++++++++++++++PRINT+++++++++++++++++++++++++
#ifdef GENERATOR_PRINT
void square::print() {
	//square::test();
	std::cout << "the seed " << seed << std::endl;
	for (const auto& e : number_each) {
		std::cout << "the number of points: " << e << std::endl;
	}

	std::cout << "the width: " << width << std::endl;
	std::cout << "the height: " << height << std::endl;
	int i = 1;
	for (auto e : points) {
		std::cout << "point" << i << ": " << e.x() << " " << e.y() << std::endl;
		i++;
	}
};

void square::drawPoints(cairo_t* cr) {
	for (auto e : points) {
		cairo_arc(cr, e.x() + 0.1 * width, 1.1 * height - e.y(), 1, 0, 2 * M_PI);
		cairo_stroke_preserve(cr);
		cairo_fill(cr);
	}
}
#endif
//xPRINT---------------PRINT-------------------------


bool square::look_up_x(double x) {
	if (points_x.find(x) != points_x.end()) {
		return true;
	} 
	return false;
}


bool square::look_up_y(double y) {
	if (points_y.find(y) != points_y.end()) {
		return true;
	}
	return false;
}