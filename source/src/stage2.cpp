#include "bn_vector.h"
#include "global_resources.h"
#include "stage_init.h"

#include "bn_sprite_items_akyuu_spritesheet.h"
#include "sprite_animations.h"

#include "bn_regular_bg_items_screen10n.h"


#include "bn_log.h"

namespace rra
{
namespace stage2
{
    void load_stage(Global_VRAM* VRAM, int frame_counter, int current_level) {

        rra::stage_init(VRAM);   // Resets all backgrounds and non-player sprites

        bn::regular_bg_ptr level_layout = bn::regular_bg_items::screen10n.create_bg(8, 48);

        switch(current_level){
            // case 10:
                // level_layout = bn::regular_bg_items::screen10n.create_bg(8, 48);
                // break;
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
                {
                rra::sprite_anim::rumia_anim(VRAM, frame_counter);

                auto current_rumia_sprite = VRAM->global_sprites.back();

                current_rumia_sprite.set_top_left_position(196, 108);

                VRAM->global_sprites.push_back(current_rumia_sprite);
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

    std::vector<rra::Rect> load_collisions(int current_lvl){

        bn::vector<rra::Rect, 9999> collision_vector;                               // Initializes collision_vector.
        bn::vector<rra::Rect, 9999>* collision_vector_ptr = &collision_vector       // Initializes a pointer to collision_vector.

        switch (current_lvl){
            case 10:

                

                // std::array<std::array<int, 2>, 2> collisions.
                // You can also define them as std::array<int, 4> if you're into that ("^-^)
                rra::Rect collisions1L {(std::array<int, 2> {0, 80}), (std::array<int, 2> {15, 160})};
                rra::Rect collisions2L {(std::array<int, 2> {16, 112}), (std::array<int, 2> {31, 160})};
                rra::Rect collisions3L {(std::array<int, 2> {32, 144}), (std::array<int, 2> {64, 160})};

                rra::Rect collisions1R {(std::array<int, 2> {160, 144}), (std::array<int, 2> {240, 160})};
                rra::Rect collisions2R {(std::array<int, 2> {176, 128}), (std::array<int, 2> {240, 143})};
                rra::Rect collisions3R {(std::array<int, 2> {192, 112}), (std::array<int, 2> {240, 127})};
                rra::Rect collisions4R {(std::array<int, 2> {208, 96}), (std::array<int, 2> {240, 111})};
                rra::Rect collisions5R {(std::array<int, 2> {224, 80}), (std::array<int, 2> {240, 95})};
            


                collision_Vector_ptr->push.back(collisions1L);
                collision_Vector_ptr->push.back(collisions2L);
                collision_Vector_ptr->push.back(collisions3L);

                collision_Vector_ptr->push.back(collisions1R);
                collision_Vector_ptr->push.back(collisions2R);
                collision_Vector_ptr->push.back(collisions3R);
                collision_Vector_ptr->push.back(collisions4R);
                collision_Vector_ptr->push.back(collisions5R);

                break;


            default:
        }

        return collision_vector_ptr;

    }
}
}