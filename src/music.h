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
  raylib::Sound &play(const std::string &sound);
  raylib::Sound &pause(const std::string &sound);
  raylib::Sound &resume(const std::string &sound);
  raylib::Sound &stop(const std::string &sound);
  raylib::Sound &play_multi(const std::string &sound);
  raylib::Sound &stop_multi(const std::string &sound);
  raylib::Sound &set_pitch(const std::string &sound, float pitch);
  raylib::Sound &set_volume(const std::string &sound, float volume);
  bool is_playing(const std::string &sound);
  unsigned int get_sample_count(const std::string &sound);
  void set_sample_count(const std::string &sound, unsigned int value);
  raylib::AudioStream get_audio_stream(const std::string &sound);
  void set_audio_stream(const std::string &sound, raylib::AudioStream value);
  void unload(const std::string &sound);
  void set(const std::string &sound, raylib::Sound rsound);
  raylib::Sound &update(const std::string &sound, const void *data,
                        int sample_count);
  raylib::Sound &operator[](const std::string &sound);
};

class Amusic {
  nlohmann::json config;
  std::unordered_map<std::string, raylib::Music> music;

public:
  Amusic();
  ~Amusic();
  int get_ctx_type(const std::string &sound);
  bool is_looping(const std::string &sound);
  unsigned int get_sample_count(const std::string &sound);
  float get_time_length(const std::string &sound);
  float get_time_played(const std::string &sound);
  bool is_playing(const std::string &sound);
  raylib::Music &play(const std::string &sound);
  raylib::Music &pause(const std::string &sound);
  raylib::Music &resume(const std::string &sound);
  void set(const std::string &sound, raylib::Music music);
  void set_ctx_type(const std::string &sound, int value);
  void set_looping(const std::string &sound, bool value);
  raylib::Music &set_pitch(const std::string &sound, float pitch);
  void set_sample_count(const std::string &sound, unsigned int value);
  raylib::Music &set_volume(const std::string &sound, float volume);
  raylib::Music &stop(const std::string &sound);
  raylib::Music &update(const std::string &sound);
  void unload(const std::string &sound);
  raylib::Music &operator[](const std::string &sound);
};
