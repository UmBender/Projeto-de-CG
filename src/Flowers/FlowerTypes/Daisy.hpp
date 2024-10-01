#pragma once
#include "../Flower.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <array>
#include <iostream>
#include <math.h>

class Daisy : public Flower {
private:
  void draw_petal(GLfloat angle, GLfloat dist, GLfloat height);
  void draw_flower_core(GLfloat dist, GLfloat height);
  void draw_stem();
  void draw_leaf();
  std::array<GLfloat, 4> Bx;
  std::array<GLfloat, 4> By;
  std::array<GLfloat, 4> Bz;
  GLfloat height;

protected:
public:
  Daisy();
  Daisy(GLfloat x, GLfloat y, GLfloat z, GLfloat height);
  ~Daisy();
  void draw_flower();
};
