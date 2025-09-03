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
#include "bn_vector.h"
template<typename Type, int MaxSize>

struct global_resources {

        bn::vector<bn::sprite_ptr, 27>    global_player_sprites;        // Idling, jumping, dashing should be available in all levels!
        bn::vector<bn::sprite_ptr, 100>   global_sprites;               // 128 is the maximum number of sprites that can fit in the GBA's VRAM. But I'm padding 27 here for the player's sprites. And leaving 1 extra, unused slot just in case :P
        bn::vector<bn::sprite_ptr, 4>     global_backgrounds;           // 4 is the maximum number of backgrounds that can fit in the GBA's VRAM

    };





int main()
{

    bn::core::init();

    int frame_counter = 0;    // As a timer for animations :3

    /*
    struct global_resources {

        bn::ivector<bn::sprite_ptr>     global_player_sprites;        
        bn::ivector<bn::sprite_ptr>     global_sprites;               
        bn::ivector<bn::sprite_ptr>     global_backgrounds;         

    };
    */

    // Play main menu, intro scene... etc.

    BN_LOG("checkpoint_A");


    // vvv   Do these need top_left() method...?   vvv


    /*
    bn::sprite_items::reimu_idle_spritesheet.create_sprite(0, 0),
    bn::sprite_items::reimu_jump_spritesheet.create_sprite(0, 0),
    bn::sprite_items::cirno_spritesheet.create_sprite(0, 0),
    bn::sprite_items::akyuu_spritesheet.create_sprite(0, 0),
    bn::sprite_items::rumia_idle_spritesheet.create_sprite(0, 0),
    bn::sprite_items::youmu_idle_spritesheet.create_sprite(0, 0),
    bn::sprite_items::spirit.create_sprite(0, 0),

    bn::regular_bg_items::screen1n.create_bg(8, 48),
    bn::regular_bg_items::screen2n.create_bg(8, 48),
    bn::regular_bg_items::screen10n.create_bg(8, 48),
    bn::regular_bg_items::screen21n.create_bg(8, 48)
    
    
    BN_LOG("checkpoint_B");

    global_ptr->screen1n.set_visible(false);
    global_ptr->screen2n.set_visible(false);
    global_ptr->screen10n.set_visible(false);
    global_ptr->screen21n.set_visible(false);

    global_ptr->reimu_jump_sprite.set_visible(false);
    global_ptr->akyuu_sprite.set_visible(false);
    global_ptr->cirno_sprite.set_visible(false);
    global_ptr->rumia_sprite.set_visible(false);
    global_ptr->youmu_idle_sprite.set_visible(false);
    global_ptr->spirit_sprite.set_visible(false);
    */

    BN_LOG("checkpoint_C");


    // sprites_pointer = &sprites_ptr;
    // backgrounds_pointer = &regular_bg_ptr;

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
