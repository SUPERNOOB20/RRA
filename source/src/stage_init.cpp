namespace rra{
    void stage_init(global_resources*) {
        global_resources->global_sprites.clear();          // Clears all non-player sprites in VRAM.
        global_resources->global_backgrounds.clear();       // Resets all backgrounds in VRAM.
    }
}