#ifndef CIRCLE_HPP_INCLUDED
#define CIRCLE_HPP_INCLUDED
#include <iostream>
#include "point.hpp"

namespace geometry {
	namespace circle {
		class Circle {
		public:
			geomerty::point::Point p;
			double r;
			friend std::istream& operator>>(std::istream& input1, Circle& c) {
				input1 >> c.p >> c.r;
				return input1;
			}
		};
		Circle input_circle(Circle& a);
	}
}
#endif // CIRCLE_HPP_INCLUDED;