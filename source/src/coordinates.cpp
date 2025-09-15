#include "coordinates.h"
#include <tuple>

// Defines the location of a rectangle.
// Useful for hitboxes, collisions, etc.
Coordinates::Coordinates(std::tuple<int, int> top_left_corner, std::tuple<int, int> bottom_right_corner)
    : top_left_corner{ top_left_corner }
    , bottom_right_corner { bottom_right_corner }
{
}

Coordinates::Coordinates(std::tuple<std::tuple<int, int>, std::tuple<int, int>> top_left_and_bottom_right_corners)
    : top_left_corner{ std::get<0>(top_left_and_bottom_right_corners) }
    , bottom_right_corner { std::get<1>(top_left_and_bottom_right_corners) }
{
}