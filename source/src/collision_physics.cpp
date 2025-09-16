#include <tuple>
#include "player_bounding_boxes.h"



// Checks if any player-block collisions are happening. If so, then it solves them.
void check_and_handle_collisions(Player* player, bn::vector<Coordinates>* block_coords){

    player_coords = player->collision_hitbox();

    for (Coordinates coordinate : block_coords) {
  
        bool player_is_colliding_with_block = && && &&

        if (player_is_colliding_with_block){
            handle_collisions()
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