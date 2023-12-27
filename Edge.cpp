#include "Edge.h"
using namespace std;

bool Edge::operator<(Edge *desni)
{
    if (this == nullptr || desni == nullptr )
    {
        cout << "operator< this ili desni je null" << endl;
        return false;
    }
    
    if (this == desni)
    {
        cout << "operator< isti su " << endl;
        return false;
    }
    

    return this->weight < desni->weight ? true : false;
}

bool Edge::operator>(Edge *desni)
{
    if (this == nullptr || desni == nullptr )
    {
        cout << "operator> this ili desni je null" << endl;
        return false;
    }
    
    if (this == desni)
    {
        cout << "operator> isti su " << endl;
        return false;
    }
    
    return this->weight>desni->weight ? true : false;
}

bool Edge::operator==(Edge *desni)
{    
    return this->source == desni->getSrc() && 
    this->dest == desni->getDest() &&
    this->weight == desni->weight 
    ? true : false;
}

Edge::~Edge()
{
    if (next != NULL)
    {
        //delete next;
    }   
    // if (dest !=NULL)
    // {
    //     delete dest;
    // }
    

}

ostream &operator<<(ostream &levo, Edge *desno)
{
    levo << "source :" << desno->getSrc() << endl;
    levo << "destination :" << desno->getDest() << endl;
    levo << "weight : " << desno->weight << endl;
    
    return levo;
}
