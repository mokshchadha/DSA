#include<iostream>
using namespace std;

struct node {
  int key;
  struct node * left=NULL, * right=NULL;
};

node * newNode(int key){
  node * temp = new node;
  temp->key = key;
  return temp;
}

node * insert(node* root, int key){
  if(root==NULL) return newNode(key);
  if(key< root->key) root->left = insert(root->left, key);
  else if(key> root->key) root->right = insert(root->right, key);

  return root;
}

node * minValueOf(node * root){
  node * temp = root;
  while(temp->left != NULL){
    temp = temp->left;
  }
  return temp;
}

node * deleteNode(node * root, int key){
  if(root == NULL) return root;
  if(root->key > key) root->left = deleteNode(root->left, key);
  else if(root->key < key) root->right = deleteNode(root->right, key);

  else{
    if(root->left == NULL) {
      node * temp = root->right;
      free(root);
      return temp;
    }
    else if(root->right == NULL){
      node * temp = root->left;
      free(root);
      return temp;
    }

  else {  node * temp = minValueOf(root->right);
    //copy the inorder succesor content
    root->key = temp->key;
    //delete the inorder sucessor
    root->right = deleteNode(root->right, temp->key);
    }

    return root;
  }
}

int main(){
  node * root = newNode(3);

  return 0;
}
