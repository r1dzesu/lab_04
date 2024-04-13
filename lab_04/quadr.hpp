#ifndef QUADR_HPP_INCLUDED
#define QUADR_HPP_INCLUDED
#include <iostream>
#include "point.hpp"

namespace geometry {
	namespace quadr {
		class Quadr {
		public:
			geomerty::point::Point p1, p2, p3, p4;
			friend std::istream& operator>>(std::istream& input1, Quadr& q) {
				input1 >> q.p1>> q.p2 >> q.p3 >> q.p4;
				return input1;
			}
		};

		Quadr  input_quadr(Quadr& quad);
	}
}
#endif // QUADR_HPP_INCLUDED;
