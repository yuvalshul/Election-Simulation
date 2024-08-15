#pragma once

#include <vector>
#include "Graph.h"

class SelectionPolicy;
class Coalition;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    
    Agent(const Agent &a); //copy constr

    Agent(Agent &&a); //move constr

    Agent& operator=(Agent &&a);//move assignment operator 

    Agent& operator=(const Agent &a);  //copy assignment

    ~Agent();//destrucur

    Agent();


    int getPartyId() const;
    int getId() const;
    void step(Simulation &sim);
    void set_coal(Coalition &c);
    void set_id(int id);
    void set_partyId(int pId);
    Coalition* get_coal_pointer();

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    Coalition *mCoal;
};
