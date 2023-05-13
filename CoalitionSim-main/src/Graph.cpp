#include "Graph.h"
using std::vector;



Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!

}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

Party &Graph::getParty2(int partyId)
{
    return mVertices[partyId];
}

vector<Party>& Graph::getPartyVector()
{
    return mVertices;
}


 vector<int> Graph::getNeighborIds(int v)
{
    vector<int> neighbors = vector<int>();
    int n = this->getNumVertices();
    for (int i = 0; i < n; i++)
    {
        if (mEdges[v][i] > 0)
        {
            neighbors.push_back(i);
        }
        
    }
    return neighbors;
}


State Graph::getStateById(int id) {
    Party myParty = getParty(id);
    State myState = myParty.getState();
    return myState;
}
