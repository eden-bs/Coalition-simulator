#pragma once
#include <vector>
#include "Party.h"

class Neighbor;


using std::vector;

class Graph
{
public:
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    const Party &getParty(int partyId) const;
    Party &getParty2(int partyId);
    vector<Party> &getPartyVector();
    vector<int> getNeighborIds(int v);
    vector<Neighbor>& getNeighborsSet(int v);
    State getStateById(int id) ;

private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};
