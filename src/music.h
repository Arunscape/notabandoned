#include "raylib-cpp.hpp"
#include <memory>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>

const std::string MUSIC_CONFIG_PATH = "../assets/music/";

class Asound {
  nlohmann::json config;
  std::unordered_map<std::string, raylib::Sound> sounds;

public:
  Asound();
  ~Asound();
  void play(std::string sound);
  void pause(std::string sound);
  void resume(std::string sound);
  void stop(std::string sound);
  void play_multi(std::string sound);
  void stop_multi(std::string sound);
  void set_pitch(std::string sound, float pitch);
  void set_volume(std::string sound, float volume);
  bool is_playing(std::string sound);
  unsigned int get_sample_count(std::string sound);
  void set_sample_count(std::string sound, unsigned int value);
  raylib::AudioStream get_audio_stream(std::string sound);
  void set_audio_stream(std::string sound, raylib::AudioStream value);
  void unload(std::string sound);
  void set(std::string sound, raylib::Sound rsound);
  void update(std::string sound, const void* data, int sample_count);


};
