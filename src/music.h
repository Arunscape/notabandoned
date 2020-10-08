#include "raylib-cpp.hpp"
#include <memory>
#include <nlohmann/json.hpp>
#include <string>

const std::string MUSIC_CONFIG_PATH =  "../assets/music/";

class Sounds {
  nlohmann::json config;
  //raylib::AudioDevice audio;

  //std::unique_ptr<raylib::Sound> walk;
  std::unique_ptr<raylib::Music> menu; // loops by default

public:
  Sounds();
  ~Sounds();
  void walk_sound();
  void stop_walk_sound();
  void menu_loop();
  void stop_menu_loop();
  void update();
};
