#include "player.h"

#include <tuple>
#include <array>

#ifndef PLAYER_BOUNDING_BOXES_H
#define PLAYER_BOUNDING_BOXES_H



class Player
{

public:

    class Damage_Hitbox
    {
        private:
            std::array<int, 2>                 getPosition_topleft_corner(Player& p) { return {p.player_x + 8, p.player_y + 15}; }
            std::array<int, 2>                 getPosition_bottomright_corner(Player& p) { return {p.player_x + 19, p.player_y + 32}; }
            std::array<std::array<int, 2>, 2>  getPosition_topleft_and_bottomright_corners(Player& p) { return {{p.player_x + 8, p.player_y + 15}, {p.player_x + 19, p.player_y + 32}}; }

        public:
            std::tuple<int, int> player_topleft_damage_hitbox();
            std::tuple<int, int> player_bottomright_damage_hitbox();
            std::tuple<std::tuple<int, int>, std::tuple<int, int>> damage_hitbox();
            std::array<int, 4> damage_hitbox_array();                                        // Same as collision_hitbox, but returns the result in a different format - returns an array of the 4 vertices :3 In this order: top_left_corner_x, top_left_corner_y, bottom_left_corner_x, bottom_left_corner_y.
            std::array<std::tuple<int, int>, 4> damage_hitbox_vertex_array();                // Same as collision_hitbox, but returns the result in a different format - returns an array of the 4 vertices :3 In this order: top left corner, top right corner, bottom left corner, bottom right corner.
    };

    class Collision_Hitbox
    {
        private:
            std::array<int, 2>                 GetPosition_topleft_corner(Player& p) { return {p.player_x + 11, p.player_y + 22}; }    
            std::array<int, 2>                 GetPosition_bottomright_corner(Player& p) { return {p.player_x + 15, p.player_y + 25}; }    
            std::array<std::array<int, 2>, 2>  GetPosition_topleft_and_bottomright_corners(Player& p) { return {{p.player_x + 11, p.player_y + 22}, {p.player_x + 15, p.player_y + 25}}; }    
        
        public:
            std::tuple<int, int> player_topleft_collision_hitbox();
            std::tuple<int, int> player_bottomright_collision_hitbox();
            std::tuple<std::tuple<int, int>, std::tuple<int, int>> collision_hitbox();
            std::array<int, 4> collision_hitbox_array();                                        // Same as collision_hitbox, but returns the result in a different format - returns an array of the 4 vertices :3 In this order: top_left_corner_x, top_left_corner_y, bottom_left_corner_x, bottom_left_corner_y.
            std::array<std::tuple<int, int>, 4> collision_hitbox_vertex_array();                // Same as collision_hitbox, but returns the result in a different format - returns an array of the 4 vertices :3 In this order: top left corner, top right corner, bottom left corner, bottom right corner.
    };
    
private:

    int player_x {0};               // Might be changed later on with fixed-point math (signed 20.11f fixed-point)
    int player_y {0};               // Might be changed later on with fixed-point math (signed 20.11f fixed-point)
    
    std::tuple<int, int> getPosition() const { return std::tuple<int,int> (player_x, player_y); }
    int getPosition_x() const { return player_x; }
    int getPosition_y() const { return player_y; }
    
};


// bool collides_horizontally (player.Coordinates) {

// }

// int main {
// Player player {player_x, player_y};
// }



#endif