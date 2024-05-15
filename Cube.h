//
// Created by Asus on 15.05.2024.
//

#ifndef GIT_CONTEINER_CUBE_H
#define GIT_CONTEINER_CUBE_H

#endif //GIT_CONTEINER_CUBE_H
#include "VolumeShape.h"

class Cube : public VolumeShape{
private:
    double edge;
public:
    Cube() : VolumeShape(" "), edge(0.0){}
    Cube(string name, double e) : VolumeShape(name), edge(e){}

    double calcPer() override { return edge * 12; }
    double calcArea() override { return pow(edge,2) * 6; }
    double calcVolume() override { return pow(edge,3); }
    void print() override {
        cout << name << endl << "Per: " << calcPer() << ", area: " << calcArea() << " and volume: " << calcVolume() << endl;
    }
    friend ostream& operator << (ostream& OS, Cube& c){
        OS << c.name << endl << "Per: " << c.calcPer() << ", area: " << c.calcArea() << " and volume: " << c.calcVolume() << endl;
        return OS;
    }
    friend istream& operator >> (istream& IS, Cube& c){
        IS >> c.name >> c.edge;
        return IS;
    }
    static void input(Vector<VolumeShape*>&vector) {
        ifstream fin("Cube.txt");
        string tempName;
        double tempEdge;
        if (!fin.is_open()) {
            cerr << "Unable to open Cube.txt" << endl;
            return;
        }
        while (fin >> tempName >> tempEdge) {
            Cube* newCube = new Cube(tempName, tempEdge);
            vector.push_back(dynamic_cast<VolumeShape*>(newCube));
        }
        fin.close();
    }
};