#include "bn_core.h"
#include <bn_sprites.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_tiles.h>
#include <bn_sprite_tiles_ptr.h>

#include "bn_sprite_item.h"
// #include "bn_sprite_items_ice_block.h"
#include "bn_sprite_items_reimu_idle_spritesheet.h"
#include "bn_sprite_items_akyuu_spritesheet.h"


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

int frame_counter = 0;    // As a timer for animations :3

int player_x = -96;
int player_y = 64;

int current_stage = 1;
char current_difficulty = 'n';

void change_stage() {
    if (player_x > 118) {
        current_stage++;
        player_x = -96;
    }

    if (player_x < -118) {
        current_stage--;
        player_x = 96;
    }
}

const int reimu_anim_frames = 20;       // Sets the amount of frames each sprite should play for (i.e. frame speed). anim_frames == 60 means 1fps animation, anim_frames == 30 means 2fps animation, etc.
const int akyuu_anim_frames = 30;
    // const int cirno_idle_frames = 25;
    // const int cirno_laughing_frames = 10;

collision(x, y)

int main()
{
    bn::core::init();

    while(true)
    {


        // "collision" should be "(x1, y1, x2, y2)"
        // I need to try to make a vector with "spike" collisions, and a vector with "block" collissions.

        // We need to set up a vector of sprite_ptr to represent individual letters.
        // We can only have a max of 16 letters in this vector.
        // bn::vector<bn::sprite_ptr, 16> text_sprites;

        
        // The first two values represent X and Y.
        // The third is your constant text.
        // The fourth is your sprite_ptr vector.
        // text_generator.generate(-6 * 16, -68, "ded", text_sprites);




        change_stage();

        bn::sprite_ptr reimu_sprite = bn::sprite_items::reimu_idle_spritesheet.create_sprite(player_x, player_y);

        if ((frame_counter % (reimu_anim_frames * 3)) < (reimu_anim_frames)) {
            reimu_sprite.set_tiles(bn::sprite_items::reimu_idle_spritesheet.tiles_item().create_tiles(0));                
        } else if ((frame_counter % (reimu_anim_frames * 3)) < (reimu_anim_frames * 2)) {
            reimu_sprite.set_tiles(bn::sprite_items::reimu_idle_spritesheet.tiles_item().create_tiles(1));                
        } else {
            reimu_sprite.set_tiles(bn::sprite_items::reimu_idle_spritesheet.tiles_item().create_tiles(2));                
        }


        

        // void akyuu_anim(int frame_counter)    
        bn::sprite_ptr akyuu_sprite = bn::sprite_items::akyuu_spritesheet.create_sprite(96, 12);
        akyuu_sprite.set_visible(false);

        if (current_stage == 2){

            akyuu_sprite.set_visible(true);

            if ((frame_counter % (akyuu_anim_frames * 2)) < (akyuu_anim_frames)) {
                akyuu_sprite.set_tiles(bn::sprite_items::akyuu_spritesheet.tiles_item().create_tiles(0));  
                BN_LOG("huhh");
            } else {
                akyuu_sprite.set_tiles(bn::sprite_items::akyuu_spritesheet.tiles_item().create_tiles(1));                
            }
        }





        auto current_stage_bg = bn::regular_bg_items::screen1n.create_bg(8, 48);

        if (current_stage == 1) {
            current_stage_bg = bn::regular_bg_items::screen1n.create_bg(8, 48);
        } else if (current_stage == 2) {
            current_stage_bg = bn::regular_bg_items::screen2n.create_bg(8, 48);
        } else {
            int nop = 0;            // hey_compiler_whats_up_xddd
        }

        bn::regular_bg_ptr regular_bg = current_stage_bg;


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

        bn::core::update();
    }
}
