#include <bn_vector.h>
#include <bn_sprite_ptr.h>
#include <bn_regular_bg_ptr.h>

#include "global_resources.h"

struct Global_VRAM allocate_VRAM(bn::vector<bn::sprite_ptr, 26> global_player_sprites, bn::vector<bn::sprite_ptr, 100> global_sprites, bn::vector<bn::regular_bg_ptr, 4> global_backgrounds){
    Global_VRAM allocated_VRAM = {.global_player_sprites = global_player_sprites, .global_sprites = global_sprites, .global_backgrounds = global_backgrounds};


    return allocated_VRAM;
}