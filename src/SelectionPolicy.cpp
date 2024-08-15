#include "SelectionPolicy.h"
#include "Party.h"
#include "Simulation.h"


SelectionPolicy* MandatesSelectionPolicy::clone() const
{
    return new MandatesSelectionPolicy(*this);
}


void MandatesSelectionPolicy::select(vector<Party*> &n, Graph &g, Agent &a)
{
    Party demi= Party(-1, "", -1, nullptr);
    Party *offerTo = &demi;
    for (unsigned int i = 0; i < n.size(); i++)
    {
        vector<Agent> offers = n[i]->get_mOffers();
        bool canOfferTo = true;
        for (unsigned int j = 0; (j < offers.size()) & canOfferTo; j++) // checks if the agents coal already offered the party to join
        {
            if (offers[j].get_coal_pointer()->get_cId() == a.get_coal_pointer()->get_cId())
                canOfferTo = false;
        }

        if (canOfferTo && n[i]->getMandates() > offerTo->getMandates())
        {
            offerTo = n[i];
        }
    }
    if (offerTo->getId() != -1)
    {
        offerTo->addOffer(a);
    }
}

SelectionPolicy* EdgeWeightSelectionPolicy::clone() const
{
    return new EdgeWeightSelectionPolicy(*this);
}


void EdgeWeightSelectionPolicy::select(vector<Party*> &n, Graph &g, Agent &a)
{
    Party demi= Party(-1, "", -1, nullptr);
    Party *offerTo = &demi;
    int max = -1;
    for (unsigned int i = 0; i < n.size(); i++)
    {
        vector<Agent> offers = n[i]->get_mOffers();
        bool canOfferTo = true;
        for (unsigned int j = 0; (j < offers.size()) & canOfferTo; j++) // checks if the agents coal already offered the party to join
        {
            if (offers[j].get_coal_pointer()->get_cId() == a.get_coal_pointer()->get_cId())
                canOfferTo = false;
        }

        if (canOfferTo && g.getEdgeWeight(n[i]->getId(), a.getPartyId()) > max)
        {
            offerTo = n[i];
            max = g.getEdgeWeight(n[i]->getId(), a.getPartyId());
        }
    }
    if (offerTo->getId() != -1)
    {
        offerTo->addOffer(a);
    }
}