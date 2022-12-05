#include<iostream>
using namespace std;
class Graph
{
    public:
   virtual bool isEmpty()=0;
   virtual bool isDirected()=0;
    virtual void addVertex(string newVertex)=0;
    virtual void addEdge(string originv,string destinVertex)=0;
    virtual  void removeVertex(string vertexToRemove)=0;
    void removeEdge(int vertex1, int vertex2);
    int numVertices();
    int numEdges();
    int indegree(int vertex);
    int outdegree(int vertex);
    int degree(int vertex);
    int neighbours(int vertex);
    int neighbours(int vertex1, int vertex2);
};
class EdgeNode{
     public:
     EdgeNode*next;
     string info;
     EdgeNode(){
        info="";
         next=NULL;
     }
     EdgeNode(string destinv){
        info = destinv;
        next= NULL;
     }

};
class Verticeslist:public Graph{
    public:
    EdgeNode*head;
    EdgeNode*tail;
    string info;
    Verticeslist(){
        info="";
        head=NULL;
        tail=NULL;
    }
      Verticeslist(string originv){
        info=originv;
        head=NULL;
        tail=NULL;
    }
    bool isEmpty();
    bool isDirected();
    void addVertex(string newVertex);
    void addEdge(string originv,string destinVertex);
    void removeVertex(string vertexToRemove);

};
bool Verticeslist :: isEmpty(){
    if(head==NULL && tail == NULL){
        return true;
    }
    else 
     return false;
}
bool Verticeslist:: isDirected(){
  return true;
}
void Verticeslist :: addVertex(string newvertex){
    EdgeNode*newNode= new EdgeNode();
    newNode->info = newvertex;
        if (isEmpty())
    {
        head = newNode;
        tail = newNode;
        cout << "First vertices added " << newvertex << endl;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        cout << "Next vertices added " << newvertex << endl;
    }
}
void Verticeslist :: addEdge(string originv,string destinVertex){
    
    EdgeNode*newNode= new EdgeNode();
    newNode->info = destinVertex;
    newNode-> next = NULL;
  
    EdgeNode *p = head;
    if (isEmpty())
    {
        cout << "No nodes in th  graph" << endl;
    }
    while (p != NULL)
    {
        if (p->info == originv ){
            if (p->next== NULL){
            p->next = newNode;
            tail = newNode;
            cout << "Added destin vertex to the origin vertex and the edge is between  " << originv<<"," <<destinVertex<< endl;
          
             break;
            }
            else{ 
            p->next =p->next->next;
            }
        }
        else{

        p = p->next;

        }
    }
}

 void Verticeslist::removeVertex(string vertexToRemove)
 {

}
 








int main(){
    Graph *vl = new Verticeslist();
    if(vl->isEmpty()){
        cout<<"NULL GRAPH"<<endl;
    }
    else{
         cout<<"Graph is not empty"<<endl;
    };
    vl->addVertex("Pokhara");
    vl->addVertex("Syangja");
    if(vl->isEmpty()){
        cout<<"NULL GRAPH"<<endl;
    }
    else{
         cout<<"Graph is not empty"<<endl;
    };
    vl->addEdge("Pokhara","Syangja");
    vl->addEdge("Pokhara","Parbat");
    vl->addEdge("Syangja","Parbat");
    vl->addEdge("Syangja","Pokhara");
    // vl-> removeVertex("Syangja");
    
}