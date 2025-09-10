#include "bn_vector.h"
#include "global_resources.h"
#include "stage_init.h"

#include "bn_sprite_items_akyuu_spritesheet.h"
// #include "bn_sprite_items_spirit_spritesheet.h"
// #include "bn_sprite_items_will_o_wisp_spritesheet.h"
#include "sprite_animations.h"

#include "bn_regular_bg_items_screen40n.h"

#include "bn_log.h"

namespace rra
{
namespace stage5
{
    void load_stage(Global_VRAM* VRAM, int frame_counter, int current_level) {

        rra::stage_init(VRAM);   // Resets all backgrounds and non-player sprites

        bn::regular_bg_ptr level_layout = bn::regular_bg_items::screen40n.create_bg(8, 48);

        switch(current_level){
            case 40:
                // level_layout = bn::regular_bg_items::screen40n.create_bg(8, 48);
                break;

            case 41:
                // level_layout = bn::regular_bg_items::screen41n.create_bg(8, 48);
                break;

            case 42:
                // level_layout = bn::regular_bg_items::screen42n.create_bg(8, 48);
                break;

            case 43:
                // level_layout = bn::regular_bg_items::screen43n.create_bg(8, 48);
                // break;
            case 44:
                // level_layout = bn::regular_bg_items::screen44n.create_bg(8, 48);
                break;
            case 45:
                // level_layout = bn::regular_bg_items::screen45n.create_bg(8, 48);
                break;
            case 46:
                // level_layout = bn::regular_bg_items::screen46n.create_bg(8, 48);
                break;
            case 47:
                // level_layout = bn::regular_bg_items::screen47n.create_bg(8, 48);
                break;
            case 48:
                // generate_hall(VRAM);
                // ^ Please disable push_back() after this!!!
                break;
            case 49:
                {
                rra::sprite_anim::yorihime_idle_anim(VRAM, frame_counter);

                auto current_yorihime_sprite = VRAM->global_sprites.back();

                current_yorihime_sprite.set_top_left_position(208, 112);       // Places Yorihime at the bottom right corner of the screen.

                VRAM->global_sprites.push_back(current_yorihime_sprite);
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