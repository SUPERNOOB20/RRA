#pragma once

#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"

struct global_data
{
    bn::sprite_ptr reimu_idle_sprite;
    bn::sprite_ptr reimu_jump_sprite;
    bn::sprite_ptr cirno_sprite;
    bn::sprite_ptr akyuu_sprite;

    bn::regular_bg_ptr screen1n;
    bn::regular_bg_ptr screen2n;
};


namespace rra
{

namespace sprite_anim
{
    // void cirno_anim(int frame_counter, *);
    // void yukari_portal_anim(int frame_counter);
    // void yukari_anim(int frame_counter);
    void reimu_anim(global_data* global_sprites_and_backgrounds, int frame_counter, int player_x, int player_y);
    void akyuu_anim(global_data* global_sprites_and_backgrounds, int frame_counter);
}

}