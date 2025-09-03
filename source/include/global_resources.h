#include <bn_vector.h>
#include <bn_sprite_ptr.h>
#include <bn_regular_bg_ptr.h>

template<typename Type, int MaxSize>
bn::vector<bn::sprite_ptr, 1> pepe; 

struct global_VRAM {
    
    // template<typename Type, int MaxSize>

    bn::vector<bn::sprite_ptr, 26>      global_player_sprites;         // Idling, jumping, dashing should be available in all levels!
    bn::vector<bn::sprite_ptr, 100>     global_sprites;               // 128 is the maximum number of sprites that can fit in the GBA's VRAM. But I'm padding 26 here for the player's sprites. And leaving 1 extra, unused slot just in case :P
    bn::vector<bn::regular_bg_ptr, 4>   global_backgrounds;         // 4 is the maximum number of backgrounds that can fit in the GBA's VRAM.
};


// global_VRAM initializer.
// "This trick only works once"- lest the GBA might crash!
struct global_VRAM allocate_VRAM(bn::vector<bn::sprite_ptr, 26> global_player_sprites, bn::vector<bn::sprite_ptr, 100> global_sprites, bn::vector<bn::regular_bg_ptr, 4> global_backgrounds);