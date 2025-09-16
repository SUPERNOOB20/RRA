// This source file has the task of setting the player's
// hitbox and collision boxes

// :3

#include "player_bounding_boxes.h"
#include <tuple>
#include <array>

Player::Player(bool alive, int player_x, int player_y, signed int player_de_facto_speed_x, signed int player_de_facto_speed_y, signed int player_speed_x, signed int player_speed_y)

    : alive { true }   // If alive = false, trigger a "game over" screen.

    , player_x { 0 }               // Might be changed later on with fixed-point math (signed 20.11f fixed-point)
    , player_y { 0 }               // Might be changed later on with fixed-point math (signed 20.11f fixed-point)

{
}


std::tuple<int, int> Player::player_topleft_damage_hitbox(){
    std::tuple<int, int> player_topleft_hitbox = {getPosition_x() + 11, getPosition_y() + 22};    // edge INCLUDED
    return player_topleft_hitbox;
}

std::tuple<int, int> Player::player_bottomright_damage_hitbox(){
    std::tuple<int, int> player_topleft_hitbox = {getPosition_x() + 15, getPosition_y() + 25};    // edge INCLUDED
    return player_topleft_hitbox;
}

std::tuple<std::tuple<int, int>, std::tuple<int, int>> Player::damage_hitbox(){      // Returns (player_topleft_hitbox(), player_bottomright_hitbox())
    std::tuple<std::tuple<int, int>, std::tuple<int, int>> hitbox = {player_topleft_damage_hitbox(), player_bottomright_damage_hitbox()};
    return hitbox;
}

std::tuple<int, int> Player::player_topleft_collision_hitbox(){
    std::tuple<int, int> player_topleft_hitbox = {getPosition_x() + 8, getPosition_y() + 15};    // edge INCLUDED
    return player_topleft_hitbox;
}

std::tuple<int, int> Player::player_bottomright_collision_hitbox(){
    std::tuple<int, int> player_topleft_hitbox = {getPosition_x() + 19, getPosition_y() + 32};    // edge INCLUDED
    return player_topleft_hitbox;
}

std::tuple<std::tuple<int, int>, std::tuple<int, int>> Player::collision_hitbox(){      // Returns (player_topleft_hitbox(), player_bottomright_hitbox())
    std::tuple<std::tuple<int, int>, std::tuple<int, int>> hitbox = {player_topleft_damage_hitbox(), player_bottomright_damage_hitbox()};
    return hitbox;
}

std::array<int, 4> Player::collision_hitbox_array(){

    // auto test = std::get<0>(player_topleft_damage_hitbox());

    // auto a = Player::player_topleft_damage_hitbox();

    std::array<int, 4> hitbox = {std::get<0>(Player::player_topleft_damage_hitbox()), std::get<1>(player_topleft_damage_hitbox()), std::get<0>(player_bottomright_damage_hitbox()), std::get<1>(player_bottomright_damage_hitbox())};
    return hitbox;
}

// check_