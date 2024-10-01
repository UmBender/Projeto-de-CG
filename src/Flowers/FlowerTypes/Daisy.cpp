#include "Daisy.hpp"
#include <GL/gl.h>

Daisy::Daisy() : Flower() {
  Bx = {0, 2.0f, 0, -4.0f};
  By = {0, 0 + 3.3f, 0 + 6.7f, 10.0f};
  Bz = {0, 0, 0, 0};
}
Daisy::Daisy(GLfloat x, GLfloat y, GLfloat z) : Flower(x, y, z) {
  Bx = {0, 4.0f, 4.0f, 0};
  By = {0, 6.7f, 13.4f, 20.0f};
  Bz = {0, 0, 0, 0};
}
Daisy::~Daisy() {}
void Daisy::draw_flower() {
  /*
   * TODO Consertar drift que da na parte de cima da flor quando muda a posicao
   * da camera
   */
  float n{360.0f};
  float radius{10.0f};
  float height{20.0f};
  for (float i{0}; i < n; i += 20) {
    draw_petal(i, radius, height);
  }
  draw_flower_core(radius, height);
  draw_stem();
}

void Daisy::draw_petal(GLfloat angle, GLfloat dist, GLfloat height) {
  glPushMatrix();
  // Coloca a flor no local correto
  glTranslated(root_x_position, root_y_position, root_z_position);
  // Coloca a petala na posicao correta em volta da flor
  glTranslated(dist * cos(deg_to_rad(angle)), height,
               -dist * (sin(deg_to_rad(angle)) + 1));
  // Rotaciona para ficar ortogonal em relacao ao centro
  glRotated(angle, 0.0, 1.0, 0.0);
  {
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.8f);
    glVertex3f(0.0f, 0.0f, 2.0f);
    glVertex3f(35.0f, 0.0f, 4.0f);
    for (int i{0}; i <= 180; i += 30) {
      glVertex3f(35.0f + 5.0f * sin(deg_to_rad(i)), 0.0f,
                 4.0f * cos(deg_to_rad(i)));
    }

    glVertex3f(35.0f, 0.0f, -4.0f);
    glVertex3f(0.0f, 0.0f, -2.0f);
    glEnd();
  }
  glPopMatrix();
}
void Daisy::draw_flower_core(GLfloat dist, GLfloat height) {
  glPushMatrix();
  // Coloca o centro da flor no centro da flor
  glTranslated(root_x_position, root_y_position, root_z_position);
  // Coloca na posicao adequada acima do caule
  glTranslated(0.0f, height, -dist);
  // Pinta o centro de amarelo
  glColor3f(1.0f, 1.0f, 0.0f);
  // Aqui desenha um circula com o centro um pouco elevado
  int parts{20};
  for (int i{0}; i < parts; i++) {
    glBegin(GL_POLYGON);
    glVertex3f(0.0f, 4.0f, 0.0f);
    glVertex3f((dist + 2.0f) * cos(deg_to_rad(i * 360.0f / parts)), 0.0f,
               (dist + 2.0f) * sin(deg_to_rad(i * 360.0f / parts)));
    glVertex3f((dist + 2.0f) * cos(deg_to_rad((i + 1) * 360.0f / parts)), 0.0f,
               (dist + 2.0f) * sin(deg_to_rad((i + 1) * 360.0f / parts)));
    glEnd();
  }
  glPopMatrix();
}
void Daisy::draw_stem() {
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
  glBegin(GL_QUADS);
  glColor3f(88.0 / 128.0, 57.0 / 128.0, 39.0 / 128.0);
  glVertex3f(10, 2, 10);
  glVertex3f(10, 2, -10);
  glVertex3f(-10, 2, -10);
  glVertex3f(-10, 2, 10);
  glEnd();
  glPopMatrix();
}

void Daisy::draw_leaf() {
  glPushMatrix();
  // Coloca o centro da flor no centro da flor
  glTranslated(root_x_position, root_y_position, root_z_position);
  // Pinta o centro de amarelo
  glColor3f(1.0f, 1.0f, 0.0f);
  // Aqui desenha um circula com o centro um pouco elevado
  int parts{20};
  glBegin(GL_POLYGON);

  glEnd();
  glPopMatrix();
}
inline float Daisy::deg_to_rad(float deg) { return (deg / 360.0) * (M_PI * 2); }
