#include "bn_core.h"
// #include <bn_sprites.h>
// #include <bn_sprite_ptr.h>
// #include <bn_sprite_tiles.h>
// #include <bn_sprite_tiles_ptr.h>
// #include "bn_sprite_items_ice_block.h"
// #include "bn_sprite_item.h"


// #include "bn_sprite_actions.h"
// #include "bn_sprites_actions.h"
// #include "bn_sprite_animate_actions.h"

// #include "bn_sprite_palette_ptr.h"

// #include "bn_sprite_builder.h"

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"

#include "bn_sprite_tiles_ptr.h"
#include "bn_regular_bg_items_screen0.h"
#include "bn_sprite_items_seal.h"

#include "bn_keypad.h"
#include "bn_log.h"

#include "sprite_animations.h"

#include "bn_unique_ptr_fwd.h"

// #include "global_ptr.h"

#include "stage1.h"
#include "stage2.h"
#include "stage3.h"
#include "stage4.h"
#include "stage5.h"

#include "global_resources.h"
#include "stage_init.h"
#include "game.h"
#include "player.h"
#include "rect.h"

#include <tuple>
#include <array>


int player_x = 5;
int player_y = 112;

bool facing_right = true;    // Allocates 1 bit of storage for the direction the player is facing. If false, player is facing left. If true, player is facing right. 

int current_level = 1;
char current_difficulty = 'n';

/*
Player p;
Player* p_ptr = &p;

p_ptr->Player::set_position(p_ptr, player_x, player_y);

rra::Rect damage_hitbox[] { std::array<int, 4> {(p_ptr->getPosition_x()) + 8, (p_ptr->getPosition_y()) + 15, (p_ptr->getPosition_x()) + 19, (p_ptr->getPosition_y()) + 32}};
rra::Rect collision_hitbox[] { std::array<int, 4> {(p_ptr->getPosition_x()) + 11, (p_ptr->getPosition_y()) + 22, (p_ptr->getPosition_x()) + 15, (p_ptr->getPosition_y()) + 25}};
*/

void load_first_screen(Global_VRAM* VRAM){
    
    rra::stage_init(VRAM);   // Resets all backgrounds and non-player sprites

    bn::regular_bg_ptr level_layout = bn::regular_bg_items::screen0.create_bg(8, 48);
                
    VRAM->global_backgrounds.push_back(level_layout);
}

void update_player_position(){

    if (bn::keypad::right_held())
    {
        if (bn::keypad::l_held())
        {
            // Shifting makes you move at 1/3 speed.
            // int player_speed = (1 << player_fp) + ((1 << player_fp) / 3);
        } else if (bn::keypad::r_held()) {
            player_x += 5;
        } else {
            player_x++;
        }

        facing_right = true;

    }

    if (bn::keypad::left_held())
    {
        if (bn::keypad::l_held())
        {
            // Shifting makes you move at 1/3 speed.
            // int player_speed = (1 << player_fp) + ((1 << player_fp) / 3);
        } else if (bn::keypad::r_held()) {
            player_x -= 5;
        } else {
            player_x--;
        }

        facing_right = false;

    }

    return;
}




namespace rra
{

namespace game
{

    // This function changes level, calling other stageX.cpp files accordingly.
    // Levels 1 to 10 are meant to be handled by stage1.cpp.
    // Levels 11 to 20 are meant to be handled by stage2.cpp.
    // etc...
    void change_level(Global_VRAM* VRAM, int frame_counter) {

        if (player_x > 220) {
            current_level++;
            if (VRAM->global_backgrounds.size() > 0){
                VRAM->global_backgrounds.pop_back();
            }
            rra::stage_init(VRAM);   // Resets all backgrounds and non-player sprites
            player_x = 10;
        } else if (player_x < -15) {
            current_level--;
            if (VRAM->global_backgrounds.size() > 0){
                VRAM->global_backgrounds.pop_back();
            }
            rra::stage_init(VRAM);   // Resets all backgrounds and non-player sprites
            player_x = 200;
        }

        // change_stage()
        if (current_level == 0) {

            load_first_screen(VRAM);

        }
        if ((current_level >= 1) && (current_level < 10)) {
            
            rra::stage1::load_stage(VRAM, frame_counter, current_level);
            
        } else if ((current_level >= 10) && (current_level < 20)) {

            rra::stage2::load_stage(VRAM, frame_counter, current_level);

        } else if ((current_level >= 20) && (current_level < 30)) {

            rra::stage3::load_stage(VRAM, frame_counter, current_level);

        } else if ((current_level >= 30) && (current_level < 40)){

            rra::stage4::load_stage(VRAM, frame_counter, current_level);

        } else {        // When (current_level >= 40)
            rra::stage5::load_stage(VRAM, frame_counter, current_level);
        }

        return;
    }


    void handle_frame(Global_VRAM* VRAM, int frame_counter) {

        /*
        if (frame_counter == 0){

            
            Player p;
            Player* p_ptr = &p;

            p_ptr->set_position(p_ptr, player_x, player_y);
            
            std::array<int, 4> test = {1, 2, 3, 4};
            rra::Rect { test };

            Rect collision_hitbox[] { std::array<int, 4> {(p_ptr->getPosition_x()) + 8, (p_ptr->getPosition_y()) + 15, (p_ptr->getPosition_x()) + 19, (p_ptr->getPosition_y()) + 32}};
            Rect damage_hitbox[] { std::array<int, 4> {(p_ptr->getPosition_x()) + 11, (p_ptr->getPosition_y()) + 22, (p_ptr->getPosition_x()) + 15, (p_ptr->getPosition_y()) + 25}};
        }
        */

        rra::game::change_level(VRAM, frame_counter);

        rra::sprite_anim::reimu_anim(VRAM, frame_counter, player_x, player_y);

        frame_counter++;

        update_player_position();

        check_and_handle_collisions();

        if (bn::keypad::b_pressed())
        {

            // Player_Projectile seal_projectile{}
            /*
            bn::sprite_ptr seal_sprite = bn::sprite_items::seal.create_sprite(0, 0); 

            VRAM->global_sprites.push_back(seal_sprite);

            seal_sprite.set_tiles(bn::sprite_items::seal.tiles_item().create_tiles(0));  
            */
        }


        if (bn::keypad::start_pressed())
        {
            BN_LOG("    ");
            BN_LOG("frame_counter, player_x, current_level: ");
            BN_LOG(frame_counter, "   ", player_x, "   ", current_level);
            BN_LOG("vv ----------- VRAM ---------- vv");
            BN_LOG("current vector size:    ", VRAM->global_player_sprites.size(), "   ", VRAM->global_sprites.size(), "   ", VRAM->global_backgrounds.size());
            BN_LOG("max vector size:    ", VRAM->global_player_sprites.max_size(), "   ", VRAM->global_sprites.max_size(), "   ", VRAM->global_backgrounds.max_size());
            BN_LOG("---------------------------------");
            // int decoy = 0;
        }

        return;
    }

}
}
