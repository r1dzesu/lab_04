#include "geom.hpp"
#include "output.hpp"
#include "point.hpp"
#include "circle.hpp"
#include "quadr.hpp"
#include <cmath>
#include <iostream>

namespace geometry {
	double angle_betw_vec(geomerty::point::Point v1, geomerty::point::Point v2) {
		return v1.x * v2.x + v1.y * v2.y / (std::sqrt(v1.x * v1.x + v1.y * v1.y) * std::sqrt(v2.x * v2.x + v2.y * v2.y));
	}

	double dist_betw_points(geomerty::point::Point p1, geomerty::point::Point p2) {
		return std::sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
	}

	double dist_betw_point_segment(geomerty::point::Point c, geomerty::point::Point p1, geomerty::point::Point p2) {
		if (angle_betw_vec(c-p1, p2-p1) <= 0 || angle_betw_vec(c-p2, p1-p2) <= 0)
			return std::min(dist_betw_points(c, p1), dist_betw_points(c, p2));
		double a = p1.x - p2.x, b = p2.y - p1.y, d = -p2.y * p1.x + p2.x * p1.y;
		return abs(a * c.x + b * c.y + d) / sqrt(a * a + b * b);
	}

	void position_quard_about_circle(geometry::circle::Circle c, geometry::quadr::Quadr q) {
		if (dist_betw_points(c.p, q.p1) < c.r && dist_betw_points(c.p, q.p2) < c.r && dist_betw_points(c.p, q.p3) < c.r && dist_betw_points(c.p, q.p4) < c.r) {
			output::figures_dnt_intersect(); // quard is in the circle
			return;
		}

		if (dist_betw_point_segment(c.p, q.p1, q.p2) <= c.r || dist_betw_point_segment(c.p, q.p2, q.p3) <= c.r || dist_betw_point_segment(c.p, q.p3, q.p4) <= c.r || dist_betw_point_segment(c.p, q.p4, q.p1) <= c.r) {
			output::figures_intersect(); // quadr intersects the circle
			return;
		}
		output::figures_dnt_intersect(); // quard is in the circle
		return;
	}

	bool three_points_are_collinear(geomerty::point::Point p1, geomerty::point::Point p2, geomerty::point::Point p3) {
		return (p3.y * (p1.x - p2.x) + p3.x * (p2.y - p1.y) - p2.y * p1.x + p2.x * p1.y == 0) ? true : false;
	}

	bool four_points_are_collinear(geometry::quadr::Quadr q) {
		return (three_points_are_collinear(q.p1, q.p2, q.p3) || three_points_are_collinear(q.p1, q.p2, q.p4) || three_points_are_collinear(q.p2, q.p3, q.p4) || three_points_are_collinear(q.p1, q.p3, q.p4)) ? true : false;
	}
}
