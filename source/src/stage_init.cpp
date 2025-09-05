#include <bn_vector.h>
#include "global_resources.h"

#include "stage_init.h"

namespace rra{
    void stage_init(Global_VRAM* VRAM) {
        VRAM->global_sprites.clear();          // Clears all non-player sprites in VRAM.
        VRAM->global_backgrounds.clear();       // Resets all backgrounds in VRAM.

        // BN_CODE_IWRAM void vram_clear();
    }
}