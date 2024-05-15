#include "Vector.h"
#include "Square.h"
#include "Cube.h"
#include "Circle.h"
#include "Sphere.h"
#include "Traingle.h"
#include "Wedge.h"

int main() {
    Vector<Shape*>shape;
    Vector<VolumeShape*>volumeshape;

    Square::input(shape);
    Circle::input(shape);
    Triangle::input(shape);

    Cube::input(volumeshape);
    Sphere::input(volumeshape);
    Wedge::input(volumeshape);

    cout << endl <<"Shapes:" << endl;
    for(auto a : shape){
        cout << *a;
    }
    cout << endl << "Volume Shapes:" << endl;
    for(auto a : volumeshape){
        cout << *a;
    }
    shape.pop_index(2);
    cout << endl << "Shapes after pop_index():" << endl;
    for(auto a : shape){
        cout << *a;
    }
    volumeshape.clear();
    cout << endl << "Volume shapes after clear():" << endl;
    for(auto a : volumeshape){
        cout << *a;
    }
    return 0;
}
