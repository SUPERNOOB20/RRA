#include "bn_core.h"
#include <bn_sprites.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_tiles.h>
#include <bn_sprite_tiles_ptr.h>

#include "bn_sprite_item.h"
// #include "bn_sprite_items_ice_block.h"
#include "bn_sprite_items_reimu_idle_spritesheet.h"
#include "bn_sprite_items_akyuu_spritesheet.h"

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

int main()
{
    bn::core::init();

    struct global_data global_instance = {

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

        rra::game::handle_frame(global_ptr, frame_counter);

        frame_counter++;

        bn::core::update();
    }
}
