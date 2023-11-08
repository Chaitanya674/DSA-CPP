#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};

Node* BuildTree(Node* root){
    cout<< "Enter the data : "<< endl;
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }
    cout<< "Enter the left of " << data << endl;
    root-> left = BuildTree(root->right);
    cout<< "Enter the right of " << data << endl;
    root-> right = BuildTree(root->right);
    return root;

}

void BFS(Node* root){
    queue<Node*> q;
    q.push(root);
    //adding seperator for showing the levels
    q.push(NULL); 
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<< endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<< temp -> data <<" ";
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
    Node* root = NULL;
    cout<< "Enter data to create BST" <<endl;
    root = BuildTree(root);
    BFS(root);
    return 0;
}