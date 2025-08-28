#ifndef BN_REGULAR_BG_ITEMS_SCREEN2N_H
#define BN_REGULAR_BG_ITEMS_SCREEN2N_H

#include "bn_regular_bg_item.h"

//{{BLOCK(screen2n_bn_gfx)

//======================================================================
//
//	screen2n_bn_gfx, 256x256@8, 
//	+ palette 80 entries, not compressed
//	+ 22 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 160 + 1408 + 2048 = 3616
//
//	Time-stamp: 2025-08-28, 16:15:12
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SCREEN2N_BN_GFX_H
#define GRIT_SCREEN2N_BN_GFX_H

#define screen2n_bn_gfxTilesLen 1408
extern const bn::tile screen2n_bn_gfxTiles[44];

#define screen2n_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell screen2n_bn_gfxMap[1024];

#define screen2n_bn_gfxPalLen 160
extern const bn::color screen2n_bn_gfxPal[80];

#endif // GRIT_SCREEN2N_BN_GFX_H

//}}BLOCK(screen2n_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item screen2n(
            regular_bg_tiles_item(span<const tile>(screen2n_bn_gfxTiles, 44), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(screen2n_bn_gfxPal, 80), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(screen2n_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

