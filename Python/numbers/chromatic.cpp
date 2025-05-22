#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>
#include <algorithm>

using namespace std;

int n;                   // number of nodes
vector<vector<int>> adj; // adjacency list

bool isSafe(int v, int color, vector<int> &colors)
{
    for (int u : adj[v])
    {
        if (colors[u] == color)
            return false;
    }
    return true;
}

bool colorGraph(int v, int maxColors, vector<int> &colors)
{
    if (v == n)
        return true;
    for (int c = 1; c <= maxColors; ++c)
    {
        if (isSafe(v, c, colors))
        {
            colors[v] = c;
            if (colorGraph(v + 1, maxColors, colors))
                return true;
            colors[v] = 0;
        }
    }
    return false;
}

int findChromaticNumber()
{
    vector<int> colors(n, 0);
    for (int k = 1; k <= n; ++k)
    {
        if (colorGraph(0, k, colors))
            return k;
    }
    return n; // worst case
}

void loadDIMACS(const string &filename)
{
    ifstream infile(filename);
    string line;
    while (getline(infile, line))
    {
        if (line.empty() || line[0] == 'c')
            continue;
        if (line[0] == 'p')
        {
            istringstream ss(line);
            string tmp;
            int m;
            ss >> tmp >> tmp >> n >> m;
            adj.assign(n, vector<int>());
        }
        else if (line[0] == 'e')
        {
            istringstream ss(line);
            char e;
            int u, v;
            ss >> e >> u >> v;
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cerr << "Usage: ./chromatic_solver graph.col" << endl;
        return 1;
    }

    loadDIMACS(argv[1]);
    int chromatic = findChromaticNumber();
    cout << chromatic << endl;
    return 0;
}
