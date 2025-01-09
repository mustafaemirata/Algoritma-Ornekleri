#include <stdio.h>
#include <limits.h>
struct Node
{
    int data;
    struct Node* right;
    struct Node* left;
};

struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
int findMax(struct Node* root)
{
    if(root==NULL)
    {
        return INT_MIN;

    }
    int rootVal=root->data;
    int leftValue=findMax(root->left);
    int rightValue=findMax(root->right);

    int max=rootVal;
    if(leftValue>max)
    {
        max=leftValue;
    }

    if(rightValue>max)
    {
        max=rightValue;
    }
    return max;
}

int main()
{
    struct Node* root=createNode(10);
    root->left=createNode(20);
    root->right=createNode(30);
    root->left->left=createNode(40);
    root->left->right=createNode(50);
    root->right->left=createNode(60);
    root->right->right=createNode(70);

    printf("Max değer: %d\n",findMax(root));
}