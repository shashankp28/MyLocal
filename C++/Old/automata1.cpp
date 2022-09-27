#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iterator>
#include <set>
#define ull unsigned long long int
#define ll long long int
#define fastio ios_base::sync_with_stdio(false)
#define tie cin.tie(NULL)
#define range(i,n1,n2) for(int i=n1;i<n2;i++)
#define in(x1, x2) x1 x2;cin>>x2
#define all(s) s.begin(), s.end()
#define arin(a, n) a[n];range(i,0,n) cin>>a[i]
using namespace std;
typedef struct node
{
	int val;
	struct node* next[2];
} node;
int main() 
{
    std::cout << std::fixed;
    fastio;tie;
	in(int, t);
	while(t--)
	{
		in(string, s);
		node* q[4];
		range(i, 0, 4)
		{   
			q[i] = new node();
		}
		/*q[0]->val = 5;
		q[1]->val = 5;
		q[2]->val = 5;
		q[3]->val = 5;
		range(i, 0, 4)
		{
			cout<<q[i]->val;
		}*/
		q[0]->next[0] = q[0];
		q[0]->next[1] = q[1];
		q[1]->next[0] = q[2];
		q[1]->next[1] = q[1];
		q[2]->next[0] = q[3];
		q[2]->next[1] = q[1];
		q[3]->next[0] = q[0];
		q[3]->next[1] = q[1];
		struct node *ans=q[0];
		range(i, 0, s.size())
		{
			ans = ans->next[s[i]-48];
		}
		cout<<(ans==q[3] ? "Yes" : "No")<<"\n";
	}	
	return 0;
}
