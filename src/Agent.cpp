#include "Agent.h"
#include "Simulation.h"
#include "SelectionPolicy.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoal(nullptr)
{
    // You can change the implementation of the constructor, but not the signature!
}

Agent::Agent(const Agent &a) : mAgentId(a.mAgentId), mPartyId(a.mPartyId), mSelectionPolicy(a.mSelectionPolicy->clone()), mCoal(a.mCoal){} //copy constr


Agent::Agent(Agent &&a) : mAgentId(a.mAgentId), mPartyId(a.mPartyId), mSelectionPolicy(a.mSelectionPolicy), mCoal(a.mCoal) //move constr
{
    a.mSelectionPolicy = nullptr;
    a.mCoal = nullptr;
} 


Agent& Agent::operator=(Agent &&a) //move assignment operator
{
    mAgentId = a.mAgentId;
    mPartyId = a.mPartyId;
    delete(mSelectionPolicy); 
    mSelectionPolicy = a.mSelectionPolicy;
    mCoal = a.mCoal;
    a.mCoal = nullptr;
    a.mSelectionPolicy = nullptr;

    return *this;
}

Agent& Agent::operator=(const Agent &a) //copy assignment operator
{
    if(this != &a){
        mAgentId = a.mAgentId;
        mPartyId = a.mPartyId;
        delete(mSelectionPolicy); 
        mSelectionPolicy = a.mSelectionPolicy->clone();
        mCoal = a.mCoal;
    }
    return *this;
}

Agent::~Agent()
{   
    delete(mSelectionPolicy);
    mSelectionPolicy = nullptr;

}


void Agent::set_id(int id)
{
    mAgentId = id;
}

void Agent::set_partyId(int pId)
{
    mPartyId = pId;
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
    // TODO: implement this method
    Graph &g = sim.getGraph();
    vector<Party*> n = g.neighborsOf(mPartyId);
    mSelectionPolicy->select(n, g, *this);
}

void Agent::set_coal(Coalition &c)
{
    mCoal = &c;
}

Coalition* Agent::get_coal_pointer()
{
    return mCoal;
}

Agent::Agent():mAgentId(-2), mPartyId(-2), mSelectionPolicy(nullptr), mCoal(nullptr){}
