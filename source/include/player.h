#ifndef PLAYER_H
#define PLAYER_H

// #include <tuple>
#include <array>


// Generic stuff to define generic player atributes, like position, speed, and of course, alive status :p
class Player {
    
    private:

        bool m_alive {true};   // If alive = false, trigger a "game over" screen.

        int m_player_x {0};               // Might be changed later on with fixed-point math (signed 20.11f fixed-point)
        int m_player_y {0};               // Might be changed later on with fixed-point math (signed 20.11f fixed-point)

        signed int m_player_real_x {0};
        signed int m_player_real_y {0};

        signed int m_player_de_facto_speed_x {0};         // Might be changed later on with fixed-point math (signed 20.11f fixed-point)
        signed int m_player_de_facto_speed_y {0};         // Might be changed later on with fixed-point math (signed 20.11f fixed-point)

        signed int m_player_speed_x {0};         // Might be changed later on with fixed-point math (signed 20.11f fixed-point)
        signed int m_player_speed_y {0};         // Might be changed later on with fixed-point math (signed 20.11f fixed-point)  


        
    public:
        Player(bool alive, signed int player_real_x, signed int player_real_y, int player_x, int player_y, signed int player_de_facto_speed_x, signed int player_de_facto_speed_y, signed int player_speed_x, signed int player_speed_y);
        Player() {};

        // std::tuple<int, int> Player::get_position();
        std::array<int, 2> getPosition() { return std::array<int, 2> {m_player_x, m_player_y}; }
        int getPosition_x() { return m_player_x; }
        int getPosition_y() { return m_player_y; }

        void set_position(Player* player, int player_x, int player_y);

        bool is_alive();
};

#endif