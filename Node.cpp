#include "Node.h"

Node::Node(int n)
{
    group = 0;
    info = n;
    next = NULL;
    adj = NULL;
}

Node* Node::getNext()
{
    if (next == NULL)
        return nullptr;
    else
        return next;
}

void Node::setNext(Node *n)
{
    next = n;
}

void Node::insertEdge(Edge *a)
{
    if (adj == nullptr)
    {
        adj = a;
    }
    else
    {
        Edge* tp = adj;
        while (tp->getNext() != nullptr)
        {
            if(tp->getSrc()->getInfo() == a->getSrc()->getInfo() && tp->getDest()->getInfo() == a->getDest()->getInfo())
            tp = tp->getNext();
        }
        tp->setNext(a);
        
    }
    
}

void Node::addEdge(Node *kraj, int weight)
{
    Edge* prevtp = nullptr;
    Edge* etp = this->adj;

    if (etp == nullptr)
    {
        etp = new Edge(this,kraj,weight);
        adj = etp;
    }
    else
    {
        while (etp != nullptr /*etp->getDest()->getInfo() != kraj->getInfo()*/)
        {
            prevtp = etp;
            etp = etp->getNext();
        }
        if (etp == nullptr)
        {
            prevtp->setNext(new Edge(this,kraj,weight));
        }
        
    }
    

}

void Node::deleteLink(Node* poc, Node* kraj)
{
    Edge* prev= nullptr;
    Edge* tp = poc->adj;
    while (tp!= nullptr && tp->getDest()->getInfo() != kraj->getInfo())
    {
        prev =tp;
        tp = tp->getNext();
    }
    
    if (tp == nullptr)
    {
        cout << "deleteLink : tp je null, sto znaci da ga nema : ";
        return;
    }
    if (prev == nullptr)
    {
        adj = tp->getNext();
        tp->setNext(nullptr);
    }
    else
    {
        prev->setNext(tp->getNext());
        tp->setNext(nullptr);
    }
    cout << "Brisem od : " << info << "DO : " << tp->getDest()->getInfo() << endl;

    delete tp;  

}

void Node::traverseLinks()
{
    if (adj == nullptr)
    {
        cout << "Nodes : traverse links() adj == nullptr" << endl;
        return ;
    }
    Edge* tp = adj;
    while (tp!=nullptr)
    {
        cout << tp->getSrc()->info << " to : " 
        << tp->getDest()->getInfo() 
        << " Weight : " << tp->getWeight() << endl;
        tp = tp->getNext();
    }
    
    
}

bool Node::operator==(Node *desni)
{
    if (this == nullptr || desni == nullptr)
    {
        return false;
    }
    
    if (this == desni || this->info == desni->info)
    {
        cout << "Node :operator== Isti su " << this->info << endl;
        return true;
    }
    
    return false;
}

int Node::Count()
{
    int i;
    Node* tp;
    while (tp!=nullptr)
    {
        i++;
        tp=tp->next;
    }
    
    return i;
}

Node::~Node()
{
    if (next != NULL)
    {
        delete next;
    }

    if (adj != NULL)
    {
        delete adj;
    }
    
}

ostream &operator<<(ostream &levo, Node *desno)
{
    levo << desno->getInfo() << endl;
    return levo;
}
