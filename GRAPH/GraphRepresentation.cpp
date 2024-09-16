#include <iostream>
#include <vector>

void printgraph(const std::vector<std::vector<int>> &vect)
{
    for (int i = 0; i < vect.size(); i++)  
    { 
        for (int j = 0; j < vect[i].size(); j++) 
        { 
            std::cout << vect[i][j] << " "; 
        }     
        std::cout << std::endl; 
    } 
}

int main()
{

    int n,m;
    std::cin>>n>>m;

    std::vector<std::vector<int>> vect(n+1,std::vector<int> (m+1,0));
    for(int i = 0; i < m; i++)
    {
        int u,v;
        std::cin>>u>>v;
        vect[v][u] = 1;
        vect[u][v] = 1;
    }
    
    printgraph(vect);
    return 0;
}
											