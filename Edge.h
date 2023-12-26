#include <iostream>
using namespace std;

class Node;

class Edge
{
private:
    Node* source; // zbog Kruskalovog Alg sam dodao
    Node* dest;
    
    Edge* next;
    
    int weight;

public:
    // friend class Node;
    Edge(Node* de, int we){ source = nullptr ;next = nullptr; dest = de; weight = we;};
    Edge(Node* src,Node* de, int we){source = src; next = nullptr; dest = de; weight = we;};
    Edge(){dest = nullptr; next = nullptr; weight = 0;};

    Edge* getNext(){if(next== nullptr)return nullptr; else return next;}
    void setNext(Edge* n){next = n;};

    Node* getSrc() {if(source!=nullptr)return source;else return nullptr;}
    Node* getDest(){ if(dest!=nullptr)return dest;else return nullptr;}
    int getWeight() {return weight;}

    bool operator<(Edge* desni);
    bool operator>(Edge* desni);
    bool operator==(Edge* desni);

    friend ostream& operator<<(ostream& levo, Edge* desno);
    ~Edge();
};
