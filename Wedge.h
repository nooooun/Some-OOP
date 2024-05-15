//
// Created by Asus on 15.05.2024.
//

#ifndef GIT_CONTEINER_WEDGE_H
#define GIT_CONTEINER_WEDGE_H

#endif //GIT_CONTEINER_WEDGE_H
#pragma once

#include "VolumeShape.h"

class Wedge : public VolumeShape{
private:
    double side;
    double height;
public:
    Wedge() : VolumeShape(" "), side(0.0), height(0.0){}
    Wedge(string name, double s, double h) : VolumeShape(name), side(s), height(h){}

    double calcPer() override { return 6 * side + 3 * height; }
    double calcArea() override { return (sqrt(3) * pow(side,2) / 2) + (3 * side * height); }
    double calcVolume() override { return sqrt(3) * pow(side,2) * height / 4; }

    void print() override {
        cout << name << endl << "Per: " << calcPer() << ", area: " << calcArea() << " and volume: " << calcVolume() << endl;
    }
    friend ostream& operator << (ostream& OS, Wedge& w){
        OS << w.name << endl << "Per: " << w.calcPer() << ", area: " << w.calcArea() << " and volume: " << w.calcVolume() << endl;
        return OS;
    }
    friend istream& operator >> (istream& IS, Wedge& w){
        IS >> w.name >> w.side >> w.height;
        return IS;
    }
    static void input(Vector<VolumeShape*>&vector) {
        ifstream fin("Wedge.txt");
        string tempName;
        double tempSide;
        double tempHeight;
        if (!fin.is_open()) {
            cerr << "Unable to open Wedge.txt" << endl;
            return;
        }
        while (fin >> tempName >> tempSide >> tempHeight) {
            Wedge* newWedge = new Wedge(tempName, tempSide, tempHeight);
            vector.push_back(dynamic_cast<VolumeShape*>(newWedge));
        }
        fin.close();
    }
};