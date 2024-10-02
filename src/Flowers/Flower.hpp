#pragma once
#include <GL/gl.h>
#include <GL/glut.h>
#include <array>
#include <cmath>
#include <iostream>

class Flower {
private:
public:
  Flower();
  Flower(GLfloat x, GLfloat y, GLfloat z);
  ~Flower();
  virtual void draw_flower() = 0;
  static inline GLfloat randf(GLfloat min, GLfloat max) {
    srand(time(NULL));
    int random_value = rand() % 1000;
    return (random_value / 1000.0f) * (max - min) + min;
  }
  void update_animation() {};

protected:
  GLfloat root_x_position, root_y_position, root_z_position;
  static float calculate_point(std::array<GLfloat, 4> &b, float t) {
    return (pow(1 - t, 3) * b[0] + 3 * t * pow(1 - t, 2) * b[1] +
            3 * pow(t, 2) * (1 - t) * b[2] + pow(t, 3) * b[3]);
  }

  static inline GLfloat deg_to_rad(GLfloat deg) {
    return (deg / 360.0) * (M_PI * 2);
  }
};
