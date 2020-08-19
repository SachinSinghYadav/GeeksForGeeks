#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v,e;
    cin>>v>>e;
    int** edges=new int*[v];
    for(int i=0;i<v;i++)
        edges[i]=new int[v];
    //memset(edges,-1,sizeof(edges));
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
           edges[i][j]=-1;
    int sv,ev,w;
    for(int i=0;i<v;i++)
    {
        cin>>sv>>ev>>w;
       //
        edges[sv][ev]=w;
    }
    int *weight=new int[v];
    int* parent=new int[v];
    parent[0]=-1;
    bool* visited=new bool[v];
    for(int i=0;i<v;i++)
        weight[i]=INT_MAX;
    weight[0]=0;
    for(int i=0;i<v;i++)
        visited[i]=false;
    int k=v;

    while(k--)
    {
        int mn=INT_MAX;
        for(int i=0;i<v;i++)
            if(weight[i]<=mn && !visited[i])
                mn=i;
        for(int i=0;i<v;i++)
        {
            if(edges[mn][i]!=-1 && !visited[i])
            {
                if(edges[mn][i]<=weight[i]){
                    weight[i]=edges[mn][i];
                    parent[i]=mn;
                }
            }

        }
        visited[mn]=true;
    }
    for(int i=1;i<v;i++){
        if(i>parent[i])
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        else
           cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
    }
}
