#include <GL/glut.h>
#include <math.h>

float calculaPonto(char c, float t, GLfloat Bx[], GLfloat By[], GLfloat Bz[]) {
  switch (c) {
  case 'x':
    return (pow(1.0 - t, 3.0) * Bx[0] + 3.0 * t * pow(1.0 - t, 2.0) * Bx[1] +
            3.0 * pow(t, 2.0) * (1.0 - t) * Bx[2] + pow(t, 3.0) * Bx[3]);
    break;
  case 'y':
    return (pow(1.0 - t, 3.0) * By[0] + 3.0 * t * pow(1.0 - t, 2.0) * By[1] +
            3.0 * pow(t, 2.0) * (1.0 - t) * By[2] + pow(t, 3.0) * By[3]);
    break;
  case 'z':
    return (pow(1.0 - t, 3.0) * Bz[0] + 3.0 * t * pow(1.0 - t, 2.0) * Bz[1] +
            3.0 * pow(t, 2.0) * (1.0 - t) * Bz[2] + pow(t, 3.0) * Bz[3]);
    break;
  }
  return 0;
}

GLfloat *calculate_sunflower_stem_coords(char c, GLfloat root_position) {
  GLfloat *coords = new GLfloat[4];
  switch (c) {
  case 'x':
    coords[0] = root_position;
    coords[1] = root_position + 2;
    coords[2] = root_position;
    coords[3] = root_position - 4;
    break;
  case 'y':
    coords[0] = root_position;
    coords[1] = root_position + 5;
    coords[2] = root_position + 10;
    coords[3] = root_position + 15;
    break;
  case 'z':
    coords[0] = root_position;
    coords[1] = root_position;
    coords[2] = root_position;
    coords[3] = root_position;
    break;
  }
  return coords;
}
