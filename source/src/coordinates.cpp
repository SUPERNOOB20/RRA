#include "coordinates.h"
#include <tuple>





Rect_Coordinates::Rect_Coordinates(std::tuple<int, int> top_left_corner, std::tuple<int, int> bottom_right_corner)
    : top_left_corner{ top_left_corner }
    , bottom_right_corner { bottom_right_corner }
{
}


Rect_Coordinates::Rect_Coordinates(std::tuple<std::tuple<int, int>, std::tuple<int, int>> top_left_and_bottom_right_corners)
    : top_left_corner{ std::get<0>(top_left_and_bottom_right_corners) }
    , bottom_right_corner { std::get<1>(top_left_and_bottom_right_corners) }
{
}


Rect_Coordinates::Rect_Coordinates(std::tuple<int, int, int, int> int_coords)
    : top_left_corner{ (std::get<0>(int_coords), std::get<1>(int_coords)) }
    , bottom_right_corner { (std::get<2>(int_coords), std::get<3>(int_coords)) }
{
}


top_left_corner(std::tuple<int, int> top_left_corner);
top_left_corner_x(int top_left_corner_x_coord);
top_left_corner_y(int top_left_corner_y_coord);
bottom_right_corner(std::tuple<int, int> bottom_right_corner);
bottom_right_corner_x(int bottom_right_corner_x);
bottom_right_corner_y(int bottom_right_corner_y);