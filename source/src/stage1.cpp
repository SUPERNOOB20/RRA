#include <tuple>
#include <vector>
#include "coordinates.h"

#include "bn_vector.h"
#include "global_resources.h"
#include "stage_init.h"

#include "bn_sprite_items_akyuu_spritesheet.h"
#include "sprite_animations.h"

#include "bn_regular_bg_items_screen1n.h"
#include "bn_regular_bg_items_screen2n.h"

#include "bn_log.h"


std::vector<Coordinates> hazards;
std::vector<Coordinates> collisions;


std::vector<Coordinates> load_hazards(int current_lvl){
    switch (current_lvl){
        case 1:
            /*
            std::tuple<int, int> spike_1(112, 150);
            std::tuple<int, int> spike_2(127, 160);
            auto tup3 = tuple_cat(spike_1, spike_2);
            */

            std::tuple<std::tuple<int, int>, std::tuple<int, int>> spikes ((std::tuple<int, int> (112, 150)), (std::tuple<int, int> (127, 160)));

            Coordinates spikes_1 = {spikes};
            break;
        case 2:
            break;
        default:
    }
}



std::vector<Coordinates> load_collisions(int current_lvl){
    switch (current_lvl){
        case 1:
            /*
            std::tuple<int, int> spike_1(112, 150);
            std::tuple<int, int> spike_2(127, 160);
            auto tup3 = tuple_cat(spike_1, spike_2);
            */

            std::tuple<std::tuple<int, int>, std::tuple<int, int>> collisions ((std::tuple<int, int> (112, 150)), (std::tuple<int, int> (127, 160)));

            Collision_Block collisions_1 = {collisions};
            break;
        case 2:
            break;
        default:
    }
}


namespace rra
{
namespace stage1
{

    void load_stage(Global_VRAM* VRAM, int frame_counter, int current_level) {

        rra::stage_init(VRAM);   // Resets all backgrounds and non-player sprites

        bn::regular_bg_ptr level_layout = bn::regular_bg_items::screen1n.create_bg(8, 48);
        // VRAM->global_backgrounds.push_back(level_layout);

        switch(current_level){
            case 1:
                load_hazards(1);
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