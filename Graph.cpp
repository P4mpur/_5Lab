#include "Graph.h"

void Graph::AddNode(int n)
{
    if (head == NULL)
    {
        head = new Node(n);
    }
    else
    {
        Node *tp = head;
        while (tp->getNext() != nullptr && tp != NULL)
        {
            if (tp->getInfo() == n)
            {
                return;
            }
            
            tp = tp->getNext();
            
        }
        tp->setNext(new Node(n));
    }
}

Node* Graph::deleteNode(int n)
{
    if (head == nullptr)
    {
        cout << "deleteNode: A be Head je prazan" << endl;
        return nullptr;
    }
    else
    {
        Node* tp = head;
        Node* prev = nullptr;
        while (tp != nullptr && tp->getInfo() != n)
        {
            prev = tp;
            tp = tp->getNext();
        }
        if (tp == nullptr)
        {
            cout << "deleteNode: n Ne postoji";
            return nullptr;
        }
        else if(prev == nullptr)
        {
            head = tp->getNext();
            tp->setNext(nullptr);
            return tp;
        }
        else
        {
            prev->setNext(tp->getNext());
            tp->setNext(nullptr);
            return tp;

        }
        
        
    }
    
}

void Graph::traverseNodes()
{
    if (head == NULL)
    {
        cout << "TraverseNodes: bajco, glava je null" << endl;
        exit;
    }
    Node *tp = head;
    while (tp != NULL)
    {
        cout << tp->getInfo() << endl;
        tp->traverseLinks();
        tp = tp->getNext();
    }
}


Node *Graph::findNode(int n) //vraca nullptr ako je ne nadje
{
        if (head == nullptr)
        {
            cout << "findNode: head je null";
        }
    
    Node* tp = head;
    while (tp!=nullptr && tp->getInfo() != n)
    {
        tp = tp->getNext();
    }
    
    return tp;
}

void Graph::addEdge(int poc, int kraj, int weight)
{
    Node* Npoc;
    Node* Nkraj;

    if ((Npoc = findNode(poc))==nullptr)
    {
        cout << "addEdge: findNode(poc) == null";
        return;    
    }
        
    if ((Nkraj = findNode(kraj))==nullptr)
    {
        cout << "addEdge: findNode(kraj) == null";
        return;    
    }

    if ((Nkraj == Npoc)) 
    {
        cout << "addEdge: Isti su " <<endl;
        return;
    }
    

    Npoc->addEdge(Nkraj, weight);
    Nkraj->addEdge(Npoc,weight);

}

void Graph::deleteEdge(int poc, int kraj)
{
    Node* Npoc;
    Node* Nkraj;
    if (head == nullptr)
    {
        cout << "deleteEdge : head == nullptr" ;
        return;
    }
    if ((Npoc = findNode(poc))== nullptr)
    {
        cout << "deleteEdge() Npoc je null";
        return;
    }
        
    if ((Nkraj = findNode(kraj))== nullptr)
    {
        cout << "deleteEdge() Nkraj je null";
        return;
    }

    Npoc->deleteLink(Npoc,Nkraj);

    Nkraj->deleteLink(Nkraj,Npoc);

    
}




void Graph::Kruskal()
{
    //sve promenljive sto ti trebaju
    int i =0;
    vector<Granjke*> vektor;
    Node* tpNode = head;
    Edge* tpEdge = nullptr;
    Edge* pomDest = nullptr;
    bool istina = false;


    //traverse i dodavaj u vektor
    while (tpNode != nullptr)
    {
        tpEdge = tpNode->getAdj();
        while (tpEdge != nullptr) 
        {
            istina = false;

            for (auto i : vektor)
            {
                if (i->srcGranjka == tpEdge || i->destGranjka == tpEdge) // odavde 
                {
                    istina = true;
                    break;
                }
                
            }
            
            if(!istina)
            {
            vektor.push_back(
                new Granjke(tpEdge,findEdge
                (tpEdge->getDest()->getInfo(),tpEdge->getSrc()->getInfo())
                ,tpEdge->getWeight()));
            } // do ovde ide samo ubacivanje unikatnih, nisam znao preko <algorithm> da sredim to
            
            tpEdge = tpEdge->getNext();
        }
        //kasnije ces da odlucis da li ces da brises adj ili ne


        tpNode = tpNode->getNext();
    }
    
    //// ---> izbacuju se sad nepotrebni

    
    //print provera 
        for (auto &i : vektor)
        {
            cout << "Source Djavo : " << endl;
            cout << "source : " << i->srcGranjka->getSrc();
            cout << "destination : " << i->srcGranjka->getDest();
            cout << "weight : " << i->weight << endl; 
            cout << "  " << endl;

            cout << "Destination Djavo : " << endl ;
            cout << "source : " << i->destGranjka->getSrc();
            cout << "destination : " << i->destGranjka->getDest();
            cout << "weight : " << i->weight << endl; 
            cout << "  " << endl;
        }
        
}

void Graph::spojiSaSvima(int n)
{
    Node* op;
    int num = 0;
    if (head == NULL)
    {
        cout << "spojiSaSvima() prazna galva ";
        return;
    }

    if ((op = findNode(n)) == nullptr)
    {
        cout << "spojiSaSvima() nema ga taj broj";
        return;
    }
    Node* tp = head;

    while (tp!= nullptr)
    {
        if (op->getInfo() == tp->getInfo() || &op == &tp)
        {
            tp = tp->getNext();
            continue;
        }
        num = rand()%50;
        addEdge(op->getInfo(),tp->getInfo(),num);
        tp = tp->getNext();
                
    }
    
    
    
    
}

void Graph::spojiNasumicno(int n)
{
    int brEl = 0;
    int zbir = 0;
    int sab = 0;

    Node* spojtp;

    Node* tp = head;
    while (tp!=nullptr)
    {
        tp = tp->getNext();
        brEl++;
    }
    tp = head;
    while(zbir < n/2 )
    {
        if (tp == nullptr)
        {
            tp = head;
        }
        
        sab = (rand() % brEl);
        
        

        spojtp = head;
        for (int i = 0; i < sab; i++)
        {
            spojtp = spojtp->getNext();
        }
        
         if (alreadyConnected(tp,spojtp))
        {
            tp = tp->getNext();
            continue;
        }
        else
        {
            addEdge(tp->getInfo(),spojtp->getInfo(),rand()%50);
            
        }
        zbir++;
        tp = tp->getNext();

    }
}

void Graph::daisyChain()
{
    if (head == nullptr)
    {
        cout << "daisyChaing() : head == null" << endl;
    }
    
    Node* tp = head;
    while (tp->getNext() != nullptr)
    {
        addEdge(tp->getInfo(),tp->getNext()->getInfo(), rand()%50);
        tp = tp->getNext();
    }
    
}

bool Graph::alreadyConnected(Node *poc, Node *kraj)
{
    Edge *tp = poc->getAdj();
    if (poc == kraj)
    {
        return false;
    }
    

    while (tp != NULL)
    {
        if (tp->getDest()->getInfo() == kraj->getInfo())
        {
            return true;
        }
        tp = tp->getNext();
    }
    

    return false;
}

Edge *Graph::findEdge(int poc, int kraj)
{
    Edge* tp;
    Node* Npoc;
    Node* Nkraj;
    Npoc = findNode(poc);
    Nkraj = findNode(kraj);
    // if (Npoc == (Node*)NULL); ne radi lepo ispitivanje 
    // {
    //     cout << "Graph :findEdge Npoc == nullptr" << endl;
    //     return nullptr;
    // }
    
    // if (Nkraj == (Node*)nullptr);
    // {
    //     cout << "Graph :findEdge Nkraj == nullptr" << endl;
    //     return nullptr;
    // }

    tp = Npoc->getAdj();
    while (tp != nullptr)
    {
        if (tp->getDest() == Nkraj)
        {
            return tp;
        }
        
        tp = tp->getNext();
    }
    
    cout << "find Edge() : Ne postoji da je povezan takav" << poc << " i " << kraj << endl; 
    return nullptr;
}

Graph::~Graph()
{
    if (head != NULL)
    {
        delete head;
    }
    
}

// bool operator==(Granjke *levi, Edge *desni)
// {
//     if (levi == nullptr && desni == nullptr )
//     {
//         cout << "Granjke, operator== : levi ili desni nullptr" << endl;
//         return false;
//     }

    
//     return levi->destGranjka == desni || levi->srcGranjka == desni ? true : false;
// }

bool Granjke::operator==(Edge *desni)
{
    if(desni == nullptr)
    {
        cout << "operator == desni == nullptr";
    }
    return destGranjka == desni || srcGranjka == desni ? true : false;
}
