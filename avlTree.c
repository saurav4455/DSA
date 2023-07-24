// C program to insert a node in AVL tree
#include<stdio.h>
#include<stdlib.h>

// An AVL tree node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};

// A utility function to get the height of the tree
int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given key and
	NULL left and right pointers. */
struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially added at leaf
	return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	// Return new root
	return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.
struct Node* insert(struct Node* node, int key)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}


struct Node* find_minimum(struct Node * root)
{
    if (root == NULL)
        return NULL;
    else if (root -> left != NULL) // node with minimum value will have no left child
        return find_minimum(root -> left); // left most element will be minimum
    return root;
}

struct Node* delete(struct Node * root, int x)
{
    //searching for the item to be deleted
    if (root == NULL)
        return NULL;
    if (x > root -> key)
        root -> right = delete(root -> right, x);
    else if (x < root -> key)
        root -> left= delete(root -> left, x);
    else
    {
        //No Child node
        if (root -> left == NULL && root -> right == NULL)
        {
            free(root);
            return NULL;
        }

        //One Child node
        else if (root -> left== NULL || root -> right == NULL)
        {
            struct Node *temp;
            if (root -> left== NULL)
                temp = root -> right;
            else
                temp = root -> left;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct Node *temp = find_minimum(root -> right);
            root -> key = temp -> key;
            root -> right = delete(root -> right, temp -> key);
        }
    }
    return root;
}

void postorder(struct Node * root)

{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
        printf("%d ",root->key);
	}
}

void inorder(struct Node * root)
{
    
    int temp;
	if(root!=NULL)
	{
		inorder(root->left);
        printf("%d ",root->key);
        temp=root->key;
		inorder(root->right);

	}
   
}




int main()
{
struct Node *root = NULL;
int n,p,q,temp;
    printf("Enter the number of nodes to be inserted\n");
    scanf("%d",&n);
    printf("Enter the range of the number\n");
    scanf("%d%d",&p,&q);
    q=q-p;
    int arr[n];

for(int i=0; i<n ;i++)
    {
    
        temp=(rand()%q);
        temp=temp+p;
        arr[i]=temp;
        root = insert(root, temp);
    }


printf("Preorder traversal of the constructed AVL tree is \n");
preOrder(root);
printf("\n");
printf("Postorder traversal of the constructed AVL tree is \n");
postorder(root);
printf("\n");
printf("Inorder traversal of the constructed AVL tree is \n");
inorder(root);
printf("\n");


int choice=1,x;
while(choice=1)
{
    printf("DO you want to delete any node\n1. TO delete\n2.To not Delete\n");
    scanf("%d",&choice);
    int flag=0;
    if(choice==1)
    {
        printf("Enter the data to be deleted\n");
        scanf("%d",&x);
        for(int i=0;i<n;i++)
        {
            if(arr[i]==x){flag=1;}
        }
        if(flag==1)
            {delete(root,x);}
        else
        {
            printf("%d not found in the tree\n",x);
        }   
        
        


        printf("Preorder traversal of the constructed AVL tree is \n");
        preOrder(root);
        printf("\n");
        printf("Postorder traversal of the constructed AVL tree is \n");
        postorder(root);
        printf("\n");
        printf("Inorder traversal of the constructed AVL tree is \n");
        inorder(root);
        printf("\n");
    }
    else{break;}
}




return 0;
}
