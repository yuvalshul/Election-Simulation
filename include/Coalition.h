#pragma once

#include <vector>
#include "Agent.h"
using namespace std;


class  Coalition
{
private:
    int cId;
    vector<Agent> av;
    vector<int> pv;
    int cMAnd;
public:
    Coalition(Agent &a, Graph &g);
    int get_cId();
    vector<Agent> get_agents();
    vector<int> get_parties();
    void add_agent(Agent &a);
    void add_party(int p, int pm);
    int get_mand();
};