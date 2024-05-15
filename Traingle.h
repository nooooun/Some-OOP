//
// Created by Asus on 15.05.2024.
//

#ifndef GIT_CONTEINER_TRAINGLE_H
#define GIT_CONTEINER_TRAINGLE_H

#endif //GIT_CONTEINER_TRAINGLE_H
#pragma once

#include "Shape.h"

class Triangle : public Shape{
private:
    double side;
public:
    Triangle() : Shape(" "), side(0.0){}
    Triangle(string name, double s) : Shape(name), side(s){}

    double calcPer() override { return side * 3; }
    double calcArea() override { return sqrt(3) * pow(side,2) / 4; }
    void print() override {
        cout << name << endl << "Per: " << calcPer() << " and area: " << calcArea() << endl;
    }
    friend ostream& operator <<(ostream& OS, Triangle& t){
        OS << t.name << "Per: " << t.calcPer() << " and area: " << t.calcArea() << endl;
        return OS;
    }
    friend istream& operator >>(istream& IS, Triangle& t){
        IS >> t.name >> t.side;
        return IS;
    }
    static void input(Vector<Shape*>&vector) {
        ifstream fin("Triangle.txt");
        string tempName;
        double tempSide;
        if (!fin.is_open()) {
            cerr << "Unable to Triangle.txt" << endl;
            return;
        }
        while (fin >> tempName >> tempSide) {
            Triangle* newTriangle = new Triangle(tempName, tempSide);
            vector.push_back(dynamic_cast<Shape*>(newTriangle));
        }
        fin.close();
    }
};