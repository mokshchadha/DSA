#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node{
  int key;
  Node *left;
  Node *right;
};

Node* createNode(int key){
  Node * node = new Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node * searchNode(Node * root , int key){
   if(root == NULL ) return NULL;

   queue<Node *> q;
   Node * result;
   q.push(root);

   while(!q.empty()){
     Node * temp = q.front();
     q.pop();

     if(temp->key == key) result = temp;
     if(temp->left!=NULL) q.push(temp->left);
     if(temp->right!=NULL) q.push(temp->right);
   }

   return result;

}

void insert(Node ** root, int key){

  if(*root == NULL) {
    (*root)->key = key;
  }
  Node * node = createNode(key);
  queue<Node*> q;
  q.push(*root);

  while(!q.empty()){
    Node * temp = q.front();
    q.pop();

    if(temp->left==NULL) {
      temp->left = node;
       return;
     }
    else if(temp->right==NULL) {
      temp->right = node;
      return;
    }
  }
}

void deleteNode(Node * root, int key){
  //find the node
  Node * nodeToDelete = searchNode(root, key);
  //find the extreme node for replacement
  queue<Node * > q;
  Node * extremeNode;
  q.push(root);

  while(!q.empty()){
    extremeNode = q.front();
    q.pop();
    if(extremeNode->left!=NULL) q.push(extremeNode->left);
    if(extremeNode->right!=NULL) q.push(extremeNode->right);
  }
  //in order to delete the node we have remove the branch
  //from the parent to the node  we want to delete

  int keyAtExtremeNode = extremeNode->key;
  cout<<"replacing with "<<keyAtExtremeNode;
  nodeToDelete->key = keyAtExtremeNode;
  //loook for parent of extreme  node;
  //and delete the deepest node
  q.push(root);
  Node * parent;
  while (!q.empty()) {
    parent = q.front();
    q.pop();
    if(parent->left!=NULL && parent->left == extremeNode)
    {
        parent->left = NULL;
        return;
    }
    else q.push(parent->left);
    if(parent->right!=NULL && parent->right == extremeNode)
      {
        parent->right = NULL;
        return;
      }
    else q.push(parent->right);
  }
return;
}

void DFSinOrder(Node * root){
  if(root == NULL) return;
  DFSinOrder(root->left);
  cout<<" "<<root->key;
  DFSinOrder(root->right);
}

void DFSpreOrder(Node * root){
  if(root == NULL) return;
  cout<<" "<<root->key;
  DFSpreOrder(root->left);
  DFSpreOrder(root->right);
}

void DFSpostOrder(Node * root){
  if(root == NULL) return;
  DFSpostOrder(root->left);
  DFSpostOrder(root->right);
  cout<<" "<<root->key;
}

string BFSRecusion(Node * root, int level){
  if(root==NULL) return "-";
  if(level==1) return to_string(root->key);
  if(level>1)
  return BFSRecusion(root->left, level-1) + BFSRecusion(root->right, level-1);
  return "";
}

void BFS(Node * root){
  queue <Node * > q;
  q.push(root);
  while(!q.empty()){
    Node * temp = q.front();
    q.pop();
    if(temp->left!=NULL) q.push(temp->left);
    if(temp->right !=NULL) q.push(temp->right);
    cout<<temp->key<<" ";
  }
}

int main()
{
  Node  * root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->right->right = createNode(5);
/*
      1
    /  \
  2     3
 /       \
4         5
*/
cout<<"In order Traversal\n";
DFSinOrder(root);
cout<<"\nPre order Traversal\n";
DFSpreOrder(root);
cout<<"\nPost order Traversal\n";
DFSpostOrder(root);
cout<<"\nBFS Traversal\n";
BFS(root);
cout<<"\nBFS Traversal w Recusion\n";
cout<<BFSRecusion(root,1)<<endl;
cout<<BFSRecusion(root,2)<<endl;
cout<<BFSRecusion(root,3)<<endl;
return 0;
};
