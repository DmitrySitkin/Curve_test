#pragma once
#include "Curves.h"
class Helixe :public Curves {
protected:
	double x, y, z, radius, step;
public:
	Helixe() : x(0.0), y(0.0), z(0.0), radius(1), step(1){}
	Helixe(double _x, double _y, double _z, double r, double s)
		:x(_x), y(_y), z(_z), step(s) {
		if (r <= 0) {
			std::cout << "Error" << std::endl;
			return;
		}
		else {
			radius = r;
		}
	}
	Helixe(const Helixe &hel) {
		x = hel.x;
		y = hel.y;
		z = hel.z;
		radius = hel.radius;
		step = hel.step;
	}

	double get_point_x(double t) {
		return (x + radius * cos(t));
	}
	double get_point_y(double t) {
		return (y + radius * sin(t));
	}
	double get_point_z(double t) {
		return ((radius * step * t) / (2 * PI));
	}

	double get_radius() { return radius; }

	double get_derive_point_x(double t) {
		return ((-1) * radius * sin(t));
	}
	double get_derive_point_y(double t) {
		return (radius * cos(t));
	}
	double get_derive_point_z(double t) {
		return ((radius * step) / (2 * PI));
	}

	Helixe& operator= (const Helixe &hel) {
		x = hel.x;
		y = hel.y;
		z = hel.z;
		radius = radius = hel.radius;
		step = hel.step;
		return *this;
	}
	~Helixe() {}
};
