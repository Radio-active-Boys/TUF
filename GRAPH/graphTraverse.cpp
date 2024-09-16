#include <iostream>
#include <vector>
#include <queue>
#include <stack>
class Graph
{
    private:
    int n;
    std::vector<int>* adjList;

    public:
    Graph(int node) : n(node)
    {
        adjList = new std::vector<int> [node+1];
    }

    ~Graph()
    {
        delete [] adjList;
    }
    
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    void Display()
    {
        for(int i = 0;i < n+1; i++)
        {
            std::cout<<"adjList ["<<i<<"] { ";
            for(const auto &i : adjList[i])
            {
                std::cout<<i<<" ";
            }
            std::cout<<"}"<<std::endl;
        }
    }


    std::vector<int> bfsOfGraph(int start)
    {
        std::queue<int> que;
        que.push(start);
        std::vector<int> bfsSol;
        std::vector<bool> vist(n+1,false);
        vist[start] = true;
        while(!que.empty())
        {
            int node = que.front();
            que.pop();
            vist[node] = true;
            bfsSol.push_back(node);
            for (auto it : adjList[node])
            {
                if(!vist[it])
                {
                    que.push(it);
                    vist[it] = true;
                }
            }
        }
        
        return bfsSol;
    }

    std::vector<int> dfsOfGraph(int start)
    {
        std::stack<int> stc;
        stc.push(start);
        std::vector<int> dfsSol;
        std::vector<bool> vist(n+1,false);
        vist[start] = true;
        while(!stc.empty())
        {
            int node = stc.top();
            stc.pop();
            vist[node] = true;
            dfsSol.push_back(node);
            for (auto it : adjList[node])
            {
                if(!vist[it])
                {
                    stc.push(it);
                    vist[it] = true;
                }
            }
        }
        
        return dfsSol;
    }
    

};

void printAns(std::vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " ";
    }
    std::cout<<std::endl;
}

int main()
{
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    std::vector<int> bfsResult = g.bfsOfGraph(1);
    printAns(bfsResult);
    std::vector<int> dfsResult = g.dfsOfGraph(1);
    printAns(dfsResult);

    g.Display();
    return 0;
}

/*
    Visualization:

        1
       /  \
      2 -- 5
      |  / |
      3 -- 4

1 2 5 3 4 
adjList [0] { }
adjList [1] { 2 5 }
adjList [2] { 1 3 5 }
adjList [3] { 2 5 4 }
adjList [4] { 3 5 }
adjList [5] { 1 2 3 4 }

*/



