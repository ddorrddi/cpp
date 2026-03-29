/*
클래스 선언은 헤더에서 수행
*/

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle{
private:
    int radius;
public:
    Circle();
    Circle(int r);
    double getArea() const;
};

#endif