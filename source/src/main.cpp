#include "bn_core.h"
#include <bn_sprites.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_tiles.h>
#include <bn_sprite_tiles_ptr.h>
// #include "bn_sprite_items_ice_block.h"
#include "bn_sprite_item.h"



#include "bn_sprite_actions.h"
#include "bn_sprites_actions.h"
#include "bn_sprite_animate_actions.h"

#include "bn_sprite_palette_ptr.h"

// #include "bn_sprite_builder.h"

#include <bn_regular_bg_ptr.h>
#include <bn_regular_bg_item.h>
#include "bn_regular_bg_items_screen1n.h"
#include "bn_regular_bg_items_screen2n.h"

#include "bn_keypad.h"
#include "bn_log.h"

#include "sprite_animations.h"

int main()
{
    bn::core::init();

    int frame_counter = 0;    // As a timer for animations :3

    int player_x = -96;
    int player_y = 64;

    const int reimu_anim_frames = 20;       // Sets the amount of frames each sprite should playy for (i.e. frame speed). anim_frames == 60 means 1fps animation, anim_frames == 30 means 2fps animation, etc.
    // const int cirno_idle_frames = 25;
    // const int cirno_laughing_frames = 10;

    int current_stage = 1;
    char current_difficulty = 'n';

    while(true)
    {

        

        rra::sprite_anim::reimu_anim(frame_counter, reimu_anim_frames, player_x, player_y);
        
        if (player_x > 128) {
            current_stage++;
            player_x = -96;
        }

        bn::regular_bg_ptr regular_bg = bn::regular_bg_items::screen1n.create_bg(99, 99);

        if (current_stage == 1) {
            bn::regular_bg_ptr regular_bg = bn::regular_bg_items::screen1n.create_bg(8, 48);
        } else if (current_stage == 2) {
            bn::regular_bg_ptr regular_bg = bn::regular_bg_items::screen2n.create_bg(8, 48);
        } else {
            int nop = 0;            // hey_compiler_whats_up_xddd
        }

        


        frame_counter++;

        if (bn::keypad::right_held())
        {
            player_x++;
        }

        if (bn::keypad::left_held())
        {
            player_x--;
        }


        if (bn::keypad::b_pressed())
        {
            // BN_LOG("frame_counter: ");
            // BN_LOG(frame_counter, player_x);
            // BN_LOG(std::get<0>(current_stage));
            int decoy = 0;
        }

        bn::core::update();
    }
}
