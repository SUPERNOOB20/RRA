#ifndef PLAYER
#define PLAYER

#include <tuple>

// Generic stuff to define generic player atributes, like position, speed, and of course, alive status :p
class Player {
    
    private:

        bool alive {true};   // If alive = false, trigger a "game over" screen.

        int player_x {0};               // Might be changed later on with fixed-point math (signed 20.11f fixed-point)
        int player_y {0};               // Might be changed later on with fixed-point math (signed 20.11f fixed-point)

        signed int player_real_x {0};
        signed int player_real_y {0};

        signed int player_de_facto_speed_x {0};         // Might be changed later on with fixed-point math (signed 20.11f fixed-point)
        signed int player_de_facto_speed_y {0};         // Might be changed later on with fixed-point math (signed 20.11f fixed-point)

        signed int player_speed_x {0};         // Might be changed later on with fixed-point math (signed 20.11f fixed-point)
        signed int player_speed_y {0};         // Might be changed later on with fixed-point math (signed 20.11f fixed-point)  



    public:
        Player(bool alive, signed int player_real_x, signed int player_real_y, int player_x, int player_y, signed int player_de_facto_speed_x, signed int player_de_facto_speed_y, signed int player_speed_x, signed int player_speed_y);

        // std::tuple<int, int> Player::get_position();
        std::tuple<int, int> getPosition() const { return std::tuple<int,int> (player_x, player_y); }
        int getPosition_x() const { return player_x; }
        int getPosition_y() const { return player_y; }

        void Player::set_position(Player* player, int player_x, int player_y);

        bool is_alive();
};

#endif