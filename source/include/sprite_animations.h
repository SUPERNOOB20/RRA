#ifndef GLOBAL_RESOURCES
#define GLOBAL_RESOURCES

#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"

#include <bn_vector.h>
#include "global_resources.h"


/*
struct global_data
{
    bn::sprite_ptr reimu_idle_sprite;
    bn::sprite_ptr reimu_jump_sprite;
    bn::sprite_ptr cirno_sprite;
    bn::sprite_ptr akyuu_sprite;
    bn::sprite_ptr rumia_sprite;
    bn::sprite_ptr youmu_idle_sprite;
    bn::sprite_ptr spirit_sprite;

    bn::regular_bg_ptr screen1n;
    bn::regular_bg_ptr screen2n;
    bn::regular_bg_ptr screen10n;
    bn::regular_bg_ptr screen21n;
};
*/





namespace rra
{

namespace sprite_anim
{
    // void cirno_anim(int frame_counter, *);
    // void yukari_portal_anim(int frame_counter);
    // void yukari_anim(int frame_counter);
    void reimu_anim(Global_VRAM global_sprites_and_backgrounds, int frame_counter, int player_x, int player_y);
    void akyuu_anim(Global_VRAM global_sprites_and_backgrounds, int frame_counter);
    void cirno_anim(Global_VRAM global_sprites_and_backgrounds, int frame_counter);
    void rumia_anim(Global_VRAM global_sprites_and_backgrounds, int frame_counter);
    void youmu_idle_anim(Global_VRAM global_sprites_and_backgrounds, int frame_counter);
    void spirit_anim(Global_VRAM global_sprites_and_backgrounds, int frame_counter);
}

}


#endif