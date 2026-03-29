#ifndef ADDER_H
#define ADDER_H

class Adder{
private:
    int a, b;
public:
    Adder(int a, int b);
    int process() const;
};

#endif