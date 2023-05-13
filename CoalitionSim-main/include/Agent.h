#pragma once
#include <vector>
#include "Neighbor.h"
#include "SelectionPolicy.h"
#include "Coalition.h"

class Simulation;

class Agent
{
public:

    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    ~Agent();
    Agent(const Agent& other);
    Agent(Agent&& other);
    Agent& operator=(const Agent& other);
    Agent& operator=(Agent&& other);


    int getPartyId() const;
    int getId() const;
    void step(Simulation &sim);
    int getCoalitionId();
    SelectionPolicy* getSelectionPolicy() const;
    void addNeighbor(int neighbor);
    void setNeighbors(const vector<int>& neighbors);
    void copySelectionPolicy(SelectionPolicy *sp);
    void setId(int newId);

    vector<int> getNeighbors();
    vector<int>& getRefNeighbors();

    Agent cloneAgent(int partyId, vector<int> neighbors);



private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int coalitionId;
    vector<int> neighbors;
};