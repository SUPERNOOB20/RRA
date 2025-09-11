#include "bn_log.h"
#include "bn_vector.h"

#include "fixed_32x64_sprite_font.h"

#include "bn_sprite_items_variable_8x16_font_red.h"
// #include "bn_sprite_items_variable_8x16_font_blue.h"
// #include "bn_sprite_items_variable_8x16_font_yellow.h"

#include "common_fixed_8x8_sprite_font.h"
#include "common_fixed_8x16_sprite_font.h"
#include "common_variable_8x8_sprite_font.h"
#include "common_variable_8x16_sprite_font.h"

#include "bn_keypad.h"

#include "bn_sprite_text_generator.h"

#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_item.h"

#include "bn_regular_bg_items_reimu_bg.h"
#include "bn_regular_bg_items_empty_bg.h"

#include "global_resources.h"
#include "main_menu.h"

int intro_scene_is_playing = 1;

namespace rra
{

// Plays intro scene, main menu... etc.
int display_main_menu(Global_VRAM* VRAM, Global_Texts* text_sprites, int start_frame_counter){

    text_sprites->text_sprites.clear();
    
    bn::regular_bg_ptr start_menu_bg = bn::regular_bg_items::reimu_bg.create_bg(8, 48);
    
    if (start_frame_counter == 0){
        VRAM->global_backgrounds.push_back(start_menu_bg);
    }

    bn::sprite_text_generator text_generator(common::variable_8x8_sprite_font);
    // bn::sprite_text_generator text_generator();

    // bn::vector<bn::sprite_ptr, 12> text_sprites;

    text_generator.generate(0, 70, "Press Start", text_sprites->text_sprites);
    text_generator.set_center_alignment();

    // text_sprites.set_visible(true)
    if ((start_frame_counter % 90) < 40){
        // text_sprites.set_visible(false);
        text_sprites->text_sprites.clear();
    }
    
    if (bn::keypad::start_pressed()){

        VRAM->global_backgrounds.pop_back();        // <--- PLEASE figure a way to pop this from memory without triggering the "vector is empty" error D:

        // This is a temporary workaround to avoid empty global_backgrounds ":3
        bn::regular_bg_ptr empty_background = bn::regular_bg_items::empty_bg.create_bg(8, 48);
        VRAM->global_backgrounds.push_back(empty_background);

        text_sprites->text_sprites.clear();         // No more "Press Start" if the game has already started :3
        intro_scene_is_playing = 0;

    }

    return intro_scene_is_playing;
}

}