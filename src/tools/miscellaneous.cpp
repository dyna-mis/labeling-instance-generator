/*
 * miscellaneous.cpp
 *
 *  Created on: Oct 7, 2019
 *      Author: guangping
 */
#include "miscellaneous.h"
 //xPRINT+++++++++++++++PRINT+++++++++++++++++++++++++
#ifdef GENERATOR_PRINT

cairo_surface_t* surface;
cairo_t* cr;




void startDrawing(const char* fileName) {
    surface = cairo_pdf_surface_create(fileName, width * 1.2, height * 1.2);
    cr = cairo_create(surface);
    cairo_select_font_face(cr, "serif", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_font_size(cr, 32.0);
    cairo_set_source_rgb(cr, 0.0, 0.0, 1.0);
    cairo_set_line_width(cr, 2.5);
    cairo_rectangle(cr, width * 0.01, height * 0.01, 1.1*width, 1.1*height);
    cairo_stroke(cr);
}
void finishDrawing() {
    cairo_destroy(cr);
    cairo_surface_destroy(surface);
}
#endif
//xPRINT---------------PRINT-------------------------

std::string type;
double width;
double height;
vector<size_t> number_each;
int seed;
double p_x;
double p_y;
bool is_rectangle;
std::string result_folder;
std::string prac_file;
size_t total_number;
vector<double> letter_dis = {
0,
0,
0.1,
0.7,
3.3,
8.5,
17,
29.2,
43.2,
57.2,
69.8,
79.8,
87.3,
92.5,
95.7,
97.7,
98.7,
99.3,
99.6,
99.8,
99.9,
100 };




void parseInitOptions(int argc, char* argv[]) {
	cxxopts::Options options("dynaMIS", "Geometric MIS");

	options.add_options()
		("r,rectangle", "rectangle instance", cxxopts::value<bool>()->default_value("false"))
		("t,type", "type of instance", cxxopts::value<std::string>()->default_value("uniform"))
		("w,width", "width of map", cxxopts::value<double>()->default_value("720"))
		("l,height", "height of map", cxxopts::value<double>()->default_value("1080"))
		("n,number", "total number of points", cxxopts::value<size_t>()->default_value("10"))
		("p,portion", "portions of each distribution", cxxopts::value<std::vector<double>>()->default_value("0.7,0.2,0.1"))
		("s,seed", "seed for generation", cxxopts::value<int>()->default_value("0"))
		("x", "p_x", cxxopts::value<double>()->default_value("90"))
		("y", "p_y", cxxopts::value<double>()->default_value("160"))
		("h,help", "Print usage")
		("d", "dictionary", cxxopts::value<std::string>()->default_value("D:/GIT/C++/input_generator"))
		("f", "file", cxxopts::value<std::string>()->default_value(" "))
		;
	options.allow_unrecognised_options();
	auto result = options.parse(argc, argv);

	is_rectangle = result["rectangle"].as<bool>();
	type = result["type"].as<std::string>();
	width = result["width"].as<double>();
	height = result["height"].as<double>();
	total_number = result["number"].as<size_t>();
	prac_file = result["f"].as<std::string>();
	if (type.compare("uniform") == 0) {
		number_each = { total_number};
	
	}
	else {
		vector<double> portions = result["portion"].as<vector<double>>();
		for(const auto& p: portions) {
			size_t s = (size_t)((double)total_number * p);
			number_each.push_back(s);
		}
	}


	p_x = result["x"].as<double>();
	p_y = result["y"].as<double>();
	result_folder = result["d"].as<std::string>();
	seed = result["seed"].as<int>();
	if (result.count("help"))
	{
		printInitUsage();
		exit(0);
	}
};


void printInitOptions() {
	printf("inputGenerator Initialization options \n");
	cout << "type:" << type << endl;
	cout << "width:" << width << endl;
	cout << "height:" << height << endl;
	for (const auto& e : number_each) {
		cout << "  number:" << e << endl;
	}

	cout << "p_x:" << p_x << endl;
	cout << "p_y:" << p_y << endl;
	cout << "result_folder:" << result_folder << endl;
}

/*print the manual of the program*/
void printInitUsage() {
	cout << "\n--------inputGenerator, a Point Labeling Instance Generator by " << BLUE << "TUWIEN" << RESET << " -----------------\n";
	printf("\nauthor: Sujoy Bhore, Guangping Li and Martin Nöllenburg \n");
	printf("Human-centered Algorithm Engineering: Graph and Map Visualization\n");
	printf("Research Project supported by the Austrian Science Fund(FWF), grant P 31119\n");
	printf("https://www.ac.tuwien.ac.at/research/humalgo/\n");

	printf("\n-------------------Usage--------------------------------------------------------\n");
	printf("./inputGenerator [options]\n");


	printf("\n-------------------Options------------------------------------------------------\n");
	printf("   --type, -t : type of instance (see type options below)\n");
	printf("   --width, -w : width of map (720)\n");
	printf("   --help, -h : output this help\n");
	printf("   --height, -l : height of map (1080)\n");
	printf("   --number=, -n= : total number of points \n");
	printf("   --portion=: portions of size in each distribution, separated by \",\" \n");
	printf("   --px, -x : sigma_x of a distribution\n");
	printf("   --py, -y : sigma_y of a distribution\n");
	printf("   --dictionary, -d : output dictionary\n");
	printf("   --seed, -s : seed for random generator\n");

	printf("---------------------------------------------------------------------------------\n");
	printf("\n-------------------type options------------------------------------------------------\n");
	printf("   uniform : uniform distributed point set \n");
	printf("   gaussian: gaussian distribution\n");
	printf("   ear: a main distribution with several small gaussian distribution \n");
	printf("see examples in ./examples \n");
	printf("---------------------------------------------------------------------------------\n");
}

double label_height = 10;
double label_width = 10;

bool check_valid(const Point_2& p) {

	// grid & line
	double x_factor = p.x() / label_width;
	double intpart;
	double fractpart = modf(x_factor, &intpart);
	if (fractpart < 0.01) return false;
	if (fractpart > 0.49 && fractpart < 0.51) return false;

	double y_factor = p.y() / label_height;
	fractpart = modf(y_factor, &intpart);
	if (fractpart < 0.01) return false;
	if (fractpart > 0.49 && fractpart < 0.51) return false;

	return true;
}