#include <tuple>
#include <array>

#ifndef PLAYER_MOVEMENT_H
#define PLAYER_MOVEMENT_H

class Player {
    
    private:

        bool alive {true};   // If alive = false, trigger a "game over" screen.

        int player_x {0};               // Might be changed later on with fixed-point math (signed 20.11f fixed-point)
        int player_y {0};               // Might be changed later on with fixed-point math (signed 20.11f fixed-point)

        signed int player_de_facto_speed_x {0};         // Might be changed later on with fixed-point math (signed 20.11f fixed-point)
        signed int player_de_facto_speed_y {0};         // Might be changed later on with fixed-point math (signed 20.11f fixed-point)

        signed int player_speed_x {0};         // Might be changed later on with fixed-point math (signed 20.11f fixed-point)
        signed int player_speed_y {0};         // Might be changed later on with fixed-point math (signed 20.11f fixed-point)    


    public:
        Player(bool alive, int player_x, int player_y, signed int player_de_facto_speed_x, signed int player_de_facto_speed_y, signed int player_speed_x, signed int player_speed_y);

        std::tuple<int, int> getPosition() const { return std::tuple<int,int> (player_x, player_y); }
        int getPosition_x() const { return player_x; }
        int getPosition_y() const { return player_y; }
        

        std::tuple<int, int> player_topleft_damage_hitbox();
        std::tuple<int, int> player_bottomright_damage_hitbox();
        std::tuple<std::tuple<int, int>, std::tuple<int, int>> damage_hitbox();


        std::tuple<int, int> player_topleft_collision_hitbox();
        std::tuple<int, int> player_bottomright_collision_hitbox();
        std::tuple<std::tuple<int, int>, std::tuple<int, int>> collision_hitbox();
        std::array<int, 4> collision_hitbox_array();                   // Same as collision_hitbox, but returns the result in a different format - in an array :3

        // std::array<int, int, int, int> collision_hitbox_array();    // Same as collision_hitbox, but returns the result in a different format - in an array :3
        // std::array collision_hitbox(string arr)
};


// bool collides_horizontally (player.Coordinates) {

// }

// int main {
// Player player {player_x, player_y};
// }



#endif