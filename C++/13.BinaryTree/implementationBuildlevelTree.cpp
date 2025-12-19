#include<iostream>
#include<queue>
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

Node* buildLevelTree(){
    cout << "Enter data for root: " ;
    int n;
    cin >> n;
    cout << endl;
    if(n == -1) return NULL;

    queue<Node*> q;
    Node* root = new Node(n);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << "enter left node for " << temp -> data << ": ";
        int leftnode;
        cin >> leftnode;
        if(leftnode != -1){
            temp -> left = new Node(leftnode);
            q.push(temp -> left);
        }

        cout << "enter right node for " << temp -> data << ": ";
        int rightnode;
        cin >> rightnode;
        if(rightnode != -1){
            temp -> right = new Node(rightnode);
            q.push(temp -> right);
        }
    }
    return root;
}

void print(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{

            cout<< temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }
    
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

int main(){
    Node* root = buildLevelTree();
    print(root);

    return 0;
}