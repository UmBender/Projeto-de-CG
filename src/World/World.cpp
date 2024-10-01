#include "World.hpp"
#include <GL/gl.h>

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

void World::draw_sun() {
  glBegin(GL_TRIANGLE_FAN);
  glColor3f(1.0, 1.0, 1.0);
  glVertex3f(0, y_ground_max - 20, 0);
  for (float i{0.0f}; i <= 360.0f; i += 5.625f) {
    glVertex3f(400.0f * sin((i / 360.0f) * (M_PI * 2)), y_ground_max - 20,
               400.0f * cos((i / 360.0f) * (M_PI * 2)));
  }
  glEnd();
}
