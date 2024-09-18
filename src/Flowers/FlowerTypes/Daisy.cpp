#include "Daisy.hpp"

Daisy::Daisy() : Flower() {}
Daisy::Daisy(GLfloat x, GLfloat y, GLfloat z) : Flower(x, y, z) {}
Daisy::~Daisy() {}
void Daisy::draw_flower() {

  glColor3f(0.2f, 0.2f, 0.2f);
  glPushMatrix();
  glTranslated(root_x_position, root_y_position, root_z_position);
  glutSolidTeapot(25.0f);
  glPopMatrix();
}
