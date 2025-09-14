#ifndef PLAYER_PROJECTILES_H
#define PLAYER_PROJECTILES_H

class Player_Projectile
{
    private:
        bool m_facing_right {};
        int m_anim_state {0};

    public:
        Player_Projectile(bool facing_right, int anim_state);

        void Spawn_Projectile(bool facing_right);
        void Set_Projectile_Anim_State(int anim_state);
};

#endif