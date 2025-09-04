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

        bn::regular_bg_ptr level_layout = bn::regular_bg_items::screen10n.create_bg(8, 48);

        switch(current_level){
            case 10:
                // level_layout = bn::regular_bg_items::screen10n.create_bg(8, 48);
                break;
            // case 11:
                // level_layout = bn::regular_bg_items::screen11n.create_bg(8, 48);
            // case 12:
                // level_layout = bn::regular_bg_items::screen12n.create_bg(8, 48);
            // case 13:
                // level_layout = bn::regular_bg_items::screen13n.create_bg(8, 48);
            // case 14:
                // level_layout = bn::regular_bg_items::screen11n.create_bg(8, 48);
            // case 15:
                // level_layout = bn::regular_bg_items::screen11n.create_bg(8, 48);
            // .
            // .
            // .
            // case 18:
                // generate_hall(VRAM);
                // ^ Please disable push_back() after this!!!
            case 19:
                rra::sprite_anim::rumia_anim(VRAM, frame_counter);

                auto current_rumia_sprite = VRAM->global_sprites.back();

                current_rumia_sprite.set_top_left_position(224, 124);

                VRAM->global_sprites.push_back(current_rumia_sprite);
                break;

            default:
                int hey_compiler_hows_it_goin_xdddd = 0;       // <--- "nop" instruction on budget, heh
        }

        VRAM->global_backgrounds.push_back(level_layout);

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