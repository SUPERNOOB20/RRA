#include "rect.h"
// #include <tuple>
#include <array>



namespace rra
{


Rect::Rect(std::array<int, 2> top_left_corner, std::array<int, 2> bottom_right_corner)
    : top_left_corner{ top_left_corner }
    , bottom_right_corner { bottom_right_corner }
{
}

Rect::Rect(std::array<std::array<int, 2>, 2> top_left_and_bottom_right_corners)
    : top_left_corner{ top_left_and_bottom_right_corners[0] }
    , bottom_right_corner { top_left_and_bottom_right_corners[1] }
{
}

Rect::Rect(std::array<int, 4> int_coords)
    : top_left_corner{ std::array<int, 2> {int_coords[0], int_coords[1]} }
    , bottom_right_corner{ std::array<int, 2> {int_coords[2], int_coords[3]} }
{
}



std::array<int, 2> Rect::get_top_left_corner(Rect coords){
    return coords.top_left_corner;
}

int Rect::get_top_left_corner_x(Rect coords){
    return coords.top_left_corner[0];
}

int Rect::get_top_left_corner_y(Rect coords){
    return coords.top_left_corner[1];
}

std::array<int, 2> Rect::get_bottom_right_corner(Rect coords){
    return coords.bottom_right_corner;
}

int Rect::get_bottom_right_corner_x(Rect coords){
    return coords.bottom_right_corner[0];
}

int Rect::get_bottom_right_corner_y(Rect coords){
    return coords.bottom_right_corner[1];
}


// Returns (player_topleft_hitbox(), player_bottomright_hitbox()). This is sufficient to define a rectangle, or hitbox, or collision, etc.!
std::array<std::array<int, 2>, 2> Rect::get_top_left_and_bottom_right_corners(Rect coords){      
    std::array<std::array<int, 2>, 2> hitbox = {get_top_left_corner(coords), get_bottom_right_corner(coords)};
    return hitbox;
} 

std::array<int, 4> Rect::get_array(Rect coords){
    std::array<int, 4> hitbox = {rra::Rect::get_top_left_corner(coords)[0], rra::Rect::get_top_left_corner(coords)[1], rra::Rect::get_bottom_right_corner(coords)[0], rra::Rect::get_bottom_right_corner(coords)[1]};
    return hitbox;
} 

std::array<std::array<int, 2>, 4> Rect::get_vertex_array(Rect coords){

    std::array<int, 2> topleft_corner = rra::Rect::get_top_left_corner(coords);
    std::array<int, 2> topright_corner = {rra::Rect::get_bottom_right_corner(coords)[0], rra::Rect::get_top_left_corner(coords)[1]};
    std::array<int, 2> bottomleft_corner = {rra::Rect::get_top_left_corner(coords)[0], rra::Rect::get_bottom_right_corner(coords)[1]};
    std::array<int, 2> bottomright_corner = rra::Rect::get_bottom_right_corner(coords);

    std::array<std::array<int, 2>, 4> hitbox = {topleft_corner, topright_corner, bottomleft_corner, bottomright_corner};
    return hitbox;
}

std::array<int, 2> Rect::get_vertex(Rect rectangle, int index){
    return rectangle.get_vertex_array(rectangle)[index];
}

};