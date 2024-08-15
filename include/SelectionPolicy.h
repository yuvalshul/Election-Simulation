#pragma once
#include <vector>
using std::vector;

class Party;
class Agent;
class Graph;

class SelectionPolicy
{
public:
    virtual SelectionPolicy* clone() const = 0;
    virtual void select(vector<Party*> &n, Graph &g, Agent &a) = 0;
    virtual ~SelectionPolicy() = default;
};

class MandatesSelectionPolicy : public SelectionPolicy
{
    virtual SelectionPolicy* clone() const override;
    virtual void select(vector<Party*> &n, Graph &g, Agent &a) override;
    virtual ~MandatesSelectionPolicy() = default;
};

class EdgeWeightSelectionPolicy : public SelectionPolicy
{
    virtual SelectionPolicy* clone() const override;
    virtual void select(vector<Party*> &n, Graph &g, Agent &a) override;
    virtual ~EdgeWeightSelectionPolicy() = default;
};