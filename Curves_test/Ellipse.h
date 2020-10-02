#pragma once
#include <utility>
#include "Curves.h"

const double PI = 3.14159;

class Ellipse :public Curves {
protected:
	double x, y, z, radius, radius_2;
public:
	Ellipse(): x(0.0), y(0), z(0), radius(1), radius_2(2) {}
	Ellipse(double _x, double _y, double _z, double r1, double r2)
		: x(_x), y(_y), z(_z) {
		if (r1 <= 0 || r2 <= 0) {
			std::cout << "Error" << std::endl;
			return;
		}
		else {
			radius = r1;
			radius_2 = r2;
		}
	}
	Ellipse(const Ellipse &ell) {
		x = ell.x;
		y = ell.y;
		z = ell.z;
		radius = ell.radius;
		radius_2 = ell.radius_2;
	}
	double get_point_x(double t) { 
		return (x + radius * cos(t));
	}
	double get_point_y(double t) { 
		return (y + radius_2 * sin(t));
	}
	double get_point_z(double t) { return 0; }

	double get_derive_point_x(double t) {
		return ((-1) * radius * sin(t));
	}
	double get_derive_point_y(double t) {
		return (radius_2 * cos(t));
	}
	double get_derive_point_z(double t) { return 0; }

	double get_radius() { return 0; }
	std::pair<double, double> get_radiuses() { 
		return std::make_pair(radius, radius_2);
	}

	Ellipse& operator= (const Ellipse &ell) {
		x = ell.x;
		y = ell.y;
		z = ell.z;
		radius = ell.radius;
		radius_2 = ell.radius_2;
		return *this;
	}
	~Ellipse() {}
};