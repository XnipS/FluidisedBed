#pragma once

#include <string>
#include <vector>

struct Colour3 {
  float r = 0;
  float b = 0;
  float g = 0;
  Colour3(float red, float blue, float green) {
    r = red;
    b = blue;
    g = green;
  }
};

class renderEngine {
 public:
  renderEngine();
  ~renderEngine();

  void Initialise(const char* title, int w, int h);
  void UpdateConfig(float* gravity, float* damp, float* size, float* heat);
  void UpdateImage(float* colours);
  void FloodImage(Colour3 col);
  void Update();
  void Render();
  void Clean();
  bool Running() { return isRunning; };
  std::vector<std::string> currentDebugInfo;

 private:
  int tick = 0;
  bool isRunning;
};