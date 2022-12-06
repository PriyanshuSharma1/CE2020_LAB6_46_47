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
 

  void printEdgeList() {
    cout << "[";
    for (auto it = edgeList.begin(); it != edgeList.end(); it++) {
      cout << it -> getendVertex() << " , ";
    }
    cout << "]";
    cout << endl;
  }
  int edges()
  {
    static int n=0;
     for (auto it = edgeList.begin(); it != edgeList.end(); it++) {
      n=n+1;
    }
    return n;
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
            cout<<temp.getVertex()<<"-->";
            temp.printEdgeList();
            
        }
        
    }
    Vertex get_Vertex(int v) {
    Vertex temp;
    for (int i = 0; i < vertices.size(); i++) {
      temp = vertices.at(i);
      if (temp.getVertex() == v) {
        return temp;
      }
    }
    return temp;
  }
  void Neighbors(int v) {
    cout << get_Vertex(v).getVertex() <<  " -> Neighbours: ";
    for (int i = 0; i < vertices.size(); i++) {
      if (vertices.at(i).getVertex() == v) {
        cout << " [";
        for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
          cout << it -> getendVertex() <<", ";
        }
        cout << "]";

      }
    }

  }
    bool edgeExists(int fromVertex, int toVertex) {
    Vertex v = get_Vertex(fromVertex);
    list < Edge > e;
    e = v.getEdgelist();
    bool flag = false;
    for (auto it = e.begin(); it != e.end(); it++) {
      if (it -> getendVertex() == toVertex) {
        flag = true;
        return flag;
        break;
      }

    }
    return flag;
  }
      void addEdge(int fromVertex, int toVertex)
    {
        bool check1= exists(fromVertex);
        bool check2= exists(toVertex);
        bool check3= edgeExists(fromVertex,toVertex);
        if((check1 && check2)==true)
        {
            if(check3==true)
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
        else
        {
            cout<<"Invalid Vertex"<<endl;
        }
       
    }

  void removeVertex(int v) {
    int vIndex = 0;
    for (int i = 0; i < vertices.size(); i++) {
      if (vertices.at(i).getVertex() == v) {
        vIndex = i;
      }
    }
    for (int i = 0; i < vertices.size(); i++) {
      for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
        if (it -> getendVertex() == v) {
          vertices.at(i).edgeList.erase(it);
          break;
        }
      }

    }
    vertices.erase(vertices.begin() + vIndex);
    cout << "Vertex Deleted Successfully" << endl;
  }
 
void removeEdge(int fromVertex, int toVertex) {
    bool check = edgeExists(fromVertex, toVertex);
    if (check == true) {
      for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).getVertex() == fromVertex) {
          for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
            if (it -> getendVertex() == toVertex) {
              vertices.at(i).edgeList.erase(it);
              break;
            }
          }
        }

        if (vertices.at(i).getVertex() == toVertex) {

          for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
            if (it -> getendVertex() == fromVertex) {
              vertices.at(i).edgeList.erase(it);
              break;
            }
          }
        }
      }
      cout << "Edge Between " << fromVertex << " and " << toVertex << " Deleted Successfully." << endl;
    }
  }

  void numVertices()
  {
   cout<<"The number of Vertices are: "<<vertices.size()<<endl;
  }
  int inDegree(Vertex v)
  {
    
  }
  int outDegree(Vertex v)
  {
    

  }
  int degree(Vertex v)
  {
    
  }
  bool isEmpty()
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
  int numEdge()
  {

    static int num_edges=0;
    for (int i = 0; i < vertices.size(); i++)
    {
           int num= vertices.at(i).edgeList.size();
           num_edges=num_edges+num;

           

    }
    return num_edges;
    
  }
};
int main()
{

    Graph g;
    bool check;
    Vertex v1;
    int option;
  
  do{
      cout<<"_______________ MENU _________________ "<<endl<<endl;
      cout<< "Select Options-- Enter 0 to exit."<<endl;
      cout << "1. Add Vertex" << endl;
      cout << "2. Remove Vertex" << endl;
      cout << "3. Add Edge" << endl;
      cout << "4. Remove Edge" << endl;
      cout << "5. Check if 2 Vertices are Neigbors" << endl;
      cout << "6. Print All Neigbors of a Vertex" << endl;
      cout << "7. Count the number of vertices " << endl;
      cout << "8. Count the number of Edges " << endl;
      cout << "9. Print Graph" << endl;
      cout << "10. Print Indegree of a Vertex" << endl;
      cout << "11. Print Outdegree of a Vertex" << endl;
      cout << "12. Print Degree of a Vertex" << endl;
      cout << "13. Check empty or not" << endl;

      cin>> option; 

Vertex v1;
int data1,data2,data;

    switch (option) {
    case 0:

      break;

    case 1:
     
      cout << "Add Vertex Operation -" << endl;
      cout << "Enter Vertex :";
      cin >> data1;
      v1.setVertex(data1);
      g.addVertex(v1);

      break;

    case 2:
      cout << "Remove Vertex Operation -" << endl;
      cout << "Enter Vertex to Delete : ";
      cin >> data1;
      g.removeVertex(data1);

      break;

    case 3:
      cout << "Add Edge Operation -" << endl;
      cout << "Enter Source Vertex: ";
      cin >> data1;
      cout << "Enter End Vertex: ";
      cin >> data2;
      g.addEdge(data1, data2);

      break;

    case 4:
      cout << "Delete Edge Operation -" << endl;
      cout << "Enter Source Vertex: ";
      cin >> data1;
      cout << "Enter End Vertex: ";
      cin >> data2;
      g.removeEdge(data1, data2);

      break;

    case 5:
      cout << "Check if 2 Vertices are Neigbors -" << endl;
      cout << "Enter Source Vertex: ";
      cin >> data1;
      cout << "Enter End Vertex: ";
      cin >> data2;
      check = g.edgeExists(data1, data2);
      if (check == true) {
        cout << "Vertices are Neigbors (Edge exist)";
      } else {
        cout << "Vertices are NOT Neigbors (Edge does NOT exist)";
      }

      break;

    case 6:
      cout << "Print All Neigbors of a Vertex -" << endl;
      cout << "Enter Vertex to fetch all Neigbors : ";
      cin >> data;
      g.Neighbors(data1);

      break;
    case 7:
     
      cout << "Number of vertices in graph : "<<endl;
      g.numVertices();

      break;
    case 8:
     
      cout << "Number of edges in graph : "<<endl;
       cout<<"The number of edges in the graph is "<<g.numEdge()<<endl;

      break;
      case 9:
      cout << "Print Graph Operation -" << endl;
      g.printGraph();

      break;
    case 10:
     
      cout << "Indegree of vertices in graph : "<< endl;
      cout << "Enter Vertex whose indegree is needed: ";
      cin >> data1;
      g.inDegree(data1);
      cout<<"The number of in degree of the given vertex is: "<<g.inDegree(data1);


      break;

    case 11:
     
      cout << "Outdegree of vertices in graph : "<< endl;
      cout << "Enter Vertex whose outdegree is needed: ";
      cin >> data1;
      cout<<"The number of out degree of the given vertex is: "<<g.outDegree(data1);

      break;
    case 12:
     
      cout << "Degree of vertices in graph : "<< endl;
      cout << "Enter Vertex whose degree is needed: ";
      cin >> data1;
            cout<<"The number of  degree of the given vertex is: "<<g.degree(data1);

    

      break;
    case 13:
        if(g.isEmpty()==true)
        {
            cout<<"The graph is empty"<<endl;

        }
        else
        {
            cout <<" The graph is not empty"<<endl;
        }

  
    }
    cout << endl;

  } while (option != 0);

  return 0;
}

    