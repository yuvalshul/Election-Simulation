#include "Party.h"
#include "JoinPolicy.h"
#include "Simulation.h"
#include "Agent.h"
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), mTimer(3), mOffers{}{}


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

void Party::step(Simulation &s)
{
    // TODO: implement this method

    if (mState == CollectingOffers)
    {
        mTimer--;
    }
    if (mTimer == 0)
    {
        mState = Joined;
        mTimer = -1;
        mJoinPolicy->join(mOffers, s, mId);
    }
}

void Party::addOffer(Agent &a)
{
    mOffers.push_back(a);
    if(mState == Waiting)
        mState = CollectingOffers;
    
}

int Party::getId()
{
    return mId;
}

// rule of 5:
Party::Party(const Party &p):mId(p.mId), mName(p.mName), mMandates(p.mMandates), mJoinPolicy(p.mJoinPolicy->clone()), mState(p.mState), mTimer(p.mTimer), mOffers(p.mOffers){} // copy constr

Party::Party(Party &&p) : mId(p.mId), mName(p.mName), mMandates(p.mMandates), mJoinPolicy(p.mJoinPolicy), mState(p.mState), mTimer(p.mTimer), mOffers(p.mOffers) // move constr
{
    p.mJoinPolicy = nullptr;
}
Party &Party::operator=(const Party &p) // copy assign opertator
{
    if (this != &p)
    {
        mId = p.mId;
        mName = p.mName;
        mMandates = p.mMandates;
        delete (mJoinPolicy);
        mJoinPolicy = p.mJoinPolicy->clone();
        mState = p.mState;
        mTimer = p.mTimer;
        mOffers.clear();
        mOffers = p.mOffers;
    }
    return *this;
}
Party &Party::operator=(Party &&p) // move assign operator
{
    mId = p.mId;
    mName = p.mName;
    mMandates = p.mMandates;
    delete (mJoinPolicy);
    mJoinPolicy = p.mJoinPolicy;
    mState = p.mState;
    mTimer = p.mTimer;
    mOffers = p.mOffers;
    return *this;
}
Party::~Party() // destr
{
    delete(mJoinPolicy);
    mJoinPolicy = nullptr;    
}

vector<Agent> Party::get_mOffers()
{
    return mOffers;
}

