#include<iostream>
#include<vector>
#include<list>
#include<iterator>
using namespace std;
class Edge
{
    public:
    int endVertex;
    Edge()
    {
    }
    Edge(int endVertex)
    {
        this->endVertex=endVertex;
    }
    void setEdge(int endVertex)
    {
        this->endVertex=endVertex;
    }
    int getendVertex()
    {
        return endVertex;
    }
};
class Vertex
{
    public:
        int vertex;
    list<Edge>edgeList;
    Vertex()
    {
        vertex=0;
    }
    Vertex(int vertex)
    {
        this->vertex=vertex;
    }
    int getVertex()
    {
        return vertex;
    }
    int setVertex(int v)
    {
        vertex=v;
    }
    list<Edge>getEdgelist()
    {
        return edgeList;
    }
    void addtoEdgelist(int toVertex)
    {
        Edge e(toVertex);
        edgeList.push_back(e);
        cout<<"Edge between "<<vertex<<" and "<<toVertex<<" added."<<endl;

    }
  
    
};
class Graph
{
    public:
    vector<Vertex> vertices;
    bool exists(int v)
    {
        bool flag= false;
        for (int i = 0; i < vertices.size(); i++)
        {
            if(vertices.at(i).getVertex()==v)
            {
                return true;
            }
        }
        return flag;
    }
    void addVertex(Vertex newVertex)
    {
        bool check= exists(newVertex.getVertex());
        if(check==true)
        {
            cout<<"Vertex already exists"<<endl;

        }
        else{
            vertices.push_back(newVertex);
            cout<<"New Vertex Added successfully"<<endl;
        }
    }
    void printGraph()
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            Vertex temp;
            temp=vertices.at(i);
            cout<<temp.getVertex()<<endl;
            
        }
        
    }
      void addEdge(int fromVertex, int toVertex)
    {
        bool check1= exists(fromVertex);
        bool check2= exists(toVertex);
        if((check1 && check2)==true)
        {
            cout<<"Edge already exists"<<endl;
        }
        else
        {
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices.at(i).getVertex()==fromVertex)
                {
                    Edge e(toVertex);
                    vertices.at(i).edgeList.push_back(e);
                
                }
                else if(vertices.at(i).getVertex()==toVertex){
                    Edge e(fromVertex);
                    vertices.at(i).edgeList.push_back(e);
                }
               
            }
             cout<<"Edge between "<<fromVertex<<" and "<<toVertex<<" added successfully"<<endl;
        }

    }
   
  
    
    

};
int main()
{
    Graph g;

    bool check;
    Vertex v1;
    v1.setVertex(2);
    g.addVertex(2);
        v1.setVertex(4);

    g.addVertex(4);
        v1.setVertex(5);

    g.addVertex(5);
    v1.setVertex(2);
    g.addVertex(2);
    g.printGraph();
    g.addEdge(4,5);
    g.addEdge(2,4);
    g.printGraph();
    

}