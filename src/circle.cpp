// Copyright 2022 UNN-CS
#include "../include/circle.h"
#include <cmath>

Circle::Circle(double radius) { setRadius(radius); }

void Circle::setRadius(double radius) {
  this->radius = radius;
  updateFerence();
  updateArea();
}

void Circle::setFerence(double ference) {
  this->ference = ference;
  radius = ference / (2 * PI);
  updateArea();
}

void Circle::setArea(double area) {
  this->area = area;
  radius = sqrt(area / PI);
  updateFerence();
}

double Circle::getRadius() const { return radius; }

double Circle::getFerence() const { return ference; }

double Circle::getArea() const { return area; }

void Circle::updateFerence() { ference = 2 * PI * radius; }

void Circle::updateArea() { area = PI * radius * radius; }
