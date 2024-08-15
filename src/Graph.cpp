#include "Graph.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges)
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}
Party* Graph::getParty(int partyId)
{
    return &mVertices[partyId];
}

const vector<Party*> Graph::neighborsOf(int partyId)
{
    vector<Party*> vec = {};
    int parties = mVertices.size();
    for (int i = 0; i < parties; i++)
    {
        if (getEdgeWeight(partyId, i) > 0 && getParty(i)->getState() != Joined)
            vec.push_back((getParty(i)));
    }
    return vec;
}
