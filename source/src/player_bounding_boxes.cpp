// This source file has the task of setting the player's
// hitbox and collision boxes

// :3

#include "player.h"
#include "player_movement.h"
#include "player_bounding_boxes.h"
#include "coordinates.h"
#include <tuple>
#include <array>




std::tuple<int, int> Player::Damage_Hitbox::player_topleft_damage_hitbox(){
    std::tuple<int, int> player_topleft_hitbox = {getPosition_topleft_corner()[0] + 11, getPosition_topleft_corner()[1] + 22};    // edge INCLUDED
    return player_topleft_hitbox;
}

std::tuple<int, int> Player::Damage_Hitbox::player_bottomright_damage_hitbox(){
    std::tuple<int, int> player_topleft_hitbox = {getPosition_x() + 15, getPosition_y() + 25};    // edge INCLUDED
    return player_topleft_hitbox;
}

std::tuple<std::tuple<int, int>, std::tuple<int, int>> Player::Damage_Hitbox::damage_hitbox(){      // Returns (player_topleft_hitbox(), player_bottomright_hitbox())
    std::tuple<std::tuple<int, int>, std::tuple<int, int>> hitbox = {player_topleft_damage_hitbox(), player_bottomright_damage_hitbox()};
    return hitbox;
} 

std::array<int, 4> damage_hitbox_array(){
    std::array<int, 4> hitbox = {std::get<0>(player_topleft_damage_hitbox()), std::get<1>(player_topleft_damage_hitbox()), std::get<0>(player_bottomright_damage_hitbox()), std::get<1>(player_bottomright_damage_hitbox())};
    return hitbox;
} 

std::array<std::tuple<int, int>, 4> damage_hitbox_vertex_array(){
    std::tuple<int, int> topleft_corner = Player::Damage_Hitbox::player_topleft_damage_hitbox();
    std::tuple<int, int> topright_corner = {std::get<0>(Player::Damage_Hitbox::player_bottomright_damage_hitbox()), std::get<1>(Player::Damage_Hitbox::player_topleft_damage_hitbox())};
    std::tuple<int, int> bottomleft_corner = {std::get<0>(Player::Damage_Hitbox::player_topleft_damage_hitbox()), std::get<1>(Player::Damage_Hitbox::player_bottomright_damage_hitbox())};
    std::tuple<int, int> bottomright_corner = Player::Damage_Hitbox::player_bottomright_damage_hitbox();

    std::array<std::tuple<int, int>, 4> hitbox = {topleft_corner, topright_corner, bottomleft_corner, bottomright_corner};
    return hitbox;
}

std::tuple<int, int> Player::Collision_Hitbox::player_topleft_collision_hitbox(){
    std::tuple<int, int> player_topleft_hitbox = {getPosition_x() + 8, getPosition_y() + 15};    // edge INCLUDED
    return player_topleft_hitbox;
}

std::tuple<int, int> Player::Collision_Hitbox::player_bottomright_collision_hitbox(){
    std::tuple<int, int> player_topleft_hitbox = {getPosition_x() + 19, getPosition_y() + 32};    // edge INCLUDED
    return player_topleft_hitbox;
}

std::tuple<std::tuple<int, int>, std::tuple<int, int>> Player::Collision_Hitbox::collision_hitbox(){      // Returns (player_topleft_hitbox(), player_bottomright_hitbox())
    std::tuple<std::tuple<int, int>, std::tuple<int, int>> hitbox = {player_topleft_collision_hitbox(), player_bottomright_collision_hitbox()};
    return hitbox;
}

std::array<int, 4> Player::Collision_Hitbox::collision_hitbox_array(){

    std::array<int, 4> hitbox = {std::get<0>(player_topleft_collision_hitbox()), std::get<1>(player_topleft_collision_hitbox()), std::get<0>(player_bottomright_damage_hitbox()), std::get<1>(player_bottomright_damage_hitbox())};
    return hitbox;
}

std::array<std::tuple<int, int>, 4> Player::Collision_Hitbox::collision_hitbox_vertex_array(){

    std::tuple<int, int> topleft_corner = Player::Collision_Hitbox::player_topleft_collision_hitbox();
    std::tuple<int, int> topright_corner = {std::get<0>(Player::Collision_Hitbox::player_bottomright_collision_hitbox()), std::get<1>(Player::Collision_Hitbox::player_topleft_collision_hitbox())};
    std::tuple<int, int> bottomleft_corner = {std::get<0>(Player::Collision_Hitbox::player_topleft_collision_hitbox()), std::get<1>(Player::Collision_Hitbox::player_bottomright_collision_hitbox())};
    std::tuple<int, int> bottomright_corner = Player::Collision_Hitbox::player_bottomright_collision_hitbox();

    std::array<std::tuple<int, int>, 4> hitbox = {topleft_corner, topright_corner, bottomleft_corner, bottomright_corner};
    return hitbox;
}

// check_