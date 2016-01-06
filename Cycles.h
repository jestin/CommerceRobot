#ifndef CYCLES_H
#define CYCLES_H

#define UP_DOWN_POSITIONS 2
#define UP_DOWN_1 2, 0, 2, 0, 2, 0, 2, 0
#define UP_DOWN_2 2, 2, 2, 2, 2, 2, 2, 2
#define UP_DOWN_CYCLE {UP_DOWN_1, UP_DOWN_2}

#define WALK_POSITIONS 4                 // number of positions in this cycle
#define WALK_1 2, 0, 2, 0, 2, 2, 2, 2    // front legs down, back legs up, crouucing forward
#define WALK_2 2, 0, 2, 0, 2, 2, 2, 0    // lift back leg up
#define WALK_3 2, 0, 2, 0, 2, 2, 3, 0    // swing back leg forward
#define WALK_4 2, 0, 2, 0, 2, 2, 3, 2    // black back leg down
#define WALK_CYCLE {WALK_1, WALK_2, WALK_3, WALK_4}

#endif
