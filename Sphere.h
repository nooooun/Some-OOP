//
// Created by Asus on 15.05.2024.
//

#ifndef GIT_CONTEINER_SPHERE_H
#define GIT_CONTEINER_SPHERE_H

#endif //GIT_CONTEINER_SPHERE_H
#include "VolumeShape.h"

class Sphere : public VolumeShape{
private:
    double radius;
public:
    Sphere() : VolumeShape(" "), radius(0.0){}
    Sphere(string name, double r) : VolumeShape(name), radius(r){}

    double calcPer() override { return 0; }
    double calcArea() override { return 4 * p * pow(radius,2); }
    double calcVolume() override { return 4 * p * pow(radius,3) / 3; }
    void print() override {
        cout << name << endl << "Per: " << calcPer() << ", area: " << calcArea() << " and volume: " << calcVolume() << endl;
    }
    friend ostream& operator << (ostream& OS, Sphere& s){
        OS << s.name << endl << "Per: " << s.calcPer() << ", area: " << s.calcArea() << " and volume: " << s.calcVolume() << endl;
        return OS;
    }
    friend istream& operator >>(istream& IS, Sphere& s){
        IS >> s.name >> s.radius;
        return IS;
    }
    static void input(Vector<VolumeShape*>&vector) {
        ifstream fin("Sphere.txt");
        string tempName;
        double tempRadius;
        if (!fin.is_open()) {
            cerr << "Unable to open Sphere.txt" << endl;
            return;
        }
        while (fin >> tempName >> tempRadius) {
            Sphere* newSphere = new Sphere(tempName, tempRadius);
            vector.push_back(dynamic_cast<VolumeShape*>(newSphere));
        }
        fin.close();
    }
};