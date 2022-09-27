#include <bits/stdc++.h>
#include <iostream>
#include <time.h>
using namespace std;
int main() 
{
    clock_t tStart = clock();
    for(int i=0; i<10000; i++) cout<<i<<"\n";
    cout<<"Time taken: "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<"sec";
	return 0;
}
