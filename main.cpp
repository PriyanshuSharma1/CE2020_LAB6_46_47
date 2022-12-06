#include <iostream>
#include "graph.h"
using namespace std;
int main()
{

    Graph g;
    bool check;
    Vertex v1;
    int option;

    do
    {
        cout << "__Choose among list of opeartions__ " << endl;
        cout << "Select Options-- Enter 0 to exit." << endl;
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

        cin >> option;

        Vertex v1;
        int data1, data2, data;

        switch (option)
        {
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
            if (check == true)
            {
                cout << "Vertices are Neigbors (Edge exist)";
            }
            else
            {
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

            cout << "Number of vertices in graph : " << endl;
            g.numVertices();

            break;
        case 8:

            cout << "Number of edges in graph : " << endl;
            g.numEdge();

            break;
        case 9:
            cout << "Print Graph Operation -" << endl;
            g.printGraph();

            break;
        case 10:

            cout << "Indegree of vertices in graph : " << endl;
            cout << "Enter Vertex whose indegree is needed: ";
            cin >> data1;
            g.inDegree(data1);

            break;

        case 11:

            cout << "Outdegree of vertices in graph : " << endl;
            cout << "Enter Vertex whose outdegree is needed: ";
            cin >> data1;
            g.outDegree(data1);

            break;
        case 12:

            cout << "Degree of vertices in graph : " << endl;
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
