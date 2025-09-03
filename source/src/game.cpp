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

#include <bn_regular_bg_ptr.h>
#include <bn_regular_bg_item.h>

// #include "bn_regular_bg_items_screen1n.h"
// #include "bn_regular_bg_items_screen2n.h"
// #include "bn_regular_bg_items_screen10n.h"
// #include "bn_regular_bg_items_screen21n.h"

#include "bn_keypad.h"
#include "bn_log.h"

#include "sprite_animations.h"

// #include "global_ptr.h"

#include "stage1.h"
#include "stage2.h"
#include "stage3.h"


int player_x = 5;
int player_y = 112;

int current_level = 1;
char current_difficulty = 'n';


namespace rra
{


namespace game
{

    // This function changes level, calling other stageX.cpp files accordingly.
    // Levels 1 to 10 are meant to be handled by stage1.cpp.
    // Levels 11 to 20 are meant to be handled by stage2.cpp.
    // etc...
    void change_level(Global_VRAM VRAM, int frame_counter) {
        if (player_x > 220) {
            current_level++;
            player_x = 10;
        }

        if (player_x < -15) {
            current_level--;
            player_x = 200;
        }

        // change_stage()
        if ((current_level >= 1) && (current_level < 10)) {
            
            rra::stage1::load_stage(VRAM, frame_counter, current_level);
            
        } else if ((current_level >= 10) && (current_level < 20)) {

            rra::stage2::load_stage(VRAM, frame_counter, current_level);

        } else if ((current_level >= 20) && (current_level < 30)) {

            rra::stage3::load_stage(VRAM, frame_counter, current_level);
            // VRAM->screen2n.set_visible(true);
        } else if current_level == 20 {
            stage2;            // hey_compiler_whats_up_xddd
        }

        /*
        if (current_level == 1) {
            VRAM->screen1n.set_visible(true);
        } else if (current_level == 2) {
            VRAM->screen2n.set_visible(true);
            VRAM->akyuu_sprite.set_visible(true);
            VRAM->akyuu_sprite.set_top_left_position(190, 80);
            rra::sprite_anim::akyuu_anim(VRAM, frame_counter);
        } else if (current_level == 10) {
            VRAM->screen2n.set_visible(true);
        } else {
            int nop = 0;            // hey_compiler_whats_up_xddd
        }
        */

        return;
    }



    void handle_frame(Global_VRAM VRAM, int frame_counter) {

        rra::game::change_level(VRAM, frame_counter);

        rra::sprite_anim::reimu_anim(VRAM, frame_counter, player_x, player_y);

        frame_counter++;

        if (bn::keypad::right_held())
        {
            if (bn::keypad::l_held())
            {
                player_x += 10;
            } else if (bn::keypad::r_held()) {
                player_x += 100;
            } else {
                player_x++;
            }
        }

        if (bn::keypad::left_held())
        {
            if (bn::keypad::l_held())
            {
                player_x -= 10;
            } else if (bn::keypad::r_held()) {
                player_x += 100;
            } else {
                player_x--;
            }
        }

        if (bn::keypad::start_pressed())
        {
            BN_LOG("frame_counter, player_x, current_level: ");
            BN_LOG(frame_counter, "   ", player_x, "   ", current_level);
            // int decoy = 0;
        }

        return;
    }

}
}