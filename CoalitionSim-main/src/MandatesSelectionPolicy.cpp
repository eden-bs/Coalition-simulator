#include "SelectionPolicy.h"
#include <vector>
#include "Simulation.h"

int MandatesSelectionPolicy::choose(Simulation& s, int mPartyId, vector<int>& neighbors) const
{
    auto graph = s.getGraphC();
    int bestSelection = neighbors[0];
    for (auto neighbor : neighbors)
    {
        if (graph.getMandates(neighbor) > graph.getMandates(bestSelection))
            bestSelection = neighbor;
    }
    return bestSelection;
}

int MandatesSelectionPolicy::getType() {
    return 1;
}