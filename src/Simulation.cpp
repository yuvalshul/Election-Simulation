#include "Simulation.h"
#include "Agent.h"
#include <vector>
#include "Graph.h"
#include "Coalition.h"
using std::vector;

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), coalitions{} 
{
    int agentsSize = mAgents.size();
    for(int i = 0; i<agentsSize; i++)
    {
        Coalition c(mAgents[i], mGraph);
        coalitions.push_back(c);    //creating a coalition base on the given agents - its a vector of pointer because we want 1 copy of each coalition
    }

    for(int i =0; i<agentsSize; i++)
    {
        mAgents[i].set_coal(coalitions[i]); //setting the coal fiels to each agents base on the coalitions we created in the 1st loop
    }
    
}

void Simulation::step()
{
    // TODO: implement this method
    
    for (int i = 0; i < mGraph.getNumVertices(); i++)
    {
        mGraph.getParty(i)->step(*this);
        
    }
    int mAgentsSize = mAgents.size();
    for (int i = 0; i < mAgentsSize; i++)
    {
        mAgents[i].step(*this);
    }
    
    
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method

    bool terminate = false;
    int numOfJoined = 0;
    int coalitionsSize = coalitions.size();
    for(int i = 0; i < coalitionsSize && !terminate; i++)
    {
        Coalition c = coalitions[i];
        int numOfParties = c.get_parties().size();
        numOfJoined = numOfJoined + numOfParties;
        if (c.get_mand() > 60)
            terminate = true;
    }
    if (numOfJoined == mGraph.getNumVertices() && !terminate)
    {
       terminate = true;
    }
    return terminate;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    vector<vector<int>> output(coalitions.size()); 
    int coalitionsSize = coalitions.size();
    for (int i = 0; i < coalitionsSize; i++)
    {
        Coalition c = coalitions[i];
        vector<int> parties = c.get_parties();
        int partiesSize = parties.size();
        for (int j = 0; j < partiesSize; j++)
        {
            output[i].push_back(parties[j]);
        }
        
    }

    return output;
    
}

void Simulation::addAgent(Agent &a){
    mAgents.push_back(a);
}


Graph& Simulation::getGraph()
{
    return mGraph;
}
