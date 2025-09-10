#include "bn_vector.h"
#include "global_resources.h"
#include "stage_init.h"

#include "bn_sprite_items_akyuu_spritesheet.h"
// #include "bn_sprite_items_spirit_spritesheet.h"
// #include "bn_sprite_items_will_o_wisp_spritesheet.h"
#include "sprite_animations.h"

#include "bn_regular_bg_items_screen21n.h"

#include "bn_log.h"

namespace rra
{
namespace stage4
{
    void load_stage(Global_VRAM* VRAM, int frame_counter, int current_level) {

        rra::stage_init(VRAM);   // Resets all backgrounds and non-player sprites

        bn::regular_bg_ptr level_layout = bn::regular_bg_items::screen21n.create_bg(8, 48);

        switch(current_level){
            case 30:
                break;

            case 31:
                break;

            case 32:
                break;

            // case 33:
                // level_layout = bn::regular_bg_items::screen33n.create_bg(8, 48);
                // break;
            // case 34:
                // level_layout = bn::regular_bg_items::screen34n.create_bg(8, 48);
                // break;
            // case 35:
                // level_layout = bn::regular_bg_items::screen35n.create_bg(8, 48);
                // break;
            // case 36:
                // level_layout = bn::regular_bg_items::screen36n.create_bg(8, 48);
                // break;
            // case 37:
                // level_layout = bn::regular_bg_items::screen37n.create_bg(8, 48);
                // break;
            // case 38:
                // generate_hall(VRAM);
                // ^ Please disable push_back() after this!!!
                // break;
            case 29:
                {
                rra::sprite_anim::youmu_idle_anim(VRAM, frame_counter);

                auto current_youmu_sprite = VRAM->global_sprites.back();

                current_youmu_sprite.set_top_left_position(190, 80);

                VRAM->global_sprites.push_back(current_youmu_sprite);
                }
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