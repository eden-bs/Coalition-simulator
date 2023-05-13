#pragma once

#include <vector>
#include "State.h"



class Neighbor
{
public:
    Neighbor(int id, int mandates, int weight, State state);
    ~Neighbor() = default;
    Neighbor(const Neighbor& other): id(other.id), mandates(other.mandates), weight(other.weight), mState(other.mState){};
//    Neighbor(Neighbor&& other) : id(other.id), mandates(other.mandates), weight(other.weight), mState(other.mState)  {};
//    Neighbor& operator=(const Neighbor &other) {
//        this->id = other.id;
//        this->mandates = other.mandates;
//        this->weight = other.weight;
//        this->mState = other.mState;
//        return *this;
//    };
//    Neighbor& operator=(const Neighbor&& other){
//        this->id = other.id;
//        this->mandates = other.mandates;
//        this->weight = other.weight;
//        this->mState = other.mState;
//        return *this;
//    }


    int getId();
    int getMandates();
    int getWeight();
    void setState(State state);

private:
    int id;
    int mandates;
    int weight;
    State mState;
};
