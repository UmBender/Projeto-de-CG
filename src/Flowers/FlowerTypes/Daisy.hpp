#pragma once
#include "../Flower.hpp"
#include <GL/gl.h>
#include <GL/glut.h>

#include <iostream>

class Daisy : public Flower {
public:
  Daisy();
  Daisy(GLfloat x, GLfloat y, GLfloat z);
  ~Daisy();
  void draw_flower();
};
