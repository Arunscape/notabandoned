#include "music.h"
#include <fstream>
#include <iostream>

Asound::Asound(std::string sound_str) {
  std::ifstream file(MUSIC_CONFIG_PATH + "config.json");

  if (!file.is_open()) {
    std::cerr << "Failed to open config file for music" << std::endl;
    exit(1);
  }

  file >> config;

  std::cout << "Asound will play " << config[sound_str] << std::endl;
  std::string s = MUSIC_CONFIG_PATH + std::string(config[sound_str]);
  raylib::Sound rs(s);

  sound = std::make_unique<raylib::Sound>(s);
}

Asound::~Asound() {}

raylib::Sound *Asound::get() { return sound.get(); }
