#ifndef BN_REGULAR_BG_ITEMS_SCREEN1N_H
#define BN_REGULAR_BG_ITEMS_SCREEN1N_H

#include "bn_regular_bg_item.h"

//{{BLOCK(screen1n_bn_gfx)

//======================================================================
//
//	screen1n_bn_gfx, 256x256@8, 
//	+ palette 80 entries, not compressed
//	+ 9 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 160 + 576 + 2048 = 2784
//
//	Time-stamp: 2025-08-28, 15:22:03
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SCREEN1N_BN_GFX_H
#define GRIT_SCREEN1N_BN_GFX_H

#define screen1n_bn_gfxTilesLen 576
extern const bn::tile screen1n_bn_gfxTiles[18];

#define screen1n_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell screen1n_bn_gfxMap[1024];

#define screen1n_bn_gfxPalLen 160
extern const bn::color screen1n_bn_gfxPal[80];

#endif // GRIT_SCREEN1N_BN_GFX_H

//}}BLOCK(screen1n_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item screen1n(
            regular_bg_tiles_item(span<const tile>(screen1n_bn_gfxTiles, 18), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(screen1n_bn_gfxPal, 80), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(screen1n_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

