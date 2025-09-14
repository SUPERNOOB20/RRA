class Player_Projectile
{
    private:
        bool m_facing_right {};
        int m_anim_state {0};

    public:
        void Set_Player_Projectile(bool facing_right, int anim_state)
        : m_facing_right{ facing_right };    
        , m_anim_state{ anim_state };
        {
        }
        
};