#ifndef COLLISION_PHYSICS_H
#define COLLISION_PHYSICS_H

#include "player.h"
#include "bn_vector.h"

// class Collision_Block
// {
    
// }


void check_and_handle_collisions(Player* player_collision_hitbox, bn::vector<rra::Rect, 9999>* blocks_coords);


#endif