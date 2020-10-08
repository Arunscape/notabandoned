#include "music.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>

Sounds::Sounds() {
  std::ifstream file(std::string(MUSIC_CONFIG_PATH) + std::string("config.json"));

  if (!file.is_open()) {
    std::cerr << "Failed to open config file for music" << std::endl;
    exit(1);
  }

  file >> config;
  
  //walk = std::unique_ptr(raylib::Sound(std::string(CONFIG_PATH) + std::string(config["walk"])));
//  menu = std::make_unique<raylib::Music>(raylib::Music(std::string(CONFIG_PATH) + std::string(config["menu"])));

  std::cout << "Got filename " << config["menu"] << std::endl;

}

//void Sounds::walk_sound() { walk.Play(); }

//void Sounds::stop_walk_sound() { walk.Stop(); }

//void Sounds::menu_loop() { menu->Play(); }

//void Sounds::update(){ menu->Update(); }

//void Sounds::stop_menu_loop() { menu->Stop(); }

Sounds::~Sounds() {}
