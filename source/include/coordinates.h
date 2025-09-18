#ifndef COORDINATES_H
#define COORDINATES_H



#include <tuple>


// Defines the location of a rectangle.
// Useful for hitboxes, collisions, etc.
//
// Rect_Coordinates = ((top_left_corner_x, top_left_corner_y), (bottom_right_corner_x, bottom_right_corner_y))
struct Rect_Coordinates{
    
    private:
        // Don't worry, it's just (x1, y1), (x2, y2)
        std::tuple<int, int> top_left_corner;         
        std::tuple<int, int> bottom_right_corner;     

    public:
        Rect_Coordinates(std::tuple<int, int> top_left_corner, std::tuple<int, int> bottom_right_corner);
        Rect_Coordinates(std::tuple<std::tuple<int, int>, std::tuple<int, int>> top_left_and_bottom_right_corners_inside_tuple);
        Rect_Coordinates(std::tuple<int, int, int, int> int_coords);

        std::tuple<int, int> get_top_left_corner(Rect_Coordinates coords);
        int get_top_left_corner_x(Rect_Coordinates coords);
        int get_top_left_corner_y(Rect_Coordinates coords);
        std::tuple<int, int> get_bottom_right_corner(Rect_Coordinates coords);
        int get_bottom_right_corner_x(Rect_Coordinates coords);
        int get_bottom_right_corner_y(Rect_Coordinates coords);

};



#endif