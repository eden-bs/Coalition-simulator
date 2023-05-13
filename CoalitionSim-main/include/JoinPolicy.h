#pragma once
#include <vector>
using std::vector;

class Simulation;
class JoinPolicy {
    public:
        JoinPolicy() = default;
        virtual ~JoinPolicy() = default;
        virtual char getType() = 0;
        virtual int choose(Simulation &s, vector<int> offers) = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        MandatesJoinPolicy() = default;
        virtual char getType();
        virtual int choose(Simulation &s, vector<int> offers);

};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        LastOfferJoinPolicy() = default;
        virtual char getType();
        virtual int choose(Simulation &s, vector<int> offers);
};