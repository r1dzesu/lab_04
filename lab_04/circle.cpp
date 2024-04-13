#include "circle.hpp"
#include "output.hpp"
#include <iostream>
#include <limits>
#include <exception>

namespace geometry {
	namespace circle {
		Circle input_circle(Circle& a) {
			output::coord_circle();
			while (1) {
				try {
					std::cin >> a;
					if (!std::cin)
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						throw std::exception_ptr();//виключення при неправильному вводі
					}
					if (a.r < 0) throw std::invalid_argument("");//виключення, якщорадіус < 0 
					return a;
				}
				catch (std::exception_ptr) {
					output::incor_input();
				}
				catch (std::invalid_argument) {
					output::inv_rad();
				}
			}
		}
	}
}
