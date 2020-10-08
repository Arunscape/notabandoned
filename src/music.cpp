#include "music.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

Sounds::Sounds() {
  std::ifstream file(std::string(CONFIG_PATH) + std::string("config.json"));

  if (!file.is_open()) {
    std::cerr << "Failed to open config file for music" << std::endl;
    exit(1);
  }

  file >> config;
  
  walk.set(raylib::Sound(std::string(CONFIG_PATH) + std::string(config["walk"])));
  menu.set(raylib::Music(std::string(CONFIG_PATH) + std::string(config["menu"])));

}

void Sounds::walk_sound() { walk.Play(); }

void Sounds::stop_walk_sound() { walk.Stop(); }

void Sounds::menu_loop() { menu.Play(); }

void Sounds::stop_menu_loop() { menu.Stop(); }

Sounds::~Sounds() {}
