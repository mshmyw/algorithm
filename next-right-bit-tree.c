 /**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left, *right, *next;
};

void connect(struct TreeLinkNode *root) {
    struct TreeLinkNode *temp, *next;

    if(root == NULL)
        return;

    next = NULL;
    temp = root->next;
    while(temp && (next == NULL)){

        if(temp->left != NULL)
            next = temp->left;
        else if(temp->right != NULL)
            next = temp->right;

        temp = temp->next;
    }

    if(root->left != NULL)
        if(root->right != NULL)
           root->left->next = root->right;
        else
           root->left->next = next;

    if(root->right != NULL)
        root->right->next = next;

    connect(root->left);
    connect(root->right);

    return;
}
