// Copyright 2021 NNTU-CS
#include "train.h"

#include <cstdlib>

Train::Train() : countOp(0), first(nullptr), current(nullptr) {}

Train::~Train() {
    if (!first) return;
    
    Car* temp = first->next;
    while (temp != first) {
        Car* next = temp->next;
        delete temp;
        temp = next;
    }
    delete first;
}

void Train::addCar(bool light) {
    Car* newCar = new Car{light, nullptr, nullptr};
    
    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
        current = first;
    } else {
        Car* last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (!first) return 0;

    countOp = 0;

    current = first;

    if (!current->light) {
        current->light = true;
        countOp++;
    }
    
    int length = 0;
    bool found = false;
    
    while (!found) {
        int steps = 0;
        Car* temp = current;
        
        do {
            temp = temp->next;
            steps++;
            countOp++;
            
            if (temp->light) {
                temp->light = false;
                countOp++;
                
                for (int i = 0; i < steps; i++) {
                    temp = temp->prev;
                    countOp++;
                }
                
                if (temp == current && !current->light) {
                    length = steps;
                    found = true;
                }
                
                break;
            }
        } while (temp != current && !found);
    }
    
    return length;
}

int Train::getOpCount() {
    return countOp;
}
