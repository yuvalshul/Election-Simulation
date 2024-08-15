#pragma once
#include "Party.h"
#include <vector>
using std::vector;


class JoinPolicy 
{
    public:
    virtual JoinPolicy* clone() const = 0;
    virtual void join(vector<Agent> &mOffers, Simulation &s, int partyId) = 0;
    virtual ~JoinPolicy() = default;
};

class MandatesJoinPolicy : public JoinPolicy 
{
    public:
    virtual JoinPolicy* clone() const override;
    virtual void join(vector<Agent> &mOffers, Simulation &s, int partyId) override;
    virtual ~MandatesJoinPolicy() = default;
};

class LastOfferJoinPolicy : public JoinPolicy 
{
    public:
    virtual JoinPolicy* clone() const override;
    virtual void join(vector<Agent> &mOffers, Simulation &s, int partyId) override;
    virtual ~LastOfferJoinPolicy() = default;
};