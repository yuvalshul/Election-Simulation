#include "Coalition.h"
#include <vector>
#include "Agent.h"
#include "Party.h"
using namespace std;


Coalition::Coalition(Agent &a, Graph &g): cId(a.getId()), av{}, pv{}, cMAnd(g.getMandates(a.getPartyId()))
{
    av.push_back(a);
    pv.push_back(a.getPartyId());
    
}

int Coalition::get_cId(){
    return cId;
}

vector<Agent> Coalition::get_agents()
{
    return av;
}

vector<int> Coalition::get_parties()
{
    return pv;
}

void Coalition::add_agent(Agent &a)
{
    av.push_back(a);
}

void Coalition::add_party(int p, int pm)
{
    pv.push_back(p);
    cMAnd += pm;
}

int Coalition::get_mand()
{
    return cMAnd;
}




