#pragma once
#include "../Flower.hpp"
#include "../Seeder.hpp"
#include <GL/gl.h>
#include <GL/glut.h>

class Rose : public Flower {
private:
  void draw_petal(GLfloat angle, GLfloat dist, GLfloat vertical_angle);
  void draw_flower_core(GLfloat dist);
  void draw_stem();
  void draw_leaf();
  std::array<GLfloat, 4> Bx;
  std::array<GLfloat, 4> By;
  std::array<GLfloat, 4> Bz;
  GLfloat height;

protected:
public:
  Rose();
  Rose(GLfloat x, GLfloat y, GLfloat z, GLfloat height);
  ~Rose();
  void draw_flower();
};
