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
    //  void addEdgeToEdgelist(int toVertexID, int weight)
  //  {
  //	  	Edge e(toVertexID,weight);
  //		edgeList.push_back(e); 
  //		cout<<"Edge between "<<state_id<<" and "<<toVertexID<<" added Successfully"<<endl; 	
  //  }

  void printEdgeList() {
    cout << "[";
    for (auto it = edgeList.begin(); it != edgeList.end(); it++) {
      cout << it -> getendVertex() << " , ";
    }
    cout << "]";
    cout << endl;
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
    Vertex get_Vertex(int vid) {
    Vertex temp;
    for (int i = 0; i < vertices.size(); i++) {
      temp = vertices.at(i);
      if (temp.getVertex() == vid) {
        return temp;
      }
    }
    return temp;
  }
  void getAllNeigborsByID(int vid) {
    cout << get_Vertex(vid).getVertex() <<  "Neighbours: ";
    for (int i = 0; i < vertices.size(); i++) {
      if (vertices.at(i).getVertex() == vid) {
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
   void updateVertex(int oldVID, string vname) {
    bool check = exists(oldVID);
    if (check == true) {
      for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).getVertex() == oldVID) {
          break;
        }
      }
      cout << "Vertex Updated Successfully " << endl;
    }
  }
  void deleteVertex(int vid) {
    int vIndex = 0;
    for (int i = 0; i < vertices.size(); i++) {
      if (vertices.at(i).getVertex() == vid) {
        vIndex = i;
      }
    }
    for (int i = 0; i < vertices.size(); i++) {
      for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
        if (it -> getendVertex() == vid) {
          vertices.at(i).edgeList.erase(it);
          break;
        }
      }

    }
    vertices.erase(vertices.begin() + vIndex);
    cout << "Vertex Deleted Successfully" << endl;
  }
 
void deleteEdge(int fromVertex, int toVertex) {
    bool check = edgeExists(fromVertex, toVertex);
    if (check == true) {
      for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).getVertex() == fromVertex) {
          for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
            if (it -> getendVertex() == toVertex) {
              vertices.at(i).edgeList.erase(it);
              //cout<<"First erase"<<endl;
              break;
            }
          }
        }

        if (vertices.at(i).getVertex() == toVertex) {

          for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
            if (it -> getendVertex() == fromVertex) {
              vertices.at(i).edgeList.erase(it);
              //cout<<"second erase"<<endl;
              break;
            }
          }
        }
      }
      cout << "Edge Between " << fromVertex << " and " << toVertex << " Deleted Successfully." << endl;
    }
  }
//   void updateEdge(int fromVertex, int toVertex, int newWeight) {
//     bool check = edgeExists(fromVertex, toVertex);
//     if (check == true) {
//       for (int i = 0; i < vertices.size(); i++) {

//         if (vertices.at(i).getVertex() == fromVertex) {
//           for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
//             if (it -> getendVertex() == toVertex) {
//               break;
//             }

//           }

//         } else if (vertices.at(i).getVertex() == toVertex) {
//           for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
//             if (it -> getendVertex() == fromVertex) {
            
//               break;
//             }

//           }
//         }
//       }
//       cout << "Edge Weight Updated Successfully " << endl;
//     } else {
//       cout << "Edge between " <<fromVertex<<" to " <<toVertex << " DOES NOT Exist" << endl;
//     }
//   }
  void numVertices()
  {
   cout<<"The number of Vertices are: "<<vertices.size()<<endl;
  }
  void numEdges()
  {
  }
  void Indegree(){

  }


 

  
    
    

};
int main()
{

    Graph g;
    bool check;
    Vertex v1;
    int option;
    v1.setVertex(2);
    g.addVertex(2);
        v1.setVertex(4);

    g.addVertex(4);
        v1.setVertex(5);
    g.addVertex(6);
    v1.setVertex(6);
    g.addVertex(5);
    v1.setVertex(2);
    g.addVertex(2);
    g.printGraph();
    g.addEdge(4,5);
    g.addEdge(2,4);
    g.addEdge(6,5);
    g.printGraph();

    g.deleteEdge(6,5);
        g.deleteVertex(6);
    g.printGraph();
    g.getAllNeigborsByID(4);
  do{
      cout<<"__Choose among list of opeartions__ "<<endl;
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
int data1,data2;

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
      g.deleteVertex(data1);

      break;

    case 3:
      cout << "Add Edge Operation -" << endl;
      cout << "Enter Source Vertex: ";
      cin >> data1;
      cout << "Enter Destination Vertex: ";
      cin >> data2;
      g.addEdge(data1, data2);

      break;

    case 4:
      cout << "Delete Edge Operation -" << endl;
      cout << "Enter Source Vertex: ";
      cin >> data1;
      cout << "Enter Destination Vertex: ";
      cin >> data2;
      g.deleteEdge(data1, data2);

      break;

    case 5:
      cout << "Check if 2 Vertices are Neigbors -" << endl;
      cout << "Enter Source Vertex: ";
      cin >> data1;
      cout << "Enter Destination Vertex: ";
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
      g.getAllNeigborsByID(data1);

      break;
    case 7:
     
      cout << "Number of vertices in graph : "<<endl;
      g.numVertices();

      break;
    case 8:
     
      cout << "Number of edges in graph : "<<endl;
      g.numEdges();

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

      break;

    case 11:
     
      cout << "Outdegree of vertices in graph : "<< endl;
      cout << "Enter Vertex whose outdegree is needed: ";
      cin >> data1;
      g.outDegree(data1);

      break;
    case 12:
     
      cout << "Degree of vertices in graph : "<< endl;
      cout << "Enter Vertex whose degree is needed: ";
      cin >> data1;
      g.degree(data1);

      break;

    default:
      cout << "Enter Proper Option number " << endl;
    }
    cout << endl;

  } while (option != 0);

  return 0;
}

    