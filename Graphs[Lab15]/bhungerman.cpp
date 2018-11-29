#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool running;

struct Graph
{
  public:
    list<string> vertices;
    map<pair<string, string>, int> edges;
    void PrintOut(void);
    void AddEdge(string, string, int);
    bool FindVertex(string);
    int FindEdgeCost(string vert1, string vert2);
    int IsReachable(string vert1, string vert2);
};

void Graph::PrintOut(void)
{
    list<string>::iterator it;
    map<pair<string, string>, int>::iterator eit;

    for (it = vertices.begin(); it != vertices.end(); it++)
    {
        cout << *it << endl;
    }

    for (eit = edges.begin(); eit != edges.end(); eit++)
    {
        cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
    }
}

void Graph::AddEdge(string vert1, string vert2, int weight)
{
    pair <string, string> product;
    product = make_pair(string(vert1), string(vert2));
    edges.insert(product, weight);

}

bool Graph::FindVertex(string vert1)
{
}

int Graph::FindEdgeCost(string vert1, string vert2)
{
}

int Graph::IsReachable(string vert1, string vert2)
{
}

int main()
{
    Graph G;

    string val;
    char command = 'i'; //insert

    int state = 0;

    while (running)
    {
        switch (state)
        {
            cin >> val;
            if (val == "END") {
                state++;
                break;
            }
        case 0:
            G.vertices.push_back(val);
            break;
        case 1:

            break;
        case 2:

            break;
        }

        switch (val)
        {
        case -1:
            outputHashTable();
            command = 's'; //search (index of)
            break;
        case -2:
            command = 'd'; //delete
            break;
        case -3:
            outputHashTable();
            running = false;
            break;
        default:
            switch (command)
            {
            case 'i':
                insertKey(val);
                break;
            case 's':
                searchKey(val);
                break;
            case 'd':
                deleteKey(val);
                break;
            }
        }
    }
}
