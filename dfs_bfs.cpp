#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    node* left;
    node* right;
    node(int k){
        key=k;
        left=right=NULL;
    }
};

void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

void preorder(node* root){
    if(root!=NULL){
        cout<<root->key<<" ";
        inorder(root->left);
        inorder(root->right);
    }
}


int height(node* root){
    if(root==NULL){
        return 0;
    }
    return (max(height(root->left), height(root->right))+1);
}

void printK(node* root, int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->key<<" ";
    }
    else{
        printK(root->left, k-1);
        printK(root->right, k-1);
    }
}

void bfs(node* root, int h){
    for(int i=0; i<h; i++){
        printK(root, i);
    }
}

int main(){
    node* root = new node(10);
    root->left = new node(20);
    root->right =new node(30);
    root->left->left=new node(40);
    root->right->left=new node(50);
    root->right->right=new node(60);
    root->right->right->left=new node(70);
    inorder(root);
    cout<<"\n";
    preorder(root);
    cout<<"\n";
    int h=height(root);
    bfs(root, h);
    return 0;
}