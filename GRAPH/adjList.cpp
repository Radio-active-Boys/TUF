#include <iostream>
#include <vector>

void printGraph(const int &n,const std::vector<int> adj[])
{
    for(int i = 0;i < n+1; i++)
    {
        std::cout<<"adj ["<<i<<"] {";
        for(const auto &i : adj[i])
        {
            std::cout<<i<<" ";
        }
        std::cout<<"}"<<std::endl;
    }
}

int main ()
{

    std::cout<<"Enter Graph Node: ";
    int n,m;
    std::cin>>n>>m;
    std::vector<int> adjList[n+1];
    for (int i = 0; i < m ; i++)
    {
        int u,v;
        std::cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    printGraph(n,adjList);
    return 0;
}