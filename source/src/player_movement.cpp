#include "player_movement.h"
#include <tuple>

// signed 27.4f fixed-point format.
const int player_fp = 3;

Player::Player(bool alive, int player_x, int player_y, signed int player_de_facto_speed_x, signed int player_de_facto_speed_y, signed int player_speed_x, signed int player_speed_y)
    
    : alive { true }   // If alive = false, trigger a "game over" screen.

    , player_x { 0 }               // Might be changed later on with fixed-point math (signed 27.4f fixed-point)
    , player_y { 0 }               // Might be changed later on with fixed-point math (signed 27.4f fixed-point)

    , player_de_facto_speed_x { 0 }         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)
    , player_de_facto_speed_y { 0 }         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)

    , player_speed_x { 0 }         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)
    , player_speed_y { 0 }         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)    

{
}

std::tuple<int, int> Player::position(){
    std::tuple<int, int> player_position = {player_x, player_y};
    return player_position;
}

std::tuple<int, int> Player::player_topleft_hitbox(){
    std::tuple<int, int> player_topleft_hitbox = {player_x + 11, player_y + 22};    // edge INCLUDED
    return player_topleft_hitbox;
}

std::tuple<int, int> Player::player_bottomright_hitbox(){
    std::tuple<int, int> player_topleft_hitbox = {player_x + 15, player_y + 25};    // edge INCLUDED
    return player_topleft_hitbox;
}

std::tuple<std::tuple<int, int>, std::tuple<int, int>> Player::hitbox(){      // Returns (player_topleft_hitbox(), player_bottomright_hitbox())
    std::tuple<std::tuple<int, int>, std::tuple<int, int>> hitbox = {player_topleft_hitbox(), player_bottomright_hitbox()};
    return hitbox;
}

bool Player::is_alive(){
    return alive;
}

// bool collides_horizontally (player.Coordinates) {

// }

// int main {
// Player player {player_x, player_y};
// }