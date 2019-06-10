/* Copyright (c) 2019 The Design Pattern Authors. All rights reserved.
*/

#ifndef ALGORITHMS_MORRIS_TRAVERSAL_H_
#define ALGORITHMS_MORRIS_TRAVERSAL_H_
struct node {
  node *left;
  node *right;
  int value;
  /* data */
};
void inorder_morris_traversal(struct node *root);
#endif  // ALGORITHMS_MORRIS_TRAVERSAL_H_

