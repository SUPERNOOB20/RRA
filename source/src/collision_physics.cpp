#include "bn_vector.h"
#include "rect.h"
#include <tuple>
#include <array>
// #include "player_bounding_boxes.h"
#include "player.h"



// Checks if any player-block collisions are happening. If so, then it solves them.
// "player_coords" stands for player_collision_coordinates
// "block_coords" stands for blocks_collision_coordinates
void check_and_handle_collisions(Player* player, bn::vector<rra::Rect, 9999>* block_coords){

    // player_vertices = ((x1, y1), (x2, y2), (x3, y3), (x4, y4))
    std::array<<int, 2>, 4> player_vertices = player->get_();

    // for (Rect_Coordinates block : block_coords){
    for (int block_coord_index = 0 ; block_coords->size() ; block_coord_index++){

        bool block_collides_with_player = check_collisions(player_vertices, block_coords);

        if (block_collides_with_player){
            handle_collisions(player_vertices, block_coords);
        }

        return;
    }
}

bool check_collisions(std::array<int, 4> player_vertices, rra::Rect block){

    bool block_collides_with_player = false;

    // for (std::array<int, 2> vertex : player_vertices){
    for (int player_vertex_index ; 3; player_vertex_index++){
        if ((player_vertex_index.x()) && ()){
            block_collides_with_player = true;
        }
    }

    return;
}