#include "bn_vector.h"

namespace rra
{
namespace stage1
{
    void load_stage((global_resources* global_sprites_and_backgrounds, int frame_counter, int current_level)){

        rra::stage_init()   // Resets all backgrounds and non-player sprites

        switch(current_level){
            case 1:
                global_sprites_and_backgrounds->screen1n.set_visible(true);        
            case 2:
                global_sprites_and_backgrounds->screen2n.set_visible(true);
            default:
                break
        }


        global_sprites_and_backgrounds->screen1n.set_visible(true);
        

        global_sprites_and_backgrounds->screen2n.set_visible(true);
            global_sprites_and_backgrounds->akyuu_sprite.set_visible(true);
            global_sprites_and_backgrounds->akyuu_sprite.set_top_left_position(190, 80);
            rra::sprite_anim::akyuu_anim(global_sprites_and_backgrounds, frame_counter);
        return;
    };
}
}