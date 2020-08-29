/*Triplet Sum in Array*/
/*https://practice.geeksforgeeks.org/problems/triplet-sum-in-array/0*/


#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t; cin>>t;
    while(t--)
    {
        int n,sum; cin>>n>>sum;
        int *arr=new int[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        int flag=0;
        for(int i=0;i<n-2;i++)
        {
            int start=i+1;
            int end=n-1;
            while(start<end)
            {
                int total=arr[i]+arr[start]+arr[end];
                if(total==sum)
                {
                    cout<<1<<endl;
                    flag=1;
                    break;
                }
                if(sum>total)start++;
                if(sum<total) end--;
            }
            if(flag==1)
                break;
        }
        if(flag==0)
            cout<<0<<endl;
        delete [] arr;
    }
}
