#include "morris_traversal.h"
#include <iostream>
using namespace std;

/*非递归， 非栈 二叉树中序遍历 */
void inorder_morris_traversal(struct node *root) {
  struct node *curr = root;
  struct node *prev;
  while (!curr) {
    if (curr->left == nullptr) {
      curr = curr->right;
    } else {
      prev = curr->left;
      while ((prev->right != nullptr) && (prev->right != curr)) {
        prev = prev->right;
      }
      if (prev->right == nullptr) {
        prev->right = curr;
        curr = curr->left;
      } else {
        prev->right = nullptr;
        std::cout << "value " << curr->value << std::endl;
        curr = curr->right;
      }
    }
  }
}