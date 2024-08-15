#pragma once

#include <vector>
#include "Coalition.h"
#include "Graph.h"
#include "Agent.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;
    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    void addAgent(Agent &a); //our f
    Graph &getGraph();

    

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> coalitions;
};
