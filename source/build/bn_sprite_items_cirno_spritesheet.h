#ifndef BN_SPRITE_ITEMS_CIRNO_SPRITESHEET_H
#define BN_SPRITE_ITEMS_CIRNO_SPRITESHEET_H

#include "bn_sprite_item.h"

//{{BLOCK(cirno_spritesheet_bn_gfx)

//======================================================================
//
//	cirno_spritesheet_bn_gfx, 32x128@8, 
//	+ palette 32 entries, not compressed
//	+ 64 tiles Metatiled by 4x4 not compressed
//	Total size: 64 + 4096 = 4160
//
//	Time-stamp: 2025-08-27, 21:27:38
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CIRNO_SPRITESHEET_BN_GFX_H
#define GRIT_CIRNO_SPRITESHEET_BN_GFX_H

#define cirno_spritesheet_bn_gfxTilesLen 4096
extern const bn::tile cirno_spritesheet_bn_gfxTiles[128];

#define cirno_spritesheet_bn_gfxPalLen 64
extern const bn::color cirno_spritesheet_bn_gfxPal[32];

#endif // GRIT_CIRNO_SPRITESHEET_BN_GFX_H

//}}BLOCK(cirno_spritesheet_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item cirno_spritesheet(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(cirno_spritesheet_bn_gfxTiles, 128), bpp_mode::BPP_8, compression_type::NONE, 4), 
            sprite_palette_item(span<const color>(cirno_spritesheet_bn_gfxPal, 32), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

