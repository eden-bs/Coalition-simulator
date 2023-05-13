#include "SelectionPolicy.h"
#include <vector>
#include "Simulation.h"

int EdgeWeightSelectionPolicy::choose(Simulation& s, int mPartyId, vector<int>& neighbors) const
{
    auto graph = s.getGraphC();
    int bestSelection = neighbors[0];
    int bestWeight = graph.getEdgeWeight(mPartyId,bestSelection);
    for (int neighbor : neighbors) {
//        Party p = graph.getParty2(neighbor);
        int neighborWeight = graph.getEdgeWeight(mPartyId,neighbor);
        if (bestWeight < neighborWeight) {
            bestSelection = neighbor;
            bestWeight = neighborWeight;
        }
    }
    return bestSelection;
}

int EdgeWeightSelectionPolicy::getType() {
    return '0';
}