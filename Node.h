#include <iostream>
#include "Edge.h"
using namespace std;

// class Edge;

class Node
{
private:
    int info;
    Node* next;
    int group;

    Edge* adj; //adj list


public:
    Node(int n);

    //get set
    Node* getNext();
    void setNext(Node* n);

    int getInfo(){ return info;};
    Edge* getAdj(){return adj;}
    
    int getGroup() {return group; }
    void setGroup(int n) {group = n;}

    void addEdge(Node* kraj,int weight);
    void deleteLink(Node* poc, Node* kraj);

    void traverseLinks();
    bool operator==(Node* desni);

    friend ostream& operator<<(ostream& levo, Node* desno);
    ~Node();
};