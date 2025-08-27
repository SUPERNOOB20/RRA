#include "bn_sprite_ptr.h"
#include "sprite_animations.h"

#include "bn_sprite_items_reimu_idle_spritesheet.h"
#include "bn_sprite_items_cirno_spritesheet.h"



#pragma once





namespace rra
{


namespace sprite_anim
{
    void reimu_anim(int frame_counter, int reimu_anim_frames, int player_x, int player_y){

        bn::sprite_ptr reimu_sprite = bn::sprite_items::reimu_idle_spritesheet.create_sprite(player_x, player_y);

        if ((frame_counter % (reimu_anim_frames * 3)) < (reimu_anim_frames)) {
            reimu_sprite.set_tiles(bn::sprite_items::reimu_idle_spritesheet.tiles_item().create_tiles(0));                
        } else if ((frame_counter % (reimu_anim_frames * 3)) < (reimu_anim_frames * 2)) {
            reimu_sprite.set_tiles(bn::sprite_items::reimu_idle_spritesheet.tiles_item().create_tiles(1));                
        } else {
            reimu_sprite.set_tiles(bn::sprite_items::reimu_idle_spritesheet.tiles_item().create_tiles(2));                
        }

    }
    // cirno_anim(int frame_counter);
        // cirno_sprite.set_tiles(bn::sprite_items::cirno_spritesheet.tiles_item().create_tiles(3));
}

}