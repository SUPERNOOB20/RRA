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
#include "game.h"

#include "global_resources.h"

#include "bn_keypad.h"

#include "bn_sprite_text_generator.h"

#include "bn_display.h"

#include "bn_math.h"

#include "fixed_32x64_sprite_font.h"

#include "bn_sprite_items_variable_8x16_font_red.h"
// #include "bn_sprite_items_variable_8x16_font_blue.h"
// #include "bn_sprite_items_variable_8x16_font_yellow.h"

#include "common_fixed_8x8_sprite_font.h"
#include "common_fixed_8x16_sprite_font.h"
#include "common_variable_8x8_sprite_font.h"
#include "common_variable_8x16_sprite_font.h"

#include "bn_regular_bg_items_reimu_bg.h"

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





    bn::regular_bg_ptr start_menu_bg = bn::regular_bg_items::reimu_bg.create_bg(8, 48);
    vram_ptr->global_backgrounds.push_back(start_menu_bg);

    bn::sprite_text_generator text_generator(common::variable_8x8_sprite_font);
    // bn::sprite_text_generator text_generator();

    int start_frame_counter = 0;
    int intro_scene_is_playing = 1;
    while(intro_scene_is_playing)
    {
        // Play main menu, intro scene... etc.

        bn::vector<bn::sprite_ptr, 12> text_sprites;

        text_generator.generate(0, 70, "Press Start", text_sprites);
        text_generator.set_center_alignment();

        // text_sprites.set_visible(true)
        if ((start_frame_counter % 90) < 40){
            // text_sprites.set_visible(false);
            text_sprites.clear();
        }
        
        if (bn::keypad::start_pressed()){
            // bn::regular_bg_ptr ~regular_bg_ptr();
            // rra::stage_init(vram_ptr);

            BN_LOG("    ");
            BN_LOG("frame_counter: ");
            BN_LOG(frame_counter);
            BN_LOG("vv ----------- VRAM ---------- vv");
            BN_LOG("current vector size:    ", vram_ptr->global_player_sprites.size(), "   ", vram_ptr->global_sprites.size(), "   ", vram_ptr->global_backgrounds.size());
            BN_LOG("max vector size:    ", vram_ptr->global_player_sprites.max_size(), "   ", vram_ptr->global_sprites.max_size(), "   ", vram_ptr->global_backgrounds.max_size());
            BN_LOG("---------------------------------");

            // bn::regular_bg_ptr level_layout = bn::regular_bg_items::screen1n.create_bg(8, 48);

            // bn::sprite_palette_item& palette_item = bn::sprite_items::screen1n.palette_item();

            // bn::bg_palette_ptr bg_palette = start_menu_bg.palette();
            // bg_palette.set_colors(palette_item);

            /*
            bn::regular_bg_item reimu_bg(
            regular_bg_tiles_item(span<const tile>(screen21n_bn_gfxTiles, 874), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(screen21n_bn_gfxPal, 80), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(screen21n_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
            */

            vram_ptr->global_backgrounds.pop_back();

            intro_scene_is_playing = 0;

            // template<typename regular_bg_ptr>
            // bn::default_delete operator()(bn::regular_bg_ptr* start_menu_bg);

            bn::core::update();

            break;
        }

        start_frame_counter++;

        if ((bn::keypad::start_pressed()) || (bn::keypad::start_pressed())){
            BN_LOG("you shall not log!");
        }

        bn::core::update();
    }

    rra::stage_init(vram_ptr);

    while(true)
    {
        rra::game::handle_frame(vram_ptr, frame_counter);

        frame_counter++;

        bn::core::update();
    }
}
