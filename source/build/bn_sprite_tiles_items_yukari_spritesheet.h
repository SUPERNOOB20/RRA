#ifndef BN_SPRITE_TILES_ITEMS_YUKARI_SPRITESHEET_H
#define BN_SPRITE_TILES_ITEMS_YUKARI_SPRITESHEET_H

#include "bn_sprite_tiles_item.h"
#include "bn_sprite_shape_size.h"

//{{BLOCK(yukari_spritesheet_bn_gfx)

//======================================================================
//
//	yukari_spritesheet_bn_gfx, 64x192@8, 
//	+ 192 tiles Metatiled by 8x8 not compressed
//	Total size: 12288 = 12288
//
//	Time-stamp: 2025-08-24, 14:31:07
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_YUKARI_SPRITESHEET_BN_GFX_H
#define GRIT_YUKARI_SPRITESHEET_BN_GFX_H

#define yukari_spritesheet_bn_gfxTilesLen 12288
extern const bn::tile yukari_spritesheet_bn_gfxTiles[384];

#endif // GRIT_YUKARI_SPRITESHEET_BN_GFX_H

//}}BLOCK(yukari_spritesheet_bn_gfx)

namespace bn::sprite_tiles_items
{
    constexpr inline sprite_tiles_item yukari_spritesheet(span<const tile>(yukari_spritesheet_bn_gfxTiles, 384), 
            bpp_mode::BPP_8, compression_type::NONE, 3);

    constexpr inline sprite_shape_size yukari_spritesheet_shape_size(sprite_shape::SQUARE, sprite_size::HUGE);
}

#endif

