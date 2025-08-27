#ifndef BN_SPRITE_ITEMS_AKYUU_1_H
#define BN_SPRITE_ITEMS_AKYUU_1_H

#include "bn_sprite_item.h"

//{{BLOCK(akyuu_1_bn_gfx)

//======================================================================
//
//	akyuu_1_bn_gfx, 32x32@8, 
//	+ palette 48 entries, not compressed
//	+ 16 tiles Metatiled by 4x4 not compressed
//	Total size: 96 + 1024 = 1120
//
//	Time-stamp: 2025-08-26, 21:44:41
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_AKYUU_1_BN_GFX_H
#define GRIT_AKYUU_1_BN_GFX_H

#define akyuu_1_bn_gfxTilesLen 1024
extern const bn::tile akyuu_1_bn_gfxTiles[32];

#define akyuu_1_bn_gfxPalLen 96
extern const bn::color akyuu_1_bn_gfxPal[48];

#endif // GRIT_AKYUU_1_BN_GFX_H

//}}BLOCK(akyuu_1_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item akyuu_1(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(akyuu_1_bn_gfxTiles, 32), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(akyuu_1_bn_gfxPal, 48), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

