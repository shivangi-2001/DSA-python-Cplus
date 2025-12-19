#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(){
    cout << "enter data: ";
    int n;
    cin >> n;

    if(n == -1){
        return NULL;
    }

    Node* root = new Node(n);
    cout << "Enter the data to left of " << n << ": ";
    root -> left = buildTree();

    cout << "Enter the data to right of " << n << ": ";
    root -> right = buildTree();

    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node *> q;
    q.push(root);  
    q.push(NULL); 

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left) {
                q.push(temp -> left);
            };
            if(temp -> right) {
                q.push(temp -> right);
            };
        }
    }
    return;
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }

    int val = root -> data;
    cout << val << " ";
    preorder(root -> left);
    preorder(root -> right);
}


int main(){
    Node* root = buildTree();
    cout << "level order traversal" << endl;
    levelOrderTraversal(root);
    cout << endl;
    cout << "preorder traversal: ";

    preorder(root);
    

    return 0;
}