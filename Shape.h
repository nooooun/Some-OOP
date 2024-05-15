//
// Created by Asus on 15.05.2024.
//

#ifndef GIT_CONTEINER_SHAPE_H
#define GIT_CONTEINER_SHAPE_H

#endif //GIT_CONTEINER_SHAPE_H
#pragma once

#include "Vector.h"

using namespace std;

const double p = 3.14;

class Shape{
protected:
    string name;
public:
    Shape(string n) : name(n){}
    virtual double calcPer() = 0;
    virtual double calcArea() = 0;
    virtual void print() = 0;
    friend ostream& operator << (ostream& OS, Shape& sh){
        sh.print();
        return OS;
    }
    friend istream& operator >> (istream& IS, Shape& sh){
        IS >> sh.name;
        return IS;
    }
};