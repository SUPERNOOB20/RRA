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

#include "bn_regular_bg_items_screen1n.h"
// #include "bn_regular_bg_items_screen2n.h"
// #include "bn_regular_bg_items_screen10n.h"
// #include "bn_regular_bg_items_screen21n.h"

#include "bn_keypad.h"
#include "bn_log.h"

#include "sprite_animations.h"

// #include "global_ptr.h"

#include "stage1.cpp"
#include "stage2.cpp"
#include "stage3.cpp"


int player_x = 5;
int player_y = 112;

int current_level = 1;
char current_difficulty = 'n';


namespace rra
{


namespace game
{

    void change_level(global_resources* global_sprites_and_backgrounds, int frame_counter) {
        if (player_x > 220) {
            current_level++;
            player_x = 10;
        }

        if (player_x < -15) {
            current_level--;
            player_x = 200;
        }

        if (current_level == 1) {
            global_sprites_and_backgrounds->screen1n.set_visible(true);
        } else if (current_level == 2) {
            global_sprites_and_backgrounds->screen2n.set_visible(true);
            global_sprites_and_backgrounds->akyuu_sprite.set_visible(true);
            global_sprites_and_backgrounds->akyuu_sprite.set_top_left_position(190, 80);
            rra::sprite_anim::akyuu_anim(global_sprites_and_backgrounds, frame_counter);
        } else if (current_level == 10) {
            global_sprites_and_backgrounds->screen2n.set_visible(true);
        } else {
            int nop = 0;            // hey_compiler_whats_up_xddd
        }


        return;
    }



    void handle_frame(global_resources* global_sprites_and_backgrounds, int frame_counter) {

        rra::game::change_level(global_sprites_and_backgrounds, frame_counter);

        rra::sprite_anim::reimu_anim(global_sprites_and_backgrounds, frame_counter, player_x, player_y);

        frame_counter++;

        if (bn::keypad::right_held())
        {
            if (bn::keypad::l_held())
            {
                player_x += 10;
            } else {
                player_x++;
            }
        }

        if (bn::keypad::left_held())
        {
            if (bn::keypad::l_held())
            {
                player_x -= 10;
            } else {
                player_x--;
            }
        }

        if (bn::keypad::r_pressed())
        {
            BN_LOG("frame_counter, player_x, current_level: ");
            BN_LOG(frame_counter, " ", player_x, " ", current_level);
            // int decoy = 0;
        }

        return;
    }

}
}