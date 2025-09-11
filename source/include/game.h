#ifndef GAME_H
#define GAME_H

#include "global_resources.h"

void load_first_screen(Global_VRAM* VRAM);

namespace rra
{


namespace game
{
void handle_frame(Global_VRAM* global_sprites_and_backgrounds, int frame_counter);
void change_stage(Global_VRAM* global_sprites_and_backgrounds, int frame_counter);
}


}

#endif