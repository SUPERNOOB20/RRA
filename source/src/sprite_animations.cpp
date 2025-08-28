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

// #include "global_ptr.h"

// #pragma once





namespace rra
{


namespace sprite_anim
{
    const int reimu_anim_frames = 20;       // Sets the amount of frames each sprite should play for (i.e. frame speed). anim_frames == 60 means 1fps animation, anim_frames == 30 means 2fps animation, etc.
    const int akyuu_anim_frames = 30;
    // const int cirno_idle_frames = 25;
    // const int cirno_laughing_frames = 10;

    void reimu_anim(global_data* global_sprites_and_backgrounds, int frame_counter, int player_x, int player_y){

        // bn::sprite_ptr reimu_sprite = bn::sprite_items::reimu_idle_spritesheet.create_sprite(player_x, player_y);
        global_sprites_and_backgrounds->reimu_idle_sprite.set_top_left_position(player_x, player_y);

        int i = 0;

        if ((frame_counter % (reimu_anim_frames * 3)) < (reimu_anim_frames)) {
            i = 0;
        } else if ((frame_counter % (reimu_anim_frames * 3)) < (reimu_anim_frames * 2)) {
            i = 1;
        } else {
            i = 2;
        }

        global_sprites_and_backgrounds->reimu_idle_sprite.set_tiles(bn::sprite_items::reimu_idle_spritesheet.tiles_item().create_tiles(i));                

        return;
    }

    void akyuu_anim(global_data* global_sprites_and_backgrounds, int frame_counter){
        
        // bn::sprite_ptr akyuu_sprite = bn::sprite_items::akyuu_spritesheet.create_sprite(96, 12);
        // bn::sprite_items::akyuu_spritesheet.create_sprite(96, 12);

        global_sprites_and_backgrounds->akyuu_sprite.set_top_left_position(216, 80);

        // sprite_pointer akyuu_sprite = bn::sprite_items::akyuu_spritesheet.create_sprite(96, 12);

        int i = 0;

        if ((frame_counter % (akyuu_anim_frames * 2)) < (akyuu_anim_frames)) {
            i = 0;
        } else {
            i = 1;
        }

        global_sprites_and_backgrounds->akyuu_sprite.set_tiles(bn::sprite_items::akyuu_spritesheet.tiles_item().create_tiles(i));  
        
        return;

    }

    // cirno_anim(int frame_counter);
        // cirno_sprite.set_tiles(bn::sprite_items::cirno_spritesheet.tiles_item().create_tiles(3));
}

}