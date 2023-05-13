#pragma once

#include <vector>
#include "Agent.h"
#include "Graph.h"
#include "Coalition.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;
    const Graph &getGraph() const;
    Graph &getGraphC();
    const vector<Agent> &getAgents() const;
    Agent& getAgentByPartyId(int partyId);
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    void addAgent(Agent agent);
    Coalition& getCoalitionRefByCoalitionId(int coalitionId);
    Coalition getCoalitionByCoalitionId(int coalitionId);
    Agent& getAgentById(int agentId);
    int getAgentAmount();


private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> coalitions;
};
