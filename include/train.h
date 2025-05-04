// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
private:
    struct Car {
        bool light;    // состояние лампочки
        Car* next;     // указатель на следующий вагон
        Car* prev;     // указатель на предыдущий вагон
    };
    
    int countOp;       // счетчик операций
    Car* first;       // указатель на первый вагон
    Car* current;      // указатель на текущий вагон

public:
    Train();
    ~Train();
    void addCar(bool light);  // добавить вагон с указанным состоянием лампочки
    int getLength();          // вычислить длину презда
    int getOpCount();         // вернуть число переходов
};

#endif // TRAIN_H
