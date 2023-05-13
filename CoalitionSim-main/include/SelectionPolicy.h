#pragma once
#include <vector>
// #include "Neighbor.h"
class Simulation;
using std::vector;

class SelectionPolicy { 
    public:
        SelectionPolicy() = default;
        virtual ~SelectionPolicy() = default;
        virtual int getType() = 0;
        virtual int choose(Simulation& s, int mPartyId, vector<int>& neighbors) const = 0;
};

class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
        MandatesSelectionPolicy()=default;
        virtual ~MandatesSelectionPolicy() = default;
        virtual int getType(); // 1
        virtual int choose(Simulation& s,int mPartyId, vector<int>& neighbors) const;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        EdgeWeightSelectionPolicy()=default;
        virtual ~EdgeWeightSelectionPolicy() = default;
        virtual int getType(); // 0
        virtual int choose(Simulation& s, int mPartyId, vector<int>& neighbors) const;
};


