#ifndef RECT_H
#define RECT_H



#include <tuple>


namespace rra
{


// Defines the location of a rectangle.
// Useful for hitboxes, collisions, etc.
//
// Rect = ((top_left_corner_x, top_left_corner_y), (bottom_right_corner_x, bottom_right_corner_y))
struct Rect{
    
    private:
        // Don't worry, it's just (x1, y1), (x2, y2)
        std::array<int, 2> top_left_corner{};         
        std::array<int, 2> bottom_right_corner{};     

    public:
        Rect(std::array<int, 2> top_left_corner, std::array<int, 2> bottom_right_corner);
        Rect(std::array<std::array<int, 2>, 2> top_left_and_bottom_right_corners_inside_array);
        Rect(std::array<int, 4> int_coords);

        int get_width() { return get_array()[1] - get_array()[0]; }
        int get_height() { return get_array()[2] - get_array()[0]; }

        std::array<int, 2> get_top_left_corner();
        int get_top_left_corner_x();
        int get_top_left_corner_y();
        std::array<int, 2> get_bottom_right_corner();
        int get_bottom_right_corner_x();
        int get_bottom_right_corner_y();

    
        std::array<std::array<int, 2>, 2> get_top_left_and_bottom_right_corners();
        std::array<int, 4> get_array();                                        // Same as collision_hitbox, but returns the result in a different format - returns an array of the 4 vertices :3 In this order: top_left_corner_x, top_left_corner_y, bottom_left_corner_x, bottom_left_corner_y.
        std::array<std::array<int, 2>, 4> get_vertex_array();                // Same as collision_hitbox, but returns the result in a different format - returns an array of the 4 vertices :3 In this order: top left corner, top right corner, bottom left corner, bottom right corner.

        // Friendly reminder that this one is 0-indexed! (!o _o)
        // Invariant: 0 <= index <= 3
        std::array<int, 2> get_vertex(int index);

    };
};


#endif