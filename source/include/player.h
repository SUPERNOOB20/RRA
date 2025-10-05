#ifndef PLAYER_H
#define PLAYER_H

// #include <tuple>
#include <array>
#include "rect.h"

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

        rra::Rect collision_hitbox { std::array<int, 4> {(m_player_x + 11), (m_player_y + 8), (m_player_x + 15), (m_player_y + 25)}};
        rra::Rect damage_hitbox { std::array<int, 4> {(m_player_x + 8), (m_player_y + 15), (m_player_x + 19), (m_player_y + 32)}};
        
    public:
        Player(bool alive, signed int player_real_x, signed int player_real_y, int player_x, int player_y, signed int player_de_facto_speed_x, signed int player_de_facto_speed_y, signed int player_speed_x, signed int player_speed_y);
        Player() {};

        // Returns the player's position in (x, y) format.
        std::array<int, 2> getPosition() { return std::array<int, 2> {m_player_x, m_player_y}; }
        int getPosition_x() { return m_player_x; }
        int getPosition_y() { return m_player_y; }

        rra::Rect get_collision_hitbox() { return collision_hitbox; }
        rra::Rect get_damage_hitbox() { return damage_hitbox; }

        /*
        rra::Rect get_collision_hitbox_height() { return collision_hitbox[3] - collision_hitbox[1]; }
        rra::Rect get_collision_hitbox_width() { return collision_hitbox[2] - collision_hitbox[0]; }

        rra::Rect get_damage_hitbox_height() { return damage_hitbox[3] - damage_hitbox[1]; }
        rra::Rect get_damage_hitbox_width() { return damage_hitbox[2] - damage_hitbox[0]; }
        */


        // Returns the position in Rect format: ((x1, y1), (x2, y2), (x3, y3), (x4, y4))
        rra::Rect getPositionRect(Player* player, int player_x, int player_y);
        void set_position(Player* player, int player_x, int player_y);

        bool is_alive();
};

#endif