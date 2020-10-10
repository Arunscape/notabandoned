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

  for (auto &[k, v] : config.items()) {
    std::cout << "Read sound key: " << k << " val: " << v << std::endl;
    std::string s = MUSIC_CONFIG_PATH + std::string(v);
    sounds.emplace(k, s);
  }
}

Asound::~Asound() {}

raylib::Sound &Asound::play(const std::string sound) {
  return (*this)[sound].Play();
}

raylib::Sound &Asound::pause(const std::string &sound) {
  return (*this)[sound].Pause();
}

raylib::Sound &Asound::resume(const std::string &sound) {
  return (*this)[sound].Resume();
}

raylib::Sound &Asound::stop(const std::string &sound) {
  return (*this)[sound].Stop();
}

raylib::Sound &Asound::play_multi(const std::string &sound) {
  return (*this)[sound].PlayMulti();
}

raylib::Sound &Asound::stop_multi(const std::string &sound) {
  return (*this)[sound].StopMulti();
}

raylib::Sound &Asound::set_pitch(const std::string &sound, float pitch) {
  return (*this)[sound].SetPitch(pitch);
}

raylib::Sound &Asound::set_volume(const std::string &sound, float volume) {
  return (*this)[sound].SetVolume(volume);
}

bool Asound::is_playing(const std::string &sound) {
  return (*this)[sound].IsPlaying();
}

unsigned int Asound::get_sample_count(const std::string &sound) {
  return (*this)[sound].GetSampleCount();
}

void Asound::set_sample_count(const std::string &sound, unsigned int value) {
  (*this)[sound].SetSampleCount(value);
}

raylib::AudioStream Asound::get_audio_stream(const std::string &sound) {
  return (*this)[sound].GetStream();
}

void Asound::set_audio_stream(const std::string &sound,
                              raylib::AudioStream value) {
  (*this)[sound].SetStream(value);
}

void Asound::unload(const std::string &sound) { (*this)[sound].Unload(); }

raylib::Sound &Asound::update(const std::string &sound, const void *data,
                              int sample_count) {
  return (*this)[sound].Update(data, sample_count);
}

void Asound::set(const std::string &sound, raylib::Sound rsound) {
  (*this)[sound].set(rsound);
}

raylib::Sound &Asound::operator[](const std::string &sound) {
  if (sounds.find(sound) == sounds.end())
    throw std::runtime_error("sound not found");

  return sounds.find(sound)->second;
}
