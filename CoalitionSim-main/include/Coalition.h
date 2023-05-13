#pragma once
#include <vector>
using std::vector;

class Agent;
class Coalition

{
public:
    Coalition(vector<int> partyId,vector<int> oPIds, int mandates,int coalitionId);

    ~Coalition();

    Coalition(const Coalition& other);

    Coalition(Coalition&& other);
    Coalition& operator=(const Coalition& other);

    Coalition& operator=(Coalition&& other);
    void addOfferToCoalition(int offeredParty);
    void addPartyToCoalition(int partyToAdd);
    void addMandates(int other_mandates);
    vector<int> getPartyIds();
    vector<int> getOfferedPartyIds();
    int getMandates();
    int getId();

private:
    vector<int> joinedPartyIds;
    vector<int> offeredPartyIds;
    int mandates;
    int coalitionId;
};
