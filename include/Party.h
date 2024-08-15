#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class JoinPolicy;
class Simulation;
class Agent;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    //rule of 5:
    Party(const Party &p); //copy constr
    Party(Party &&p); //move constr
    Party& operator=(const Party &p) ; //copy assign opertator
    Party& operator=(Party &&p); //move assign operator
    ~Party(); //destr

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    void addOffer(Agent &a);
    int getId();
    vector<Agent> get_mOffers();

    

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int mTimer; //myField
    vector<Agent> mOffers;//myField    
    

};
