#pragma once
#include <GL/gl.h>
#include <GL/glut.h>

// Recebe como parametro o eixo onde está calculando (variável 'c'), podendo ser
// no eixo X, Y e Z, e o valor de t.
float calculaPonto(char c, float t, GLfloat Bx[], GLfloat By[], GLfloat Bz[]);
GLfloat *calculate_sunflower_stem_coords(char c, GLfloat root_position);
