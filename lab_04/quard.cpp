#include "quadr.hpp"
#include "geom.hpp"
#include "output.hpp"
#include <iostream>
#include <limits>

namespace geometry {
	namespace quadr {
		Quadr  input_quadr(Quadr& quad) {
			output::coord_quadr();

			while (1) {
				try {
					std::cin >> quad;
					if (!std::cin)
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						throw std::exception_ptr();//виключення при неправильному вводі
					}
					if (four_points_are_collinear(quad)) throw std::invalid_argument("");
					return quad;
				}
				catch (std::exception_ptr) {
					output::incor_input();
				}
				catch (std::invalid_argument) {
					output::inv_quadr();
				}
			}
		}
	}
}