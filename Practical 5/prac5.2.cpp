#include<iostream>
using namespace std;

struct Student
{
    string name;
    Student *next;
};

Student *head = NULL;

void insertEnd(string name)
{
    Student *newStudent = new Student;
    newStudent->name = name;

    if(head == NULL)
    {
        head = newStudent;
        newStudent->next = head;
        return;
    }

    Student *temp = head;

    while(temp->next != head)
        temp = temp->next;

    temp->next = newStudent;
    newStudent->next = head;
}

void insertBeginning(string name)
{
    Student *newStudent = new Student;
    newStudent->name = name;

    if(head == NULL)
    {
        head = newStudent;
        newStudent->next = head;
        return;
    }

    Student *temp = head;

    while(temp->next != head)
        temp = temp->next;

    newStudent->next = head;
    temp->next = newStudent;
    head = newStudent;
}

void removeStudent(string name)
{
    if(head == NULL)
        return;

    Student *temp = head;
    Student *prev = NULL;

    do
    {
        if(temp->name == name)
        {
            if(temp == head)
            {
                if(head->next == head)
                {
                    head = NULL;
                    delete temp;
                    return;
                }

                Student *last = head;

                while(last->next != head)
                    last = last->next;

                head = head->next;
                last->next = head;
                delete temp;
                return;
            }

            prev->next = temp->next;
            delete temp;
            return;
        }

        prev = temp;
        temp = temp->next;

    }while(temp != head);
}

void display()
{
    if(head == NULL)
    {
        cout << "Circle is empty" << endl;
        return;
    }

    Student *temp = head;

    cout << "Circle: ";

    do
    {
        cout << temp->name << " ";
        temp = temp->next;
    }while(temp != head);

    cout << endl;
}

int main()
{
    insertEnd("A");
    display();

    insertEnd("B");
    display();

    insertEnd("C");
    display();

    insertBeginning("D");
    display();

    removeStudent("B");
    display();

    removeStudent("D");
    display();

    return 0;
}
