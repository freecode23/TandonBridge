#include <iostream>
#include <vector>
using namespace std;

class edge{//This class is to create an edge between two nodes
public:
    int src, dst;

    edge(){};
    edge(int s,int d){ // Constructor
        src=s;
        dst=d;
    }
    edge(const edge &e2){//Copy constructor for the edge class
        src = e2.src;
        dst = e2.dst;
    }
};

class graph{ //The graph class which creates the graph

private:
    int nodes;
    vector<edge> edges;
public:
    //Copy constructor for the graph
    graph(int n,vector<edge> e){
        nodes=n;
        for(int i=0;i<e.size();i++){
            edges.push_back(e[i]);
        }

    }
    //The Depth First Search function
    void DFS(int v, vector<int>&visited)
    {

        if (visited[v]==1){return;}

        else
        {
            cout<<"current node: "<<v<<endl;
            visited[v]=2;
            for(int i=0;i<edges.size();i++)
            {
                if(edges[i].src==v)
                { int dest=edges[i].dst;
                    if(visited[dest]==0) // if we havent visited the destination
                    {
                        DFS(dest,visited); // then DFS this destination
                    }
                }
            }
            visited[v]=1; //no more children then set this as visited
        }
    }
};

int main() {
    edge one(0,1);
    edge two(0,2);
    edge three(1,3);
    edge four(1,4);
    edge five(2,5);

    vector<edge> e;
    e.push_back(one);
    e.push_back(two);
    e.push_back(three);
    e.push_back(four);
    e.push_back(five);

    int n=5;
    graph g(n,e);
    vector<int> visit={0,0,0,0,0};

    for(int i=0;i<n;i++){
        g.DFS(i,visit);
    }
}