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
  Camera camera(Vector3(0, 1, 0), Vector3(1, 1, 0), Vector3::y_axis(), 70);
  Image image(512, 512);

  struct TextureParams reflectiveTextureParams;
  reflectiveTextureParams.diffuse = 1.0f;
  reflectiveTextureParams.specular = 1.0f;
  reflectiveTextureParams.reflectance = 1.0f;

  struct TextureParams nonReflectiveTextureParams;
  nonReflectiveTextureParams.diffuse = 1.0f;
  nonReflectiveTextureParams.specular = 1.0f;
  nonReflectiveTextureParams.reflectance = 0.0f;

  TextureMaterial* reflectiveTexture = new UniformTexture(&reflectiveTextureParams);
  TextureMaterial* nonReflectiveTexture = new UniformTexture(&nonReflectiveTextureParams);

  Sphere redSphere = Sphere(nonReflectiveTexture, Color3::from_rgb(200, 70, 70), Vector3(5, 1, -1.5f), 1);
  Sphere floor = Sphere(reflectiveTexture, Color3::from_rgb(200, 200, 200), Vector3(5, -1000, 0), 1000);

  PointLight pointLight = PointLight(Color3::from_rgb(80, 80, 80), Vector3(-20, 10, 0));

  std::vector<Object*> objects{&redSphere, &floor};
  std::vector<Light*> lights{&pointLight};

  Scene scene(objects, lights, camera);

  scene.render(image);
  image.display("output.ppm");

  return 0;
}
