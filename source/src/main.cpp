#include "bn_core.h"
#include <bn_sprites.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_tiles.h>
#include <bn_sprite_tiles_ptr.h>
<<<<<<< HEAD

#include "bn_sprite_item.h"
// #include "bn_sprite_items_ice_block.h"
#include "bn_sprite_items_reimu_idle_spritesheet.h"
#include "bn_sprite_items_akyuu_spritesheet.h"
=======
// #include "bn_sprite_items_ice_block.h"
#include "bn_sprite_item.h"
>>>>>>> 5306bc5 (Revert "qwq")

#include "bn_sprite_items_reimu_idle_spritesheet.h"
#include "bn_sprite_items_reimu_jump_spritesheet.h"
#include "bn_sprite_items_cirno_spritesheet.h"
#include "bn_sprite_items_akyuu_spritesheet.h"

#include <bn_regular_bg_ptr.h>
#include <bn_regular_bg_item.h>
#include "bn_regular_bg_items_screen1n.h"
#include "bn_regular_bg_items_screen2n.h"

#include "bn_keypad.h"
#include "bn_log.h"

<<<<<<< HEAD
int frame_counter = 0;    // As a timer for animations :3

int player_x = -96;
int player_y = 48;

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

// collision(x, y)

=======
#include "sprite_animations.h"
#include "game.h"

struct global_data
{
    bn::sprite_ptr reimu_idle_spritesheet;
    bn::sprite_ptr reimu_jump_spritesheet;
    bn::sprite_ptr cirno_spritesheet;
    bn::sprite_ptr akyuu_spritesheet;

    bn::regular_bg_ptr screen1n;
    bn::regular_bg_ptr screen12;
};

global_data* global_ptr;


int frame_counter = 0;    // As a timer for animations :3

>>>>>>> 5306bc5 (Revert "qwq")
int main()
{
    bn::core::init();

    global_data global_instance = {

        // vvv   Do these need top_left() method...?   vvv

        bn::sprite_items::reimu_idle_spritesheet.create_sprite(0, 0),
        bn::sprite_items::reimu_jump_spritesheet.create_sprite(0, 0),
        bn::sprite_items::cirno_spritesheet.create_sprite(0, 0),
        bn::sprite_items::akyuu_spritesheet.create_sprite(0, 0),

        bn::regular_bg_items::screen1n.create_bg(0, 0),
        bn::regular_bg_items::screen2n.create_bg(0, 0)
    };

    global_ptr = &global_instance;

    while(true)
    {

<<<<<<< HEAD

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
        bn::sprite_ptr akyuu_sprite = bn::sprite_items::akyuu_spritesheet.create_sprite(96, 16);
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

=======
        rra::game::handle_frame(global_ptr, frame_counter);
>>>>>>> 5306bc5 (Revert "qwq")

        frame_counter++;

        bn::core::update();
    }
}
