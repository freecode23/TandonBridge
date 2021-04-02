#include <iostream>
#include <vector>
using namespace std;

class edge{// This is the edge class
public:
    int src, dst;
    //The constructors for this class
    edge(){};
    edge(int s,int d){
        src=s;
        dst=d;
    }
};
// This class is used to create the graphs
class graph{

private:
    int nodes;
    vector<edge> edges;
public:
//Copy constructor for the graph class  
    graph(int n,vector<edge> e){
        nodes=n;
        for(int i=0;i<e.size();i++){
            edges.push_back(e[i]);
        }

    }
    // This function implements the topological sorting
    void topologicalSort(int v, vector<int> &visited, vector<int >&ts)
    {
        //Base Case
        if (visited[v]==1){return;}

        else
        {
            visited[v]=1;
            for(int i=0;i<edges.size();i++)
            {
                if(edges[i].src==v)
                { int dest=edges[i].dst;
                    if(visited[dest]==0)
                    {
                        topologicalSort(dest,visited,ts); //Recursive Case
                    }
                }
            }
            ts.push_back(v);
        }
    }


};


int main() {
    edge one(0,1);
    edge two(1,2);
    edge three(2,3);
    edge four(1,3);
    edge five(0,4);
    edge six(2,4);

    vector<edge> e;
    e.push_back(one);
    e.push_back(two);
    e.push_back(three);
    e.push_back(four);
    e.push_back(five);
    e.push_back(six);

    int n=5;
    graph g(n,e);
    vector<int> visit={0,0,0,0,0,0};
    vector<int> ts;
    for(int i=0;i<n;i++){
        g.topologicalSort(i,visit,ts);
    }

    for(int i=ts.size()-1;i>-1;i--){
        cout<<ts[i]<<endl;

    }
}