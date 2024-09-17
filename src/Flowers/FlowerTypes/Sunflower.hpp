#pragma once
#include "../Flower.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

class Sunflower : public Flower {
public:
  Sunflower();
  Sunflower(GLfloat x, GLfloat y, GLfloat z);
  ~Sunflower();
  void draw_flower();
};
