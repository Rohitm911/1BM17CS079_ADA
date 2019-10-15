#include<iostream>;
#include<string.h>
#include<utility>
using namespace std;


int main()
{
    string s1;
    string s2;
    cout<<"enter first string: ";
    cin>>s1;
    cout<<"enter second string: ";
    cin>>s2;
    int n1=s1.size();
    int n2=s2.size();
    int o[n1+1][n2+1];
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
            o[i][j]=0;
    }
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                o[i][j]=1+o[i-1][j-1];
            }
            else
            {
                o[i][j]=max(o[i-1][j],o[i][j-1]);
            }
        }

    }
    cout<<"length of lcs: "<<o[n1][n2]<<endl;
    int i=n1,j=n2,k=o[n1][n2]+1;
    char out[k];
    out[k]='\0';
    k--;
    while(i>=0 && j>=0)
    {
        if(s1[i-1]==s2[j-1])
            {
                out[k]=s1[i-1];
                i--;j--;k--;
            }
            else
            {
                if(o[i-1][j]>o[i][j-1])
                    i--;
                else
                    j--;
            }
            if(k==-1)
                break;
    }

    cout<<"lcs: "<<out<<endl;

}
