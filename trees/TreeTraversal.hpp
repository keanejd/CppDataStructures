#pragma namespace  
#include <stack>
#include <queue>
#include <vector>
#include "BinaryTree.hpp"
#include "BinaryNode.hpp"

using std::stack;
using std::queue;
using std::vector;

template<typename T>
class TreeTraversal {
  using Node = BinaryNode<T>;
  BinaryTree<T> * tree;

  public:
    explicit TreeTraversal(BinaryTree<T> * _tree) : tree(_tree) {}

    vector<T> inOrder() const {
      vector<T> result;
      stack<Node *> s;
      Node * curr = tree->getRoot();
      while(curr != nullptr || !s.empty()) {
        while(curr != nullptr) { 
          s.push(curr);
          curr = curr->getLeft();
        }
        curr = s.top();
        s.pop();
        result.push_back(curr->getData());
        curr = curr->getRight();
      }
      return result;
    }

    vector<T> preOrder() const {
      vector<T> result;
      if(tree->isEmpty()) return result;
      stack<Node *> s;
      s.push(tree->getRoot());
      while(!s.empty()) {
        Node * node = s.top();
        s.pop();
        result.push_back(node->getData());
        if(node->getRight()) s.push(node->getRight());
        if(node->getLeft()) s.push(node->getLeft());
      }
      return result;
    }

    vector<T> postOrder() const {
      vector<T> result;
      if(tree->isEmpty()) return result;
      stack<Node*> s1, s2;
      s1.push(tree->getRoot());
      while(!s1.empty()) {
        Node * node = s1.top();
        s1.pop();
        s2.push(node);
        if(node->getLeft())
          s1.push(node->getLeft());
        if(node->getRight())
          s1.push(node->getRight());
      }

      while(!s2.empty()) {
        result.push_back(s2.top()->getData());
        s2.pop();
      }
      
      return result;
    }

    vector<T> levelOrder() const {
      vector<T> result;
      if(tree->isEmpty()) return result;
      queue<Node *> q;
      q.push(tree->getRoot());
      while(!q.empty()) {
        Node * node = q.front();
        q.pop();
        result.push_back(node->getData());
        if(node->getLeft())
          q.push(node->getLeft());
        if(node->getRight())
          q.push(node->getRight());
      }
      return result;
    }

};
