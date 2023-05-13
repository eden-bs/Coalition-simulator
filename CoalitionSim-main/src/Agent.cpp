
#include "Agent.h"
#include "Simulation.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy):mAgentId(agentId), mPartyId(partyId),
 mSelectionPolicy(selectionPolicy), coalitionId(mAgentId), neighbors()
{
// You can change the implementation of the constructor, but not the signature!
}

Agent:: ~Agent()
{
    delete mSelectionPolicy;
    mSelectionPolicy = nullptr;
}

Agent::Agent(const Agent& other):
    mAgentId(other.mAgentId), mPartyId(other.mPartyId),
    mSelectionPolicy(nullptr), coalitionId(other.coalitionId),
    neighbors(other.neighbors)
{
    if (other.mSelectionPolicy){
        int type = (other.mSelectionPolicy)->getType();
        if (type == 1)
            mSelectionPolicy = new MandatesSelectionPolicy;
        else
            mSelectionPolicy = new EdgeWeightSelectionPolicy;
        }
}

Agent::Agent(Agent&& other):mAgentId(other.mAgentId), mPartyId(other.mPartyId),
 mSelectionPolicy(other.mSelectionPolicy), coalitionId(other.coalitionId), neighbors(other.neighbors)
{
    other.mSelectionPolicy = nullptr;
}

Agent& Agent::operator=(const Agent& other)
{
    if (this == &other)
            return *this;
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        coalitionId= other.coalitionId;
        neighbors = other.neighbors;
        if (other.mSelectionPolicy){
            int type = (other.mSelectionPolicy)->getType();
            if (type == 1)
                mSelectionPolicy = new MandatesSelectionPolicy;
            else
                mSelectionPolicy = new EdgeWeightSelectionPolicy;
        }
        return *this;
}

Agent& Agent::operator=(Agent&& other)
{
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    coalitionId = other.coalitionId;
    neighbors = other.neighbors;
    delete mSelectionPolicy;
    mSelectionPolicy = other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
    return *this;
}


int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}


void Agent::step(Simulation &sim)
{
    auto &graph = sim.getGraphC();
    for (unsigned int i = 0; i < neighbors.size();i++)
    {
        int nId = neighbors[i];
        Party party = graph.getParty(nId);

        if (party.getState() == Joined)
            neighbors.erase(neighbors.begin()+i);
    }
    if (neighbors.empty()){
        return;
    }

    int partyToOffer = mSelectionPolicy->choose(sim, mPartyId, neighbors);

    Coalition& coalition = sim.getCoalitionRefByCoalitionId(coalitionId);
    coalition.addOfferToCoalition(partyToOffer);
    for (int party: coalition.getPartyIds())
    {
        Agent& agent = sim.getAgentByPartyId(party);
        vector<int>& neighborsTemp = agent.getRefNeighbors();
        for (unsigned int i =0; i< neighborsTemp.size();i++)
            if (neighborsTemp[i] == partyToOffer)
                neighborsTemp.erase(neighborsTemp.begin()+i);
    }
    Party &p = graph.getParty2(partyToOffer);
    int offer = mAgentId;
    p.addOffer(offer);
    if (p.getState() == Waiting)
        p.setState(CollectingOffers);
    //for party in neighbors if party waiting/collectingOffers find most suitable by SelectionPolicy and send offer
}

int Agent::getCoalitionId()
{
    return coalitionId;
}


vector<int> Agent::getNeighbors()
{
    return neighbors;
}
vector<int>& Agent::getRefNeighbors()
{
    return neighbors;
}


void Agent::addNeighbor(int neighbor){
    neighbors.push_back(neighbor);
}

SelectionPolicy* Agent::getSelectionPolicy() const
{
    return mSelectionPolicy;
}

void Agent::setNeighbors(const vector<int>& newNeighbors)
{
    neighbors = newNeighbors;
}

void Agent::copySelectionPolicy(SelectionPolicy *sp)
{
    if (sp->getType()==1)
        mSelectionPolicy = new MandatesSelectionPolicy;
    else
        mSelectionPolicy = new EdgeWeightSelectionPolicy;
}

//Agent& Agent::cloneAgent(int partyId, vector<int> neighbors)
//{
//
//    Agent *agentClone =new Agent(*this);
//    agentClone->setNeighbors(neighbors);
//    agentClone->mPartyId =partyId;
//    return *agentClone;
//}
Agent Agent::cloneAgent(int partyId, vector<int> neighbors)
{
    Agent agentClone =Agent(*this);
    agentClone.setNeighbors(neighbors);
    agentClone.mPartyId =partyId;
    return agentClone;
}

void Agent::setId(int newId)
{
    mAgentId = newId;
}



