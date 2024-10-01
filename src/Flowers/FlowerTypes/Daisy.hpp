#pragma once
#include "../../Helpers/MathCalculus.hpp"
#include "../Flower.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <array>
#include <iostream>
#include <math.h>

class Daisy : public Flower {
public:
  Daisy();
  Daisy(GLfloat x, GLfloat y, GLfloat z);
  ~Daisy();
  void draw_flower();

private:
  void draw_petal(GLfloat angle, GLfloat dist, GLfloat height);
  void draw_flower_core(GLfloat dist, GLfloat height);
  void draw_stem();
  void draw_leaf();
  float deg_to_rad(GLfloat deg);
  std::array<GLfloat, 4> Bx;
  std::array<GLfloat, 4> By;
  std::array<GLfloat, 4> Bz;
};
