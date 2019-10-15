#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter number of items: ";
    cin>>n;
    int v[n];
    int w[n];
    int max_w;
    cout<<"enter the values of items:\n";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<"enter weight of items: \n";
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    cout<<"enter max value of knapsack: ";
    cin>>max_w;
    int o[n+1][max_w+1];
    for(int i=0;i<=n;i++)
        o[i][0]=0;
    for(int i=0;i<=max_w;i++)
        o[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=max_w;j++)
        {
            if(j-w[i-1]>=0)
            {
                o[i][j]=max((v[i-1]+o[i-1][j-w[i-1]]),o[i-1][j]);
            }
            else
            {
                o[i][j]=o[i-1][j];
            }
        }
    }

    cout<<"max value of knapsack: "<<o[n][max_w]<<endl;

    return 0;
}
