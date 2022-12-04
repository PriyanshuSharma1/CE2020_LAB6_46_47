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