#include<bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int source,destination,weight;
};
bool compare(Edge a,Edge b)
{
    return(a.weight<b.weight);
}
int main()
{
    int v,e;cin>>v>>e;
    Edge* input=new Edge[e];
    Edge* output=new Edge[v-1];
    int *parent=new int[v];
    for(int i=0;i<v;i++)
        parent[i]=i;
    for(int i=0;i<e;i++)
    {
        cin>>input[i].source>>input[i].destination>>input[i].weight;
    }
    sort(input,input+e,compare);
    for(int i=0;i<e;i++)
    {
        cout<<input[i].source<<" "<<input[i].destination<<" "<<input[i].weight<<endl;
    }
    int cnt=0,i=0,k=0;
    while(cnt<v-1)
    {
        int p1=input[i].source;
        int p2=input[i].destination;
        while(parent[p1]!=p1)
            p1=parent[p1];
        while(parent[p2]!=p2)
            p2=parent[p2];
        if(p1!=p2)
        {
            output[k++]=input[i];
            parent[p1]=p2;
            cnt++;
        }
        i++;
    }
    cout<<"MST"<<endl;
    for(int i=0;i<k;i++)
    {
        cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
    }

}
