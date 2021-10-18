#include <iostream>
using namespace std;

class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class Queue{
    private:
        int front;
        int rear;
        int size;
        Node **Q;
    public:
        Queue(){
            front=rear=-1;
            size=10;
            Q=new Node*[size];
        }
        Queue(int size){
            front=rear=-1;
            this->size=size;
            Q=new Node*[this->size];
        }
        void enqueue(Node *x);
        Node* dequeue();
        void Display();
        bool isEmpty();
        bool isFull();
};

bool Queue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool Queue::isFull() {
    if (rear == size-1){
        return true;
    }
    return false;
}

void Queue::enqueue(Node *x){
    if(rear==size-1)
        cout<<"Queue full\n";
    else
        rear++;
        Q[rear]=x;
}

Node* Queue::dequeue(){
    Node* x=NULL;
    if(front==rear){
        cout<<"queue is empty";
    }
    else
        front++;
        x=Q[front+1];
    return x;
}

void Queue::Display(){
    for(int i=front+1;i<=rear;i++){
        cout<<Q[i]<<" ";
    }
}

// ====TREE===
class Tree{
    private:
        Node* root;
    public:
        Tree() { root = nullptr; }
        void CreateTree();
        void Preorder(){ Preorder(root); }  
        void Preorder(Node* p);
        void Postorder(){ Postorder(root); }  
        void Postorder(Node* p);
        void Inorder(){ Inorder(root); }
        void Inorder(Node* p);
        void Levelorder(){ Levelorder(root); }  
        void Levelorder(Node* p);
        int Height(){ return Height(root); }  
        int Height(Node* p);
        Node* getRoot(){ return root; }     
};

 
void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
 
    Queue q(100);
    root = new Node;
    cout << "Enter root value: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    q.enqueue(root);
 
    while (! q.isEmpty()){
        p = q.dequeue();
 
        cout << "Enter left child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
 
        cout << "Enter right child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = NULL;
            t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p) {
    if (p){
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
 
void Tree::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}
 
void Tree::Postorder(Node *p) {
    if (p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}
 
void Tree::Levelorder(Node *p) {
    Queue q(100);
    cout << root->data << ", " << flush;
    q.enqueue(root);
 
    while (! q.isEmpty()){
        p = q.dequeue();
        if (p->lchild){
            cout << p->lchild->data << ", " << flush;
            q.enqueue(p->lchild);
        }
        if (p->rchild){
            cout << p->rchild->data << ", " << flush;
            q.enqueue(p->rchild);
        }
    }
}
 
int Tree::Height(Node *p) {
    int l = 0;
    int r = 0;
    if (p == NULL){
        return 0;
    }
 
    l = Height(p->lchild);
    r = Height(p->rchild);
    if (l > r){
        return l + 1;
    } else {
        return r + 1;
    }
}

int main(){

    Tree t;
 
    t.CreateTree();
 
    cout << "Preorder: " << flush;
    t.Preorder(t.getRoot());
    cout << endl;
 
    cout << "Inorder: " << flush;
    t.Inorder(t.getRoot());
    cout << endl;
 
    cout << "Postorder: " << flush;
    t.Postorder(t.getRoot());
    cout << endl;
 
    cout << "Levelorder: " << flush;
    t.Levelorder(t.getRoot());
    cout << endl;
 
    cout << "Height: " << t.Height(t.getRoot()) << endl;
 
    cout << "Recursive Passing Private Parameter in Constructor" << endl;
 
    cout << "Preorder: " << flush;
    t.Preorder();
    cout << endl;
 
    cout << "Inorder: " << flush;
    t.Inorder();
    cout << endl;
 
    cout << "Postorder: " << flush;
    t.Postorder();
    cout << endl;
 
    cout << "Levelorder: " << flush;
    t.Levelorder();
    cout << endl;
 
    cout << "Height: " << t.Height() << endl;

}
