#include "Sunflower.hpp"
#include <GL/gl.h>

Sunflower::Sunflower() : Flower() {
  Bx = {0, 2.0f, 0, -4.0f};
  By = {0, 0 + 3.3f, 0 + 6.7f, 10.0f};
  Bz = {0, 0, 0, 0};
}
Sunflower::Sunflower(GLfloat x, GLfloat y, GLfloat z, GLfloat height)
    : Flower(x, y, z), height(height) {
  Bx = {0, randf(-5.0f, 5.0f), randf(-5.0f, 5.0f), 0};
  By = {0, height / 3.0f, 2.0f * height / 3.0f, height};
  Bz = {0, randf(-5.0f, 5.0f), randf(-5.0f, 5.0f), 0};
}
Sunflower::~Sunflower() {}
void Sunflower::draw_flower() {
  float n{360.0f};
  float radius{7.0f};
  for (float i{0}; i < n; i += 10) {
    draw_petal(i, radius, height);
  }
  draw_flower_core(radius, height);
  draw_stem();
}
void Sunflower::draw_petal(GLfloat angle, GLfloat dist, GLfloat height) {
  glPushMatrix();
  // Coloca a flor no local correto
  glTranslated(root_x_position, root_y_position, root_z_position);
  // Coloca a petala na posicao correta em volta da flor
  glTranslated(dist * cos(deg_to_rad(angle)), height,
               -dist * sin(deg_to_rad(angle)));
  // Rotaciona para ficar vertical e coerente com o centro
  glRotated(angle, 0.0, 0.0, -1.0);
  glRotated(90.0f, 1.0, 0.0, 0.0);
  {
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 2.0f);
    glVertex3f(10.0f, 0.0f, 4.0f);
    glVertex3f(15.0f, 0.0f, 0.0f);
    glVertex3f(10.0f, 0.0f, -4.0f);
    glVertex3f(0.0f, 0.0f, -2.0f);
    glEnd();
  }
  glPopMatrix();
}
void Sunflower::draw_flower_core(GLfloat dist, GLfloat height) {
  glPushMatrix();
  // Coloca o centro da flor no centro da flor
  glTranslated(root_x_position, root_y_position, root_z_position);
  // Coloca na posicao adequada acima do caule
  glTranslated(0.0f, height, 0.0f);
  // Pinta o centro de marrom
  glColor3f(0.59f, 0.29f, 0.0f);
  // Aqui desenha um circula com o centro um pouco elevado
  glRotated(50.0f, 1.0, 0.0, 0.0);
  int parts{50};
  for (int i{0}; i < parts; i++) {
    glBegin(GL_POLYGON);
    glVertex3f(0.0f, 0.0f, -2.0f);
    glVertex3f((dist + 0.5f) * cos(deg_to_rad(i * 360.0f / parts)),
               (dist + 0.5f) * sin(deg_to_rad(i * 360.0f / parts)), 0.04);
    glVertex3f((dist + 0.5f) * cos(deg_to_rad((i + 1) * 360.0f / parts)),
               (dist + 0.5f) * sin(deg_to_rad((i + 1) * 360.0f / parts)), 0.0f);
    glEnd();
  }
  glPopMatrix();
}
void Sunflower::draw_stem() {
  glPushMatrix();
  glTranslatef(root_x_position, root_y_position, root_z_position);
  for (float t{0.02f}; t <= 1.0f; t += 0.02f) {
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUAD_STRIP);
    // Pontos de cima
    GLfloat px = calculate_point(Bx, t);
    GLfloat py = calculate_point(By, t);
    GLfloat pz = calculate_point(Bz, t);
    // Pontos de baixo
    GLfloat px_old = calculate_point(Bx, t - 0.02f);
    GLfloat py_old = calculate_point(By, t - 0.02f);
    GLfloat pz_old = calculate_point(Bz, t - 0.02f);

    // Desenha a caula de forma circular
    for (float i{0.0f}; i <= 360.0f; i += 22.5f) {
      // Define os pontos de cima
      glVertex3f(px + cos(deg_to_rad(i)), py, pz + sin(deg_to_rad(i)));
      // Define os pontos de baixo
      glVertex3f(px_old + cos(deg_to_rad(i)), py_old,
                 pz_old + sin(deg_to_rad(i)));
    }
    glEnd();
  }
  // Desenha terra de baixo da flor
  glBegin(GL_TRIANGLE_FAN);
  glColor3f(88.0 / 128.0, 57.0 / 128.0, 39.0 / 128.0);
  glVertex3f(0.0f, 2.0f, 0.0f);
  for (GLfloat i{0.0f}; i <= 360.0f; i += 11.25f) {
    glVertex3f(10.0f * sin(deg_to_rad(i)), -1.0f, 10.0f * cos(deg_to_rad(i)));
  }
  glEnd();
  glPopMatrix();
}
