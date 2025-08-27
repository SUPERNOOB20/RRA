#include "bn_core.h"
#include <bn_sprites.h>
#include "bn_sprite_ptr.h"
#include <bn_sprite_tiles.h>
#include <bn_sprite_tiles_ptr.h>

#include "sprite_animations.h"

#include "bn_sprite_actions.h"
#include "bn_sprites_actions.h"
#include "bn_sprite_animate_actions.h"

#include "bn_sprite_palette_ptr.h"

#include "bn_sprite_items_reimu_idle_spritesheet.h"
#include "bn_sprite_items_cirno_spritesheet.h"
#include "bn_sprite_items_akyuu_spritesheet.h"
// #include "bn_sprite_items_akyuu_1s.h"
// #include "bn_sprite_items_akyuu_2s.h"

#include "bn_log.h"

// #pragma once





namespace rra
{


namespace sprite_anim
{
    const int reimu_anim_frames = 20;       // Sets the amount of frames each sprite should play for (i.e. frame speed). anim_frames == 60 means 1fps animation, anim_frames == 30 means 2fps animation, etc.
    const int akyuu_anim_frames = 30;
    // const int cirno_idle_frames = 25;
    // const int cirno_laughing_frames = 10;

    void reimu_anim(int frame_counter, int player_x, int player_y){

        bn::sprite_ptr reimu_sprite = bn::sprite_items::reimu_idle_spritesheet.create_sprite(player_x, player_y);

        if ((frame_counter % (reimu_anim_frames * 3)) < (reimu_anim_frames)) {
            reimu_sprite.set_tiles(bn::sprite_items::reimu_idle_spritesheet.tiles_item().create_tiles(0));                
        } else if ((frame_counter % (reimu_anim_frames * 3)) < (reimu_anim_frames * 2)) {
            reimu_sprite.set_tiles(bn::sprite_items::reimu_idle_spritesheet.tiles_item().create_tiles(1));                
        } else {
            reimu_sprite.set_tiles(bn::sprite_items::reimu_idle_spritesheet.tiles_item().create_tiles(2));                
        }

        return;
    }

    void akyuu_anim(int frame_counter){
        
        bn::sprite_ptr akyuu_sprite = bn::sprite_items::akyuu_spritesheet.create_sprite(96, 12);

        if ((frame_counter % (akyuu_anim_frames * 2)) < (akyuu_anim_frames)) {
            akyuu_sprite.set_tiles(bn::sprite_items::akyuu_spritesheet.tiles_item().create_tiles(0));                             
        } else {
            akyuu_sprite.set_tiles(bn::sprite_items::akyuu_spritesheet.tiles_item().create_tiles(1));                
        }
    }

    // cirno_anim(int frame_counter);
        // cirno_sprite.set_tiles(bn::sprite_items::cirno_spritesheet.tiles_item().create_tiles(3));
}

}