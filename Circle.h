//
// Created by Asus on 15.05.2024.
//

#ifndef GIT_CONTEINER_CIRCLE_H
#define GIT_CONTEINER_CIRCLE_H

#endif //GIT_CONTEINER_CIRCLE_H
#pragma once

#include "Shape.h"

class Circle : public Shape{
private:
    double radius;
public:
    Circle() : Shape(" "), radius(0.0){}
    Circle(string name, double r) : Shape(name), radius(r){}

    double calcPer() override { return 2 * p * radius; }
    double calcArea() override { return p * pow(radius,2); }
    void print() override {
        cout << name << endl << "Per: " << calcPer() << " and area: " << calcArea() << endl;
    }
    friend ostream& operator <<(ostream& OS, Circle& c){
        OS << c.name << endl << "Per: " << c.calcPer() << " and area: " << c.calcArea() << endl;
        return OS;
    }
    friend istream& operator >>(istream& IS, Circle& c){
        IS >> c.name >> c.radius;
        return IS;
    }
    static void input(Vector<Shape*>&vector) {
        ifstream fin("Circle.txt");
        string tempName;
        double tempRadius;
        if (!fin.is_open()) {
            cerr << "Unable to open Circle.txt" << endl;
            return;
        }
        while (fin >> tempName >> tempRadius) {
            Circle* newCircle = new Circle(tempName, tempRadius);
            vector.push_back(dynamic_cast<Shape*>(newCircle));
        }
        fin.close();
    }
};