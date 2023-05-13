
#include "../include/Coalition.h"


Coalition::Coalition(vector<int> jPIds, vector<int> oPIds, int m, int id): joinedPartyIds(jPIds),offeredPartyIds(oPIds), mandates(m), coalitionId(id)
{
}

Coalition:: ~Coalition() = default;

Coalition::Coalition(const Coalition& other): joinedPartyIds(other.joinedPartyIds), offeredPartyIds(other.offeredPartyIds), mandates(other.mandates), coalitionId(other.coalitionId)
{
}

Coalition::Coalition(Coalition&& other):joinedPartyIds(other.joinedPartyIds), offeredPartyIds(other.offeredPartyIds), mandates(other.mandates), coalitionId(other.coalitionId)
{
}

Coalition& Coalition::operator=(const Coalition& other)
{
    if (this ==&other)
        return *this;
    mandates = other.mandates;
    joinedPartyIds = other.joinedPartyIds;
    offeredPartyIds =other.offeredPartyIds;
    coalitionId = other.coalitionId;
    return *this;
}

Coalition& Coalition::operator=(Coalition&& other)
{
    if (this ==&other)
        return *this;
    mandates = other.mandates;
    joinedPartyIds = other.joinedPartyIds;
    offeredPartyIds =other.offeredPartyIds;
    coalitionId = other.coalitionId;
    return *this;
}


void Coalition::addPartyToCoalition(int partyToAdd)
{
    joinedPartyIds.push_back(partyToAdd);
}

void Coalition::addOfferToCoalition(int offeredParty) {
    offeredPartyIds.push_back(offeredParty);
}


void Coalition::addMandates(int other_mandates)
{
    mandates += other_mandates;
}


vector<int> Coalition::getPartyIds()
{
    return joinedPartyIds;
}

vector<int> Coalition::getOfferedPartyIds()
{
    return offeredPartyIds;
}

int Coalition::getMandates()
{
    return mandates;
}

int Coalition::getId()
{
    return coalitionId;
}
