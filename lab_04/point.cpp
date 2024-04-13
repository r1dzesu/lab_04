#include "point.hpp"
#include "output.hpp"
#include <iostream>

namespace geomerty {
	namespace point {
		Point input_point(Point& p) {
			while (true)
			{
				try {
					std::cin >> p;
					if (!std::cin)
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						throw std::invalid_argument("");
					}
					return p;
				}
				catch (std::invalid_argument) {
					output::incor_input();
				}
			}
		}

		 
	}
}
