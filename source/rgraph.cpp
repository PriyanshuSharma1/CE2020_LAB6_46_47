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

    

}