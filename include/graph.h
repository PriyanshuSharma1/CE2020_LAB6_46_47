#ifndef graph_h
#define graph_h
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

class Edge
{
public:
    int endVertex;
    Edge()
    {
    }
    Edge(int endVertex);

    void setEdge(int endVertex);
    int getendVertex();
};
class Vertex
{
public:
    int vertex;
    list<Edge> edgeList;
    Vertex()
    {
        vertex = 0;
    }
    Vertex(int vertex);
    int getVertex();

    int setVertex(int v);

    list<Edge> getEdgelist();

    void addtoEdgelist(int toVertex);

    void numEdges();

    void printEdgeList();
};

class Graph
{
public:
    vector<Vertex> vertices;
    bool exists(int v);
    void addVertex(Vertex newVertex);
    void printGraph();
    Vertex get_Vertex(int v);
    void Neighbors(int v);
    bool edgeExists(int fromVertex, int toVertex);
    void addEdge(int fromVertex, int toVertex);

    void removeVertex(int v);

    void removeEdge(int fromVertex, int toVertex);

    void numVertices();

    void inDegree(int v);

    void outDegree(int v);

    void degree(int v);

    void isEmpty();

    void numEdge();
};
#endif