reset_vram:
        movs    r3, #192
        movs    r2, #0
        lsls    r3, r3, #19
.L2:
        strh    r2, [r3]
        adds    r3, r3, #2
        b       .L2
