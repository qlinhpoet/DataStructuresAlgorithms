#include <iostream>

#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph
{
private:
    unordered_map<string, unordered_set<string>> adjList;

public:
    bool addVertex(string vertex)
    {
        if(adjList.count(vertex)==0)    //is vertex not stored in adjency List?
        {
            adjList[vertex];
            return true;
        }
        return false;
    }

    void printGraph()
    {
        for(auto [vertex, edges] : adjList)
        {
            cout << vertex << ":[ ";
            for(auto edge : edges)
            {
                cout << edge << " ";
            }
            cout <<"]"<< endl;
        }
    }

    bool addEdge(string vertex1, string vertex2)
    {
        if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        
        {
            adjList.at(vertex1).insert(vertex2);    //insert edge FROM vertex1 TO vertex2
            adjList.at(vertex2).insert(vertex1);    //insert edge FROM vertex2 TO vertex1
            return true;
        }
        return false;
    }

    bool removeEdge(string vertex1, string vertex2)
    {
        if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            adjList.at(vertex1).erase(vertex2);     //remove edge from vertex1 to vertex2
            adjList.at(vertex2).erase(vertex1);     //remove edge from vertex2 to vertex1
            return true;
        }
        return false;
    }

    bool removeVertex(string vertex)
    {
        if(adjList.count(vertex) ==0 ) return false;
        for(auto otherVertex : adjList.at(vertex))
        {
            adjList.at(otherVertex).erase(vertex);
        }
        adjList.erase(vertex);
        return true;
    }
};

int main()
{
    Graph *myGraph = new Graph;

    myGraph->addVertex("A");
    myGraph->addVertex("B");
    myGraph->printGraph();

    myGraph->addEdge("A", "B");
    myGraph->printGraph();

    myGraph->removeEdge("A", "B");
    myGraph->printGraph();
    
    myGraph->removeVertex("A");
    myGraph->printGraph();
    return 0;
}