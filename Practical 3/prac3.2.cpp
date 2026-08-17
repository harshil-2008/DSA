#include <iostream>
using namespace std;

int main()
{
    int A[]={0,0,0,1,0,2,2,2,1,1,1,0,0,1,1,0,2};

    int n = sizeof(A)/sizeof(A[0]);

    int c0=0,c1=0,c2=0;

    for(int i=0; i<n; i++)
    {
        if(A[i]==0)
        {
            c0++;
        }
        else if(A[i]==1)
        {
            c1++;
        }
        else
        {
            c2++;
        }
    }

    for(int i=0; i<c0; i++)
{
    A[i]=0;
}

for(int i=c0; i<c0+c1;i++)
{
    A[i]=1;
}
for(int i=c1+c0; i<c0+c1+c2;i++)
{
    A[i]=2;
}

for(int j=0; j<n; j++)
{
    if(j==0)
    {
        cout<<"{ "<<A[0];
    }
    else if(j==n-1)
    {
        cout<<A[j]<<"}";
    }
    else
    {
        cout<<" "<<A[j]<<",";
    }
}
}
