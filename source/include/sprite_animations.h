#ifndef SPRITE_ANIMATIONS_H
#define SPRITE_ANIMATIONS_H

#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"

#include <bn_vector.h>
#include "global_resources.h"

namespace rra
{

namespace sprite_anim
{
    // void cirno_anim(int frame_counter, *);
    // void yukari_portal_anim(int frame_counter);
    // void yukari_anim(int frame_counter);
    void reimu_anim(Global_VRAM* global_sprites_and_backgrounds, int frame_counter, int player_x, int player_y);
    void akyuu_anim(Global_VRAM* global_sprites_and_backgrounds, int frame_counter);
    void cirno_anim(Global_VRAM* global_sprites_and_backgrounds, int frame_counter);
    void rumia_anim(Global_VRAM* global_sprites_and_backgrounds, int frame_counter);
    void youmu_idle_anim(Global_VRAM* global_sprites_and_backgrounds, int frame_counter);
    void spirit_anim(Global_VRAM* global_sprites_and_backgrounds, int frame_counter);
    void will_o_wisp_anim(Global_VRAM* global_sprites_and_backgrounds, int frame_counter);
}

}

#endif