#include <iostream>
using namespace std;

int main()
{
    int A[]={2,45,67,12,98,56,76,23, 31};

    int size=sizeof(A)/sizeof(A[0]);

    //Bubble sort
    for(int i=0; i<size; i++)
    {
        for(int j=0;j<size-1; j++)
        {
            int temp=0;
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
    cout<<"Selection Sort: "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<A[i]<<endl;
    }


    //Selection Sorting

    for(int i = 0; i < size - 1; i++)
    {
        int min = i;

        for(int j = i + 1; j < size; j++)
        {
            if(A[j] < A[min])
            {
                min = j;
            }
        }

        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }

    cout << "Selection Sorted: " << endl;

    for(int i = 0; i < size; i++)
    {
        cout << A[i] << endl;
    }


    //Insertion Sorting
    for(int i=1; i<size;i++)
    {
        int key=A[i];
        int j=i-1;

        while(j>0 && A[j]>key)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
    cout << "Insertion Sorted: " << endl;

    for(int i = 0; i < size; i++)
    {
        cout << A[i] << endl;
    }
}
