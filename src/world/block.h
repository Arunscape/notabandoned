#pragma once

#include <cstdint>
#include <raylib-cpp.hpp>
#include <memory>
#include <climits>

namespace World {

typedef uint8_t blockid_t;

class Block {
public:
    virtual ~Block() {}
    virtual void draw_at(Vector3) const = 0;
    virtual bool is_hard() const = 0;
};

class PlainBlock : public Block {
public:
    PlainBlock(const std::string &filename);
    virtual ~PlainBlock() {}
    virtual void draw_at(Vector3) const;
    virtual bool is_hard() const { return true; }
private:
    raylib::Texture2D texture;
};

class AirBlock : public Block {
public:
    virtual ~AirBlock() {}
    virtual void draw_at(Vector3) const {}
    virtual bool is_hard() const { return false; }
private:
};

class ResourcePack {
public:
    const Block &get_block(blockid_t) const;
    ResourcePack &set_block(blockid_t id, std::unique_ptr<Block> block);
private:
    std::unique_ptr<Block> blocks[1 << (sizeof(blockid_t)*CHAR_BIT)];
};

}
