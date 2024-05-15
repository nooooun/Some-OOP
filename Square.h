//
// Created by Asus on 15.05.2024.
//

#ifndef GIT_CONTEINER_SQUARE_H
#define GIT_CONTEINER_SQUARE_H

#endif //GIT_CONTEINER_SQUARE_H
#pragma once

#include "Shape.h"

class Square : public Shape{
private:
    double edge;
public:
    Square() : Shape(" "), edge(0.0){}
    Square(string name, double e) : Shape(name), edge(e){}

    double calcPer() override{
        return edge * 4;
    }
    double calcArea() override{
        return pow(edge, 2);
    }
    void print() override{
        cout << name << endl << "Per: " << calcPer() << " and area: " << calcArea() << endl;
    }
    friend ostream& operator<<(ostream& OS, Square& s){
        OS << s.name << endl << "Per: " << s.calcPer() << " and area: " << s.calcArea() << endl;
        return OS;
    }
    friend istream& operator >> (istream& IS, Square& s){
        IS >> s.name >> s.edge;
        return IS;
    }
    static void input(Vector<Shape*>&vector) {
        ifstream fin("Square.txt");
        string tempName;
        double tempEdge;
        if (!fin.is_open()) {
            cerr << "Unable to Square.txt" << endl;
            return;
        }
        while (fin >> tempName >> tempEdge) {
            Square* newSquare = new Square(tempName, tempEdge);
            vector.push_back(dynamic_cast<Shape*>(newSquare));
        }
        fin.close();
    }
};
