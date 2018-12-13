#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

struct Node{
    char name[50],position[50];
    int num;
    Node *next;
}*front=NULL,*rear=NULL,*temp=NULL;

class Queue{
public:
    void enQueue(int num,char name[],char position[]);
    void deQueue();
    void displayQueue();
};
void Queue::enQueue(int num, char name[], char position[]){
    temp = new Node;
    temp->num = num;
    strcpy(temp->name,name);
    strcpy(temp->position,position);
    temp->next = NULL;
    if(front == NULL){
        front = temp;
        rear = temp;
    } else{
        rear->next = temp;
        rear =temp;
    }
}

void Queue::deQueue() {
    if (front==NULL){
        cout<<"Queue Empty"<<endl;
    } else{
        temp = front;
        front=front->next;
        delete temp;
    }
}
void Queue::displayQueue() {
    if(front==NULL){
        cout<<"Queue Empty"<<endl;
        return;
    }
    for (temp = front; temp !=NULL ; temp=temp->next){
        cout<<temp->num<<"->"<<temp->name<<"->"<<temp->position<<endl;
    }
}
int main() {
    Queue queue;
    int in;
    while (true){
        cout<<"-------------------"<<endl;
        cout<<"|Linked List Stack|"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"1. EnQueue"<<endl;
        cout<<"2. DeQueue"<<endl;
        cout<<"3. Display Queue"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Masukkan Pilihan : ";cin>>in;
        switch (in){
            case 1: {
                Node node;
                cout<<endl;
                cout << "Data Pemain NBA"<< endl;
                cout << "----------------------" << endl;
                cout << "Masukkan Nomor Punggung : ";
                cin>>node.num;
                cout << "Masukkan Nama Pemain    : ";
                cin.ignore(1);
                cin.getline(node.name,100);
                cout << "Masukkan Posisi Pemain  : ";
                cin.getline(node.position,20);
                queue.enQueue(node.num, node.name, node.position);
                break;
            }
            case 2:
                queue.deQueue();
                break;
            case 3:
                queue.displayQueue();
                break;
            case 4:
                exit(0);
            default:
                cout<<"Out of Range";
        }
    }
}