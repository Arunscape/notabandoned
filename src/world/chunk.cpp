#include <world/chunk.h>
#include <iostream>
#include <cstring>

namespace World {

Chunk::Chunk(const ChunkPos &position): position(position) {
    memset(block_data, 0, sizeof(block_data));
}

void Chunk::draw(const ResourcePack& resources) const {
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            for (int z = 0; z < depth; ++z) {
                resources.get_block(block_data[x][y][z]).draw_at(
                    { float(x + position.x*width),
                      float(y),
                      float(z + position.z*depth) });
            }
        }
    }
}

blockid_t& Chunk::operator[](const BlockPos& pos) {
    return block_data[pos.x][pos.y][pos.z];
}

const blockid_t& Chunk::operator[](const BlockPos& pos) const {
    return block_data[pos.x][pos.y][pos.z];
}

void Chunk::set_block(const BlockPos& pos, blockid_t bid) {
    (*this)[pos] = bid;
}

ChunkManager::ChunkManager(const ResourcePack& rp, ChunkLoader& cl)
    : resource_pack(rp), chunk_loader(cl) {
    cl.set_chunk_manager(this);
}

void ChunkManager::add_chunk(const ChunkPos &pos, std::unique_ptr<Chunk> chunk) {
    chunks[pos] = move(chunk);
}

void ChunkManager::draw(const ChunkPos& position) {

    for (int x = position.x-render_distance; x < position.x+render_distance; ++x) {
        for (int z = position.z-render_distance; z < position.z+render_distance; ++z) {
            ChunkPos cpos = { x, z };
            if (chunks.find(cpos) != chunks.end()) {
                if (chunks[cpos]) {
                    chunks[cpos]->draw(resource_pack);
                }
            } else {
                chunk_loader.request_chunk(cpos);
            }
        }
    }
}

blockid_t ChunkManager::operator[](const BlockPos& block) const
{
    const auto& chunk = chunks.find(block.chunk_pos());
    if (chunk == chunks.end() && chunk->second == nullptr) {
        return 0;
    }

    return (*chunk->second)[block.chunk_relative()];
}

}
