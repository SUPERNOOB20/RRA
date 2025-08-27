#ifndef BN_SPRITE_TILES_ITEMS_REIMU_JUMP_SPRITESHEET_H
#define BN_SPRITE_TILES_ITEMS_REIMU_JUMP_SPRITESHEET_H

#include "bn_sprite_tiles_item.h"
#include "bn_sprite_shape_size.h"

//{{BLOCK(reimu_jump_spritesheet_bn_gfx)

//======================================================================
//
//	reimu_jump_spritesheet_bn_gfx, 32x64@4, 
//	+ 32 tiles Metatiled by 4x4 not compressed
//	Total size: 1024 = 1024
//
//	Time-stamp: 2025-08-24, 14:31:07
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_REIMU_JUMP_SPRITESHEET_BN_GFX_H
#define GRIT_REIMU_JUMP_SPRITESHEET_BN_GFX_H

#define reimu_jump_spritesheet_bn_gfxTilesLen 1024
extern const bn::tile reimu_jump_spritesheet_bn_gfxTiles[32];

#endif // GRIT_REIMU_JUMP_SPRITESHEET_BN_GFX_H

//}}BLOCK(reimu_jump_spritesheet_bn_gfx)

namespace bn::sprite_tiles_items
{
    constexpr inline sprite_tiles_item reimu_jump_spritesheet(span<const tile>(reimu_jump_spritesheet_bn_gfxTiles, 32), 
            bpp_mode::BPP_4, compression_type::NONE, 2);

    constexpr inline sprite_shape_size reimu_jump_spritesheet_shape_size(sprite_shape::SQUARE, sprite_size::BIG);
}

#endif

