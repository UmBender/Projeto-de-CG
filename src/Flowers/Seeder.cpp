#include "Seeder.hpp"

Seeder::Seeder() {}
Seeder::Seeder(Camera *ref_camera)
    : number_flowers(0), random_generator(time(NULL)), camera(ref_camera) {}

Flower *Seeder::generate_flower() {
  std::uniform_int_distribution<std::mt19937::result_type> random_flower_dist(
      1, 3);
  number_flowers++;

  switch (random_flower_dist(random_generator)) {
  case 1:
    flowers_distribution["Daisy"]++;
    return new Daisy(camera->get_xcamera(), 0.0F, camera->get_zcamera(),
                     Flower::randf(15.0f, 100.0f));
    break;
  case 2:
    flowers_distribution["Sunflower"]++;
    return new Sunflower(camera->get_xcamera(), 0.0F, camera->get_zcamera(),
                    Flower::randf(15.0f, 100.0f));
    break;
  case 3:
    flowers_distribution["Rose"]++;
    return new Rose(camera->get_xcamera(), 0.0F, camera->get_zcamera(),
                    Flower::randf(15.0f, 100.0f));
    break;
  }
  return nullptr;
}

inline std::size_t Seeder::get_number_flower() { return number_flowers; }
