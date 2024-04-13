#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED
#include <iostream>

namespace geomerty {
	namespace point {
		class Point {
		public: 
			double x, y;
			friend std::istream& operator>>(std::istream& input1, Point& q) {
				input1 >> q.x >> q.y;
				return input1;
			}
			friend Point operator-(Point a, Point b) {
				Point o;
				o.x = a.x - b.x;
				o.y = a.y - b.y;
				return o;
			}
		};
		Point input_point(Point& p);
	}
}
#endif // POINT_HPP_INCLUDED;

