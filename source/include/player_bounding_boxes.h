#include "player.h"

#include <tuple>
#include <array>

#ifndef PLAYER_BOUNDING_BOXES_H
#define PLAYER_BOUNDING_BOXES_H



class Player {

    // I didn't want to duplicate code from "player.h", but alas... *sigh*

    private:

    int player_x {0};               // Might be changed later on with fixed-point math (signed 20.11f fixed-point)
    int player_y {0};               // Might be changed later on with fixed-point math (signed 20.11f fixed-point)
    
    std::tuple<int, int> getPosition() const { return std::tuple<int,int> (player_x, player_y); }
    int getPosition_x() const { return player_x; }
    int getPosition_y() const { return player_y; }

    // End of duplicated code. Phew ":3



    public:

        std::tuple<int, int> player_topleft_damage_hitbox();
        std::tuple<int, int> player_bottomright_damage_hitbox();
        std::tuple<std::tuple<int, int>, std::tuple<int, int>> damage_hitbox();

        std::tuple<int, int> player_topleft_collision_hitbox();
        std::tuple<int, int> player_bottomright_collision_hitbox();
        std::tuple<std::tuple<int, int>, std::tuple<int, int>> collision_hitbox();
        std::array<int, 4> collision_hitbox_array();                                        // Same as collision_hitbox, but returns the result in a different format - returns an array of the 4 vertices :3 In this order: top_left_corner_x, top_left_corner_y, bottom_left_corner_x, bottom_left_corner_y.
        std::array<std::tuple<int, int>, 4> collision_hitbox_vertex_array();                // Same as collision_hitbox, but returns the result in a different format - returns an array of the 4 vertices :3 In this order: top left corner, top right corner, bottom left corner, bottom right corner.

        // vv  Dropped idea to make collision_hitbox argument call constructors... ew  vv
        // std::array collision_hitbox(string arr)
};


// bool collides_horizontally (player.Coordinates) {

// }

// int main {
// Player player {player_x, player_y};
// }



#endif