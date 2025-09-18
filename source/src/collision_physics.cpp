#include "bn_vector.h"
#include "coordinates.h"
#include <tuple>
#include "player_bounding_boxes.h"



// Checks if any player-block collisions are happening. If so, then it solves them.
// "player_coords" stands for player_collision_coordinates
// "block_coords" stands for blocks_collision_coordinates
void check_and_handle_collisions(Player* player, bn::vector<Rect_Coordinates, 9999>* block_coords){

    // player_vertices = ((x1, y1), (x2, y2), (x3, y3), (x4, y4))
    std::tuple<std::tuple<int, int>, std::tuple<int, int>> player_vertices = player->collision_hitbox();

    // for (Rect_Coordinates block : block_coords){
    for (int block_coord_index = 0 ; block_coords->size() ; block_coord_index++){

        bool block_collides_with_player = check_collisions(player_vertices, block);

        if (block_collides_with_player){
            handle_collisions(player_vertices, block_coords);
        }

        return;
    }
}

bool check_collisions(std::tuple<std::tuple<int, int>, std::tuple<int, int>> player_vertices, Rect_Coordinates block){

    bool block_collides_with_player = false;

    // for (std::tuple<int, int> vertex : player_vertices){
    for (int player_vertex_index ; 3; player_vertex_index++){
        if ((player_coords.test()) && ()){
            block_collides_with_player = true;
        }
    }
}
    /*
    for (Rect_Coordinates coordinate : block_coords) {
  
        bool player_is_colliding_with_block = (player_coords_x) && () && () && ()

        if (player_is_colliding_with_block){
            handle_collisions();
        }
            
    }
    */

    return;
}



// Checks if any player-block collisions are happening. If so, then it solves them.
// "player_coords" stands for player_collision_coordinates
// "block_coords" stands for blocks_collision_coordinates
void check_and_handle_collisions(Player* player, bn::vector<Rect_Coordinates, 9999>* block_coords){

    // player_coords = ((x1, y1), (x2, y2), (x3, y3), (x4, y4))
    std::tuple<std::tuple<int, int>, std::tuple<int, int>> Player* player_coords = player->collision_hitbox();

    
    for (Rect_Coordinates block : block_coords) {
  
        bool player_is_colliding_with_block = (player_coords_x) && () && () && ()

        if (player_is_colliding_with_block){
            handle_collisions();
        }
            
    }

    return;
}
















/*
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
}


*/