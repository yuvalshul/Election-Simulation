#include "JoinPolicy.h"
#include "Simulation.h"



JoinPolicy* MandatesJoinPolicy::clone() const
{
    return new MandatesJoinPolicy(*this);
}


void MandatesJoinPolicy::join(vector<Agent> &mOffers, Simulation &s, int partyId) 
{
    Agent a(mOffers[0]);
    Graph g = s.getGraph();
    int mand = a.get_coal_pointer()->get_mand();
    for (unsigned int i = 1; i < mOffers.size(); i++)
    {
        Agent curr = mOffers[i];
        if (mand < curr.get_coal_pointer()->get_mand())
        {
            a = curr;
            mand = curr.get_coal_pointer()->get_mand();
        }
    }
    Agent clone(a);
    clone.set_partyId(partyId);
    clone.set_id(s.getAgents().size());    
    s.addAgent(clone);
    a.get_coal_pointer()->add_party(partyId, g.getMandates(partyId));
    a.get_coal_pointer()->add_agent(clone);
}



JoinPolicy* LastOfferJoinPolicy::clone() const
{
    return new LastOfferJoinPolicy(*this);
}


void LastOfferJoinPolicy::join(vector<Agent> &mOffers, Simulation &s, int partyId){
    Agent a = mOffers[mOffers.size()-1];
    Agent clone(a);
    clone.set_partyId(partyId);
    clone.set_id(s.getAgents().size());
    s.addAgent(clone);
    a.get_coal_pointer()->add_party(partyId, s.getGraph().getMandates(partyId));
    a.get_coal_pointer()->add_agent(clone);
}