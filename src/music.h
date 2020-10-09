#include "raylib-cpp.hpp"
#include <memory>
#include <nlohmann/json.hpp>
#include <string>

const std::string MUSIC_CONFIG_PATH = "../assets/music/";

class Asound {
  nlohmann::json config;
  std::unique_ptr<raylib::Sound> sound;

public:
  Asound(const std::string sound_str);
  ~Asound();
  raylib::Sound *get();
};
