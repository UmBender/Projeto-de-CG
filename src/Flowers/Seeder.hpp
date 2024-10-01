#pragma once
#include "../World/Camera.hpp"
#include "Flower.hpp"
#include "FlowerTypes/Daisy.hpp"
#include "FlowerTypes/Rose.hpp"
#include "FlowerTypes/Sunflower.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <map>
#include <random>
#include <string>

class Seeder {
private:
  std::size_t number_flowers;
  std::map<std::string, std::size_t> flowers_distribution;
  std::mt19937 random_generator;
  Camera *camera;

protected:
public:
  Seeder();
  Seeder(Camera *ref_camera);
  Flower *generate_flower();
  std::size_t get_number_flower();
};
