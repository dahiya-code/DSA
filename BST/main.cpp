/* Iterative tree traversals */
 
//Preorder 
void Preorder(Node* root){
    if(!root)return;
    stack<Node*>s;
    s.push(root);
    while(!s.empty()){
        Node* tem=s.top();
        cout<<tem->data;
        s.pop();
        if(tem->right)s.push(tem->right);//processed after left child
        if(tem->left)s.push(tem->left);
    }
}

//Inorder
void Inorder(Node* root){
    if(!root)return;
    stack<Node*>s;
    Node* cur=root;
    while(!s.empty() || curr){
        while(curr){
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->data;
        curr=curr->right;
    }
}

//Postorder
void Postorder(Node* root){
    if(!root)return;
    stack<Node*>s;
    do{
        while(root){
            if(root->right)s.push(root->right);
            s.push(root);
            root=root->left;
        }
        root=s.pop();
        if(root->right && s.top()==root->right){/*if curr node has right child
                                                which hasn't been processed yet*/
            s.pop();
            s.push(root);
            root=root->right;
        }
        else{
            cout<<root->data;
            root=NULL;
        }
    }while(!s.empty());
}
