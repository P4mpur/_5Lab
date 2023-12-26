#include "Node.h"
//#include "Edge.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Granjke
{
    public:
    Granjke(Edge *src, Edge *dest, int we)
    {
        srcGranjka = src;
        destGranjka = dest;
        weight = we;
    };
    Edge *srcGranjka;
    Edge *destGranjka;
    int weight;

    bool operator==(Edge *desni);
};

class Graph
{
private:
    Node* head;
    

public:
    Graph(/* args */){head = NULL;};
    
    void AddNode(int n);
    
    Node* deleteNode(int n);

    //void deleteAll();

    void traverseNodes(); 

    Node* findNode(int n); // vraca nullptr ako je ne nadje
    
    void addEdge(int poc, int kraj,int weight);
    void deleteEdge(int poc, int kraj);

    void Kruskal();

    void spojiSaSvima(int n);
    void spojiNasumicno(int n); 

    void daisyChain();
    
    bool alreadyConnected(Node* poc, Node* kraj);

    Node* getHead() {return head;}
    Edge* findEdge(int , int );

    //friend bool operator==(Granjke* levi, Edge* desni);
    ~Graph();
};

