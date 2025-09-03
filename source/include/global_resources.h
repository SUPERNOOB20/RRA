#include <bn_vector.h>
#include <bn_sprite_ptr.h>
#include <bn_regular_bg_ptr.h>

struct global_resources
{
    bn::vector<bn::sprite_ptr, 27>        global_player_sprites;        
    bn::vector<bn::sprite_ptr, 100>       global_sprites;               
    bn::vector<bn::regular_bg_ptr, 4>     global_backgrounds;           
};