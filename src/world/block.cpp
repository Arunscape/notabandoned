#include <world/block.h>

namespace World {

PlainBlock::PlainBlock(const std::string &filename)
    : texture(filename) {}

void PlainBlock::draw_at(Vector3 pos) const {
    // i'm pretty sure they got the constness wrong
    const_cast<PlainBlock *>(this)->texture.Draw(pos, 1, 1, 1, RAYWHITE);
}

const Block &ResourcePack::get_block(blockid_t id) const {
    if (blocks[id]) {
        return *blocks[id];
    } else {
        return *blocks[0];
    }
}

ResourcePack& ResourcePack::set_block(blockid_t id, std::unique_ptr<Block> block) {
    blocks[id] = std::move(block);
    return *this;
}

}
