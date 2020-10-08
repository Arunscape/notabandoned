#include "raylib-cpp.hpp"
#include <nlohmann/json.hpp>
#include <string>

const std::string CONFIG_PATH =  "../assets/music/";

class Sounds {
  nlohmann::json config;
  raylib::AudioDevice ad; // do I need to call its constructor to initialize it
                          // or is it implicit?

  raylib::Sound walk;
  raylib::Music menu;

public:
  Sounds();
  ~Sounds();
  void walk_sound();
  void stop_walk_sound();
  void menu_loop();
  void stop_menu_loop();
};
