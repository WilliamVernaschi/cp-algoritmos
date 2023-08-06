#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const double EPS = 1e-9;

#define X real()
#define Y imag()

template<typename T>
struct line{
  T A, B, C;
};

template<typename T>
T cross_prod(complex<T> p1, complex<T> p2){
    return p1.X*p2.Y - p2.X*p1.Y;
}

template<typename T>
T det(T a, T b, T c, T d) {
    return a*d - b*c;
}

// returns true if the lines are parallel, otherwise, return false
bool parallel(line<ll> m, line<ll> n) {
    return det(m.A, m.B, n.A, n.B) == 0;
}

bool parallel(line<ld> m, line<ld> n) {
  return abs(det(m.A, m.B, n.A, n.B)) < EPS;
}

// returns true if the lines m and n have an intersection complex
// and stores it in `res`, otherwise, return false.
template<typename T>
bool intersect(line<T> m, line<T> n, complex<ld> &res) {


  if(parallel(m, n)) return false;

  T zn = det(m.A, m.B, n.A, n.B);
  res.X = -det(m.c, m.b, n.c, n.b) / (ld)zn;
  res.Y = -det(m.a, m.c, n.a, n.c) / (ld)zn;

  return true;
}

// defined as a · b = |a||b| cos(O)
// 1. a · b = b · a
// 2. (ka) · b = a · (kb)
// 3. (a + b) · c = a·c + b·c
//
// properties:
// dot_prod(a, a) = |a|^2
// lenght of projection of a onto b = dot_prod(a,b)/|b|
template<typename T>
T dot_prod(complex<T> p1, complex<T> p2){
  return p1.X * p2.X + p1.Y * p2.Y;
}

// returns 2*(Area described by a convex not intersecting
// polygon)
template<typename T>
T area(vector<complex<T>> &poly){
  ll output = 0;
  for(ll i=0; i<(int)poly.size(); i++){
    complex<T> p1 = poly[i];
    complex<T> p2 = poly[(i+1)%poly.size()];
    output += cross_prod(p1,p2);
  }
  return abs(output);
}


// returns the integer triplet (A,B,C) that uniquely identifies the
// line that goes trough p1 and p2.
// Ax + By + C = 0 for any complex (x,y) that lies on the line.
line<ll> line_equation(complex<ll> p1, complex<ll> p2){
  line<ll> l;

  l.A = p1.Y - p2.Y;
  l.B = p2.X - p1.X;
  l.C = -l.A*p1.X - l.B*p1.Y;

  ll g = __gcd(__gcd(abs(l.A), abs(l.B)), abs(l.C));
  l.A /= g, l.B /= g, l.C /= g;

  if(l.A < 0 || (l.A == 0 && l.B < 0))
    l.A *= -1, l.B *= -1, l.C *= -1;
  

  return l;
}

// rotates a point/vector by a radians counterclockwise
void rotate(complex<ld> p, double a){
  p *= polar(1.0, a);
}

// returns the triplet that uniquely identifies the
// line that goes trough p1 and p2.
// Ax + By + C = 0 for any complex (x,y) that lies on the line.
line<ld> line_equation(complex<ld> p1, complex<ld> p2){
  line<ld> l;

  l.A = p1.Y - p2.Y;
  l.B = p2.X - p1.X;
  l.C = -l.A*p1.X - l.B*p1.Y;

  ld Z = sqrtl(l.A*l.A + l.B*l.B);

  l.A /= Z, l.B /= Z, l.C /= Z;

  if(l.A < -EPS || (abs(l.A) < EPS && l.B < -EPS))
    l.A *= -1, l.B *= -1, l.C *= -1;

  return l;
}

// returns the number of intersection points between a circle and line and 
// fills the ans vector with them.
int circle_line_intersect(complex<ld> center, ld radius, line<ld> l, vector<complex<ld>> &ans){

  l.C = l.C - l.A*center.X - l.B*center.Y;
  ld n = l.A*l.A + l.B*l.B;

  ld x0 = - (l.A*l.C)/(n);
  ld y0 = - (l.B*l.C)/(n);

  if(l.C*l.C > radius*radius*(n)+EPS){
    return 0;
  }
  else if(abs(l.C*l.C - radius*radius*n) < EPS){
    ans.push_back(complex<ld>(x0+center.X, y0+center.Y));
    return 1;
  }

  double d = radius*radius - l.C*l.C/(n);
  double mult = sqrtl (d / (n));

  double ax, ay, bx, by;
  ax = x0 + l.B * mult;
  bx = x0 - l.B * mult;
  ans.push_back(complex<ld>(ax+center.X, bx+center.Y));
  ay = y0 - l.A * mult;
  by = y0 + l.A * mult;
  ans.push_back(complex<ld>(ay+center.X, by+center.Y));
  return 2;

}


