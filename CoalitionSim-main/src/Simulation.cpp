#include "Simulation.h"
#include <iostream>
using namespace std;


Simulation::Simulation(Graph graph, vector<Agent> agents) : 
mGraph(graph), mAgents(agents), coalitions()
{

    for(Agent& agent: mAgents){
        // Initiates agent's coalition
        int agentPartyId = agent.getPartyId();
        Coalition agentCoal = Coalition(vector<int> {agentPartyId},vector<int> {agentPartyId}, graph.getMandates(agentPartyId),agent.getId());
        coalitions.push_back(agentCoal);

        //initiates agent's Neighbors
        vector<int> agentNeighborsIds = mGraph.getNeighborIds(agent.getPartyId());
        for(int neighbor: agentNeighborsIds){
            agent.addNeighbor(neighbor);
        }
    }
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step()
{
    // TODO: implement this method
    for(auto &party:mGraph.getPartyVector())
        party.step(*this);

    for (auto &agent:mAgents)
        agent.step(*this);
}

bool Simulation::shouldTerminate() const
{
    for (auto coalition: coalitions)
        if (coalition.getMandates() >= 61)
            return true;
    for (int i = 0; i< mGraph.getNumVertices(); i++)
        if (mGraph.getParty(i).getState() != Joined)
            return false;
    return true;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}


Graph &Simulation::getGraphC()
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

Agent& Simulation::getAgentByPartyId(int partyId)
{
    for(Agent &a: mAgents)
        if (a.getPartyId() == partyId)
            return a;
    return mAgents[0];

}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

Agent& Simulation::getAgentById(int agentId)
{
    for(Agent& agent:mAgents)
        if (agent.getId()==agentId)
            return agent;
    return mAgents[0];
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<vector<int>> coalitionsVector;
    for (Coalition coalVector: coalitions)
    {
        coalitionsVector.push_back(coalVector.getPartyIds());
    }
    return coalitionsVector;
}

Coalition& Simulation::getCoalitionRefByCoalitionId(int coalitionId)
{
    for (Coalition &c: coalitions) {
        if (c.getId() == coalitionId)
            return c;
    }
    return coalitions[0];
}
Coalition Simulation::getCoalitionByCoalitionId(int coalitionId)
{
    for (Coalition c: coalitions) {
        if (c.getId() == coalitionId)
            return c;
    }
    return coalitions[0];
}

int Simulation::getAgentAmount()
{
    return mAgents.size();
}

void Simulation::addAgent(Agent agent)
{
    mAgents.push_back(agent);
}


