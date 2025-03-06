// Copyright 2025 UNN-CS Team

#include "../include/circle.h"
#include "../include/tasks.h"
#include <cmath>
#include <gtest/gtest.h>

TEST(CircleTest, RadiusSetter) {
  Circle circle(5);
  circle.setRadius(10);
  EXPECT_DOUBLE_EQ(circle.getRadius(), 10);
  EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * PI * 10);
  EXPECT_DOUBLE_EQ(circle.getArea(), PI * 10 * 10);
}

TEST(CircleTest, FerenceSetter) {
  Circle circle(5);
  circle.setFerence(20);
  EXPECT_DOUBLE_EQ(circle.getFerence(), 20);
  EXPECT_DOUBLE_EQ(circle.getRadius(), 20 / (2 * PI));
  EXPECT_DOUBLE_EQ(circle.getArea(), PI * pow(20 / (2 * PI), 2));
}

TEST(CircleTest, AreaSetter) {
  Circle circle(5);
  circle.setArea(50);
  EXPECT_DOUBLE_EQ(circle.getArea(), 50);
  EXPECT_DOUBLE_EQ(circle.getRadius(), sqrt(50 / PI));
  EXPECT_DOUBLE_EQ(circle.getFerence(), 2 * PI * sqrt(50 / PI));
}

TEST(TasksTest, CalculateGap) {
  double gap = calculateGap();
  EXPECT_GT(gap, 0);
  EXPECT_LT(gap, 1);
}

TEST(TasksTest, CalculatePoolCost) {
  double cost = calculatePoolCost();
  EXPECT_GT(cost, 0);
}
