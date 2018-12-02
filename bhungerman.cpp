#include <map>
#include <list>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
class Node
{
 public:
   string id;
   int distance;
   bool visted;

   Node()
   {
      id = "Temp";
      visted = false;
      distance = 0;
   }
   void setID(string input)
   {
      id = input;
   }
   void setVisted(bool input)
   {
      visted = input;
   }
   void setDistance(int value)
   {
      distance = value;
   }
};

bool compareIds(const Node *a, const Node *b)
{
   return a->id < b->id;
}
struct Graph
{
   vector<Node *> vertices;
   vector<vector<string>> edges;
   vector<vector<int>> weights;
   void PrintOut(void);
   void AddEdge(string, string, int);
   int FindVertex(string);
   int FindEdgeCost(string vert1, string vert2);
   int IsReachable(string vert1, string vert2);
};

void Graph::PrintOut(void)
{
   // list<string>::iterator it;
   // map<pair<string,string>,int>::iterator eit;

   // for(it=vertices.begin(); it!=vertices.end(); it++) {
   //     cout << *it << endl;
   // }

   // for(eit = edges.begin(); eit != edges.end(); eit++) {
   //     cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
   // }

   vector<Node *> sorted = vertices;
   for (int i = 0; i < sorted.size(); i++)
   {
      cout << sorted[i]->id << endl;
   }

   //Sort Here
   sort(sorted.begin(), sorted.end(), compareIds);
   for (int i = 0; i < sorted.size(); i++)
   {
      vector<int> tempWeights;
      vector<string> sorted2 = edges[FindVertex(sorted[i]->id)];
      sort(sorted2.begin(), sorted2.end());

      for (int k = 0; k < weights[FindVertex(sorted[i]->id)].size(); k++)
      {
         int index = 0;
         while (index < weights[FindVertex(sorted[i]->id)].size())
         {
            if (edges[FindVertex(sorted[i]->id)][k] == sorted2[index])
            {
               tempWeights.push_back(weights[FindVertex(sorted[i]->id)][index]);
               index++;
               continue;
            }
            index++;
         }
      }

      for (int j = 0; j < tempWeights.size(); j++)
      {
         cout << sorted[i]->id << " " << sorted2[j] << " " << tempWeights[j] << endl;
      }
   }
}

void Graph::AddEdge(string vert1, string vert2, int weight)
{
   edges[FindVertex(vert1)].push_back(vert2);
   weights[FindVertex(vert1)].push_back(weight);
}

int Graph::FindVertex(string vert1)
{
   for (int i = 0; i < vertices.size(); i++)
   {
      if (vertices[i]->id == vert1)
         return i;
   }
   return -1;
}

int Graph::FindEdgeCost(string vert1, string vert2)
{
   if (FindVertex(vert1) == -1)
   {
      return -1;
   }
   for (int i = 0; i < edges[FindVertex(vert1)].size(); i++)
   {
      if (edges[FindVertex(vert1)][i] == vert2)
      {
         return weights[FindVertex(vert1)][i];
      }
   }
   return -1;
}

int Graph::IsReachable(string vert1, string vert2)
{
   for (int i = 0; i < vertices.size(); i++)
   {
      vertices[i]->setVisted(false);
   }

   int count;
   list<Node *> queue;
   vertices[FindVertex(vert1)]->distance = 0;
   vertices[FindVertex(vert1)]->setVisted(true);
   queue.push_back(vertices[FindVertex(vert1)]);

   if (vert1 == vert2)
   {
      return 0;
   }

   while (!queue.empty())
   {
      int j;
      Node *temp = queue.front();
      queue.pop_front();
      for (int i = 0; i < edges[FindVertex(temp->id)].size(); i++)
      {
         Node *v = vertices[FindVertex(edges[FindVertex(temp->id)][i])];

         if (!v->visted)
         {
            v->setVisted(true);
            v->setDistance(temp->distance + 1);

            if (v->id == vert2)
            {
               return v->distance;
            }
            cout << "queuing" << v->id << "\n";
            if (v->id == "1")
            {
               cout << "printing queue: ";
               while (!queue.empty())
               {
                  std::cout << queue.front()->id << " ";
                  queue.pop_front();
               }
               break;
            }
            queue.push_back(v);
         }
      }
   }

   return -1;
}

int main()
{
   Graph G;
   string node1, node2, operation;
   int weight, opCodes;
   int stage = 0;

   while (stage != 3)
   {
      if (stage == 0)
      {
         std::cin >> node1;
      }
      else if (stage == 1)
      {
         std::cin >> node1;
         if (node1 == "END")
         {
            G.PrintOut();
            stage++;
            continue;
         }
         std::cin >> node2;
         std::cin >> weight;
      }
      else if (stage == 2)
      {
         node1 = "";
         std::cin >> operation;
      }

      if (node1 == "END" || operation == "END")
      {
         stage++;
         continue;
      }

      if (stage == 0)
      {
         Node *temp = new Node();
         temp->setID(node1);
         G.vertices.push_back(temp);
         G.edges.resize(G.vertices.size());
         G.weights.resize(G.vertices.size());
      }
      else if (stage == 1)
      {
         G.AddEdge(node1, node2, weight);
      }
      else if (stage == 2)
      {
         if (operation == "0")
         {
            break;
         }
         else if (operation == "1")
         {
            std::cin >> node1;
            if (G.FindVertex(node1) >= 0)
            {
               cout << "1" << endl;
            }
            else if (G.FindVertex(node1) == -1)
            {
               cout << "0" << endl;
            }
         }
         else if (operation == "2")
         {
            std::cin >> node1;
            std::cin >> node2;
            cout << G.FindEdgeCost(node1, node2) << endl;
         }
         else if (operation == "3")
         {
            std::cin >> node1;
            std::cin >> node2;
            cout << G.IsReachable(node1, node2) << endl;
         }
      }
   }
}

/*
0=A
1=B
2=C
3=D
4=E
5=F

0
1
2
3
4
5
END
0 4 1
0 3 5
1 2 3
2 3 3
2 5 3
3 1 1
3 2 2
3 4 2
4 1 5
4 3 3
5 0 4
END
3 0 2




*/