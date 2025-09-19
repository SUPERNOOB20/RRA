#include "coordinates.h"
// #include <tuple>
#include <array>





Rect_Coordinates::Rect_Coordinates(std::array<int, 2> top_left_corner, std::array<int, 2> bottom_right_corner)
    : top_left_corner{ top_left_corner }
    , bottom_right_corner { bottom_right_corner }
{
}

Rect_Coordinates::Rect_Coordinates(std::array<std::array<int, 2>, 2> top_left_and_bottom_right_corners)
    : top_left_corner{ top_left_and_bottom_right_corners[0] }
    , bottom_right_corner { top_left_and_bottom_right_corners[1] }
{
}

Rect_Coordinates::Rect_Coordinates(std::array<int, 4> int_coords)
    : top_left_corner{ std::array<int, 2> {int_coords[0], int_coords[1]} }
    , bottom_right_corner{ std::array<int, 2> {int_coords[2], int_coords[3])} }
{
}



std::array<int, 2> Rect_Coordinates::get_top_left_corner(Rect_Coordinates coords){
    return coords.top_left_corner;
}

int Rect_Coordinates::get_top_left_corner_x(Rect_Coordinates coords){
    return coords.top_left_corner[0];
}

int Rect_Coordinates::get_top_left_corner_y(Rect_Coordinates coords){
    return coords.top_left_corner[1];
}

std::array<int, 2> Rect_Coordinates::get_bottom_right_corner(Rect_Coordinates coords){
    return coords.bottom_right_corner;
}

int Rect_Coordinates::get_bottom_right_corner_x(Rect_Coordinates coords){
    // return std::get<0>(bottom_right_corner);
    return coords.bottom_right_corner[0];
}

int Rect_Coordinates::get_bottom_right_corner_y(Rect_Coordinates coords){
    // return std::get<1>(bottom_right_corner);
    return coords.bottom_right_corner[1];
}