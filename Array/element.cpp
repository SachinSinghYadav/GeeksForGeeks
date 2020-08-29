/* https://practice.geeksforgeeks.org/problems/unsorted-array/0  */
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> arr)
{
    vector<int> nsr,ngl;
    stack<int>s;
    for(int i=arr.size()-1;i>=0;i--)
    {
        if(s.empty())
        {
            nsr.push_back(-1);
        }
        else if(s.top()<arr[i])
            nsr.push_back(s.top());
        else if(s.top()>=arr[i])
        {
            while(!s.empty() && s.top()>=arr[i])
                s.pop();
            if(s.empty())
                nsr.push_back(-1);
            else
                nsr.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(nsr.begin(),nsr.end());
    while(!s.empty())
        s.pop();
    for(int i=0;i<arr.size();i++)
    {
        if(s.empty())
            ngl.push_back(-1);
        else if(s.top()>arr[i])
            ngl.push_back(s.top());
        else if(s.top()<=arr[i])
        {
            while(!s.empty() && s.top()<=arr[i])
                s.pop();
            if(s.empty())
                ngl.push_back(-1);
            else
                ngl.push_back(s.top());
        }
        s.push(arr[i]);
    }
    for(int i=1;i<nsr.size()-1;i++)
       if(nsr[i]==-1 && ngl[i]==-1)
      {
           return arr[i];
      }
      return -1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            int k; cin>>k;
            v.push_back(k);
        }
        cout<<solve(v)<<endl;
    }
    return 0;
}
