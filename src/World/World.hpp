#pragma once
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

class World {
private:
  GLfloat x_ground_max;
  GLfloat y_ground_max;
  GLfloat z_ground_max;
  GLfloat x_ground_min;
  GLfloat y_ground_min;
  GLfloat z_ground_min;

protected:
public:
  World(GLfloat x_min, GLfloat x_max, GLfloat y_min, GLfloat y_max,
        GLfloat z_min, GLfloat z_max);
  World();
  void draw_sky();
  void draw_floor();
};
