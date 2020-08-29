/* https://practice.geeksforgeeks.org/problems/save-ironman/0 */
/* Getline concept is used*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string s,s1,k;
        getline(cin,s);
        for(int i=0;s[i];i++)
        {
            if(s[i]!=' ')
            {
            if(s[i]>='A' && (int)s[i]<'Z')
                s1.push_back((s[i]-'A')+97);
            if((int)s[i]>='a' && (int)s[i]<='z')
                s1.push_back(s[i]);
            if(s[i]>='0' && s[i]<='9')
                s1.push_back(s[i]);
            }
        }
        s=s1;
        reverse(s1.begin(),s1.end());
        if(s1==s)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
