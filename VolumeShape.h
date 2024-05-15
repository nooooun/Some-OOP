//
// Created by Asus on 15.05.2024.
//

#ifndef GIT_CONTEINER_VOLUMESHAPE_H
#define GIT_CONTEINER_VOLUMESHAPE_H

#endif //GIT_CONTEINER_VOLUMESHAPE_H
#pragma once

#include "Shape.h"

class VolumeShape : public Shape{
public:
    VolumeShape(string name) : Shape(name){}
    virtual double calcPer() = 0;
    virtual double calcArea() = 0;
    virtual double calcVolume() = 0;
    virtual void print() = 0;
    friend ostream& operator <<(ostream& OS, VolumeShape& vs){
        vs.print();
        return OS;
    }
    friend istream& operator >>(istream& IS, VolumeShape& vs){
        IS >> vs.name;
        return IS;
    }
};