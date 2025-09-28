#include "bn_vector.h"
#include "global_resources.h"
#include "stage_init.h"

#include "sprite_animations.h"

#include "bn_regular_bg_items_screen0.h"

#include "bn_log.h"

namespace rra
{
namespace stage0
{

    void load_stage(Global_VRAM* VRAM) {

        rra::stage_init(VRAM);   // Resets all backgrounds and non-player sprites

        bn::regular_bg_ptr level_layout = bn::regular_bg_items::screen0.create_bg(8, 48);
                
        VRAM->global_backgrounds.push_back(level_layout);
        
        

        return;
    }
}
}