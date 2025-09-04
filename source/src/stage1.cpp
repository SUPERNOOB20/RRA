#include "bn_vector.h"
#include "global_resources.h"
#include "stage_init.h"

#include "bn_sprite_items_akyuu_spritesheet.h"
#include "sprite_animations.h"

#include "bn_regular_bg_items_screen1n.h"
#include "bn_regular_bg_items_screen2n.h"
// #include "bn_regular_bg_items_screen10n.h"
// #include "bn_regular_bg_items_screen21n.h"

// #include "bn_log.h"

namespace rra
{
namespace stage1
{

    void load_stage(Global_VRAM* VRAM, int frame_counter, int current_level) {

        rra::stage_init(VRAM);   // Resets all backgrounds and non-player sprites

        bn::regular_bg_ptr screen_1n = bn::regular_bg_items::screen1n.create_bg(8, 48);
        bn::regular_bg_ptr screen_2n = bn::regular_bg_items::screen2n.create_bg(8, 48);

        // bn::bg_palette_ptr screen_2n_palette = screen_2n.palette();
        // void screen_2n_palette.set_colors(screen_1n.palette());

        screen_1n.set_visible(false);
        screen_2n.set_visible(false);

        switch(current_level){
            case 1:
                screen_1n.set_visible(true);
                VRAM->global_backgrounds.push_back(screen_1n);     
                break;   
            case 2:
                screen_2n.set_visible(true);
                VRAM->global_backgrounds.push_back(screen_2n);  
                break;
            default:
                int hey_compiler_hows_it_goin_xdddd = 0;       // <--- "nop" instruction on budget, heh
        }
        
        rra::sprite_anim::akyuu_anim(VRAM, frame_counter);

        auto current_akyuu_sprite = VRAM->global_sprites.back();

        current_akyuu_sprite.set_top_left_position(190, 80);

        VRAM->global_sprites.push_back(current_akyuu_sprite);

        return;
    };
}
}