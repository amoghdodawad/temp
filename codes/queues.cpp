#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
        
        Node(){
            this->data = -1;
            this->next = NULL;
        }
};

class Queue {
    Node *front, *rear;
    public:
        Queue(){
            this->front = this->rear = NULL;
        }

        void push(int x){
            Node *temp = new Node(x);
            if(this->rear == NULL) this->front = this->rear = temp;
            else {
                this->rear->next = temp;
                this->rear = this->rear->next;
            }
            return;
        }

        int front(){
            if(this->front) return this->front->data;
            return -1;
        }

        void pop(){
            Node *temp = this->front;
            if(!temp) return;
            this->front = this->front->next;
            if(this->front == NULL) this->rear = NULL; 
            delete temp;
            return;
        }
};