#include<iostream>
using namespace std;

int stack[100];
int top = -1;
int n;

void push(int tray)
{
    if(top == n - 1)
    {
        cout << "Error: Stack is full" << endl;
        return;
    }

    top++;
    stack[top] = tray;
}

void pop()
{
    if(top == -1)
    {
        cout << "Error: Stack is empty" << endl;
        return;
    }

    cout << "Taken tray: " << stack[top] << endl;
    top--;
}

void display()
{
    if(top == -1)
    {
        cout << "Top tray: None" << endl;
        return;
    }

    cout << "Top tray: " << stack[top] << endl;
}

int main()
{
    cout << "Enter maximum number of trays: ";
    cin >> n;

    push(10);
    display();

    push(20);
    display();

    push(30);
    display();

    pop();
    display();

    pop();
    display();

    pop();
    display();

    pop();
    display();

    return 0;
}
