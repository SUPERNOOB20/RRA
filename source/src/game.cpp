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
#include "bn_regular_bg_items_screen2n.h"

#include "bn_keypad.h"
#include "bn_log.h"

#include "sprite_animations.h"

// #include "global_ptr.h"

int player_x = 5;
int player_y = 112;

int current_stage = 1;
char current_difficulty = 'n';


namespace rra
{


namespace game
{

    void change_stage(global_data* global_sprites_and_backgrounds, int frame_counter) {
        if (player_x > 220) {
            current_stage++;
            player_x = 10;
        }

        if (player_x < -15) {
            current_stage--;
            player_x = 200;
        }

        
        // Do I need to destroy backgrounds???
        // bn::screen1n.~regular_bg_ptr();
        // bn::screen2n.~regular_bg_ptr();

        auto current_stage_bg = bn::regular_bg_items::screen1n.create_bg(8, 48);

        global_sprites_and_backgrounds->screen1n.set_visible(false);
        global_sprites_and_backgrounds->screen2n.set_visible(false);

        global_sprites_and_backgrounds->reimu_jump_sprite.set_visible(false);
        global_sprites_and_backgrounds->akyuu_sprite.set_visible(false);
        global_sprites_and_backgrounds->cirno_sprite.set_visible(false);

        if (current_stage == 1) {
            // current_stage_bg = bn::regular_bg_items::screen1n.create_bg(8, 48);
            global_sprites_and_backgrounds->screen1n.set_visible(true);
        } else if (current_stage == 2) {
            // current_stage_bg = bn::regular_bg_items::screen2n.create_bg(8, 48);
            global_sprites_and_backgrounds->screen2n.set_visible(true);
            global_sprites_and_backgrounds->akyuu_sprite.set_visible(true);
            rra::sprite_anim::akyuu_anim(global_sprites_and_backgrounds, frame_counter);
        } else {
            int nop = 0;            // hey_compiler_whats_up_xddd
        }

        bn::regular_bg_ptr regular_bg = current_stage_bg;

        

        return;
    }



    void handle_frame(global_data* global_sprites_and_backgrounds, int frame_counter) {

        rra::game::change_stage(global_sprites_and_backgrounds, frame_counter);

        rra::sprite_anim::reimu_anim(global_sprites_and_backgrounds, frame_counter, player_x, player_y);

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
            BN_LOG("frame_counter, player_x, current_stage: ");
            BN_LOG(frame_counter, " ", player_x, " ", current_stage);
            // int decoy = 0;
        }

        return;
    }

}
}