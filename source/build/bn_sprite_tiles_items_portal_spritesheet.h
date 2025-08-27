#ifndef BN_SPRITE_TILES_ITEMS_PORTAL_SPRITESHEET_H
#define BN_SPRITE_TILES_ITEMS_PORTAL_SPRITESHEET_H

#include "bn_sprite_tiles_item.h"
#include "bn_sprite_shape_size.h"

//{{BLOCK(portal_spritesheet_bn_gfx)

//======================================================================
//
//	portal_spritesheet_bn_gfx, 32x96@4, 
//	+ 48 tiles Metatiled by 4x4 not compressed
//	Total size: 1536 = 1536
//
//	Time-stamp: 2025-08-24, 13:59:37
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PORTAL_SPRITESHEET_BN_GFX_H
#define GRIT_PORTAL_SPRITESHEET_BN_GFX_H

#define portal_spritesheet_bn_gfxTilesLen 1536
extern const bn::tile portal_spritesheet_bn_gfxTiles[48];

#endif // GRIT_PORTAL_SPRITESHEET_BN_GFX_H

//}}BLOCK(portal_spritesheet_bn_gfx)

namespace bn::sprite_tiles_items
{
    constexpr inline sprite_tiles_item portal_spritesheet(span<const tile>(portal_spritesheet_bn_gfxTiles, 48), 
            bpp_mode::BPP_4, compression_type::NONE, 3);

    constexpr inline sprite_shape_size portal_spritesheet_shape_size(sprite_shape::SQUARE, sprite_size::BIG);
}

#endif

