#include "bn_vector.h"
#include "global_resources.h"
#include "stage_init.h"

#include "bn_sprite_items_akyuu_spritesheet.h"
#include "sprite_animations.h"

// include "bn_regular_bg_items_screen1n.h"
// include "bn_regular_bg_items_screen2n.h"
// #include "bn_regular_bg_items_screen10n.h"
#include "bn_regular_bg_items_screen21n.h"

#include "bn_log.h"

namespace rra
{
namespace stage3
{
    void load_stage(Global_VRAM* VRAM, int frame_counter, int current_level) {

        rra::stage_init(VRAM);   // Resets all backgrounds and non-player sprites

        bn::regular_bg_ptr screen_21n = bn::regular_bg_items::screen21n.create_bg(8, 48);

        screen_21n.set_visible(false);

        switch(current_level){
            case 21:
                screen_21n.set_visible(true);
                VRAM->global_backgrounds.push_back(screen_21n);        

                BN_LOG("You've gotten to level << 21 >> successfully! (Stage < 3 >)");

                break;

            // case 2:
                // screen_2n.set_visible(true);
                // VRAM.push_back(screen_2n);  
                // break;

            default:
                int hey_compiler_hows_it_goin_xdddd = 0;       // <--- "nop" instruction on budget, heh
        };
        
        /*
        rra::sprite_anim::akyuu_anim(VRAM, frame_counter);

        auto current_akyuu_sprite = VRAM->global_sprites.back();

        current_akyuu_sprite.set_top_left_position(190, 80);

        VRAM->global_sprites.push_back(current_akyuu_sprite);
        */

        return;
    };
}
}