#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int val){
            data=val;
            next=prev=NULL;
        }
};
class implementofDLL{
    Node* head;
    Node* tail;
    public:
        DoublyList(){
            head=tail=NULL;
        }
        void Push_front(int val){
            Node* newNode=new Node(val);

            if (head==NULL){
                head=tail=newNode;
            }
            else{
                newNode->next=head;
                head->prev=newNode;
                head=newNode;
            }
        }
        void Push_back(int val){
            if(head==NULL){
               head=tail=newNode;     
            }
            else{
                newNode->next=tail;
                tail->prev=newNode;
                tail=newNode;
            }
        }
        void Pop_front(){
            if(head==NULL){
                cout<<"DLL is Empty\n";
                return;
            }
            Node*temp=head;
            head=head->next;
            if (head!=NULL){
                head->prev=NULL;
            }
            temp->next=NULL;
            delete temp;
        }
        void Push_back(){
            if(tail==NULL){
                cout<<"DLL is empty\n";
                return;
            }
            Node* temp=tail;
            tail=tail->prev;
            if(tail!=NULL){
                tail->next=NULL;
            }
            temp->prev=NULL;
            delete temp;
        }
        void print(){
            Node* temp=head;
            while (temp!=NULL){
                cout<<temp->data<<"<=>";
                temp=temp->next;
            }
            cout<<"NULL\n";
        }
};
int main(){
    implementofDLL dll;
    dll.Push_front(1);
    dll.Push_front(2);
    dll.Push_front(3);
    dll.Push_back(4);
    dll.Push_back(0);
    dll.Push_back(5);

    dll.print();

    dll.Pop_front();
    dll.Pop_front();
    
    dll.print();
    
    dll.Pop_back();
    dll.Pop_back();

    dll.print();
    
    return 0;
}