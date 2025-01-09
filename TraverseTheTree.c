#include <stdio.h>
struct Node
{
    int data;
    struct Node* right;
    struct Node* left;
};

struct Stack
{
    struct Node* data;
    struct Stack* next;
};
void push(struct Stack **top, struct Node* node)
{
    struct Stack* newStackNode=(struct Stack*)malloc(sizeof(struct Stack));
    newStackNode->data=node;
    newStackNode->next=*top;
    *top=newStackNode;
}
struct Node* pop(struct Stack **top)
{
    if(*top==NULL)
    {
        return NULL;
    }
    struct Stack *temp=top;
    struct Node* node=temp->data;
    *top=temp->next;

    free(temp);
    return node;
}
int isEmpty(struct Stack*top)
{
    return top==NULL;
}

struct Node* createNode(int data)
{
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void preOrderTraversal(struct Node* root)
{
    if(root=NULL)
    {
        return;
    }
    struct Stack*stack=NULL;
    while(!isEmpty(stack))
    {
        struct Node* temp=pop(&stack);
        printf("%d",temp->data);
        if(temp->right!=NULL)
        {
            push(&stack, temp->right);
        }

        if(temp->left!=NULL)
        {
            push(&stack, temp->left);
        }
    }
}
int main()
{
    struct Node* root=createNode(10);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->right->left=createNode(6);
    root->right->right=createNode(7);

    printf("Preorder yığın ile: ");
    preOrderTraversal(root);

}


