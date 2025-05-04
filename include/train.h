// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
    struct Car {
        bool light;    // состояние лампочки
        Car* next;
        Car* prev; 
    };
    
    int countOp;       // счетчик шагов (переходов между вагонами)
    Car* first;        // первый вагон поезда
    Car* current;      // текущий вагон, в котором находится наблюдатель

 public:
    Train();
    ~Train();
    void addCar(bool light);  // добавить вагон с указанным состоянием лампочки
    int getLength();          // вычислить длину поезда
    int getOpCount();         // вернуть количество переходов
};

#endif  // TRAIN_H
