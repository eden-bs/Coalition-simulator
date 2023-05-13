
#include "../include/Neighbor.h"
//implement rule of 5
Neighbor::Neighbor(int id, int mandates, int weight, State state) 
: id(id), mandates(mandates), weight(weight), mState(state)
{

}

int Neighbor::getId()
{
    return id;
}

int Neighbor::getMandates(){
    return mandates;
}

int Neighbor::getWeight()
{
    return weight;
}

void Neighbor::setState(State newState)
{
    mState = newState;
}

//Neighbor::Neighbor() {
//    id = -1;
//    mandates=-1;
//    weight=-1;
//    mState=Waiting;
//}
