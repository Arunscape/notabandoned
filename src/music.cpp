#include "music.h"
#include <fstream>
#include <iostream>

Asound::Asound() {
  std::ifstream file(MUSIC_CONFIG_PATH + "config.json");

  if (!file.is_open()) {
    std::cerr << "Failed to open config file for music" << std::endl;
    exit(1);
  }

  file >> config;

  for (auto &[k, v] : config.items()){
    std::cout << "Read sound key: " << k << " val: " << v << std::endl;
    std::string s = MUSIC_CONFIG_PATH + std::string(v);
    sounds.emplace(k, s);
  }
}

Asound::~Asound() {}

void Asound::play(std::string sound){
  sounds[sound].Play();
}

void Asound::pause(std::string sound) {
  sounds[sound].Pause();
}

void Asound::resume(std::string sound) {
  sounds[sound].Resume();
}

void Asound::stop(std::string sound){
  sounds[sound].Stop();
}

void Asound::play_multi(std::string sound){
  sounds[sound].PlayMulti();
}

void Asound::stop_multi(std::string sound){
  sounds[sound].StopMulti();
}

void Asound::set_pitch(std::string sound, float pitch){
  sounds[sound].SetPitch(pitch);
}

void Asound::set_volume(std::string sound, float volume){
  sounds[sound].SetVolume(volume);
}

bool Asound::is_playing(std::string sound){
  return sounds[sound].IsPlaying();
}

unsigned int Asound::get_sample_count(std::string sound){
  return sounds[sound].GetSampleCount();
}

void Asound::set_sample_count(std::string sound, unsigned int value){
  sounds[sound].SetSampleCount(value);
}

raylib::AudioStream Asound::get_audio_stream(std::string sound){
  return sounds[sound].GetStream();
}

void Asound::set_audio_stream(std::string sound, raylib::AudioStream value){
  sounds[sound].SetStream(value);
}

void Asound::unload(std::string sound){
  sounds[sound].Unload();
}

void Asound::update(std::string sound, const void* data, int sample_count){
  sounds[sound].Update(data, sample_count);
}

void Asound::set(std::string sound, raylib::Sound rsound){
  sounds[sound].set(rsound);
}
