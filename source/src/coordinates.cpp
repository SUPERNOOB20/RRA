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


std::tuple<int, int> get_top_left_corner(Rect_Coordinates coords){
    return top_left_corner;
}
int get_top_left_corner_x(Rect_Coordinates coords){
    return std::get<0>(top_left_corner);
}
int get_top_left_corner_y(Rect_Coordinates coords){
    return std::get<1>(top_left_corner);
}
std::tuple<int, int> get_bottom_right_corner(Rect_Coordinates coords){
    return bottom_right_corner;
}
int get_bottom_right_corner_x(Rect_Coordinates coords){
    return std::get<0>(bottom_right_corner);
}
int get_bottom_right_corner_y(Rect_Coordinates coords){
    return std::get<1>(bottom_right_corner);
}