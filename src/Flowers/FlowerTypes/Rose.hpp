#pragma once
#include "../Flower.hpp"
#include <GL/gl.h>
#include <GL/glut.h>

class Rose : public Flower {
public:
  Rose();
  Rose(GLfloat x, GLfloat y, GLfloat z);
  ~Rose();
  void draw_flower();
};
