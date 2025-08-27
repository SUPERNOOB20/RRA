#ifndef BN_SPRITE_TILES_ITEMS_CIRNO_SPRITESHEET_H
#define BN_SPRITE_TILES_ITEMS_CIRNO_SPRITESHEET_H

#include "bn_sprite_tiles_item.h"
#include "bn_sprite_shape_size.h"

//{{BLOCK(cirno_spritesheet_bn_gfx)

//======================================================================
//
//	cirno_spritesheet_bn_gfx, 32x128@8, 
//	+ 64 tiles Metatiled by 4x4 not compressed
//	Total size: 4096 = 4096
//
//	Time-stamp: 2025-08-24, 03:22:46
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CIRNO_SPRITESHEET_BN_GFX_H
#define GRIT_CIRNO_SPRITESHEET_BN_GFX_H

#define cirno_spritesheet_bn_gfxTilesLen 4096
extern const bn::tile cirno_spritesheet_bn_gfxTiles[128];

#endif // GRIT_CIRNO_SPRITESHEET_BN_GFX_H

//}}BLOCK(cirno_spritesheet_bn_gfx)

namespace bn::sprite_tiles_items
{
    constexpr inline sprite_tiles_item cirno_spritesheet(span<const tile>(cirno_spritesheet_bn_gfxTiles, 128), 
            bpp_mode::BPP_8, compression_type::NONE, 4);

    constexpr inline sprite_shape_size cirno_spritesheet_shape_size(sprite_shape::SQUARE, sprite_size::BIG);
}

#endif

