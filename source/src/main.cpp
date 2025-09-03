#include "bn_core.h"
#include <bn_sprites.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_tiles.h>
#include <bn_sprite_tiles_ptr.h>

#include "bn_sprite_item.h"
// #include "bn_sprite_items_ice_block.h"

#include "bn_sprite_items_reimu_idle_spritesheet.h"
#include "bn_sprite_items_reimu_jump_spritesheet.h"
#include "bn_sprite_items_cirno_spritesheet.h"
#include "bn_sprite_items_akyuu_spritesheet.h"
#include "bn_sprite_items_rumia_idle_spritesheet.h"
#include "bn_sprite_items_youmu_idle_spritesheet.h"
#include "bn_sprite_items_spirit.h"
#include "bn_sprite_items_fairy.h"

#include <bn_regular_bg_ptr.h>
#include <bn_regular_bg_item.h>
#include "bn_regular_bg_items_screen1n.h"
#include "bn_regular_bg_items_screen2n.h"
#include "bn_regular_bg_items_screen10n.h"
#include "bn_regular_bg_items_screen21n.h"

// #include "bn_keypad.h"
#include "bn_log.h"

#include "sprite_animations.h"
#include "game.h"


// #include <vector>
// #include "bn_vector.h"

#include <global_resources.h>

/*
template<typename Type, int MaxSize>

struct global_resources {

        bn::vector<bn::sprite_ptr, 27>        global_player_sprites;        // Idling, jumping, dashing should be available in all levels!
        bn::vector<bn::sprite_ptr, 100>       global_sprites;               // 128 is the maximum number of sprites that can fit in the GBA's VRAM. But I'm padding 27 here for the player's sprites. And leaving 1 extra, unused slot just in case :P
        bn::vector<bn::regular_bg_ptr, 4>     global_backgrounds;           // 4 is the maximum number of backgrounds that can fit in the GBA's VRAM.

    };
*/




int main()
{

    bn::core::init();

    int frame_counter = 0;    // As a timer for animations :3

    VRAM allocate_VRAM(bn::vector<bn::sprite_ptr, 26> global_player_sprites, bn::vector<bn::sprite_ptr, 100> global_sprites, bn::vector<bn::regular_bg_ptr, 4> global_backgrounds){
        VRAM new_VRAM = {}
    }

    // Play main menu, intro scene... etc.

    BN_LOG("checkpoint_A");


    bn::sprite_items::reimu_idle_spritesheet.create_sprite(0, 0),
    bn::sprite_items::reimu_jump_spritesheet.create_sprite(0, 0),
    // bn::sprite_items::reimu_dash_spritesheet.create_sprite(0, 0),

    while(true)
    {
        rra::game::handle_frame(global_resources*, frame_counter);

        frame_counter++;

        bn::core::update();
    }
}
