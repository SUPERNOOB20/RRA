#include <tuple>

// signed 20.11f fixed-point format.
// const int player_fp = 3;

Collision_Player::Collision_Player(int player_collision_x, int player_collision_y)
    
    : player_collision_coordinates{ (0, 0), (0, 0) }

    , player_collision_x { 0 }               // Might be changed later on with fixed-point math (signed 27.4f fixed-point)
    , player_collision_y { 0 }               // Might be changed later on with fixed-point math (signed 27.4f fixed-point)

    , player_de_facto_speed_x { 0 }         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)
    , player_de_facto_speed_y { 0 }         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)

    , player_speed_x { 0 }         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)
    , player_speed_y { 0 }         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)    

{
}

std::tuple<int, int> Player::player_topleft_collision_hitbox(){
    std::tuple<int, int> player_topleft_hitbox = {player_x + 11, player_y + 22};    // edge INCLUDED
    return player_topleft_hitbox;
}

std::tuple<int, int> Player::player_bottomright_collision_hitbox(){
    std::tuple<int, int> player_topleft_hitbox = {player_x + 15, player_y + 25};    // edge INCLUDED
    return player_topleft_hitbox;
}

std::tuple<std::tuple<int, int>, std::tuple<int, int>> Player::collision_hitbox(){      // Returns (player_topleft_hitbox(), player_bottomright_hitbox())
    std::tuple<std::tuple<int, int>, std::tuple<int, int>> hitbox = {player_topleft_hitbox(), player_bottomright_hitbox()};
    return hitbox;
}



Collision_Block::Collision_Block(int player_x, int player_y)
    
    : block_coordinates{ (0, 0), (0, 0) }

    , player_x { 0 }               // Might be changed later on with fixed-point math (signed 27.4f fixed-point)
    , player_y { 0 }               // Might be changed later on with fixed-point math (signed 27.4f fixed-point)

    , player_de_facto_speed_x { 0 }         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)
    , player_de_facto_speed_y { 0 }         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)

    , player_speed_x { 0 }         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)
    , player_speed_y { 0 }         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)    

{
}

// Checks if any player-block collisions are happening. If so, then it solves them.
void check_and_handle_collisions(){
    return;
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
}