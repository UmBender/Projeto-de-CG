#include "World.hpp"

World::World(GLfloat x_min, GLfloat x_max, GLfloat y_min, GLfloat y_max,
             GLfloat z_min, GLfloat z_max)
    : x_ground_min(x_min), x_ground_max(x_max), y_ground_min(y_min),
      y_ground_max(y_max), z_ground_min(z_min), z_ground_max(z_max) {}

World::World()
    : x_ground_min(-4000), x_ground_max(4000), y_ground_min(-4000),
      y_ground_max(4000), z_ground_min(-4000), z_ground_max(4000) {}

void World::draw_sky() {
  glBegin(GL_QUADS);
  glColor3f(0.0, 0.4, 1.0);
  glVertex3f(x_ground_max, y_ground_max, z_ground_max);
  glVertex3f(x_ground_max, y_ground_max, z_ground_min);
  glVertex3f(x_ground_max, y_ground_min, z_ground_min);
  glVertex3f(x_ground_max, y_ground_min, z_ground_max);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(0.0, 0.4, 1.0);
  glVertex3f(x_ground_min, y_ground_max, z_ground_max);
  glVertex3f(x_ground_min, y_ground_max, z_ground_min);
  glVertex3f(x_ground_min, y_ground_min, z_ground_min);
  glVertex3f(x_ground_min, y_ground_min, z_ground_max);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(0.0, 0.4, 1.0);
  glVertex3f(x_ground_max, y_ground_max, z_ground_max);
  glVertex3f(x_ground_min, y_ground_max, z_ground_max);
  glVertex3f(x_ground_min, y_ground_min, z_ground_max);
  glVertex3f(x_ground_max, y_ground_min, z_ground_max);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(0.0, 0.4, 1.0);
  glVertex3f(x_ground_max, y_ground_max, z_ground_min);
  glVertex3f(x_ground_min, y_ground_max, z_ground_min);
  glVertex3f(x_ground_min, y_ground_min, z_ground_min);
  glVertex3f(x_ground_max, y_ground_min, z_ground_min);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(0.0, 0.4, 1.0);
  glVertex3f(x_ground_max, y_ground_max, z_ground_max);
  glVertex3f(x_ground_min, y_ground_max, z_ground_max);
  glVertex3f(x_ground_min, y_ground_max, z_ground_min);
  glVertex3f(x_ground_max, y_ground_max, z_ground_min);
  glEnd();
  // glBegin(GL_QUADS);
  // glColor3f(0.0, 0.4, 1.0);
  // glVertex3f(100, 100, z_ground_max);
  // glVertex3f(-100, 100, z_ground_max);
  // glVertex3f(-100, 0, z_ground_min);
  // glVertex3f(100, 0, z_ground_min);
  // glEnd();
}

void World::draw_floor() {
  glBegin(GL_QUADS);
  glColor3f(0.1, 0.8, 0.1);
  glVertex3f(x_ground_max, 0, z_ground_max);
  glVertex3f(x_ground_max, 0, z_ground_min);
  glVertex3f(x_ground_min, 0, z_ground_min);
  glVertex3f(x_ground_min, 0, z_ground_max);
  glEnd();
}
