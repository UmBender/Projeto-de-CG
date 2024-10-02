#pragma once
#include "../../Helpers/MathCalculus.hpp"
#include "../Flower.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>

class Sunflower : public Flower {
public:
  void draw_petal(GLfloat angle, GLfloat dist, GLfloat vertical_angle);
  void draw_flower_core(GLfloat dist, GLfloat height);
  void draw_stem();
  void draw_leaf();
  std::array<GLfloat, 4> Bx;
  std::array<GLfloat, 4> By;
  std::array<GLfloat, 4> Bz;
  GLfloat height;

protected:
public:
  Sunflower();
  Sunflower(GLfloat x, GLfloat y, GLfloat z, GLfloat height);
  ~Sunflower();
  void draw_flower();
};
