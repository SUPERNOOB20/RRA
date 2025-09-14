#include "player_projectiles.h"

Player_Projectile::Player_Projectile(bool facing_right, int anim_state)
    : m_facing_right { facing_right }
    , m_anim_state   { anim_state }
{
}

void Player_Projectile::spawn_projectile(bool facing_right)
{
    m_facing_right = facing_right;
}

void Player_Projectile::set_projectile_anim_state(int anim_state)
{
    m_anim_state = anim_state;
}