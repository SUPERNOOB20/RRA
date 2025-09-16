#include "player_movement.h"
#include <tuple>

// signed 20.11f fixed-point format.
const int player_fp = 11;

Player::Player(bool alive, signed int player_real_x, signed int player_real_y, int player_x, int player_y, signed int player_de_facto_speed_x, signed int player_de_facto_speed_y, signed int player_speed_x, signed int player_speed_y)
    
    : alive { true }   // If alive = false, trigger a "game over" screen.

    , player_x { 0 }               // Might be changed later on with fixed-point math (signed 20.11f fixed-point)
    , player_y { 0 }               // Might be changed later on with fixed-point math (signed 20.11f fixed-point)

    , player_real_x { 0 }
    , player_real_y { 0 }

    , player_de_facto_speed_x { 0 }         // Might be changed later on with fixed-point math (signed 20.11f fixed-point)
    , player_de_facto_speed_y { 0 }         // Might be changed later on with fixed-point math (signed 20.11f fixed-point)

    , player_speed_x { 0 }         // Might be changed later on with fixed-point math (signed 20.11f fixed-point)
    , player_speed_y { 0 }         // Might be changed later on with fixed-point math (signed 20.11f fixed-point)    

{
}

std::tuple<int, int> Player::get_position(){
    std::tuple<int, int> player_position = {player_x, player_y};
    return player_position;
}

std::tuple<int, int> Player::set_position(int player_x, int player_y){
    std::tuple<int, int> player_position = {player_x, player_y};
    return player_position;
}

// If the player isn't alive, they shouldn't be able to move anymore! :p
bool Player::is_alive(){
    return alive;
}

// bool collides_horizontally (player.Coordinates) {

// }

// int main {
// Player player {player_x, player_y};
// }