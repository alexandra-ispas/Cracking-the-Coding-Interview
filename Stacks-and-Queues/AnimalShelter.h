#ifndef STACKS_AND_QUEUES_ANIMALSHELTER_H
#define STACKS_AND_QUEUES_ANIMALSHELTER_H

#include "Utils.h"
#include "Queue.cpp"

class Animal {
public:
    string race;
    string name;
    int time;

    Animal(string race) {
        this->race = race;
    }
};

class AnimalShelter {
    Queue<Animal *> *dogs;
    Queue<Animal *> *cats;
    int time;

public:
    AnimalShelter();
    ~AnimalShelter();
    void enqueue(Animal *animal);
    int getTime();
    Animal *dequeueAny();
    Animal *dequeueDog();
    Animal *dequeueCat();
};


#endif //STACKS_AND_QUEUES_ANIMALSHELTER_H
