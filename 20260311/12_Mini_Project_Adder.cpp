#include "12_Mini_Project_Adder.h"

Adder::Adder(int x, int y) : a(x), b(y) {}
int Adder::process() const { return a + b; }