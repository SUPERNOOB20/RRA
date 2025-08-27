#ifndef BN_SPRITE_ITEMS_ICE_BLOCK_H
#define BN_SPRITE_ITEMS_ICE_BLOCK_H

#include "bn_sprite_item.h"

//{{BLOCK(ice_block_bn_gfx)

//======================================================================
//
//	ice_block_bn_gfx, 32x32@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles Metatiled by 4x4 not compressed
//	Total size: 32 + 512 = 544
//
//	Time-stamp: 2025-08-27, 13:29:15
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ICE_BLOCK_BN_GFX_H
#define GRIT_ICE_BLOCK_BN_GFX_H

#define ice_block_bn_gfxTilesLen 512
extern const bn::tile ice_block_bn_gfxTiles[16];

#define ice_block_bn_gfxPalLen 32
extern const bn::color ice_block_bn_gfxPal[16];

#endif // GRIT_ICE_BLOCK_BN_GFX_H

//}}BLOCK(ice_block_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item ice_block(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(ice_block_bn_gfxTiles, 16), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(ice_block_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

