#pragma once

struct global_data
{
    bn::sprite_ptr reimu_idle_spritesheet;
    bn::sprite_ptr reimu_jump_spritesheet;
    bn::sprite_ptr cirno_spritesheet;
    bn::sprite_ptr akyuu_spritesheet;

    bn::regular_bg_ptr screen1n;
    bn::regular_bg_ptr screen2n;
};



namespace rra
{


namespace game
{
void handle_frame(global_data* global_sprites_and_backgrounds, int frame_counter);
}


}