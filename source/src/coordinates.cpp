#include "coordinates.h"
#include <tuple>


// Defines the location of a rectangle.
// Useful for hitboxes, collisions, etc.
struct Coordinates::Coordinates(std::tuple<int, int> top_left_corner, std::tuple<int, int> bottom_right_corner){
    : top_left_corner{ top_left_corner }
    , bottom_right_corner { bottom_right_corner }
{
}