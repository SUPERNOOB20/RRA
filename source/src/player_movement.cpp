// signed 27.4f fixed-point format.
const int player_fp = 3;

class Player {
    
    private:

        bool alive = {true};   // If alive = false, trigger a "game over" screen.

        int player_x {0};               // Might be changed later on with fixed-point math (signed 27.4f fixed-point)
        int player_y {0};               // Might be changed later on with fixed-point math (signed 27.4f fixed-point)

        signed int player_de_facto_speed_x {0};         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)
        signed int player_de_facto_speed_y {0};         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)

        signed int player_speed_x {0};         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)
        signed int player_speed_y {0};         // Might be changed later on with fixed-point math (signed 27.4f fixed-point)    

    public:

    std::tuple<int, int> position(){
        std::tuple<int, int> player_position = {player_x, player_y};
        return player_position;
    }

    std::tuple<int, int> player_topleft_hitbox(){
        std::tuple<int, int> player_topleft_hitbox = {player_x + 11, player_y + 22};    // edge INCLUDED
        return player_topleft_hitbox;
    }

    std::tuple<int, int> player_bottomright_hitbox(){
        std::tuple<int, int> player_topleft_hitbox = {player_x + 15, player_y + 25};    // edge INCLUDED
        return player_topleft_hitbox;
    }

    std::tuple<int, int> hitbox(){      // Returns (player_topleft_hitbox(), player_bottomright_hitbox())

        return {player_topleft_hitbox(), player_bottomright_hitbox()};
    }

    // is_alive
}


// bool collides_horizontally (player.Coordinates) {

// }

Player player {player_x, player_y};