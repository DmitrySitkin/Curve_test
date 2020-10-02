#pragma once
#include <math.h>
#include "Curves.h"
class Circle :public Curves {
protected:
	double x, y, z, radius;
public:
	Circle() : x(0.0), y(0.0), z(0.0), radius(1) {}
	Circle(double _x, double _y, double _z, double r) 
		: x(_x), y(_y), z(_z) {
		if (r <= 0) {
			std::cout << "Error" << std::endl;
			return;
		}
		else {
			radius = r;
		}
	}
	Circle(const Circle &c) {
		x = c.x;
		y = c.y;
		z = c.z;
		radius = c.radius;
	}

	double get_point_x(double t) {
		return (x + radius * cos(t));
	}
	double get_point_y(double t) {
		return (y + radius * sin(t));
	}
	double get_point_z(double t) { return 0; }

	double get_derive_point_x(double t) {
		return ((-1) * radius * sin(t));
	}
	double get_derive_point_y(double t) {
		return (radius * cos(t));
	}
	double get_derive_point_z(double t) { return 0;	}

	double get_radius() { return radius; }
	
	Circle& operator= (const Circle &c) {
		x = c.x;
		y = c.y;
		z = c.z;
		radius = c.radius;
		return *this;
	}

	friend bool operator< (const Circle &c1, const Circle &c2) {
		return (c1.radius < c2.radius);
	}

	bool operator < (const Circle &c2) const {
		return (radius < c2.radius);
	}

	 bool operator > (const Circle c2) const {
		 return (radius > c2.radius);
	}

	friend bool operator<= (const Circle &c1, const Circle &c2) {
		return (c1.radius <= c2.radius);
	}

	friend bool operator> (const Circle &c1, const Circle &c2) {
		return (c1.radius > c2.radius);
	}

	friend bool operator>= (const Circle &c1, const Circle &c2) {
		return (c1.radius >= c2.radius);
	}

	friend bool operator== (const Circle &c1, const Circle &c2) {
		return (c1.radius == c2.radius);
	}

	friend bool operator!= (const Circle &c1, const Circle &c2) {
		return (c1.radius != c2.radius);
	}
	~Circle() {}
};
