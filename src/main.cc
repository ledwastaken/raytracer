#include <iostream>
#include <memory>

#include "camera.hh"
#include "color3.hh"
#include "image.hh"
#include "point-light.hh"
#include "scene.hh"
#include "sphere.hh"
#include "uniform-texture.hh"
#include "vector3.hh"

using namespace camera;
using namespace color3;
using namespace image;
using namespace light;
using namespace object;
using namespace scene;
using namespace texture;
using namespace vector3;

int main(void)
{
  Camera camera(Vector3(0, 0, 0), Vector3::x_axis(), Vector3::y_axis(), 70);
  Image image(512, 512);

  TextureMaterial* texture = new UniformTexture(1.0f, 1.0f);

  Sphere greySphere = Sphere(texture, Color3::from_rgb(100, 100, 100), Vector3(5, 0, -1.5f), 1);
  Sphere redSphere = Sphere(texture, Color3::from_rgb(200, 70, 70), Vector3(5, 0, 1.5f), 1);
  PointLight pointLight = PointLight(Color3::from_rgb(80, 80, 80), Vector3(-20, 10, 0));

  std::vector<Object*> objects{&greySphere, &redSphere};
  std::vector<Light*> lights{&pointLight};

  Scene scene(objects, lights, camera);

  scene.render(image);
  image.display("output.ppm");

  return 0;
}
