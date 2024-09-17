#include "Rose.hpp"
Rose::Rose() : Flower() {}
Rose::Rose(GLfloat x, GLfloat y, GLfloat z) : Flower(x, y, z) {}
Rose::~Rose() {}
void Rose::draw_flower() {
  glColor3f(1.0f, 0.2f, 0.2f);
  glPushMatrix();
  glTranslated(root_x_position, root_y_position, root_z_position);
  glutWireTeapot(25.0f);
  glPopMatrix();
}
