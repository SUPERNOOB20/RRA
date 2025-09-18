// This source file has the task of setting the player's
// hitbox and collision boxes

// :3

#include "player.h"
#include "player_movement.h"
#include "player_bounding_boxes.h"
#include "coordinates.h"
#include <tuple>
#include <array>




std::tuple<int, int> Player::player_topleft_damage_hitbox(){
    std::tuple<int, int> player_topleft_hitbox = {Player::getPosition_x() + 11, Player::getPosition_y() + 22};    // edge INCLUDED
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

std::array<std::tuple<int, int>, 4> collision_hitbox_vertex_array(){
    
}

// check_