#pragma once
#include <string>
#include "JoinPolicy.h"
#include "State.h"
#include "Agent.h"
using std::string;

class Simulation;

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *jp);
    ~Party();
    Party(const Party& other);
    Party(Party&& other);
    Party& operator=(const Party& other);
    Party& operator=(Party&& other);

    JoinPolicy& getJP();
    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    void addOffer(int offerAgentId);
    

private:

    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    vector<int> offersByAgentId;
    int timer;
};
