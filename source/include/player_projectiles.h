#ifndef PLAYER_PROJECTILES_H
#define PLAYER_PROJECTILES_H

class Player_Projectile
{
    private:
        bool m_facing_right {};
        int m_anim_state {0};

    public:
        Player_Projectile(bool facing_right, int anim_state);

        void spawn_projectile(bool facing_right);
        void set_projectile_anim_state(int anim_state);
};

#endif