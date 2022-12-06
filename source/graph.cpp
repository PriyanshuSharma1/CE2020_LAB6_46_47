#include "graph.h"
#include <iostream>
using namespace std;
Edge::Edge(int endVertex)
{
    this->endVertex = endVertex;
}
void Edge::setEdge(int endVertex)
{
    this->endVertex = endVertex;
}
int Edge ::getendVertex()
{
    return endVertex;
}
Vertex::Vertex(int vertex)
{
    this->vertex = vertex;
}
int Vertex::getVertex()
{
    return vertex;
}
int Vertex::setVertex(int v)
{
    vertex = v;
}
list<Edge> Vertex::getEdgelist()
{
    return edgeList;
}
bool Graph::isEmpty()
{
      if(vertices.size()==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Vertex::addtoEdgelist(int toVertex)
{
    Edge e(toVertex);
    edgeList.push_back(e);
    cout << "Edge between " << vertex << " and " << toVertex << " added." << endl;
}
void Vertex ::numEdges()
{
    cout << "The number of Edges are: " << edgeList.size() << endl;
}
void Vertex::printEdgeList()
{
    cout << "[";
    for (auto it = edgeList.begin(); it != edgeList.end(); it++)
    {
        cout << it->getendVertex() << " , ";
    }
    cout << "]";
    cout << endl;
}
int Vertex::No_of_edges() {
    static int i=0;
    for (auto it = edgeList.begin(); it != edgeList.end(); it++) {
      i=i+1;
    }
    return i;
  }
bool Graph::exists(int v)
{
    bool flag = false;
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices.at(i).getVertex() == v)
        {
            return true;
        }
    }
    return flag;
}
void Graph::addVertex(Vertex newVertex)
{
    bool check = exists(newVertex.getVertex());
    if (check == true)
    {
        cout << "Vertex already exists" << endl;
    }
    else
    {
        vertices.push_back(newVertex);
        cout << "New Vertex Added successfully" << endl;
    }
}
void Graph::printGraph()
{
    for (int i = 0; i < vertices.size(); i++)
    {
        Vertex temp;
        temp = vertices.at(i);
        cout << temp.getVertex() << "-->";
        temp.printEdgeList();
    }
}
Vertex Graph ::get_Vertex(int v)
{
    Vertex temp;
    for (int i = 0; i < vertices.size(); i++)
    {
        temp = vertices.at(i);
        if (temp.getVertex() == v)
        {
            return temp;
        }
    }
    return temp;
}
void Graph ::Neighbors(int v)
{
    cout << get_Vertex(v).getVertex() << " -> Neighbours: ";
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices.at(i).getVertex() == v)
        {
            cout << " [";
            for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++)
            {
                cout << it->getendVertex() << ", ";
            }
            cout << "]";
        }
    }
}
bool Graph::edgeExists(int fromVertex, int toVertex)
{
    Vertex v = get_Vertex(fromVertex);
    list<Edge> e;
    e = v.getEdgelist();
    bool flag = false;
    for (auto it = e.begin(); it != e.end(); it++)
    {
        if (it->getendVertex() == toVertex)
        {
            flag = true;
            return flag;
            break;
        }
    }
    return flag;
}
void Graph::addEdge(int fromVertex, int toVertex)
{
    bool check1 = exists(fromVertex);
    bool check2 = exists(toVertex);
    bool check3 = edgeExists(fromVertex, toVertex);
    if ((check1 && check2) == true)
    {
        if (check3 == true)
        {
            cout << "Edge already exists" << endl;
        }
        else
        {
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices.at(i).getVertex() == fromVertex)
                {
                    Edge e(toVertex);
                    vertices.at(i).edgeList.push_back(e);
                }
                else if (vertices.at(i).getVertex() == toVertex)
                {
                    Edge e(fromVertex);
                    vertices.at(i).edgeList.push_back(e);
                }
            }
            cout << "Edge between " << fromVertex << " and " << toVertex << " added successfully" << endl;
        }
    }
    else
    {
        cout << "Invalid Vertex" << endl;
    }
}

void Graph::removeVertex(int v)
{
    int vIndex = 0;
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices.at(i).getVertex() == v)
        {
            vIndex = i;
        }
    }
    for (int i = 0; i < vertices.size(); i++)
    {
        for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++)
        {
            if (it->getendVertex() == v)
            {
                vertices.at(i).edgeList.erase(it);
                break;
            }
        }
    }
    vertices.erase(vertices.begin() + vIndex);
    cout << "Vertex Deleted Successfully" << endl;
}

void Graph::removeEdge(int fromVertex, int toVertex)
{
    bool check = edgeExists(fromVertex, toVertex);
    if (check == true)
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).getVertex() == fromVertex)
            {
                for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++)
                {
                    if (it->getendVertex() == toVertex)
                    {
                        vertices.at(i).edgeList.erase(it);
                        // cout<<"First erase"<<endl;
                        break;
                    }
                }
            }

            if (vertices.at(i).getVertex() == toVertex)
            {

                for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++)
                {
                    if (it->getendVertex() == fromVertex)
                    {
                        vertices.at(i).edgeList.erase(it);
                        // cout<<"second erase"<<endl;
                        break;
                    }
                }
            }
        }
        cout << "Edge Between " << fromVertex << " and " << toVertex << " Deleted Successfully." << endl;
    }
}

void Graph::numVertices()
{
    cout << "The number of Vertices are: " << vertices.size() << endl;
}

// void Graph::degree()
// {
    
//     for (int i = 0; i < vertices.size(); i++)
//         {
//             Vertex temp;
//             temp=vertices.at(i);
//             cout<<temp.getVertex()<<"  --> Degree: "<<2*temp.No_of_edges()<<endl;
            
            
//         }
  
// }

int Graph::numEdge()
{
     
  

    static int num_edges=0;
    for (int i = 0; i < vertices.size(); i++)
    {
           int num= vertices.at(i).edgeList.size();
           num_edges=num_edges+num;

           

    }
    return num_edges;
    
  
}
