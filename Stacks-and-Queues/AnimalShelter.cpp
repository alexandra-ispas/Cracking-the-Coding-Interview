#include "AnimalShelter.h"

AnimalShelter::AnimalShelter() {
    dogs = new Queue<Animal *>();
    cats = new Queue<Animal *>();
    time = 0;
}

AnimalShelter::~AnimalShelter() {
    delete dogs;
    delete cats;
}

int AnimalShelter::getTime () {
    return time;
}

void AnimalShelter::enqueue (Animal *animal) {
    animal->time = time;
    if(animal->race == "dog") {
        dogs->add(animal);
    } else {
        cats->add(animal);
    }
    time++;
}

Animal *AnimalShelter::dequeueAny () {
    Animal *toReturn;
    if(dogs->peek()->time < cats->peek()->time) {
        toReturn = dogs->peek();
        dogs->remove();
    } else {
        toReturn = cats->peek();
    }
    time--;
    return toReturn;
}

Animal *AnimalShelter::dequeueDog () {
    if(!dogs->isEmpty()) {
        Animal *toReturn = dogs->peek();
        dogs->remove();
        return toReturn;
    } else {
        throw("no dogs");
    }
}

Animal *AnimalShelter::dequeueCat () {
    if(!cats->isEmpty()) {
        Animal *toReturn = cats->peek();
        cats->remove();
        return toReturn;
    } else {
        throw("no cats");
    }
}
