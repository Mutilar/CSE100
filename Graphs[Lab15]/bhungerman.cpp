#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

bool running = true;
int len = 0;
int cost_end = 10000000;
int debug_count = 0;

struct Graph
{
  public:
    vector<string> vertices;
    vector<string> *edges;
    vector<int> *weights;
    vector<bool> *visited;
    void print();
    void AddEdge(string, string, int);
    void AddNode(string vert1);
    int FindVertex(string);
    int FindEdgeCost(string vert1, string vert2);
    int IsReachable(string vert1, string vert2);
    void resetBFS();
    int BFS(string vert1, string vert2, int cost);
    void resizeTo(int length);
    string FindIndex(int index);
};

void Graph::print()
{
    for (int j = 0; j < len; j++)
    {
        for (int i = 0; i < edges[j].size(); i++)
        {
            cout << FindIndex(j) << " " << edges[j][i] << " " << weights[j][i] << "\n";
        }
    }
}
void Graph::resizeTo(int length)
{
    edges = new vector<string>[length];
    weights = new vector<int>[length];
    visited = new vector<bool>[length];
    for (int j = 0; j < length; j++)
    {
        visited[j].resize(length);
        for (int i = 0; i < length; i++)
        {
            visited[j][i] = false;
        }
    }
}
void Graph::AddNode(string vert1)
{
    bool added = false;
    if (vertices.size() != 0)
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices[i] > vert1)
            {
                added = true;
                auto itPos = vertices.begin() + i;
                auto newIt = vertices.insert(itPos, vert1);
                break;
            }
        }
        if (!added)
        {
            vertices.push_back(vert1);
        }
    }
    else
    {
        vertices.push_back(vert1);
    }
}
void Graph::AddEdge(string vert1, string vert2, int weight)
{
    if (FindVertex(vert1) > -1 && FindVertex(vert2) > -1)
    {
        bool added = false;
        if (edges[FindVertex(vert1)].size() != 0)
        {
            for (int i = 0; i < edges[FindVertex(vert1)].size(); i++)
            {
                if (edges[FindVertex(vert1)][i] > vert2)
                {
                    added = true;
                    auto itPos = edges[FindVertex(vert1)].begin() + i;
                    auto newIt = edges[FindVertex(vert1)].insert(itPos, vert2);
                    auto itPos2 = weights[FindVertex(vert1)].begin() + i;
                    auto newIt2 = weights[FindVertex(vert1)].insert(itPos2, weight);
                    break;
                }
            }
            if (!added)
            {
                edges[FindVertex(vert1)].push_back(vert2);
                weights[FindVertex(vert1)].push_back(weight);
            }
        }
        else
        {
            edges[FindVertex(vert1)].push_back(vert2);
            weights[FindVertex(vert1)].push_back(weight);
        }
    }
}
int Graph::FindVertex(string vert1)
{
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i] == vert1)
            return i;
    }
    return -1;
}
string Graph::FindIndex(int index)
{
    return vertices[index];
}
int Graph::FindEdgeCost(string vert1, string vert2)
{
    if (FindVertex(vert1) > -1 && FindVertex(vert2) > -1)
    {
        for (int i = 0; i < edges[FindVertex(vert1)].size(); i++)
        {
            if (edges[FindVertex(vert1)][i] == vert2)
            {
                return weights[FindVertex(vert1)][i];
            }
        }
    }
    return -1;
}
int Graph::IsReachable(string vert1, string vert2)
{
}
void Graph::resetBFS()
{
    for (int j = 0; j < len; j++)
    {
        for (int i = 0; i < len; i++)
        {
            visited[j][i] = false;
        }
    }
}
int Graph::BFS(string vert1, string vert2, int cost)
{
    if (vert1 == vert2)
        cost_end = min(cost, cost_end);
    else
    {
        for (int i = 0; i < edges[FindVertex(vert1)].size(); i++)
        {
            if (!visited[FindVertex(vert1)][FindVertex(edges[FindVertex(vert1)][i])] && !visited[FindVertex(edges[FindVertex(vert1)][i])][FindVertex(vert1)])
            {
                visited[FindVertex(vert1)][FindVertex(edges[FindVertex(vert1)][i])] = true;
                visited[FindVertex(edges[FindVertex(vert1)][i])][FindVertex(vert1)] = true;
                BFS(edges[FindVertex(vert1)][i], vert2, cost + 1);
            }
        }
    }
}

int main()
{
    Graph G;
    string val;
    string val2;
    string val3;
    int cost;
    int state = 0;

    while (running)
    {
        cin >> val;
        if (val == "0")
        {
            running = false;
            break;
        }
        else if (val == "END")
        {
            state++;
            if (state == 1)
            {
                G.resizeTo(len);
            }
            if (state == 2)
            {
                G.print();
            }
        }
        else
        {
            switch (state)
            {
            case 0:
                G.AddNode(val);
                len++;
                cout << val << "\n";
                break;
            case 1:
                cin >> val2;
                cin >> cost;
                //cout << val << " " << val2 << " " << cost << "\n";
                G.AddEdge(val, val2, cost);
                break;
            case 2:
                switch (stoi(val))
                {
                case 0:
                    cout << "error";
                    break;
                case 1:
                    cin >> val2;
                    if (G.FindVertex(val2) > -1)
                        cout << "1\n";
                    else
                        cout << "0\n";
                    break;
                case 2:
                    cin >> val2;
                    cin >> val3;
                    cout << G.FindEdgeCost(val2, val3) << "\n";
                    break;
                case 3:
                    cin >> val2;
                    cin >> val3;
                    debug_count++;
                    //cout << "\n\n"
                    //     << val2 << " GOING TO " << val3 << "\n\n";
                    cost_end = 10000000;

                    G.resetBFS();
                    G.BFS(val2, val3, 0);
                    if (cost_end == 10000000)
                        cout << "-1\n";
                    else
                        cout << cost_end << "\n";
                    break;
                }
                break;
            }
        }
    }
}
