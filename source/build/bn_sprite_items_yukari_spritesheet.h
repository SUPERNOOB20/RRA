#ifndef BN_SPRITE_ITEMS_YUKARI_SPRITESHEET_H
#define BN_SPRITE_ITEMS_YUKARI_SPRITESHEET_H

#include "bn_sprite_item.h"

//{{BLOCK(yukari_spritesheet_bn_gfx)

//======================================================================
//
//	yukari_spritesheet_bn_gfx, 64x192@8, 
//	+ palette 96 entries, not compressed
//	+ 192 tiles Metatiled by 8x8 not compressed
//	Total size: 192 + 12288 = 12480
//
//	Time-stamp: 2025-08-28, 16:05:39
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_YUKARI_SPRITESHEET_BN_GFX_H
#define GRIT_YUKARI_SPRITESHEET_BN_GFX_H

#define yukari_spritesheet_bn_gfxTilesLen 12288
extern const bn::tile yukari_spritesheet_bn_gfxTiles[384];

#define yukari_spritesheet_bn_gfxPalLen 192
extern const bn::color yukari_spritesheet_bn_gfxPal[96];

#endif // GRIT_YUKARI_SPRITESHEET_BN_GFX_H

//}}BLOCK(yukari_spritesheet_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item yukari_spritesheet(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(yukari_spritesheet_bn_gfxTiles, 384), bpp_mode::BPP_8, compression_type::NONE, 3), 
            sprite_palette_item(span<const color>(yukari_spritesheet_bn_gfxPal, 96), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

