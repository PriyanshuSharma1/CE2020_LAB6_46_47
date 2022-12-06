#ifndef graph_h
#define graph_h
#include<vector>
using namespace std;

class Edge;
class Vertex;

class Graph
{
    public:
    int vertex;
    vector<int> *adjList;
    Graph(int vertex)
    {
       
    }
    bool isEmpty();
    bool isDirected();
    void addVertex(int newVertex);
    void addEdge(int vertex1,int vertex2);
    void removeVertex(int vertexToRemove);
    void removeEdge(int vertex1, int vertex2);
    int numVertices();
    int numEdges();
    int indegree(int vertex);
    int outdegree(int vertex);
    int degree(int vertex);
    int neighbours(int vertex);
    int neighbours(int vertex1, int vertex2);
};
#endif