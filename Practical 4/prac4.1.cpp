#include <iostream>
using namespace std;

int main()
{
    int queue[100];
    int n=0;

    int critical;
    cout<<"Enter critical patient token: "<<endl;
    cin>>critical;

    for(int i=n; i>0; i--)
    {
        queue[i]=queue[i-1];
    }

    queue[0]=critical;
    n++;

    cout<<"Post front insertion:-"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<queue[i]<<" ";
    }
    cout<<endl;

    int routine;
    cout<<"Enter routine patient token: ";
    cin>>routine;

    queue[n]=routine;
    n++;

    cout<<"Post end insertion:- ";
    for(int i=0; i<n; i++)
    {
        cout<<queue[i]<<" ";
    }
    cout<<endl;

    int priority, position;
    cout<<"Enter priority patient token: ";
    cin>>priority;

    cout<<"Enter position: ";
    cin>>position;

    if (position>=0 && position<=n) 
    {
        for (int i = n; i>position; i--) 
        {
            queue[i] = queue[i-1];
        }
        queue[position] = priority;
        n++;

    }
    else 
    {
        cout<<"Invalid position. Patient not inserted."<<endl;
    }

    cout<<"After position insertion: ";
    for (int i = 0; i<n; i++) {
        cout<<queue[i]<<" ";
    }

    cout<<endl;

    return 0;
}
