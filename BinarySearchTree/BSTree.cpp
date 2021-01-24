#include "BSTree.h"

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/* Sameer Hussain - CSCE 221 - PA 3*/

///////////////////////////////////
// Already Implemented Functions //
///////////////////////////////////

// These functions are already implemented for you. Scroll below to
// see the functions that you have to implement 


// constructors
BSTree::BSTree() : size(0), root(nullptr) {}

// input / output operators
ostream& operator<<(ostream& out, BSTree& tree)
{
    tree.print_level_by_level(out);
    return out;
}

ostream& operator<<(ostream& out, Node& node)
{
    return out << node.value << "[" << node.search_time << "]";
}

istream& operator>>(istream& in, BSTree& tree)
{
    /*
      take input from the in stream, and build your tree
      input will look like
      4 
      2 
      6 
      1 
      3 
      5 
      7
    */
    int next;
    while(in >> next) {
        tree.insert(next);
    }
    return in;
}

// Example recursive function
void BSTree::copy_helper(Node*& newNode, const Node* sourceNode) {
    //Don't copy if the node is nullptr
    if(sourceNode == nullptr)
        return;

    //Change the new node to a copy of sourceNode
    newNode = new Node(sourceNode->value);
    //Copy over the search cost
    newNode->search_time = sourceNode->search_time;

    //Copy left subtree
    if (sourceNode->left != nullptr)
        copy_helper(newNode->left, sourceNode->left);
    //Copy right subtree
    if(sourceNode->right != nullptr)
        copy_helper(newNode->right, sourceNode->right);
}

// recursive function
int BSTree::get_total_search_time(Node* node)
{
  if (node != nullptr) {
    return node->search_time + get_total_search_time(node->left) + get_total_search_time(node->right);
  }
  return 0;
}

// implemented
float BSTree::get_average_search_time()
{
  int total_search_time = get_total_search_time(root);
  if(total_search_time == 0)
    return -1;
	
  return ((float)total_search_time)/size;
}


///////////////////////////////////
//     Functions to Implement    //
///////////////////////////////////

// These are the functions you should implement
// Feel free to call the functions above or create new helper functions

// copy constructor
BSTree::BSTree(const BSTree& other)
{
  if(other.root != nullptr) {
    copy_helper(root, other.root);
    size = other.size;
    return;
  }
  else {
    root = nullptr;
  }
}

// move constructor
BSTree::BSTree(BSTree&& other)
{
  size = other.size;
  root = other.root;

  other.root = nullptr;
  other.size = 0;

}

//copy assignment
BSTree& BSTree::operator=(const BSTree& other)
{
  /*root = new Node(other.root->value);

  copy_helper(root, other.get_root());
  size = other.size;
  update_search_times();
  // cout << "copy" << endl;
  return *this;
  */

  if (this != &other && other.root) {
    copy_helper(root, other.root);
    size = other.size;

    return *this;
  }
  else if (this!=&other && !other.root) {
    size = 0;
    root = nullptr;
  }

  return *this;
  
}

void BSTree::destroy(Node *nde) {
  if(nde) {
    destroy(nde->left);
    destroy(nde->right);
    delete nde;
  }
}

// move assignment
BSTree& BSTree::operator=(BSTree&& other)
{
  /*
  if(this!=&other) {

    if(other.root != nullptr){
      root = new Node(other.root->value);
      root->search_time = 1;
    }
    copy_helper(-this)
  }
  */

  if (this!=&other) {
    swap(root, other.root);

    size = other.size;
    destroy(other.root);
    other.root = nullptr;
    other.size = 0;
  }
  return *this;
}

void BSTree::delTree(Node *&t){
  
  if (t == nullptr){ // traversal
    return;
  }
  if (t->left != nullptr) {
    delTree(t->left);
  }
  if (t->right != nullptr) {
    delTree(t->right);
  }
  delete t;
}

void BSTree::del_fn(Node* nde)
{
  if (nde) {
    del_fn(nde->left);
    del_fn(nde->right);
    delete nde;
  }
}


// destructor
BSTree::~BSTree()
{
  // using helper function defined
  destroy(root);
}

Node *BSTree::insert_fn(int obj, Node *&t) {

  if (t == nullptr) {
    t = new Node(obj);
    size++;
    update_search_times();
  }
  else if (obj < t->value){
    t->left = insert_fn(obj, t->left);
  }
  else if (obj > t->value) {
    t->right = insert_fn(obj, t->right);
  }
  else {
    cout << "error" << endl;
  }
  return t;
}


Node* BSTree::insert(int obj)
{
  Node * node = new Node(obj);
  Node * curr = root;
  Node * last = nullptr;

  int searchTime = 1;
  while (curr != nullptr) {
    last = curr;
    
    if (obj < curr->value) {
      
      curr = curr->left;
      searchTime++;
    }
    else {

      curr = curr->right;
      searchTime++;
    }

  }

  if (last == nullptr) {

    node->search_time = searchTime;

    size++;

    root = node;
  }
  else if (obj < last->value) {

    last->left = node;

    size++;

    node->search_time = searchTime;
  }

  else {

    last->right = node;

    size++;

    node->search_time = searchTime;

  }

  return node;

}

Node *BSTree::search_fn(Node *n, int obj){
  if (n == nullptr || n->value == obj){
    return n;
  }
  if (n->value < obj) {
    return search_fn(n->right, obj);
  }
  return search_fn(n->left, obj);
}

Node* BSTree::search(int obj)
{
    //using the helper function

   return search_fn(root, obj);
}

// unused
void BSTree::updateTime(Node *&t, int c) {

  if (t != nullptr) {
 
    t->search_time = c;
    updateTime(t->left, c+1);
    updateTime(t->right, c+1);

  }
}

void BSTree::update_search_times()
{
  if (root == nullptr)
    return;
  
  queue<Node*> q;
  q.push(root);

  int level = 1;

  while (!q.empty()) { // traverse and count
    int nCounter = q.size();
    while (nCounter > 0) {
      Node * i = q.front();

      i->search_time = level;

      q.pop();

      if (i->left)
        q.push(i->left);
      
      if (i->right)
        q.push(i->right);
    
      nCounter--;
    }
    level++;
  }
}

void BSTree::inorder(ostream& out)
{
  // defining a stack for traversal

  Node* nde = root;

  stack<Node*> s;

  while(nde || !s.empty()) {
    while(nde) {
      s.push(nde);
      nde = nde->left;
    }
    nde = s.top();

    s.pop();

    out << nde->value << "[" << nde->search_time << "]" << " "; // formatting the output

    nde = nde->right;
  }
}

void BSTree::print_level_by_level(ostream& out)
{
  queue<Node*> q;
  q.push(root);

  int num = 1;
  bool nPtr = false;

  while(num > 0) {

    Node *n = q.front();
    q.pop();
    num--;

    if(n != nullptr) {

      out << n->value << "[" << n->search_time << "]" << " "; // formatting the output

      q.push(n->left);

      q.push(n->right);

      if(n->right != nullptr || n->left != nullptr)
        nPtr = true;

    }
    else {

      out << "X";
      q.push(nullptr);
      q.push(nullptr);

    }

    if(num == 0) {

      out << endl;

      if(nPtr == true) {

        nPtr = false;

        num = q.size();

      }
    }
  }
}
