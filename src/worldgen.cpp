#include "worldgen.h"

namespace WorldGen {
World test1() {
    World world;

    world.setBlock(2, 2, 1, 0);
    world.setBlock(2, 2, 2, 0);
    world.setBlock(2, 2, 3, 0);
    world.setBlock(2, 2, 1, 1);
    world.setBlock(2, 2, 2, 1);
    world.setBlock(2, 2, 1, 2);


    int bound = 16;
    for (int x = -bound; x < bound; x++) {
        for (int z = -bound; z < bound; z++) {
            world.setBlock(1, x, 0, z);
        }
    }

    return world;
}

};
