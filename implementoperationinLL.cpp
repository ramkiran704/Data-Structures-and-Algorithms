#inlcude <iostream>
using namespace std;

class Node{
    public :
        int data;
        Node* next; 
        Node(int val){
                data=val;
                next=NULL;
        }
};
class List{
    Node* head;
    Node* tail;
    public :
        List(){
            head=tail=NULL;
        }
        void Push_front(int val){
            Node* newNode=new Node(val);//dynamic
            if (head==NULL){//case 1: head and tail is NULL
                head=tail=newNode;
                return;
            }
            else{
                newNode->next=head;
                head=newNode;
            }
        }
        void Push_back(int val){
            Node* newNode=new Node(val);
            if(head==NULL){
                head=tail=newNode;
            }
            else{
                tail->next=newNode;
                tail=newNode;
            }
        }
        void Pop_front(){
            //dynamic
            if (head==NULL){//case 1: head and tail is NULL
                cout<<"LL is empty";
                return;
            }
            else{
                Node* temp=head;
                head=head->next;
                temp->next=NULL;

                delete temp;
            }
        }
        void insert(int val,int pos){
            if(pos<0){
                cout<<"Invalid POsition";
                return;
            }
            else if(pos==0){
                Push_front(val);
                return;
            }
            else{
                Node* temp=head;
                for(int i=0;i<pos-1;i++){
                    temp=temp->next
                }
                Node* newNode=new Node(val);
                newNode->next=temp->next;
                temp->next=newNode;
            }
        }
        void Pop_back(){
            if(head==NULL){
                cout<<"LL is empty";
                return;
            }
            else{
                Node* temp=head;
                while(temp->next!=tail){
                    temp=temp->next;
                }
                temp->next=NULL;
                delete tail;
                tail=temp;

            }
        }
        void search(key){
            Node* temp=head;
            int index=0;
            while(temp!=NULL){
                if(temp->data==key){
                    return index;
                }
                temp=temp->next;
                index++;
            }
            return -1;
        }
        void printll(){
            Node* temp=head;
            while(temp!=NULL){
                cout<< temp->data<<" ->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
};
int main(){
    List l1;
    l1.Push_front(1);
    l1.Push_front(3);
    l1.Push_front(2);
    l1.insert(7,1);

    l1.Pop_front();
    l1.Push_back(4);
    l1.Push_back(5);
    cout<<l1.search(3)<<endl;
    l1.printll();
    l1.Pop_back();
    l1.printll();
    return 0;
}