#ifndef BN_SPRITE_ITEMS_REIMU_IDLE_SPRITESHEET_H
#define BN_SPRITE_ITEMS_REIMU_IDLE_SPRITESHEET_H

#include "bn_sprite_item.h"

//{{BLOCK(reimu_idle_spritesheet_bn_gfx)

//======================================================================
//
//	reimu_idle_spritesheet_bn_gfx, 32x96@4, 
//	+ palette 16 entries, not compressed
//	+ 48 tiles Metatiled by 4x4 not compressed
//	Total size: 32 + 1536 = 1568
//
//	Time-stamp: 2025-08-27, 20:43:39
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_REIMU_IDLE_SPRITESHEET_BN_GFX_H
#define GRIT_REIMU_IDLE_SPRITESHEET_BN_GFX_H

#define reimu_idle_spritesheet_bn_gfxTilesLen 1536
extern const bn::tile reimu_idle_spritesheet_bn_gfxTiles[48];

#define reimu_idle_spritesheet_bn_gfxPalLen 32
extern const bn::color reimu_idle_spritesheet_bn_gfxPal[16];

#endif // GRIT_REIMU_IDLE_SPRITESHEET_BN_GFX_H

//}}BLOCK(reimu_idle_spritesheet_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item reimu_idle_spritesheet(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(reimu_idle_spritesheet_bn_gfxTiles, 48), bpp_mode::BPP_4, compression_type::NONE, 3), 
            sprite_palette_item(span<const color>(reimu_idle_spritesheet_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

