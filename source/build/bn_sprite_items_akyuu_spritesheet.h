#ifndef BN_SPRITE_ITEMS_AKYUU_SPRITESHEET_H
#define BN_SPRITE_ITEMS_AKYUU_SPRITESHEET_H

#include "bn_sprite_item.h"

//{{BLOCK(akyuu_spritesheet_bn_gfx)

//======================================================================
//
//	akyuu_spritesheet_bn_gfx, 32x64@8, 
//	+ palette 48 entries, not compressed
//	+ 32 tiles Metatiled by 4x4 not compressed
//	Total size: 96 + 2048 = 2144
//
//	Time-stamp: 2025-08-27, 03:04:54
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_AKYUU_SPRITESHEET_BN_GFX_H
#define GRIT_AKYUU_SPRITESHEET_BN_GFX_H

#define akyuu_spritesheet_bn_gfxTilesLen 2048
extern const bn::tile akyuu_spritesheet_bn_gfxTiles[64];

#define akyuu_spritesheet_bn_gfxPalLen 96
extern const bn::color akyuu_spritesheet_bn_gfxPal[48];

#endif // GRIT_AKYUU_SPRITESHEET_BN_GFX_H

//}}BLOCK(akyuu_spritesheet_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item akyuu_spritesheet(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(akyuu_spritesheet_bn_gfxTiles, 64), bpp_mode::BPP_8, compression_type::NONE, 2), 
            sprite_palette_item(span<const color>(akyuu_spritesheet_bn_gfxPal, 48), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

