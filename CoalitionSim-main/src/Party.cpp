#include "Party.h"
#include "Simulation.h"



Party::Party(int id, string name, int mandates, JoinPolicy *jp) :
    mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), 
    mState(Waiting), offersByAgentId(), timer(0) 
{
    // You can change the implementation of the constructor, but not the signature!
}


Party:: ~Party()
{
    delete mJoinPolicy;
    mJoinPolicy = nullptr;
}


Party::Party(const Party& other):
    mId(other.mId), mName(other.mName), mMandates(other.mMandates),
    mJoinPolicy(nullptr), mState(other.mState),
    offersByAgentId(other.offersByAgentId), timer(other.timer)
{
    if (other.mJoinPolicy){
        if (other.mJoinPolicy->getType() == 'l')
            mJoinPolicy = new LastOfferJoinPolicy;
        else
            mJoinPolicy = new MandatesJoinPolicy;
    }

}


Party::Party(Party&& other):
    mId(other.mId), mName(other.mName), mMandates(other.mMandates),
    mJoinPolicy(other.mJoinPolicy), mState(other.mState),
    offersByAgentId(other.offersByAgentId), timer(other.timer)
{
    other.mJoinPolicy = nullptr;
}


Party& Party::operator=(const Party& other)
{
    if (this == &other)
        return *this;
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mJoinPolicy = nullptr;
    if (other.mJoinPolicy){
        if (other.mJoinPolicy->getType() == 'l')
            mJoinPolicy = new LastOfferJoinPolicy;
        else
            mJoinPolicy = new MandatesJoinPolicy;
    }
    mState = other.mState;
    offersByAgentId = other.offersByAgentId;
    timer = other.timer;
    return *this;
}


Party& Party::operator=(Party&& other)
{
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mJoinPolicy = other.mJoinPolicy;
    other.mJoinPolicy = nullptr;
    mState = other.mState;
    offersByAgentId = other.offersByAgentId;
    timer = other.timer;
    return *this;
}


JoinPolicy& Party::getJP(){
    return *mJoinPolicy;
}


State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string &Party::getName() const
{
    return mName;
}


void Party::addOffer(int offerAgentId)
{
    offersByAgentId.push_back(offerAgentId);
}

void Party::step(Simulation &s) {
    if (mState !=CollectingOffers)
        return;

    if (timer < 2)
    {
        timer++;
        return;
    }

    int chosenAgentId = mJoinPolicy->choose(s, offersByAgentId);
    Graph &g = s.getGraphC();
    Agent& chosenAgent = s.getAgentById(chosenAgentId);
    Coalition &chosenCoalition = s.getCoalitionRefByCoalitionId(chosenAgent.getCoalitionId());
    chosenCoalition.addMandates(mMandates);
    mState = Joined;
    vector<int> neighbors = g.getNeighborIds(mId);
    for (int offeredParty:chosenCoalition.getOfferedPartyIds())
        for (unsigned int i = 0; i < neighbors.size(); ++i)
            if (neighbors[i] == offeredParty)
                neighbors.erase(neighbors.cbegin()+i);
//    Agent& cloneAgent = chosenAgent.cloneAgent(mId, neighbors);
    Agent cloneAgent = chosenAgent.cloneAgent(mId, neighbors);
    cloneAgent.setId(s.getAgentAmount());
    s.addAgent(cloneAgent);
    chosenCoalition.addPartyToCoalition(mId);
}


