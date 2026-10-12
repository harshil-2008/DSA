#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    Node *front=NULL, *rear=NULL;
    int choice, patient;

    while(cin>>choice)
    {
        if(choice==1)
        {
            cin>>patient;

            Node *newnode=new Node;
            newnode->data=patient;
            newnode->next=NULL;

            if(front==NULL)
                front=rear=newnode;
            else
            {
                rear->next=newnode;
                rear=newnode;
            }
        }
        else if(choice==2)
        {
            if(front==NULL)
            {
                cout<<"Queue Underflow"<<endl;
            }
            else
            {
                Node *temp=front;
                front=front->next;
                delete temp;

                if(front==NULL)
                    rear=NULL;
            }
        }

        if(front==NULL)
            cout<<"Front: Empty"<<endl;
        else
            cout<<"Front: "<<front->data<<endl;
    }

    return 0;
}
