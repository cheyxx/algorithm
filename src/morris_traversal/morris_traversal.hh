#ifdef MORRIS_TRAVERSAL_HH_
#define MORRIS_TRAVERSAL_HH_
struct node
{
    node *left;
    node *right;
    int value;
    /* data */
};
void
inorder_morris_traversal(struct node *root);
#endif