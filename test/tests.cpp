// Copyright 2025 UNN-CS Team

#include "../include/tasks.h"
#include "../include/circle.h"
#include <gtest/gtest.h>
#include <cmath>
#include <limits>

TEST(CircleTest, ConstructorValidRadius) {
  Circle c(5.0);
  EXPECT_DOUBLE_EQ(5.0, c.getRadius());
}

TEST(CircleTest, ConstructorZeroRadius) {
  Circle c(0.0);
  EXPECT_DOUBLE_EQ(0.0, c.getRadius());
}

TEST(CircleTest, ConstructorNegativeRadius) {
  EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetValidRadius) {
  Circle c(2.0);
  c.setRadius(10.0);
  EXPECT_DOUBLE_EQ(10.0, c.getRadius());
}

TEST(CircleTest, SetZeroRadius) {
  Circle c(5.0);
  c.setRadius(0.0);
  EXPECT_DOUBLE_EQ(0.0, c.getFerence());
}

TEST(CircleTest, SetNegativeRadius) {
  Circle c(5.0);
  EXPECT_THROW(c.setRadius(-1.0), std::invalid_argument);
}

TEST(CircleTest, PrecisionFerenceCalculation) {
  Circle c(1.0);
  EXPECT_DOUBLE_EQ(2 * M_PI, c.getFerence());
}

TEST(CircleTest, PrecisionAreaCalculation) {
  Circle c(2.0);
  EXPECT_DOUBLE_EQ(M_PI * 4.0, c.getArea());
}

TEST(CircleTest, MaxDoubleRadius) {
  double max = std::numeric_limits<double>::max();
  Circle c(max);
  EXPECT_DOUBLE_EQ(max, c.getRadius());
}

TEST(CircleTest, MinDoubleRadius) {
  double min = std::numeric_limits<double>::min();
  Circle c(min);
  EXPECT_DOUBLE_EQ(min, c.getRadius());
}

TEST(TasksTest, EarthRopeGapCalculation) {
  double gap = calculateGap();
  EXPECT_NEAR(1 / (2 * M_PI), gap, 1e-9);
}

TEST(TasksTest, PoolCostCalculation) {
  double cost = calculatePoolCost();
  double expected = (M_PI * (4 * 4 - 3 * 3) * 1000) + (2 * M_PI * 4 * 2000);
  EXPECT_DOUBLE_EQ(expected, cost);
}

TEST(CircleTest, SetInvalidFerence) {
  Circle c(5.0);
  EXPECT_THROW(c.setFerence(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetNaNRadius) {
  Circle c(5.0);
  EXPECT_THROW(c.setRadius(NAN), std::invalid_argument);
}

TEST(CircleTest, SetInfArea) {
  Circle c(5.0);
  EXPECT_THROW(c.setArea(INFINITY), std::invalid_argument);
}

TEST(CircleTest, ChainSetters) {
  Circle c(3.0);
  c.setFerence(20.0);
  c.setArea(c.getArea() * 2);
  EXPECT_DOUBLE_EQ(40.0, c.getArea());
}

TEST(CircleTest, StateConsistency) {
  Circle c(5.0);
  double initialArea = c.getArea();
  c.setRadius(5.0);
  EXPECT_DOUBLE_EQ(initialArea, c.getArea());
}

TEST(TasksTest, EarthRopeEdgeCase) {
  double earthRadius = 6378100;
  Circle earth(earthRadius);
  earth.setFerence(earth.getFerence() + 1);
  EXPECT_GT(earth.getRadius(), earthRadius);
}

TEST(TasksTest, PoolCostComponents) {
  double concrete = (M_PI * (4 * 4 - 3 * 3)) * 1000;
  double fence = (2 * M_PI * 4) * 2000;
  EXPECT_DOUBLE_EQ(concrete + fence, calculatePoolCost());
}
