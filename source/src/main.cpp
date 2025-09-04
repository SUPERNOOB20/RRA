#include "bn_core.h"
#include <bn_sprites.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_tiles.h>
#include <bn_sprite_tiles_ptr.h>

#include "bn_sprite_item.h"
// #include "bn_sprite_items_ice_block.h"

#include "bn_sprite_items_reimu_idle_spritesheet.h"
#include "bn_sprite_items_reimu_jump_spritesheet.h"

#include "bn_sprite_items_akyuu_spritesheet.h"

#include "bn_sprite_items_fairy.h"

#include <bn_regular_bg_ptr.h>
#include <bn_regular_bg_item.h>

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

// #include <vector>
#include "bn_vector.h"
template<typename Type, int MaxSize>
bn::vector<bn::sprite_ptr, 1>        test;          // sets the template in stone, for later use in main().

int main()
{
    bn::core::init();

    int frame_counter = 0;    // As a timer for animations :3

    bn::vector<bn::sprite_ptr, 26>        global_player_sprites;        
    bn::vector<bn::sprite_ptr, 100>       global_sprites;               
    bn::vector<bn::regular_bg_ptr, 4>     global_backgrounds;           

    Global_VRAM VRAM = allocate_VRAM(global_player_sprites, global_sprites, global_backgrounds);

    Global_VRAM* vram_ptr;

    vram_ptr = &VRAM;





    bn::regular_bg_ptr start_menu_bg = bn::regular_bg_items::reimu_bg.create_bg(8, 48);

    bn::sprite_text_generator text_generator(common::variable_8x8_sprite_font);
    // bn::sprite_text_generator text_generator();

    int start_frame_counter = 0;
    int start = 1;
    while(start)
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
            rra::stage_init(vram_ptr);
            start = 0;
        }

        start_frame_counter++;

        bn::core::update();
    }



    while(true)
    {
        rra::game::handle_frame(vram_ptr, frame_counter);

        frame_counter++;

        bn::core::update();

        if (frame_counter == 1){
            BN_LOG("checkpoint_BB");
        }
    }
}
