#include "graph.h"
#include<iostream>
using namespace std;
Graph::Graph(int vertex)
{
    this->vertex=vertex;
    adjList=new vector<int>[vertex];
}
bool Graph::isEmpty()
{
    (adjList==NULL)?true:false;
}
bool Graph::isDirected()
{

}
void Graph::addVertex(int newVertex)
{

}
void Graph:: addEdge(int vertex1, int vertex2)
{
    adjList[vertex1].push_back(vertex2);
    adjList[vertex2].push_back(vertex1);
}
