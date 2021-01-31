#include <bits/stdc++.h>
using namespace std;
 
#define modulo 10000007
#define int long long 
#define N 1000000001
#define endl "\n"

struct Node{
    int data;
    Node *right;
    Node *left;
    Node(int val){
        data=val;
        right=left=NULL;
    }
};

Node* inorderSuccessor(Node* node){
    Node* curr=node;
    while(curr && curr->left)curr=curr->left;
    return curr;
}

Node* insertion(Node* root, int val){
    if(root==NULL){
        Node *tem=new Node(val);
        return tem;
    }
    if(val<root->data)root->left=insertion(root->left,val);
    else if(val>root->data)root->right=insertion(root->right,val);
    return root;
}

Node* search(Node* root, int key){
    if(root==NULL||root->data==key)return root;
    if(key<root->data)return search(root->left,key);
    return search(root->right,key);
}

Node* del(Node* root, int key){
    if(root==NULL)return root;
    else if(key<root->data) root->left=del(root->left,key);
    else if(key>root->data) root->right=del(root->right,key);
    else{
        if(!root->left){Node *tem=root->right;free(root);return tem;}
        else if(!root->right){Node *tem=root->left;free(root);return tem;}
        Node* tem=inorderSuccessor(root->right);//smallest in right Subtree
        root->data=tem->data;
        del(root->right,tem->data);
    }
    return root;
}

void inorder(Node *root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--){
        Node *root=NULL;
        root=insertion(root, 2);
        root=insertion(root, 3);
        root=insertion(root, 5);
        root=insertion(root, 1);
        root=insertion(root, 4);
        root=del(root,3);
        inorder(root);
    }
}
