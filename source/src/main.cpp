#include "bn_core.h"
#include <bn_sprites.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_tiles.h>
#include <bn_sprite_tiles_ptr.h>

#include "bn_sprite_item.h"
// #include "bn_sprite_items_ice_block.h"

#include "bn_sprite_items_reimu_idle_spritesheet.h"
#include "bn_sprite_items_reimu_jump_spritesheet.h"

#include "bn_sprite_items_akyuu_spritesheet.h"

#include "bn_sprite_items_fairy.h"

#include <bn_regular_bg_ptr.h>
#include <bn_regular_bg_item.h>

// #include "bn_keypad.h"
#include "bn_log.h"

#include "sprite_animations.h"
#include "game.h"





#include "global_resources.h"


// #include <vector>
#include "bn_vector.h"
template<typename Type, int MaxSize>
bn::vector<bn::sprite_ptr, 1>        test;          // sets the template in stone, for later use in main().

int main()
{
    bn::core::init();

    int frame_counter = 0;    // As a timer for animations :3

    bn::vector<bn::sprite_ptr, 26>        global_player_sprites;        
    bn::vector<bn::sprite_ptr, 100>       global_sprites;               
    bn::vector<bn::regular_bg_ptr, 4>     global_backgrounds;           

    Global_VRAM VRAM = allocate_VRAM(global_player_sprites, global_sprites, global_backgrounds);

    Global_VRAM* vram_ptr;

    vram_ptr = &VRAM;

    // Play main menu, intro scene... etc.

    // bn::sprite_items::reimu_idle_spritesheet.create_sprite(0, 0);
    // bn::sprite_items::reimu_jump_spritesheet.create_sprite(0, 0);
    // bn::sprite_items::reimu_dash_spritesheet.create_sprite(0, 0),

    while(true)
    {
        rra::game::handle_frame(vram_ptr, frame_counter);

        frame_counter++;

        bn::core::update();

        if (frame_counter == 1){
            BN_LOG("checkpoint_BB");
        }
    }
}
