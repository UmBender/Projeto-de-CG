#include "Flower.hpp"

Flower::Flower() : root_x_position(0), root_y_position(0), root_z_position(0) {}
Flower::Flower(GLfloat x, GLfloat y, GLfloat z)
    : root_x_position(x), root_y_position(y), root_z_position(z) {}

Flower::~Flower(){};
