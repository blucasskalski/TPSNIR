#include "crvba.h"
#include <iostream>
int CRvba::getR() const { return r; }

void CRvba::setR(int r) {
  // if (/*Blabla*/)
  this->r = r;
}
int CRvba::getV() const { return v; }

void CRvba::setV(int v) {
  // if (/*Blabla*/)
  this->v = v;
}
int CRvba::getB() const { return b; }

void CRvba::setB(int b) {
  // if (/*Blabla*/)
  this->b = b;
}
int CRvba::getA() const { return a; }

void CRvba::setA(int a) {
  // if (/*Blabla*/)
  this->a = a;
}
void CRvba::set(int r, int v, int b, int a) {
  this->r = r;
  this->v = v;
  this->b = b;
  this->a = a;
}

std::string CRvba::print() const {
  std::ostringstream oss;
  oss << "R:" << ' ';
  oss << r << std::endl;
  oss << "V:" << ' ';
  oss << v << std::endl;
  oss << "B:" << ' ';
  oss << b << std::endl;
  oss << "A:" << ' ';
  oss << a << std::endl;
  return oss.str();
}

std::string CRvba::printlong() const {
  std::ostringstream oss;
  oss << "R:" << ' ';
  oss << r << std::endl;
  oss << "V:" << ' ';
  oss << v << std::endl;
  oss << "B:" << ' ';
  oss << b << std::endl;
  oss << "A:" << ' ';
  oss << a << std::endl;
  return oss.str();
}
