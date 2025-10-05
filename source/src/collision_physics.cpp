#include "bn_vector.h"
#include "rect.h"
#include <tuple>
#include <array>
#include <vector>
// #include "player_bounding_boxes.h"
#include "player.h"

// I've decided to keep this function name small so that it takes up less space and for it to be easier to type and read :)
// In the future, maybe learn to overload == operator? Or rewrite this by making a new operator! "^^
bool eq(std::vector<int> a, std::vector<int> b){
    if (a.size() != b.size()){
        return false;
    }
        
    for (int i; a.size(); i++){
        if (a[i] != b[i]){
        return false;
    }
    }
       
    return true;
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

// Returns: player collision hitbox's "clipped_corners".
std::vector<int> check_partial_collisions(Player* player, bn::vector<rra::Rect, 9999>* block_coords){

    // Any clipped corners will be indexed here.
    std::vector<int> clipped_corners_indices = {};

    // rra::Rect 

    // player_vertices = ((x1, y1), (x2, y2), (x3, y3), (x4, y4))
    std::array<std::array<int, 2>, 4> player_vertices = (player->get_collision_hitbox()).get_array();

    // for (Rect_Coordinates block : block_coords){
    for (int block_coord_index = 0 ; block_coords->size() ; block_coord_index++){

        bool block_collides_with_player = check_collisions(player_vertices, block_coords);

        if (block_collides_with_player){
            // corners_in_partial_clip++;
            clipped_corners_indices.push_back(block_coords);
        }
    }

    return clipped_corners_indices;
}

// Invariant: clipped_corners_indices.size() == 1.
void handle_one_partial_collision(std::vector<int> clipped_corners_indices, Player* player, rra::Rect block){
    // int
    // coord clipped_corner = corners_in_partial_clip;

    rra::Rect player_collision_hitbox = player->get_collision_hitbox();



    int delta_x = block.get_bottom_right_corner.x() - player.get_collision_hitbox_width()
    int delta_y = block.get_bottom_right_corner.y() - player.get_collision_hitbox_width()

    switch (clipped_corners_indices.back()){
        case 1:
            if (delta_x > delta_y){
                player->setPosition_x(block.get_top_left_corner.x() - player->get_collision_hitbox_width());
            } else
                player->setPosition_x(block.get_top_left_corner.x() - player->get_collision_hitbox_width());
            break;
        case 2:
            if (delta x > delta y){
                player->setPosition_x(block.get_top_left_corner.x() - player->get_collision_hitbox_width());
            } else {
                player->setPosition_x(block.get_top_left_corner.x() - player->get_collision_hitbox_width());
            }
            break;
        case 3:
            if (delta x > delta y){
                player->setPosition_x(block.get_top_left_corner.x() - player->get_collision_hitbox_width());
            } else {
                player->setPosition_x(block.get_top_left_corner.x() - player->get_collision_hitbox_width());
            }
            break;
        case 4:
            if (delta x > delta y){
                player->setPosition_x(block.get_top_left_corner.x() - player->get_collision_hitbox_width());
            } else {
                player->setPosition_x(block.get_top_left_corner.x() - player->get_collision_hitbox_width());
            }
            break;
        default:
    }

    return;
}


// Invariant: clipped_corners_indices.size() == 2.
void handle_two_partial_collisions(std::vector<int> clipped_corner_indices, Player* player, rra::Rect block){

    /*
    c_tl_x = block.get_top_left_corner.x()
    c_tl_y = block.get_top_left_corner.y()
    c_br_x = block.get_top_left_corner.x()
    c_br_y = block.get_top_left_corner.y()
    */

    if (eq(clipped_corner_indices, {3, 4})){
        player.setPosition_y(block->get_top_left_corner_x)      // Case 1.
    } else if (eq(clipped_corner_indices, {2, 4})) {
        player.setPosition_y(block->get_top_left_corner_x)      // Case 2.
    } else if (eq(clipped_corner_indices == {1, 2})) {
        player.setPosition_y(block->get_top_left_corner_x)      // Case 3.
    } else (eq(clipped_corner_indices == {1, 3})) {
        player.setPosition_y(block->get_top_left_corner_x)      // Case 4.
    }

    return;
}

//
void check_and_handle_full_2c(rra::Rect player, rra::Rect block, std::vector<int>clipped_corner_indices){
    
    player.
    return;
}


// Checks if any player-block collisions are happening. If so, then it solves them.
// "player_coords" stands for player_collision_coordinates
// "blocks_coords" stands for blocks_collision_coordinates
void check_and_handle_collisions(std::vector<int> clipped_corner_indices, Player* player, bn::vector<rra::Rect, 9999>* blocks_coords){

    // "for block in blocks".
    for(int block = 0 ; int blocks_coords->size() ; block++){
        check_and_handle_collision(player, blocks_coords[block]);
    }

    return;
}


// Checks if a player-block collisions is happening. If so, then it solves it.
// "block_coords" stands for block_collision_coordinates.
void check_and_handle_collision(Player* player, rra::Rect block_coords){

    std::vector<int> clipped_corner_indices = check_partial_collisions(player, block_coords);

    int number_of_corners_in_partial_clip = sizeof(corners_in_partial_clip);
    // Checks and solves case 1.
    if (number_of_corners_in_partial_clip == 1){
        handle_one_partial_collision(clipped_corner_indices, player, block_coords);
    }

    // Checks and solves case 2.
    if (number_of_corners_in_partial_clip == 2){
        handle_two_partial_collisions(clipped_corner_indices, player, block_coords);
    }

    // Checks and solves case 3.
    check_and_handle_full_2c(clipped_corner_indices, player, block);

    // Checks and solves case 4.
    bool block_is_inside_player = rect_contained_within_another_rect(block, player->get_collision_hitbox());
    bool player_is_inside_block = rect_contained_within_another_rect(player->get_collision_hitbox(), block);

    if (block_is_inside_player || player_is_inside_block){

        // Handles full 4c.
        player->setDeFactoSpeed(player->getDeFactoSpeed() + 99);      // Solves collision via brute-forcing :3

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