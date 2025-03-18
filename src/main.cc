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
  Image image(256, 256);

  TextureMaterial* texture = new UniformTexture(1.0f, 1.0f);

  Sphere redSphere = Sphere(texture, Color3::from_rgb(70, 200, 70), Vector3(10, 0, 0), 4);
  PointLight pointLight = PointLight(Color3::from_rgb(80, 80, 80), Vector3(200, 100, -50));

  std::vector<Object*> objects{&redSphere};
  std::vector<Light*> lights{&pointLight};

  Scene scene(objects, lights, camera);

  scene.render(image);
  image.display("output.ppm");

  return 0;
}
