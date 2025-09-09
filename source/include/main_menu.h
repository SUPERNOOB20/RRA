#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "bn_sprite_ptr.h"
#include "bn_regular_bg_ptr.h"

#include "bn_vector.h"
#include "global_resources.h"

namespace rra
{

    int display_main_menu(Global_VRAM* global_sprites_and_backgrounds, int start_frame_counter);     // Returns 1 if the intro is still playing, and 0 otherwise.

}


#endif