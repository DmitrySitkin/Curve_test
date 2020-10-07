#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <memory>
#include <typeinfo>
#include "Ellipse.h"
#include "Circle.h"
#include "Helixe.h"

struct sort_by_rad
{
	bool operator()(std::shared_ptr<Circle> x, std::shared_ptr<Circle> y)
	{
		return x->get_radius() < y->get_radius();
	}
};

int main() {
	double z_point = 0;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<>
		type(1, 3),
		points(-1000, 1000), 
		radiuses(1, 100),
		steps(1, 50);
	int n = 0;
	std::cout << "Enter count of objects: ";
	std::cin >> n;
	std::vector<std::shared_ptr<Curves>> vector_curves(n);

	for (int i = 0; i < vector_curves.size(); i++) {
		int c_type = type(gen);
		double x = points(gen);
		double y = points(gen);
		double z = points(gen);
		double rad = radiuses(gen);
		double st = steps(gen);
		switch (c_type) {
		case 1: {
			vector_curves[i] = std::make_shared<Circle>(x, y, z, rad);
			break;
			}
		case 2: {
			double rad2 = radiuses(gen);
			vector_curves[i] = std::make_shared<Ellipse>(x, y, z, rad, rad2);
			break;
		}
		case 3: {
			vector_curves[i] = std::make_shared<Helixe>(x, y, z, rad, st);
			break;
		}
		default: break;
		}
	}

	for (int i = 0; i < vector_curves.size(); i++) {
		std::cout << i + 1
			<< ": Point( "
			<< vector_curves[i]->get_point_x(PI / 4)
			<< ", "
			<< vector_curves[i]->get_point_y(PI / 4)
			<< ", "
			<< vector_curves[i]->get_point_z(PI / 4)
			<< ") "
			<< " Derivative( "
			<< vector_curves[i]->get_derive_point_x(PI / 4)
			<< ", "
			<< vector_curves[i]->get_derive_point_y(PI / 4)
			<< ", "
			<< vector_curves[i]->get_derive_point_z(PI / 4)
			<< ")"
			<< std::endl
			<< std::endl;
	}

	double radius_sum = 0.0;

	std::vector<std::shared_ptr<Circle>> circ_vector;
	for (auto curv : vector_curves) {
		if (std::dynamic_pointer_cast<Circle>(curv)
			&& !std::dynamic_pointer_cast<Helixe>(curv)) {
			circ_vector.push_back(std::static_pointer_cast<Circle>(curv));
			radius_sum += curv->get_radius();
		}
	}

	std::sort(circ_vector.begin(), circ_vector.end(), sort_by_rad());
	std::cout << "Sum of all cirles is: " << radius_sum << std::endl;
	return 0;
}
