//
// Created by Asus on 15.05.2024.
//

#ifndef GIT_CONTEINER_VECTOR_H
#define GIT_CONTEINER_VECTOR_H

#endif //GIT_CONTEINER_VECTOR_H
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

template <typename T>
class Vector{
private:
    T* mas;
    int size;
    int capacity;
    void resize(){
        if(size + 1 == capacity){
            capacity *= 2;
            T* newMas = new T[capacity];
            for(int i = 0;i < size;i++){
                newMas[i] = mas[i];
            }
            delete[]mas;
            mas = newMas;
        }
    }
public:
    Vector() : size(0), capacity(10), mas(new T[capacity]){}
    ~Vector(){
        delete[]mas;
    }
    class Iterator{
    private:
        T* ptr;
    public:
        Iterator(T* pointer) : ptr(pointer){}
        T& operator*(){
            return *ptr;
        }
        Iterator& operator++(){
            ++ptr;
            return *this;
        }
        Iterator operator++(int) {
            Iterator temp = *this;
            ++ptr;
            return temp;
        }
        bool operator==(const Iterator& it) const{
            return ptr == it.ptr;
        }
        bool operator !=(const Iterator& it) const{
            return ptr != it.ptr;
        }
    };
    Iterator begin(){
        return Iterator(mas);
    }
    Iterator end(){
        return Iterator(mas + size);
    }
    bool isFull(){
        return size + 1 == capacity;
    }
    bool isEmpty(){
        return size == 0;
    }
    int getSize(){
        return size;
    }
    int getCapacity(){
        return capacity;
    }
    void push_back(T value){
        if(!isFull()){
            mas[size++] = value;
        }
        else{
            resize();
            mas[size++] = value;
        }
    }
    void pop_back(){
        if(!isEmpty()){
            T* newMas = new T[capacity];
            for(int i = 0;i < size - 1;i++){
                newMas[i] = mas[i];
            }
            delete[]mas;
            mas = newMas;
            size--;
        }
    }
    void pop_index(int index){
        T* newMas = new T[capacity];
        int j = 0;
        for(int i = 0;i < size;i++){
            if(i != index){
                newMas[j] = mas[i];
                j++;
            }
            else if(i == index){
                continue;
            }
        }
        delete[]mas;
        mas = newMas;
        size--;
    }
    void clear(){
        int count = size;
        for(int j = 0;j < count;j++){
            T*newMas = new T[capacity];
            for(int i = 0;i < size - 1;i++){
                newMas[i] = mas[i];
            }
            delete[]mas;
            mas = newMas;
            size--;
        }
    }
    T& operator[](int index) {
        return mas[index];
    }
};
