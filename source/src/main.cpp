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

#include "sprite_animations.h"
#include "game.h"


struct global_data
{
    bn::sprite_ptr reimu_idle_spritesheet;
    bn::sprite_ptr reimu_jump_spritesheet;
    bn::sprite_ptr cirno_spritesheet;
    bn::sprite_ptr akyuu_spritesheet;

    bn::regular_bg_ptr screen1n;
    bn::regular_bg_ptr screen2n;
};

global_data* global_ptr;


int frame_counter = 0;    // As a timer for animations :3

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
        rra::game::handle_frame(global_ptr, frame_counter);

        // rra::game::handle_frame(bn::sprite_ptr&, bn::regular_bg_ptr&, frame_counter);

        frame_counter++;

        bn::core::update();
    }
}
