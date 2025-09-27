#include "bn_vector.h"
#include "rect.h"
#include <tuple>
#include <array>
#include <vector>
// #include "player_bounding_boxes.h"
#include "player.h"




bool vertex_contained_within_rect(std::array<int, 2> v, rra::Rect r){

    bool res = false;

    // if v's x and y coords are within r's x and y coords, res = true.
    if ((v[0] >= r.get_top_left_corner(r)[0]) && (v[0] <= r.get_bottom_right_corner(r)[0]) &&
        (v[1] >= r.get_bottom_right_corner(r)[1]) && (v[1] <= r.get_top_left_corner(r)[1])){

            res = true;
        }
    
    return res;      
}

bool vertex_contained_within_rect(std::array<int, 2> v, rra::Rect r){

    bool res = false;

    // if v's x and y coords are within r's x and y coords, res = true.
    if ((v[0] >= r.get_top_left_corner(r)[0]) && (v[0] <= r.get_bottom_right_corner(r)[0]) &&
        (v[1] >= r.get_bottom_right_corner(r)[1]) && (v[1] <= r.get_top_left_corner(r)[1])){

            res = true;
        }
    
    return res;      
}

bool rect_contained_within_another_rect(rra::Rect r1, rra::Rect r2){

    bool res = false;

    // if r1's corners' x and y coords are within r2's corners' x and y coords, res = true.
    if ((r1.get_top_left_corner(r1)[0] > r2.get_top_left_corner(r2)[0]) &&
        (r1.get_top_left_corner(r1)[1] > r2.get_top_left_corner(r2)[1]) &&
        (r1.get_bottom_right_corner(r1)[0] < r2.get_bottom_right_corner(r2)[0]) &&
        (r1.get_bottom_right_corner(r1)[1] < r2.get_bottom_right_corner(r2)[1])){

            res = true;

        }
    
    return res;      
}

// Returns: (number_of_collisions, clipped_corners)
std::vector<std::array<int, 2>> check_partial_collisions(Player* player_collision_hitbox, bn::vector<rra::Rect, 9999>* block_coords){

    std::vector<std::array<int, 2>> clipped_corners = {};

    // player_vertices = ((x1, y1), (x2, y2), (x3, y3), (x4, y4))
    std::array<std::array<int, 2>, 4> player_vertices = player->get_();

    // for (Rect_Coordinates block : block_coords){
    for (int block_coord_index = 0 ; block_coords->size() ; block_coord_index++){

        bool block_collides_with_player = check_collisions(player_vertices, block_coords);

        if (block_collides_with_player){
            // corners_in_partial_clip++;
            clipped_corners.push_back(block_coords);
        }
    }

    return clipped_corners;
}

// Invariant: clipped_corners.size() == 1.
void handle_one_partial_collision(std::vector<std::array<int, 2>> clipped_corners){
    // int
    // coord clipped_corner = corners_in_partial_clip;
    return;
}


// Invariant: clipped_corners.size() == 2.
void handle_two_partial_collision(std::vector<std::array<int, 2>> clipped_corners, rra::Rect player, rra::Rect block){
    // int
    // coord clipped_corner = corners_in_partial_clip;
    return;
}


void check_and_handle_full_2c(rra::Rect player, rra::Rect block){
    if 
    return;
}

void handle_full_4c(Player player, rra::Rect block){
    
    if ((rect_contained_within_another_rect(block, player)) || (rect_contained_within_another_rect(player, block))){
        player->setDeFactoSpeed(player->getDeFactoSpeed() + 99);      // Solves collision via brute-forcing :3
    }

    return;
}


// Checks if any player-block collisions are happening. If so, then it solves them.
// "player_coords" stands for player_collision_coordinates
// "blocks_coords" stands for blocks_collision_coordinates
void check_and_handle_collisions(Player* player_collision_hitbox, bn::vector<rra::Rect, 9999>* blocks_coords){

    /*
    
    // "for block in blocks".
    // std::for_each(0, blocks_coords.size(), check_and_handle_collision(player_collision_hitbox, blocks_coords[i]))

    // -----------------------------------------------

    // A copy of the blocks_coords vector.
    blocks_coords_queue = blocks_coords;

    // "for block in blocks".
    for(int i = 0 ; int blocks_coords->size() ; i){
        block = blocks_coords.pop();
        check_and_handle_collision(player_collision_hitbox, blocks_coords[block]);
    }

    */

    // -----------------------------------------------

    // "for block in blocks".
    for(int block = 0 ; int blocks_coords->size() ; block++){
        check_and_handle_collision(player_collision_hitbox, blocks_coords[block]);
    }

    return;
}


// Checks if a player-block collisions is happening. If so, then it solves it.
// "player_coords" stands for player_collision_coordinates.
// "block_coords" stands for block_collision_coordinates.
void check_and_handle_collision(Player* player_collision_hitbox, bn::vector<rra::Rect, 9999>* block_coords){

    std::vector<std::array<int, 2>> corners_in_partial_clip = check_partial_collisions(player_collision_hitbox, block_coords);

    int number_of_corners_in_partial_clip = sizeof(corners_in_partial_clip);
    // Checks and solves case 1.
    if (number_of_corners_in_partial_clip == 1){
        handle_one_partial_collision(corners_in_partial_clip);
    }

    // Checks and solves case 2.
    if (number_of_corners_in_partial_clip == 2){
        handle_two_partial_collisions(corners_in_partial_clip);
    }

    // Checks and solves case 3.
    check_and_handle_full_2c();

    // Checks and solves case 4.
    bool block_is_inside_player = rect_contained_within_another_rect(block, player);
    bool player_is_inside_block = rect_contained_within_another_rect(player, block);

    if (block_is_inside_player || player_is_inside_block){
        handle_full_4c();
    }

    return;
}




/*
bool check_collisions(std::array<int, 4> player_vertices, rra::Rect block){

    bool block_collides_with_player = false;

    // for (std::array<int, 2> vertex : player_vertices){
    for (int player_vertex_index ; 3 ; player_vertex_index++){
        if ((player_vertices[player_vertex_index].x()) && ()){
            block_collides_with_player = true;
        }
    }

    return;
}
*/