// #pragma once

namespace rra
{

namespace sprite_anim
{
    // void cirno_anim(int frame_counter, *);
    // void yukari_portal_anim(int frame_counter);
    // void yukari_anim(int frame_counter);
    void reimu_anim(global_ptr* global_sprites_and_backgrounds, int frame_counter, int player_x, int player_y);
    void akyuu_anim(global_ptr* global_sprites_and_backgrounds, int frame_counter);
}

}