#include "worldgen.h"

namespace WorldGen {
World test1() {
    World world;

    world.setBlock(2, 18, 1, 16);
    world.setBlock(2, 18, 2, 16);
    world.setBlock(2, 18, 3, 16);
    world.setBlock(2, 18, 1, 17);
    world.setBlock(2, 18, 2, 17);
    world.setBlock(2, 18, 1, 18);


    int bound = 32;
    for (int x = 0; x < bound; x++) {
        for (int z = 0; z < bound; z++) {
            world.setBlock(1, x, 0, z);
        }
    }

    return world;
}

};
