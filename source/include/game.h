// #pragma once

// #include "bn_sprite_ptr.h"
// #include "bn_regular_bg_ptr.h"


/*
struct global_data
{
    bn::sprite_ptr reimu_idle_spritesheet;
    bn::sprite_ptr reimu_jump_spritesheet;
    bn::sprite_ptr cirno_sprite;
    bn::sprite_ptr akyuu_sprit;

    bn::regular_bg_ptr screen1n;
    bn::regular_bg_ptr screen2n;
};
*/




#ifndef GAME_H
#define GAME_H

#include "global_resources.h"

namespace rra
{


namespace game
{
void handle_frame(Global_VRAM* global_sprites_and_backgrounds, int frame_counter);
void change_stage(Global_VRAM* global_sprites_and_backgrounds, int frame_counter);
}


}

#endif