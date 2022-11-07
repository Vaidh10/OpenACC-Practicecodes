/**
 * @file raytracer_refactored.cpp
 * @author Adam Kenney, Jaden Stith
 * @brief Parallel using openmp.
 * @version 0.1
 * @date 2021-12-01
 *
 *
 *
 */
#include <fstream>
#include <cmath>
#include <iostream>
#include <omp.h>
#include <sys/time.h>

typedef unsigned long long timestamp_t;

static timestamp_t
get_timestamp ()
{
  struct timeval now;
  gettimeofday (&now, NULL);
  return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

struct Vec3 {
  double x,y,z;
  Vec3() : x(0), y(0), z(0) {}
  Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

  Vec3 operator + (const Vec3& v) const { return Vec3(x+v.x, y+v.y, z+v.z); }
  Vec3 operator - (const Vec3& v) const { return Vec3(x-v.x, y-v.y, z-v.z); }
  Vec3 operator * (double d) const { return Vec3(x*d, y*d, z*d); }
  Vec3 operator / (double d) const { return Vec3(x/d, y/d, z/d); }

  Vec3 normalize() const {
    double mg = sqrt(x*x + y*y + z*z);
    return Vec3(x/mg,y/mg,z/mg);
  }
};

inline double dot(const Vec3& a, const Vec3& b) {
  return (a.x*b.x + a.y*b.y + a.z*b.z);
}

struct Ray {
  Vec3 o,d;
  Ray(const Vec3& o, const Vec3& d) : o(o), d(d) {}
};

struct Sphere {
  Vec3 c;
  double r;
  Vec3 col;
  Sphere(const Vec3& c, double r, const Vec3& col) : c(c), r(r), col(col) {}

  Vec3 getNormal(const Vec3& pi) const { return (pi - c) / r; }

  bool intersect(const Ray& ray, double &t) const {
    const Vec3 o = ray.o;
    const Vec3 d = ray.d;
    const Vec3 oc = o - c;
    const double b = 2 * dot(oc, d);
    const double c = dot(oc, oc) - r*r;
    double disc = b*b - 4 * c;
    if (disc < 1e-4) return false;
    if (disc == 0){
      t = -b;
      return true;
    }else{
      disc = sqrt(disc);
      const double t0 = -b - disc;
      const double t1 = -b + disc;
      t = (t0 < t1) ? t0 : t1;
      return true;
    }
  }
};

void clamp255(Vec3& col) {
  col.x = (col.x > 255) ? 255 : (col.x < 0) ? 0 : col.x;
  col.y = (col.y > 255) ? 255 : (col.y < 0) ? 0 : col.y;
  col.z = (col.z > 255) ? 255 : (col.z < 0) ? 0 : col.z;
}

int main() {

  const int H = 800;
  const int W = 800;
  Vec3 pixelBoard[W][H];

  const Vec3 white(255, 255, 255);
  const Vec3 black(0, 0, 0);
  const Vec3 blue(50, 160, 240);
  const Vec3 purple(210, 50, 235);
  const Vec3 green(0, 255, 0);

  const Sphere sphere1(Vec3(W*0.5, H*0.5, 50), 50, blue);
  const Sphere sphere2(Vec3(W*.25, H*.25, 30), 60, purple);
  const Sphere sphere3(Vec3(W*.75, H*.75, 20), 20, green);
  const Sphere light(Vec3(W*0.5, 0, 50), 1, white);
  Sphere objects[] = {sphere1, sphere2, sphere3};

  double t;
  Vec3 pix_col(black);

  timestamp_t t0 = get_timestamp();

  int x;

  #pragma omp parallel for schedule(static) private(x, pix_col) shared(objects, pixelBoard)
  for (int y = 0; y < H; ++y) {
    for (x = 0; x < W; ++x) {
      pix_col = black;

      const Ray ray(Vec3(x,y,0),Vec3(0,0,1));

      for(Sphere s : objects){
        if (s.intersect(ray, t)) {
          const Vec3 pi = ray.o + ray.d*t;
          const Vec3 L = light.c - pi;
          const Vec3 N = s.getNormal(pi);
          const double dt = dot(L.normalize(), N.normalize());

          pix_col = (s.col + white*dt) * 0.5;
          clamp255(pix_col);
        }
      }

      pixelBoard[x][y] = Vec3(pix_col.x, pix_col.y, pix_col.z);

    }
  }
  timestamp_t t1 = get_timestamp();
  std::cout << (t1-t0) / 1000000.0L << std::endl;


  std::ofstream out("out.ppm");
  out << "P3\n" << W << ' ' << H << ' ' << "255\n";
  for(int y = 0; y < W; ++y){
      for(int x = 0; x < H; ++x){
          out << (int)pixelBoard[x][y].x << ' '
              << (int)pixelBoard[x][y].y << ' '
              << (int)pixelBoard[x][y].z << '\n';
      }
  }

}