#include "../include/JoinPolicy.h"
#include "Simulation.h"

using std::vector;



int LastOfferJoinPolicy::choose(Simulation& s, vector<int> offers)
{
    int bestOffer = offers.back();
    return bestOffer;
}

char LastOfferJoinPolicy::getType()
{
    return 'l';
}