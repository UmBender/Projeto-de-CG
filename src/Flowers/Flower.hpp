#pragma once
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

class Flower {
private:
public:
  Flower();
  Flower(GLfloat x, GLfloat y, GLfloat z);
  ~Flower();
  virtual void draw_flower() = 0;

protected:
  GLfloat root_x_position, root_y_position, root_z_position;
};
