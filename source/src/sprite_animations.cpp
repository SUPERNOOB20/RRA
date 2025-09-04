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
#include "bn_sprite_items_rumia_idle_spritesheet.h"
#include "bn_sprite_items_youmu_idle_spritesheet.h"
#include "bn_sprite_items_spirit_spritesheet.h"
#include "bn_sprite_items_will_o_wisp_spritesheet.h"
// #include "bn_sprite_items_akyuu_1s.h"
// #include "bn_sprite_items_akyuu_2s.h"

// #include "global_ptr.h"

// #pragma once


#include <bn_vector.h>
#include "global_resources.h"


namespace rra
{


namespace sprite_anim
{
    constexpr int reimu_anim_frame_screentime = 20;       // Sets the amount of frames each sprite should play for (i.e. frame "screentime"). anim_frames == 60 means 1fps animation, anim_frames == 30 means 2fps animation, etc.
    constexpr int akyuu_anim_frame_screentime = 30;
    constexpr int spirit_anim_frame_screentime = 30;
    constexpr int will_o_wisp_screentime = 15;

    constexpr int spirit_anim_number_of_frames = 13;      // There are 13 different "poses" for the spirit sprite.
    constexpr int will_o_wisp_anim_number_of_frames = 4;
    
    // constexpr int cirno_idle_frames = 25;
    // constexpr int cirno_laughing_frames = 10;

    void reimu_anim(Global_VRAM* VRAM, int frame_counter, int player_x, int player_y){

        bn::sprite_ptr reimu_sprite = bn::sprite_items::reimu_idle_spritesheet.create_sprite(player_x, player_y);
        reimu_sprite.set_top_left_position(player_x, player_y);

        if (frame_counter > 0) {
            VRAM->global_player_sprites.pop_back();    
        }

        VRAM->global_player_sprites.push_back(reimu_sprite);    

        int i = 0;

        if ((frame_counter % (reimu_anim_frame_screentime * 3)) < (reimu_anim_frame_screentime)) {
            i = 0;
        } else if ((frame_counter % (reimu_anim_frame_screentime * 3)) < (reimu_anim_frame_screentime * 2)) {
            i = 1;
        } else {
            i = 2;
        }

        reimu_sprite.set_tiles(bn::sprite_items::reimu_idle_spritesheet.tiles_item().create_tiles(i));                

        return;
    }

    void akyuu_anim(Global_VRAM* VRAM, int frame_counter){

        int i = 0;

        if ((frame_counter % (akyuu_anim_frame_screentime * 2)) < (akyuu_anim_frame_screentime)) {
            i = 0;
        } else {
            i = 1;
        }

        
        bn::sprite_ptr akyuu_sprite = bn::sprite_items::akyuu_spritesheet.create_sprite(0, 0); 

        VRAM->global_sprites.push_back(akyuu_sprite);

        akyuu_sprite.set_tiles(bn::sprite_items::akyuu_spritesheet.tiles_item().create_tiles(i));  


        return;

    }


    // cirno_anim(int frame_counter);
    // cirno_sprite.set_tiles(bn::sprite_items::cirno_spritesheet.tiles_item().create_tiles(3));
    void cirno_anim(Global_VRAM* VRAM, int frame_counter){

        bn::sprite_ptr cirno_sprite = bn::sprite_items::cirno_spritesheet.create_sprite(0, 0); 

        VRAM->global_sprites.push_back(cirno_sprite);

        int f = frame_counter % 470;
        int i = 0;

        if (f<=250) {
            if ((f % 50) > 25) {
                i = 1;
            }
        } else if (f > 350) {    // 350 < f < 470
            if ((f % 20) < 10) {
                i = 2;
            } else {
                i = 3;
            }
        }
            
        cirno_sprite.set_tiles(bn::sprite_items::cirno_spritesheet.tiles_item().create_tiles(i));

        return;
    }

    void youmu_idle_anim(Global_VRAM* VRAM, int frame_counter){

        bn::sprite_ptr youmu_idle_sprite = bn::sprite_items::youmu_idle_spritesheet.create_sprite(0, 0); 

        VRAM->global_sprites.push_back(youmu_idle_sprite);

        int i = 0;

        // youmu_idle_anim_frames = 60
        // But I didn't use that var because if I don't use integer division
        // it's prone to breaking if it's not divisible by 2 or 3!!!

        if ((frame_counter % 60) < 36){         // youmu_idle_anim_frames = 60
            i = 0;
        } else {
            i = 1;
        }        

        // VRAM->youmu_idle_sprite.set_tiles(bn::sprite_items::youmu_idle_spritesheet.tiles_item().create_tiles(i));  

        youmu_idle_sprite.set_tiles(bn::sprite_items::youmu_idle_spritesheet.tiles_item().create_tiles(i));  

        return;
    }

    void rumia_anim(Global_VRAM* VRAM, int frame_counter){

        bn::sprite_ptr rumia_idle_sprite = bn::sprite_items::rumia_idle_spritesheet.create_sprite(0, 0); 

        VRAM->global_sprites.push_back(rumia_idle_sprite);

        int total_duration = frame_counter % 481;

        constexpr int idle_frames_duration = 38;
        constexpr int non_stare_duration = idle_frames_duration * 6;                        // Duration of the non-stare loop. 38 * 2 * 3 = 228.

        constexpr int standby_duration = 115;                          // Duration of the AA frame.

        constexpr int amount_of_loops = 3;
        int i = 1;

        if (total_duration < non_stare_duration) {
            if ((non_stare_duration / amount_of_loops) < (idle_frames_duration)){     // VERY roughly speaking, it's like "0f to 37f". Kinda.
                i = 0;
            }
        } else if ((frame_counter > (non_stare_duration + idle_frames_duration))
        && (frame_counter < (non_stare_duration + idle_frames_duration + standby_duration))) {
            i = 0;
        } else if ((frame_counter > (non_stare_duration + idle_frames_duration + standby_duration))
        && (frame_counter < (non_stare_duration + idle_frames_duration + standby_duration + 76))
        || ((frame_counter > (non_stare_duration + idle_frames_duration + standby_duration + 76 + 16)))) {
            i = 2;
        } else {
            i = 3;
        }

        rumia_idle_sprite.set_tiles(bn::sprite_items::rumia_idle_spritesheet.tiles_item().create_tiles(i));

        return;
    }

    void will_o_wisp_anim(Global_VRAM* VRAM, int frame_counter){

        bn::sprite_ptr will_o_wisp_sprite = bn::sprite_items::will_o_wisp_spiritesheet.create_sprite(0, 0);

        will_o_wisp_spritesheet.set_vertical_flip(false);

        VRAM->global_sprites.push_back(spirit_sprite);

        // vvv  My animation has 13 frames. Each of them should display for 20 frames.
        int animation_frame = ((frame_counter / spirit_anim_frame_screentime) % spirit_anim_number_of_frames);          // goes from 0 to 13. You can do "+ 1" if you'd rather have it go from 1 to 14.

        will_o_wisp_spritesheet.set_tiles(bn::sprite_items::will_o_wisp_sprite.tiles_item().create_tiles(animation_frame));                

        return;
    }

    void spirit_anim(Global_VRAM* VRAM, int frame_counter){
    
        bn::sprite_ptr spirit_sprite = bn::sprite_items::spirit_spritesheet.create_sprite(0, 0);

        spirit_sprite.set_vertical_flip(false);

        int animation_frame = ((frame_counter / will_o_wisp_screentime) % will_o_wisp_anim_number_of_frames);         // goes from 0 to 3. You can do "+ 1" if you'd rather have it go from 1 to 4.

        if ((animation_frame > 4) && (animation_frame < 11))
            {
                spirit_sprite.set_vertical_flip(true);     // Cases 5 to 10 should be flipped to mirror the sprite!
            }

        spirit_sprite.set_tiles(bn::sprite_items::spirit_spritesheet.tiles_item().create_tiles(animation_frame));                
        return;
}

}