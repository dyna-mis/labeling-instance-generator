/*
 * instance.cpp
 *
 *  Created on: Oct 7, 2019
 *      Author: guangping
 */
#include "uniform.h"

void uniform::set(){
    std::mt19937 gen(rand()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis_x(label_width, width-label_width);
    std::uniform_real_distribution<> dis_y(label_height, height-label_height);
    auto rng_w = std::bind(dis_x, std::ref(gen));
    auto rng_h = std::bind(dis_y, std::ref(gen));
	while(points.size()< number_each[0]){
		Point_2 p(rng_w(), rng_h());
		if (check_valid(p)) {
			if (look_up_y(p.y()) == true) continue;
			if (look_up_x(p.x()) == true) continue;
			points_x.insert(p.x());
			points_y.insert(p.y());
			points.push_back(p);
		}
	}
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
void uniform::test(){
	square::test();
	assert((unsigned )number_each[0] == points.size());
}





