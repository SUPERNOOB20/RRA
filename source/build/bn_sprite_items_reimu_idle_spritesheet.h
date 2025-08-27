#ifndef BN_SPRITE_ITEMS_REIMU_IDLE_SPRITESHEET_H
#define BN_SPRITE_ITEMS_REIMU_IDLE_SPRITESHEET_H

#include "bn_sprite_item.h"

//{{BLOCK(reimu_idle_spritesheet_bn_gfx)

//======================================================================
//
//	reimu_idle_spritesheet_bn_gfx, 32x96@8, 
//	+ palette 32 entries, not compressed
//	+ 48 tiles Metatiled by 4x4 not compressed
//	Total size: 64 + 3072 = 3136
//
//	Time-stamp: 2025-08-26, 21:49:38
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_REIMU_IDLE_SPRITESHEET_BN_GFX_H
#define GRIT_REIMU_IDLE_SPRITESHEET_BN_GFX_H

#define reimu_idle_spritesheet_bn_gfxTilesLen 3072
extern const bn::tile reimu_idle_spritesheet_bn_gfxTiles[96];

#define reimu_idle_spritesheet_bn_gfxPalLen 64
extern const bn::color reimu_idle_spritesheet_bn_gfxPal[32];

#endif // GRIT_REIMU_IDLE_SPRITESHEET_BN_GFX_H

//}}BLOCK(reimu_idle_spritesheet_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item reimu_idle_spritesheet(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(reimu_idle_spritesheet_bn_gfxTiles, 96), bpp_mode::BPP_8, compression_type::NONE, 3), 
            sprite_palette_item(span<const color>(reimu_idle_spritesheet_bn_gfxPal, 32), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

