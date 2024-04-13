#include "output.hpp"
#include "circle.hpp"
#include "quadr.hpp"
#include "geom.hpp"
#include <iostream>

int main()
{
    geometry::circle::Circle circ1;
    geometry::quadr::Quadr quad1;

    output::name();
    output::task_requirement();

    geometry::circle::input_circle(circ1);
    geometry::quadr::input_quadr(quad1);

    geometry::position_quard_about_circle(circ1, quad1);

    output::bye();
    return 0;
}
