#pragma once
#include "Flowers/Seeder.hpp"
#include "World/Camera.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

class Bird {
private:
  int angle;
  int direction;
  Camera *camera;
  void draw_wing();
  void draw_body();
  static inline GLfloat deg_to_rad(GLfloat deg) {
    return (deg / 360.0) * (M_PI * 2);
  }

protected:
public:
  Bird();
  Bird(Camera *ref_camera);
  ~Bird();
  void draw_bird();
  void flap();
};
