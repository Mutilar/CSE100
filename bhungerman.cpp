#include<iostream>
#include<limits.h>
using namespace std;
int n=9;

//Min Node will return the node having minimum weight
int min_node(int matrix[9][9],bool visited[9]){
    int result;
    int min_value=INT_MAX;

    for(int i=0;i<n;i++){
        if(visited[i]){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<min_value && !visited[j]){//If the node is not in visited array then consider it,otherwise not,
                                                            //to avoid the loop in the minimum spanning tree
                    min_value=matrix[i][j];//update the min value
                    result=i*10 + j;
                }//endl inner if structure
            }//end inner for loop
        }//end outer if structure
    }//end outer for loop

    return result;
}

int main(){
cout<<"Hello world\n";
/*

   g.addEdge(0, 2, 9);
   g.addEdge(0, 4, 8);
   g.addEdge(0, 5, 7);
   g.addEdge(0, 7, 9);

   g.addEdge(1, 2, 7);
   g.addEdge(1, 3, 2);
   g.addEdge(1, 4, 6);
   g.addEdge(1, 8, 3);

   g.addEdge(2, 4, 7);
   g.addEdge(2, 5, 3);

   g.addEdge(3, 4, 6);
   g.addEdge(3, 6, 3);
   g.addEdge(3, 7, 4);
   g.addEdge(3, 8, 2);

   g.addEdge(4, 5, 9);
   g.addEdge(4, 7, 4);

   g.addEdge(6, 7, 1);
   g.addEdge(6, 8, 3);
*/

int matrix[9][9]={//  0  1  2  3  4  5  6  7  8
               /*0*/{ 0, 0, 9, 0, 8, 7, 0, 9, 0},
               /*1*/{ 0, 0, 7, 2, 6, 0, 0, 0, 3},
               /*2*/{ 9, 7, 0, 0, 7, 3, 0, 0, 0},
               /*3*/{ 0, 2, 0, 0, 6, 0, 3, 4, 2},
               /*4*/{ 8, 6, 7, 6, 0, 9, 0, 4, 0},
               /*5*/{ 7, 0, 3, 0, 9, 0, 0, 0, 0},
               /*6*/{ 0, 0, 0, 3, 0, 0, 0, 1, 3},
               /*7*/{ 9, 0, 0, 4, 4, 0, 1, 0, 0},
               /*8*/{ 0, 3, 0, 2, 0, 0, 3, 0, 0},
                };

//Display the matrix
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
        cout<<matrix[i][j]<<"\t";
     cout<<"\n";
}

//Make the disconnected node weight = MAX
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(matrix[i][j]==0)
            matrix[i][j]=INT_MAX;
    }
}

//Take an visited array
bool visited[9];
//Make all the entries of visited array false
for(int i=0;i<9;i++)
    visited[i]=false;

int source;
cout<<"Enter the source vertex\n";
cin>>source;

visited[source]=true;

//Tree having 'n' vertices will have 'n-1' edges in the minimum spanning tree
int t=8;
while(t>0){
    int result=min_node(matrix,visited);
    int i=result/10;
    int j=result%10;
    visited[j]=true;//Now add the new node the visited, to consider the its edeges in the condition
    cout<<"Path "<<i<<"- "<<j<<" ="<<matrix[i][j]<<endl;

t--;
}

return 0;
}