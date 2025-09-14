#ifndef COORDINATES_H
#define COORDINATES_H



#include <tuple>


// Defines the location of a rectangle.
// Useful for hitboxes, collisions, etc.
struct Coordinates{
    
    private:
        // Don't worry, it's just (x1, y1), (x2, y2)
        std::tuple<int, int> top_left_corner;         
        std::tuple<int, int> bottom_right_corner;     

    public:
        Coordinates(std::tuple<int, int> top_left_corner, std::tuple<int, int> bottom_right_corner);

};



#endif