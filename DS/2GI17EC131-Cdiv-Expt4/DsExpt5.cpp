#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};

class linkedlist{

    Node *head,*tail;
public :
    linkedlist()
    {
        head = NULL;
        tail = NULL;
    }

    void addnode(int n)
    {
        Node *temp = new Node;
        temp->data = n;
        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = tail->next;
        }
    }
    void delnode()
    {
        int n;
        Node *prev = new Node;
        Node *curr = new Node;
        prev = NULL;
        curr = head;
        cout<<"Enter the value to be deleted : ";
        cin>>n;
        while(curr != NULL)
        {
            if(curr->data == n)
            {
                prev->next = curr->next;
                prev = prev->next;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    void searchnode()
    {
        int n,c=0;
        Node *temp = new Node;
        temp = head;
        cout<<"Enter the value to be searched :";
        cin>>n;
        while(temp != NULL)
        {
            if(temp->data == n)
            {
                cout<<"The element found at position "<<c<<endl;
            }
            temp = temp->next;
            c = c + 1;
        }
    }
    void insertnode()
    {
        Node *temp = new Node;
        int n;
        cout<<"Enter the value :";
        cin>>n;
        temp->data = n;
        temp->next = NULL;
        temp->next = head;
        head = temp;
    }
    void display()
    {
        Node *temp = new Node;
        temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<endl;
    }

};

int main()
{
    linkedlist L;
    int ch,n;
    start :
    cout<<"Enter the choice\n1.Add\t2.Delete\t3.Search\t4.Insert\t5.Display\t";
    cin>>ch;
    switch(ch)
    {
    case 1 :
        cout<<"Enter the value : ";
        cin>>n;
        L.addnode(n);
        break;
    case 2 :
        L.delnode();
        break;
    case 3 :
        L.searchnode();
        break;
    case 4 :
        L.insertnode();
        break;
    case 5 :
        L.display();
        break;
    default :
        cout<<"Enter correct choice\n";
    }
    goto start;
}
