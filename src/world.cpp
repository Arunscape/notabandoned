#include "world.h"


World::~World() {
    delete [] blocks;
}
World::World() {
    blocks = new char[WORLD_BLOCKS];
    for (int i = 0; i < WORLD_BLOCKS; i++) {
        blocks[i] = 0;
    }
}

int World::idx(int x, int y, int z) {
    return x + z * WORLD_WIDTH + y * WORLD_WIDTH * WORLD_DEPTH;
}

void World::setBlock(char id, int x, int y, int z) {
    blocks[idx(x, y, z)] = id;
}


char World::getBlock(int x, int y, int z) {
    return blocks[idx(x, y, z)];
}

char World::getBlockIdx(int idx) {
    return blocks[idx];
}
