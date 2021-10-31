#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class SinglyLinkedList{

    private:
        Node *first,*last;
        int size;
    public:
        SinglyLinkedList(){
            first=NULL;
            last=NULL;
            size=0;
        }
        SinglyLinkedList(int arr[],int n){
            
            first=new Node;
            first->data=arr[0];
            first->next=NULL;
            last=first;
            size=1;
            Node *t;

            for(int i=1;i<n;i++){
                
                t=new Node;
                t->data=arr[i];
                t->next=NULL;
                last->next=t;
                last=t;
                size++;
            }
        }
        ~SinglyLinkedList(){
            Node *p=first;
            while(first){
                first=first->next;
                delete p;
                p=first;
                size--;
            }
        }

        void display(){
            
            Node *p=first;

            while(p){
                cout<<p->data<<"->";
                p=p->next;
            }
            if(size!=0)
                cout<<"NULL"<<endl;

        }
        int length(){
            return size;
        }

        void insert(int pos,int element){

            if(size==0){
                first=new Node;
                first->data=element;
                first->next=NULL;
                size++;
                last=first;
                return;
            }

            if(pos<0 || pos>=size){
                cout<<"Index Not Found, you can not insert "<<element<<" at "<<pos<<" index."<<endl;
                return;
            }
            else if(pos==0){
                Node *t=new Node;
                t->data=element;
                t->next=first;
                first=t;
                size++;
            }
            else{
                Node *p=first;

                for(int i=1;i<pos;i++){
                    p=p->next;
                }
                Node *t=new Node;
                t->data=element;
                t->next=p->next;
                p->next=t;
                size++;
                if(pos==size-1){
                    last=t;
                }
            }
        }
        
        void insertAfter(int pos,int element){
            if(pos<0 || pos>=size){
                cout<<"Index Not Found, you can not insert "<<element<<" at "<<pos<<" index."<<endl;
                return;
            }
            Node *p=first;
            for(int i=0;i<pos;i++){
                p=p->next;
            }
            Node *t=new Node;
            t->data=element;
            t->next=p->next;
            p->next=t;
            if(pos==size-1){
                last=t;
            }
            size++;

        }

        void insertBefore(int pos,int element){
            if(pos<0 || pos>=size){
                cout<<"Index Not Found, you can not insert "<<element<<" at "<<pos<<" index."<<endl;
                return;
            }
            else if(pos==0){
                Node *t=new Node;
                t->data=element;
                t->next=first;
                first=t;
                size++;
            }
            else{
                Node*p=new Node;
                for(int i=0;i<pos-1;i++){
                    p=p->next;
                }
                Node *t=new Node;
                t->data=element;
                t->next=p->next;
                p->next=t;
                size++;
            }
        }
        void insertLast(int element){
            
                Node *t=new Node;
                t->data=element;
                t->next=NULL;
                if(first==NULL){
                    first=last=t;
                }
                else{
                    last->next=t;
                    last=t;
                }
                size++;
        }
        
        void insertFirst(int element){
    
            Node *t=new Node;
            t->data=element;
            t->next=first;
            if(first==NULL){
                first=last=t;
            }
            else
                first=t;
            size++;

        }
        void insertAtSortedPosition(int element){
            
            Node* t=new Node;
            t->data=element;
            if(first==NULL){
                t->next=NULL;
                first=last=t;
            }
            else if(element<=first->data){
                t->next=first;
                first=t;
            }
            else if(element>last->data){
                t->next=NULL;
                last->next=t;
                last=t;
            }
            else{
                Node *p=first;
                while(p->next->next!=NULL && element<=(p->next->data)){
                    p=p->next;
                }
                t->next=p->next;
                p->next=t;
            }
            size++;
        }

        int Delete( int index){
            
            Node *p,*q;
            int previousData=-99999;
            if(index==0){
                p=first;
                previousData=first->data;
                first=first->next;
                delete p;
                size--;
                return previousData;
            }
            else{
                p=first;
                q=NULL;
                for(int i=0;i<index && p;i++){
                    q=p;
                    p=p->next;
                }
                if(p!=NULL){
                    q->next=p->next;
                    previousData=p->data;
                    if(p==last){
                        last=q;
                    }
                    delete p;
                    size--;
                    return previousData;
                }
                return previousData;
            }
        }

        bool isSorted(){
            Node *p=first;
            int x=-999999999;
            while(p!=NULL){
                if(p->data<x){
                    return false;
                }
                x=p->data;
                p=p->next;
            }
            return true;
        }

        void removeDuplicatesInSorted(){
            Node *p=first->next;
            Node *q=first;
            while(p!=NULL){
                if(q->data!=p->data){
                    q=p;
                    p=p->next;
                }
                else{
                    q->next=p->next;
                    delete p;
                    size--;
                    p=q->next;
                }
            }
        }

        void reversingElement(){
            int arr[size];
            Node *p=first;
            int i=0;
            while(p){
                arr[i++]=p->data;
                p=p->next;
            }
            p=first;
            i--;
            while(p){
                p->data=arr[i--];
                p=p->next;
            }
            
        }
        void reversingLinks(){
            Node *p,*q,*r,*temp;
            p=first;
            q=r=NULL;
            last=first;
            while(p){
                r=q;
                q=p;
                p=p->next;
                q->next=r;
            }
            first=q;
        }
        void recursiveReverse(Node *q,Node *p){
            if(p!=NULL){
                recursiveReverse(p,p->next);
                p->next=q;
            }
            else{
                first=q;
            }

        }
        void concatenation(SinglyLinkedList l2){
            last->next=l2.getFirst();
            l2.first=NULL;
            last=l2.getLast();
            size+=l2.size;
        }

        
       
        Node* getLast(){
            return last;
        }

        Node* getFirst(){
            return first;
        }
        
    
};
void mergingList(SinglyLinkedList l1,SinglyLinkedList l2){
            Node *third,*prev,*q=l2.getFirst(),*p=l1.getFirst();
            if(p->data<q->data){
                third=prev=p;
                p=p->next;
                prev->next=NULL;
            }
            else{
                third=prev=q;
                q=q->next;
                prev->next=NULL;
            }

            while(p!=NULL && q!=NULL ){
                if(p->data<q->data){
                    prev->next=p;
                    prev=p;
                    p=p->next;
                    prev->next=NULL;
                }
                else{
                    prev->next=q;
                    prev=q;
                    q=q->next;
                    prev->next=NULL;
                }
            }
            if(p!=NULL){
                prev->next=p;
            }
            else{
                prev->next=q;
            }

            Node *t=third;
            while(t){
                cout<<t->data<<" ";
                t=t->next;
            }

        }


int  main(){

    int ar[5]={1};
    SinglyLinkedList l;
    l.insert(0,100);
    l.insertLast(200);
    l.insertLast(300);
    l.insertLast(400);
    l.insertLast(500);
    l.insertLast(600);
    l.display();
    SinglyLinkedList l2;
    l2.insertLast(45);
    l2.insertLast(250);
    l2.display();
    mergingList(l,l2);
    cout<<l.getFirst()->data<<endl;
    cout<<l.getLast()->data<<endl;
    cout<<l.length()<<endl;

    return 0;
}
