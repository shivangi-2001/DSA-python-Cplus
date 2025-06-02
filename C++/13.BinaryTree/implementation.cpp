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

void reverseOrder(Node* root){
    vector<Node*> ans;
    ans.push_back(root);
    ans.push_back(NULL);
    int i=0;
    while(i<ans.size()){
        if(ans[i] == NULL){
            if (i + 1 < ans.size() && ans.back() != NULL) {
                ans.push_back(NULL);
            }
        }
        else{
            if(ans[i] -> left) ans.push_back(ans[i]->left);
            if(ans[i] -> right) ans.push_back(ans[i]->right);
        }
        i++;
    }

    for(int i=ans.size()-1; i>=0; i--){
        if(ans[i] == NULL){
            cout << endl;
        }else{
            cout << ans[i] -> data << " ";
        }
    }
}

void reverse2(Node* root){
    queue<Node*> q;
    stack<Node*> s;

    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        s.push(temp);
        if(temp -> left) q.push(temp -> left);
        if(temp -> right) q.push(temp -> right);
    }

    while(!s.empty()){
        cout << s.top() -> data << " ";
        s.pop();
    }
}


int main(){
    Node* root = buildTree();
    cout << "level order traversal" << endl;
    levelOrderTraversal(root);
    reverseOrder(root);
    cout << "Reverse II: "<<endl;
    reverse2(root);
    return 0;
}