#ifndef BN_SPRITE_ITEMS_REIMU_JUMP_SPRITESHEET_H
#define BN_SPRITE_ITEMS_REIMU_JUMP_SPRITESHEET_H

#include "bn_sprite_item.h"

//{{BLOCK(reimu_jump_spritesheet_bn_gfx)

//======================================================================
//
//	reimu_jump_spritesheet_bn_gfx, 32x64@4, 
//	+ palette 16 entries, not compressed
//	+ 32 tiles Metatiled by 4x4 not compressed
//	Total size: 32 + 1024 = 1056
//
//	Time-stamp: 2025-08-28, 16:15:12
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_REIMU_JUMP_SPRITESHEET_BN_GFX_H
#define GRIT_REIMU_JUMP_SPRITESHEET_BN_GFX_H

#define reimu_jump_spritesheet_bn_gfxTilesLen 1024
extern const bn::tile reimu_jump_spritesheet_bn_gfxTiles[32];

#define reimu_jump_spritesheet_bn_gfxPalLen 32
extern const bn::color reimu_jump_spritesheet_bn_gfxPal[16];

#endif // GRIT_REIMU_JUMP_SPRITESHEET_BN_GFX_H

//}}BLOCK(reimu_jump_spritesheet_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item reimu_jump_spritesheet(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(reimu_jump_spritesheet_bn_gfxTiles, 32), bpp_mode::BPP_4, compression_type::NONE, 2), 
            sprite_palette_item(span<const color>(reimu_jump_spritesheet_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

