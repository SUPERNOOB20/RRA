#include "bn_vector.h"
#include "global_resources.h"
#include "stage_init.h"

#include "bn_sprite_items_akyuu_spritesheet.h"
#include "sprite_animations.h"

// #include "bn_regular_bg_items_screen1n.h"
// #include "bn_regular_bg_items_screen2n.h"
#include "bn_regular_bg_items_screen10n.h"
// #include "bn_regular_bg_items_screen21n.h"

#include "bn_log.h"

namespace rra
{
namespace stage2
{
    void load_stage(Global_VRAM* VRAM, int frame_counter, int current_level) {

        rra::stage_init(VRAM);   // Resets all backgrounds and non-player sprites

        bn::regular_bg_ptr screen_10n = bn::regular_bg_items::screen10n.create_bg(8, 48);

        screen_10n.set_visible(false);

        switch(current_level){
            case 11:
                screen_10n.set_visible(true);
                VRAM->global_backgrounds.push_back(screen_10n);        

                BN_LOG("You've gotten to level << 11 >> successfully! (Stage < 2 >)");

                break;
            // case 2:
                // screen_2n.set_visible(true);
                // VRAM.push_back(screen_2n);  
            default:
                int hey_compiler_hows_it_goin_xdddd = 0;       // <--- "nop" instruction on budget, heh
        }

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