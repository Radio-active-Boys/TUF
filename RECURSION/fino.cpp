#include <bits/stdc++.h>

int fac(int n)
{
    if (n <= 0) return 1;
    return n*fac(n-1);

}

int main()
{
    int n = 7;
    std::cout<<"factorial "<<fac(n)<<std::endl;
    return 0;
}