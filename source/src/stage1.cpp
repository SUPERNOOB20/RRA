#include "bn_vector.h"
#include "global_resources.h"
#include "stage_init.h"

#include "bn_sprite_items_akyuu_spritesheet.h"
#include "sprite_animations.h"

#include "bn_regular_bg_items_screen1n.h"
#include "bn_regular_bg_items_screen2n.h"
// #include "bn_regular_bg_items_screen10n.h"
// #include "bn_regular_bg_items_screen21n.h"

#include "bn_log.h"

namespace rra
{
namespace stage1
{

    void load_stage(Global_VRAM* VRAM, int frame_counter, int current_level) {

        rra::stage_init(VRAM);   // Resets all backgrounds and non-player sprites

        // bn::regular_bg_ptr screen_1n = bn::regular_bg_items::screen1n.create_bg(8, 48);
        // bn::regular_bg_ptr screen_2n = bn::regular_bg_items::screen2n.create_bg(8, 48);

        // bn::bg_palette_ptr screen_2n_palette = screen_2n.palette();
        // void screen_2n_palette.set_colors(screen_1n.palette());

        // screen_1n.set_visible(false);
        // screen_2n.set_visible(false);

        // bn::regular_bg_ptr.set_palette(screen_1n);

        // bn::regular_bg_items::screen1n(bpp_mode bpp_8);

        // bn::bg_palette_ptr bg_palette = screen1n.palette();
        // bg_palette.set_colors(screen1n_item);

        bn::regular_bg_ptr level_layout = bn::regular_bg_items::screen1n.create_bg(8, 48);
        // VRAM->global_backgrounds.push_back(level_layout);

        switch(current_level){
            case 1:
                // level_layout = bn::regular_bg_items::screen1n.create_bg(8, 48);
                break;   

            case 2:
                {

                BN_LOG("    ");
                BN_LOG("frame_counter, current_level: ");
                BN_LOG(frame_counter, "   ", "   ", current_level);
                BN_LOG("vv ----------- VRAM ---------- vv");
                BN_LOG("current vector size:    ", VRAM->global_player_sprites.size(), "   ", VRAM->global_sprites.size(), "   ", VRAM->global_backgrounds.size());
                BN_LOG("max vector size:    ", VRAM->global_player_sprites.max_size(), "   ", VRAM->global_sprites.max_size(), "   ", VRAM->global_backgrounds.max_size());
                BN_LOG("---------------------------------");

                // VRAM->global_backgrounds.pop_back();

                level_layout = bn::regular_bg_items::screen2n.create_bg(8, 48);

                rra::sprite_anim::akyuu_anim(VRAM, frame_counter);

                auto current_akyuu_sprite = VRAM->global_sprites.back();

                current_akyuu_sprite.set_top_left_position(190, 80);

                VRAM->global_sprites.push_back(current_akyuu_sprite);

                BN_LOG("    ");
                BN_LOG(" :p ");
                BN_LOG("    ");
                }
                break;

            // case 3:
                // level_layout = bn::regular_bg_items::screen3n.create_bg(8, 48);
            // case 4:
                // level_layout = bn::regular_bg_items::screen4n.create_bg(8, 48);
            // case 5:
                // level_layout = bn::regular_bg_items::screen5n.create_bg(8, 48);
            // .
            // .
            // .

            // case 8:
                // generate_hall(VRAM);
                // ^ Please disable push_back() after this!!!
                // break;
            case 9:
                // level_layout = bn::regular_bg_items::screen9n.create_bg(8, 48);

                {
                rra::sprite_anim::cirno_anim(VRAM, frame_counter);

                auto current_cirno_sprite = VRAM->global_sprites.back();

                current_cirno_sprite.set_top_left_position(190, 80);

                VRAM->global_sprites.push_back(current_cirno_sprite);
                }
                break;

            default:
                int hey_compiler_hows_it_goin_xdddd = 0;       // <--- "nop" instruction on budget, heh
        }

        VRAM->global_backgrounds.push_back(level_layout);
        
        

        return;
    };
}
}