#include "bn_vector.h"
#include "global_resources.h"
#include "stage_init.h"

#include "bn_sprite_items_akyuu_spritesheet.h"
#include <sprite_animations.h>

// include "bn_regular_bg_items_screen1n.h"
// include "bn_regular_bg_items_screen2n.h"
// #include "bn_regular_bg_items_screen10n.h"
#include "bn_regular_bg_items_screen21n.h"

namespace rra
{
namespace stage1
{
    void load_stage(Global_VRAM VRAM, int frame_counter, int current_level) {

        rra::stage_init(VRAM);   // Resets all backgrounds and non-player sprites

        bn::regular_bg_ptr screen_21n = bn::regular_bg_items::screen21n.create_bg(0, 0);

        screen_21n.set_visible(false);

        switch(current_level){
            case 1:
                screen_21n.set_visible(true);
                VRAM.push_back(screen_21n);        
                break;

            // case 2:
                // screen_2n.set_visible(true);
                // VRAM.push_back(screen_2n);  
                // break;

            default:
                int hey_compiler_hows_it_goin_xdddd = 0;       // <--- "nop" instruction on budget, heh
        };
        
        bn::sprite_ptr akyuu_sprite = bn::sprite_items::akyuu_spritesheet.create_sprite(0, 0);    // This might create two sprites... so please do be careful
        akyuu_sprite.set_top_left_position(190, 80);

        rra::sprite_anim::akyuu_anim(VRAM, frame_counter);

        return;
    };
}
}