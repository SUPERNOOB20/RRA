#include "bn_core.h"
#include "bn_sprites.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_tiles.h"
#include "bn_sprite_tiles_ptr.h"

#include "bn_sprite_item.h"
// #include "bn_sprite_items_ice_block.h"

#include "bn_sprite_items_reimu_idle_spritesheet.h"
#include "bn_sprite_items_reimu_jump_spritesheet.h"

#include "bn_sprite_items_akyuu_spritesheet.h"

#include "bn_sprite_items_fairy.h"

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"

// #include "bn_keypad.h"
#include "bn_log.h"

#include "sprite_animations.h"

#include "main_menu.h"
#include "game.h"

#include "global_resources.h"

#include "bn_keypad.h"

#include "bn_sprite_text_generator.h"

#include "bn_display.h"

#include "bn_math.h"

#include "stage_init.h"

// #include "bn_regular_bg_items_screen1n.h"

#include "bn_bg_palette_item.h"
#include "bn_bg_palette_ptr.h"

// #include "bn_bg_palette_items_screen1n.h"



#include "bn_unique_ptr_fwd.h"



// #include <vector>
#include "bn_vector.h"
template<typename Type, int MaxSize>
bn::vector<bn::sprite_ptr, 1>        test;          // sets the template in stone, for later use in main().


int main()
{
    bn::core::init();

    int frame_counter = 0;    // As a timer for animations :3

    bn::vector<bn::sprite_ptr, 26>        global_player_spr;        
    bn::vector<bn::sprite_ptr, 100>       global_spr;               
    bn::vector<bn::regular_bg_ptr, 4>     global_bgs;           

    Global_VRAM VRAM = allocate_VRAM(global_player_spr, global_spr, global_bgs);

    Global_VRAM* vram_ptr;

    vram_ptr = &VRAM;

    int start_frame_counter = 0;
    int intro_scene_is_playing = 1;

    // rra::stage_init(vram_ptr);

    while(true)
    {
        if (intro_scene_is_playing){
            intro_scene_is_playing = rra::display_main_menu(vram_ptr, start_frame_counter);
            start_frame_counter++;
        } else {
            rra::game::handle_frame(vram_ptr, frame_counter);
        }
        
    
        if (bn::keypad::select_pressed()){

            BN_LOG("    ");
            BN_LOG("frame_counter: ");
            BN_LOG(frame_counter);
            BN_LOG("vv ----------- VRAM ---------- vv");
            BN_LOG("current vector size:    ", vram_ptr->global_player_sprites.size(), "   ", vram_ptr->global_sprites.size(), "   ", vram_ptr->global_backgrounds.size());
            BN_LOG("max vector size:    ", vram_ptr->global_player_sprites.max_size(), "   ", vram_ptr->global_sprites.max_size(), "   ", vram_ptr->global_backgrounds.max_size());
            BN_LOG("---------------------------------");

        }

        
        frame_counter++;
        bn::core::update();
    }
}
