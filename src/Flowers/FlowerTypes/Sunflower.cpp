#include "Sunflower.hpp"
Sunflower::Sunflower() : Flower() {}
Sunflower::Sunflower(GLfloat x, GLfloat y, GLfloat z) : Flower(x, y, z) {}
Sunflower::~Sunflower() {}

void Sunflower::draw_flower() {
  GLfloat Px, Py, Pz;

  // Pontos de controle
  GLfloat *Bx = calculate_sunflower_stem_coords('x', root_x_position);
  GLfloat *By = calculate_sunflower_stem_coords('y', root_y_position);
  GLfloat *Bz = calculate_sunflower_stem_coords('z', root_z_position);

  GLfloat stem_radius = 0.2f;
  glColor3f(0.03f, 0.28f, 0.13f);

  glBegin(GL_QUAD_STRIP);
  for (GLdouble t = 0; t <= 1.0; t += 0.1) {
    Px = calculaPonto('x', t, Bx, By, Bz);
    Py = calculaPonto('y', t, Bx, By, Bz);
    Pz = calculaPonto('z', t, Bx, By, Bz);

    GLfloat offset_x = stem_radius * sin(t * 10.0);
    GLfloat offset_z = stem_radius * cos(t * 10.0);

    glVertex3f(Px + offset_x, Py, Pz + offset_z);
    glVertex3f(Px - offset_x, Py, Pz - offset_z);
  }
  glEnd();

  // Desenha a flor
  glColor3f(0.47f, 0.25f, 0.03f);
  glPushMatrix();
  // Centro da flor
  Px = calculaPonto('x', 1.0, Bx, By, Bz);
  Py = calculaPonto('y', 1.0, Bx, By, Bz);
  Pz = calculaPonto('z', 1.0, Bx, By, Bz);
  glTranslated(Px, Py, Pz);
  glutSolidSphere(2.0, 20, 20);
  glPopMatrix();

  // Desenha o vaso
  glColor3f(0.75f, 0.0f, 0.3f);
  glPushMatrix();
  glTranslated(root_x_position, root_y_position, root_z_position);
  glBegin(GL_QUADS);
  // Base
  glNormal3f(0.0f, 1.0f, 0.0f);
  glVertex3f(-5.0, 0.0, -5.0);
  glVertex3f(-5.0, 0.0, 5.0);
  glVertex3f(5.0, 0.0, 5.0);
  glVertex3f(5.0, 0.0, -5.0);
  // Lados
  glNormal3f(-1.0f, 0.0f, 0.0f);
  glVertex3f(-5.0, 0.0, -5.0);
  glVertex3f(-5.0, 5.0, -5.0);
  glVertex3f(-5.0, 5.0, 5.0);
  glVertex3f(-5.0, 0.0, 5.0);

  glNormal3f(-1.0f, 0.0f, 0.0f);
  glVertex3f(-5.0, 0.0, 5.0);
  glVertex3f(-5.0, 5.0, 5.0);
  glVertex3f(5.0, 5.0, 5.0);
  glVertex3f(5.0, 0.0, 5.0);

  glNormal3f(1.0f, 0.0f, 0.0f);
  glVertex3f(5.0, 0.0, 5.0);
  glVertex3f(5.0, 5.0, 5.0);
  glVertex3f(5.0, 5.0, -5.0);
  glVertex3f(5.0, 0.0, -5.0);

  glNormal3f(0.0f, 0.0f, -1.0f);
  glVertex3f(5.0, 0.0, -5.0);
  glVertex3f(5.0, 5.0, -5.0);
  glVertex3f(-5.0, 5.0, -5.0);
  glVertex3f(-5.0, 0.0, -5.0);

  // Topo
  glColor3f(0.5f, 0.35f, 0.05f);
  glNormal3f(0.0f, -1.0f, 0.0f);
  glVertex3f(-5.0, 4.0, -5.0);
  glVertex3f(-5.0, 4.0, 5.0);
  glVertex3f(5.0, 4.0, 5.0);
  glVertex3f(5.0, 4.0, -5.0);
  glEnd();
  glPopMatrix();

  delete[] Bx;
  delete[] By;
  delete[] Bz;
}
