#include<iostream>
#include "Graph.h"

int main(int argc, char const *argv[])
{
    // srand(12);
    Graph obj;
    //obj.AddNode(51);
    int broj;
    // for (int i = 0; i < 8; i++)
    // {
    //     broj = rand()%100;
    //     obj.AddNode();
    // }

    for (int i = 0; i <= 8; i++)
    {
        obj.AddNode(i);
    }

    obj.traverseNodes();
    
    cout <<"-------------------" << endl;
    

    obj.addEdge(0,1,4);
    obj.addEdge(0,7,8);    
    obj.addEdge(1,2,8);    
    obj.addEdge(1,7,11);    
    obj.addEdge(7,8,7);
    obj.addEdge(7,6,1);
    obj.addEdge(2,8,2);
    obj.addEdge(8,6,6);
    obj.addEdge(2,5,4);
    obj.addEdge(6,5,2);
    obj.addEdge(2,3,7);
    obj.addEdge(3,5,14);
    obj.addEdge(3,4,9);    
    obj.addEdge(5,4,10);    
    
    
    obj.Kruskal();
    
    
    
       

    
    
    //obj.traverseNodes();
    

    // obj.spojiNasumicno(100);
    // obj.traverseNodes();

    cout << endl;

    
    return 0;
}
