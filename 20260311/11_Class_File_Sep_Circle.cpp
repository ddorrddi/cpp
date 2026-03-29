/*
함수 구현은 cpp에서 수행
*/

#include "11_Class_File_Sep_Circle.h"

Circle::Circle() : radius(1) {}
Circle::Circle(int r) : radius(r) {}
double Circle::getArea() const { return 3.14 * radius * radius; }