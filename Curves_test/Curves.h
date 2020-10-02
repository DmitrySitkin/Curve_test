#pragma once
class Curves {
public:
	Curves() {};
	virtual double get_point_x(double t) = 0;
	virtual double get_point_y(double t) = 0;
	virtual double get_point_z(double t) = 0;
	virtual double get_derive_point_x(double t) = 0;
	virtual double get_derive_point_y(double t) = 0;
	virtual double get_derive_point_z(double t) = 0;
	virtual double get_radius() = 0;
	virtual ~Curves() {};
};