/*
 * gaussian.cpp
 *
 *  Created on: Nov 18, 2019
 *      Author: guangping
 */
#include "gaussian.h"
//ratio vector,e.g <5, 5, 2> means three centers with number of points in each distribution 5:5:2
//nu: number of vertices of one percentage
void gaussian::set(){
    std::mt19937 gen(rand()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis_x(label_width, width - label_width);
    std::uniform_real_distribution<> dis_y(label_height, height - label_height);
    auto rng_w = std::bind(dis_x, std::ref(gen));
    auto rng_h = std::bind(dis_y, std::ref(gen));
	while (means.size() < number_each.size()) {
		Point_2 p(rng_w(), rng_h());
		if (check_valid(p)) {
			if (look_up_y(p.y()) == true) continue;
			if (look_up_x(p.x()) == true) continue;
			points_x.insert(p.x());
			points_y.insert(p.y());
			means.insert(p);
		}
	}
	int i = 0;
	for (auto mean : means) {
		double x, y;
		std::mt19937 gen_x{(size_t)rand() };
		std::mt19937 gen_y{ (size_t)rand() };
		 //std::normal_distribution<> d_x{mean.x(),p_x* (0.5 + 0.5*(double)rand() / (RAND_MAX))};
		 //std::normal_distribution<> d_y{mean.y(),p_y* (0.5 + 0.5 * (double)rand() / (RAND_MAX))};
		 std::normal_distribution<> d_x{ mean.x(),p_x};
		 std::normal_distribution<> d_y{ mean.y(),p_y};
		 unsigned int S = points.size()+ number_each[i];
		 while(points.size() < S){
			 x = d_x(gen_x);
			 y = d_y(gen_y);
			if(x < width && y < height&& x > 0&& y > 0){
				Point_2 p(x, y);
				if (check_valid(p)) {
					if (look_up_y(p.y()) == true) continue;
					if (look_up_x(p.x()) == true) continue;
					points_x.insert(p.x());
					points_y.insert(p.y());
					points.push_back(Point_2(x, y));
				}


			}
		 }
		 i++;
	}
	//xPRINT+++++++++++++++PRINT+++++++++++++++++++++++++
#ifdef GENERATOR_PRINT
	print();
#endif
	//xPRINT---------------PRINT-------------------------
};
//xPRINT+++++++++++++++PRINT+++++++++++++++++++++++++
#ifdef GENERATOR_PRINT
void gaussian::print(){
	square::print();
	std::cout<< "p_x: "<< p_x<< std::endl;
	std::cout<< "p_y: "<< p_y<< std::endl;
	int i =1;
	for(auto e: means){
		std::cout<<"mean"<< i<<": "<< e.x()<< " "<< e.y()<< std::endl;
		i++;
	}
	i =1;
	for(auto e: points){
		std::cout<<"point"<< i<<": "<< e.x()<< " "<< e.y()<< std::endl;
		i++;
	}
};
#endif
//xPRINT---------------PRINT-------------------------





