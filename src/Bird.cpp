#include "Bird.hpp"
#include <GL/gl.h>

Bird::Bird() : angle(0) {}
Bird::Bird(Camera *ref_camera) : angle(45), camera(ref_camera) {}

Bird::~Bird() {}
void Bird::draw_wing() {
  glNormal3f(1.0f, 0.0f, 1.0f);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_COLOR_MATERIAL_FACE);

  glPushMatrix();
  // Coloca a flor no local correto
  glTranslated((camera->get_xtarget() + 4 * camera->get_xcamera()) / 5,
               camera->get_ycamera() - 30,
               (camera->get_ztarget() + 4 * camera->get_zcamera()) / 5);

  glRotated(camera->get_angle(), 0.0, 1.0, 0.0);
  glTranslated(-1.0f, 2.0f, 2.0f);
  glRotated(30, -1.0f, 0.0f, 0.f);
  glTranslated(+2.0f, 0.0f, 0.0f);
  glScaled(-1.0f, 1.0f, -1.0f);
  glRotated(angle, 0.0, 0.0, 1.0);
  {
    glBegin(GL_QUADS);
    glColor3f(1, 1, 0);
    glNormal3f(0, 1, 1);
    glVertex3f(-0.0f, 0.0f, 3.5f);
    glVertex3f(-6.0f, 0.0f, 3.5f);
    glVertex3f(-6.0f, 0.0f, -3.5f);
    glVertex3f(-0.0f, 0.0f, -3.5f);
    glEnd();
  }
  {
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0.0, 0);
    glNormal3f(0, 1, 1);
    glVertex3f(-6.0f, 0.0f, -3.5f);
    glVertex3f(-6.0f, 0.0f, 3.5f);
    glVertex3f(-20.0f, 0.0f, 7.0f);
    glEnd();
  }
  glPopMatrix();

  glPushMatrix();
  // Coloca a flor no local correto
  glTranslated((camera->get_xtarget() + 4 * camera->get_xcamera()) / 5,
               camera->get_ycamera() - 30,
               (camera->get_ztarget() + 4 * camera->get_zcamera()) / 5);

  glRotated(camera->get_angle(), 0.0, 1.0, 0.0);
  glScaled(-1.0, 1.0, 1.0);
  glTranslated(-1.0f, 2.0f, 2.0f);
  glRotated(30, -1.0f, 0.0f, 0.f);
  glTranslated(+2.0f, 0.0f, 0.0f);
  glScaled(-1.0f, 1.0f, -1.0f);
  glRotated(angle, 0.0, 0.0, 1.0);
  {
    glBegin(GL_QUADS);
    glColor3f(1, 1, 0);
    glNormal3f(0, 1, 1);
    glVertex3f(-0.0f, 0.0f, 3.5f);
    glVertex3f(-6.0f, 0.0f, 3.5f);
    glVertex3f(-6.0f, 0.0f, -3.5f);
    glVertex3f(-0.0f, 0.0f, -3.5f);
    glEnd();
  }
  {
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glNormal3f(0, 1, 1);
    glVertex3f(-6.0f, 0.0f, -3.5f);
    glVertex3f(-6.0f, 0.0f, 3.5f);
    glVertex3f(-20.0f, 0.0f, 7.0f);
    glEnd();
  }
  glPopMatrix();
}
void Bird::draw_body() {
  glNormal3f(1.0f, 0.0f, 1.0f);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_COLOR_MATERIAL_FACE);

  glPushMatrix();
  // Coloca a flor no local correto
  glTranslated((camera->get_xtarget() + 4 * camera->get_xcamera()) / 5,
               camera->get_ycamera() - 30,
               (camera->get_ztarget() + 4 * camera->get_zcamera()) / 5);
  // Coloca a petala na posicao correta em volta da flor
  // Rotaciona para ficar ortogonal em relacao ao centro
  glRotated(camera->get_angle(), 0.0, 1.0, 0.0);
  glScaled(-1.0f, 1.0f, -1.0f);
  {
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 7.0f);
    glVertex3f(-2.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);

    glVertex3f(0.0f, 0.0f, 7.0f);
    glVertex3f(2.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);

    glVertex3f(0.0f, 0.0f, 7.0f);
    glVertex3f(2.0f, 0.0f, 0.0f);
    glVertex3f(-2.0f, 0.0f, 0.0f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glVertex3f(0.0f, 2.0f, 0.0f);
    glVertex3f(0.0f, 5.0f, -7.0f);
    glVertex3f(-2.0f, 0.0f, 0.0f);
    glVertex3f(-2.0f, 3.0f, -7.0f);
    glVertex3f(2.0f, 0.0f, 0.0f);
    glVertex3f(2.0f, 3.0f, -7.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);
    glVertex3f(0.0f, 5.0f, -7.0f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glVertex3f(0.0f, 5.0f, -7.0f);
    glVertex3f(0.0f, 5.0f, -10.0f);
    glVertex3f(2.0f, 3.0f, -7.0f);
    glVertex3f(2.0f, 3.0f, -10.0f);
    glVertex3f(-2.0f, 3.0f, -7.0f);
    glVertex3f(-2.0f, 3.0f, -10.0f);
    glVertex3f(0.0f, 5.0f, -7.0f);
    glVertex3f(0.0f, 5.0f, -10.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(0.0f, 5.0f, -10.0f);
    glVertex3f(-2.0f, 3.0f, -10.0f);
    glVertex3f(0.0f, 5.0f, -15.0f);

    glVertex3f(0.0f, 5.0f, -10.0f);
    glVertex3f(2.0f, 3.0f, -10.0f);
    glVertex3f(0.0f, 5.0f, -15.0f);

    glVertex3f(-2.0f, 3.0f, -10.0f);
    glVertex3f(2.0f, 3.0f, -10.0f);
    glVertex3f(0.0f, 5.0f, -15.0f);

    glEnd();
  }
  glPopMatrix();
}

void Bird::draw_bird() {
  draw_body();
  draw_wing();
}
void Bird::flap() {
  if (direction == 1) {
    angle += 5;
  } else {
    angle -= 5;
  }

  if (angle >= 45) {
    direction = -1;
  }
  if (angle <= 0) {
    direction = +1;
  }
}
