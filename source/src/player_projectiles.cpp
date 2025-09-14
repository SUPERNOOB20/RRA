#include "player_projectiles.h"

Player_Projectile::Player_Projectile(bool facing_right, int anim_state)
    : m_facing_right { facing_right }
    , m_anim_state   { anim_state }
{
}

void Player_Projectile::Spawn_Projectile(bool facing_right)
{
    m_facing_right = facing_right;
}

void Player_Projectile::Set_Projectile_Anim_State(int anim_state)
{
    m_anim_state = anim_state;
}