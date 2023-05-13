#include "../include/JoinPolicy.h"
#include "Simulation.h"
using std::vector;

int MandatesJoinPolicy::choose(Simulation& s, vector<int> offers)
{
    int bestOfferAgent = (offers)[0];
    for (int offer : offers)
        if(s.getCoalitionByCoalitionId(offer).getMandates()> s.getCoalitionByCoalitionId(bestOfferAgent).getMandates())
           bestOfferAgent = offer;
   return bestOfferAgent;
}

char MandatesJoinPolicy::getType()
{
    return 'm';
}