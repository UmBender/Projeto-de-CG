#include "Daisy.hpp"
#include <GL/gl.h>

Daisy::Daisy() : Flower() {
  Bx = {root_x_position, root_x_position + 2.0f, root_x_position,
        root_x_position - 4.0f};
  By = {root_y_position, root_y_position + 3.3f, root_y_position + 6.7f,
        root_y_position + 10.0f};
  Bz = {root_z_position, root_z_position, root_z_position, root_z_position};
}
Daisy::Daisy(GLfloat x, GLfloat y, GLfloat z) : Flower(x, y, z) {
  Bx = {root_x_position, root_x_position + 2.0f, root_x_position,
        root_x_position - 4.0f};
  By = {root_y_position, root_y_position + 3.3f, root_y_position + 6.7f,
        root_y_position + 10.0f};
  Bz = {root_z_position, root_z_position, root_z_position, root_z_position};
}
Daisy::~Daisy() {}
void Daisy::draw_flower() {

  float n{360.0};
  float radius{10.0};
  float height{10.0};
  for (float i{0}; i < n; i += 20) {
    draw_petal(i, radius, height);
  }
  draw_flower_core(radius, height);
  draw_stem(height);
}

void Daisy::draw_petal(float angle, float dist, float height) {
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
    glColor3f(1.0, 1.0, 0.8);
    glVertex3f(0, 0, 2);
    glVertex3f(35, 0, 4);
    for (int i = 0; i <= 180; i += 30) {
      glVertex3f(35 + 5 * sin(deg_to_rad(i)), 0, 4 * cos(deg_to_rad(i)));
    }

    glVertex3f(35, 0, -4);
    glVertex3f(0, 0, -2);
    glEnd();
  }
  glPopMatrix();
}
void Daisy::draw_flower_core(float dist, float height) {
  glPushMatrix();
  // Coloca o centro da flor no centro da flor
  glTranslated(root_x_position, root_y_position, root_z_position);
  // Coloca na posicao adequada acima do caule
  glTranslated(0.0, height, -dist);
  // Pinta o centro de amarelo
  glColor3f(1.0f, 1.0f, 0.0f);
  // Aqui desenha um circula com o centro um pouco elevado
  int parts{20};
  for (int i{0}; i < parts; i++) {
    glBegin(GL_POLYGON);
    glVertex3f(0.0f, 4.0f, 0.0f);
    glVertex3f((dist + 2.0) * cos(deg_to_rad(i * 360.0 / parts)), 0,
               (dist + 2.0) * sin(deg_to_rad(i * 360.0 / parts)));
    glVertex3f((dist + 2.0) * cos(deg_to_rad((i + 1) * 360.0 / parts)), 0,
               (dist + 2.0) * sin(deg_to_rad((i + 1) * 360.0 / parts)));
    glEnd();
  }
  glPopMatrix();
}
void Daisy::draw_stem(float height) {
  glColor3f(0.0f, 1.0f, 0.0f);
  glBegin(GL_LINE_STRIP);
  for (float t{0.0f}; t <= height; t += 0.02f) {
    GLfloat px = calculate_point(Bx, t);
    GLfloat py = calculate_point(By, t);
    GLfloat pz = calculate_point(Bz, t);
    glVertex3f(px, py, pz);
  }
  glEnd();
}

void Daisy::draw_leaf() {}
inline float Daisy::deg_to_rad(float deg) { return (deg / 360.0) * (M_PI * 2); }
