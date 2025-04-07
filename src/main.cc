#include <iostream>
#include <memory>

#include "camera.hh"
#include "color3.hh"
#include "image.hh"
#include "point-light.hh"
#include "scene.hh"
#include "plane.hh"
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
  Camera camera(Vector3(-100, 50, -100), Vector3(1, -0.5f, 1), Vector3(0.5f, 1, 0.5f), 70);
  Image image(512, 512);

  struct TextureParams textureParams1;
  textureParams1.diffuse = 1.0f;
  textureParams1.specular = 0.0f;
  textureParams1.reflectance = 0.7f;

  struct TextureParams textureParams2;
  textureParams2.diffuse = 1.0f;
  textureParams2.specular = 0.5f;
  textureParams2.reflectance = 0.0f;

  struct TextureParams textureParams3;
  textureParams3.diffuse = 1.0f;
  textureParams3.specular = 0.0f;
  textureParams3.reflectance = 0.0f;

  TextureMaterial* texture1 = new UniformTexture(&textureParams1);
  TextureMaterial* texture2 = new UniformTexture(&textureParams2);
  TextureMaterial* texture3 = new UniformTexture(&textureParams3);

  Sphere redSphere = Sphere(texture2, Color3::from_rgb(200, 70, 70), Vector3(-50, 10, -60), 10);
  Sphere greenSphere = Sphere(texture2, Color3::from_rgb(70, 200, 70), Vector3(-65, 8, -30), 8);
  Sphere blueSphere = Sphere(texture2, Color3::from_rgb(70, 70, 200), Vector3(-80, 15, -50), 15);

  Sphere mirrorSphere = Sphere(texture1, Color3::from_rgb(50, 50, 50), Vector3(-50, 50, 0), 20);

  Plane miror = Plane(texture1, Color3::from_rgb(40, 40, 40), Vector3(0, 0, 0), -Vector3::x_axis());
  Plane backwall = Plane(texture3, Color3::from_rgb(50, 50, 50), Vector3(-100, 0, 0), Vector3::x_axis());
  Plane wall = Plane(texture3, Color3::from_rgb(50, 50, 50), Vector3(0, 0, 0), -Vector3::z_axis());
  Plane floor = Plane(texture3, Color3::from_rgb(200, 200, 200), Vector3(0, 0, 0), Vector3::y_axis());

  PointLight pointLight = PointLight(Color3::from_rgb(200, 200, 200), Vector3(-50, 75, -50));

  std::vector<Object*> objects{&redSphere, &greenSphere, &blueSphere, &mirrorSphere, &miror, &wall, &floor, &backwall};
  std::vector<Light*> lights{&pointLight};

  Scene scene(objects, lights, camera);

  scene.render(image);
  image.display("output.ppm");

  return 0;
}
