#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

struct Vec3 {
  double x, y, z;
  Vec3(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
  Vec3 operator+(const Vec3 &v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
  Vec3 operator-(const Vec3 &v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
  Vec3 operator*(double d) const { return Vec3(x * d, y * d, z * d); }
  Vec3 operator/(double d) const { return Vec3(x / d, y / d, z / d); }
  double length() const { return sqrt(x * x + y * y + z * z); }
  Vec3 normalize() const { return *this / length(); }
  double dot(const Vec3 &v) const { return x * v.x + y * v.y + z * v.z; }
};

struct Ray {
  Vec3 origin, direction;
  Ray(const Vec3 &o, const Vec3 &d) : origin(o), direction(d.normalize()) {}
};

struct Sphere {
  Vec3 center;
  double radius;
  Sphere(const Vec3 &c, double r) : center(c), radius(r) {}
  bool intersect(const Ray &ray, double &t) const {
    Vec3 oc = ray.origin - center;
    double a = ray.direction.dot(ray.direction);
    double b = 2 * oc.dot(ray.direction);
    double c = oc.dot(oc) - radius * radius;
    double disc = b * b - 4 * a * c;
    if (disc < 0) {
      return false;
    } else {
      disc = sqrt(disc);
      double t0 = (-b - disc) / (2 * a);
      double t1 = (-b + disc) / (2 * a);
      t = (t0 < t1) ? t0 : t1;
      return true;
    }
  }
};

Vec3 trace(const Ray &ray, const Sphere &sphere) {
  double t;
  if (sphere.intersect(ray, t)) {
    Vec3 point = ray.origin + ray.direction * t;
    Vec3 normal = (point - sphere.center) / sphere.radius;
    Vec3 light_dir = Vec3(0, 0, 1);
    double diffuse = normal.dot(light_dir);
    return Vec3(diffuse, diffuse, diffuse);
  } else {
    return Vec3(0, 0, 0);
  }
}

int main() {
  unsigned char image[HEIGHT][WIDTH][3];
  Sphere sphere(Vec3(WIDTH/2, HEIGHT/2, 100), 100);

#pragma acc data create(image)
{
#pragma acc parallel loop collapse(2)
for (int y = 0; y < HEIGHT; y++) {
for (int x = 0; x < WIDTH; x++) {
double u = (x - WIDTH/2) / (double)WIDTH;
double v = (y - HEIGHT/2) / (double)HEIGHT;
Ray ray(Vec3(0, 0, 0), Vec3(u, v, 1));
Vec3 color = trace(ray, sphere);
image[y][x][0] = (unsigned char)(color.x * 255);
image[y][x][1] = (unsigned char)(color.y * 255);
image[y][x][2] = (unsigned char)(color.z * 255);
}
}
}

FILE f = fopen("image.ppm", "wb");
fprintf(f, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
fwrite(image, 1, HEIGHTWIDTH*3, f);
fclose(f);

return 0;
}