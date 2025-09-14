#include <tuple>

#ifndef PLAYER_MOVEMENT_H
#define PLAYER_MOVEMENT_H

class Player {
    
    private:

        bool alive {true};   // If alive = false, trigger a "game over" screen.

        int player_x {0};               // Might be changed later on with fixed-point math (signed 27.4f fixed-point)
        int player_y {0};               // Might be changed later on with fixed-point math (signed 27.4f fixed-point)

        signed int player_de_facto_speed_x {0};         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)
        signed int player_de_facto_speed_y {0};         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)

        signed int player_speed_x {0};         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)
        signed int player_speed_y {0};         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)    



    public:
        Player(bool alive, int player_x, int player_y, signed int player_de_facto_speed_x, signed int player_de_facto_speed_y, signed int player_speed_x, signed int player_speed_y);

        std::tuple<int, int> position();

        std::tuple<int, int> player_topleft_hitbox();

        std::tuple<int, int> player_bottomright_hitbox();
        
        std::tuple<std::tuple<int, int>, std::tuple<int, int>> hitbox();

        bool is_alive();
};


// bool collides_horizontally (player.Coordinates) {

// }

// int main {
// Player player {player_x, player_y};
// }



#endif