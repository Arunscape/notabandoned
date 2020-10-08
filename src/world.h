#pragma once


#define WORLD_WIDTH  32
#define WORLD_HEIGHT 8
#define WORLD_DEPTH  32
#define WORLD_BLOCKS  WORLD_WIDTH * WORLD_HEIGHT * WORLD_DEPTH

// blocks are from 0 -> (WORLD_SIZE-1)
// just ids are stored
class World {
    char* blocks;

    int idx(int x, int y, int z);

    public:
    World();
    ~World();
    void setBlock(char id, int x, int y, int z);
    char getBlock(int x, int y, int z);
    char getBlockIdx(int idx); // TODO: Replace with an iterator or something
};
