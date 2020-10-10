#pragma once

#include <world/block.h>
#include <memory>
#include <unordered_map>

namespace World {

struct ChunkPos {
    int64_t x;
    int64_t z;

    bool operator==(const ChunkPos &other) const {
        return x == other.x && z == other.z;
    }
};

}

namespace std {
  template <>
  struct hash<World::ChunkPos> {
      std::size_t operator()(const World::ChunkPos& k) const {
          using std::size_t;
          using std::int64_t;
          return hash<int64_t>{}(k.x ^ k.z) ^ hash<int64_t>{}(k.x);
      }
  };
}

namespace World {

template<typename A, typename B>
constexpr auto mod(A a, B b) {
    return (a % b + b) % b;
}
struct BlockPos;

class Chunk {
public:
    Chunk(const ChunkPos &);

    void draw(const ResourcePack&) const;
    const ChunkPos &pos() const { return position; }
    blockid_t& operator[](const BlockPos&);
    const blockid_t& operator[](const BlockPos&) const;
    void set_block(const BlockPos&, blockid_t);

    static constexpr int width = 16;
    static constexpr int height = 256;
    static constexpr int depth = 16;
private:
    ChunkPos position;
    blockid_t block_data[width][height][depth];
};

struct BlockPos {
    int64_t x;
    int64_t y;
    int64_t z;

    ChunkPos chunk_pos() const {
        return {x/Chunk::width, z/Chunk::depth};
    }

    BlockPos chunk_relative() const {
        return {mod(x, Chunk::width), y, mod(z, Chunk::depth)};
    }
};

class ChunkManager;

class ChunkLoader {
public:
    virtual void request_chunk(const ChunkPos& chunk) = 0;
    void set_chunk_manager(ChunkManager* cm) { m_chunk_manager = cm; }
    ChunkManager& chunk_manager() { return *m_chunk_manager; }
private:
    ChunkManager* m_chunk_manager;
};

class ChunkManager {
public:
    ChunkManager(const ResourcePack&, ChunkLoader&);
    void draw(const ChunkPos& position);

    void set_render_distance(int r) { render_distance = r; }
    void add_chunk(const ChunkPos &,std::unique_ptr<Chunk>);

    blockid_t operator[](const BlockPos&) const;
private:
    ChunkLoader& chunk_loader;
    const ResourcePack& resource_pack;
    int render_distance { 2 };
    std::unordered_map<ChunkPos, std::unique_ptr<Chunk>> chunks;
};

}
