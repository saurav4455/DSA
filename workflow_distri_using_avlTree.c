#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};


int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}


struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	
	x->right = y;
	y->left = T2;


	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	return x;
}

struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;


	y->left = x;
	x->right = T2;


	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	
	return y;
}

int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int key)
{

	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else 
		return node;

	
	node->height = 1 + max(height(node->left),
						height(node->right));

	
	int balance = getBalance(node);


	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}


	return node;
}

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
    else if (root -> left != NULL) 
        return find_minimum(root -> left);
    return root;
}

struct Node* delete(struct Node * root, int x)
{
    if (root == NULL)
        return NULL;
    if (x > root -> key)
        root -> right = delete(root -> right, x);
    else if (x < root -> key)
        root -> left= delete(root -> left, x);
    else
    {
     
        if (root -> left == NULL && root -> right == NULL)
        {
            free(root);
            return NULL;
        }

        
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

void projSearch(struct Node* root, int key)
{
    if (root == NULL)
        printf("project #%d not found\n",key);

    else if (root->key == key)
        printf("project #%d found\n",key); 

    else if (root->key > key) {
         projSearch(root->left, key);
    }

    else {
         projSearch(root->right, key);
    }
}

void projDel(struct Node* root, int key)
{
    if (root == NULL)
        printf("project #%d not found\n",key);

    else if (root->key == key)
    {
        printf("project #%d deleted\n",key);
        delete(root,key);

    }     

    else if (root->key > key) {
         projDel(root->left, key);
    }

    else {
         projDel(root->right, key);
    }
}

void printAVL(struct Node* root, int space) {
    if (root == NULL)
        return;

    space += 10;

    printAVL(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d < \n", root->key);

    printAVL(root->left, space);
}

void projUnder(struct Node* root, int key)
{
    
    if (root == NULL)
        printf("project #%d not found\n",key);

    else if (root->key == key)
        {
            printf("project #%d found\n",key); 
            printf("And all the projects under proj #%d are:\n",key);
            postorder(root);
			printf("\n\n");
			printAVL(root, 0);
        }
      

    else if (root->key > key) {
         projUnder(root->left, key);
    }

    else {
         projUnder(root->right, key);
    }
    
}



int main()
{
struct Node *root = NULL;
int n,p,q,temp;
    printf("Enter the number of projects\n");
    scanf("%d",&n);
    p=100; q=900;
    q=q-p;

for(int i=0; i<n ;i++)
    {
    
        temp=(rand()%q);
        temp=temp+p;
        root = insert(root, temp);
    }


    printf("List of all project ID's are: \n");
    postorder(root);


int choice=1,x;
while(choice=1)
{


    printf("\n\n0.List of all the projects\n1.TO add any project\n2.To Delete any project\n3.Search project\n4.All under going project\n5.Print AVL TREE\n");
    scanf("%d",&choice);
    int flag=0;

    if(choice==0)
    {
        printf("List of all project ID's are: \n");
        postorder(root);
    }

    else if(choice==1)
    {
        printf("Enter the project id need to be added\n#");
        scanf("%d",&x);
        root = insert(root, x);
        printf("\nproject #%d is added\n");
    }

    else if(choice==2)
    {
        printf("Enter the project id need to be deleted\n#");
        scanf("%d",&x);
        projDel(root,x); 
    }

    else if(choice==3)
    {
        printf("Enter the project id need to be searched\n#");
        scanf("%d",&x); 
        projSearch(root,x);
    }

    else if(choice==4)
    {
        printf("Enter the project id to get all undergoing projects\n#");
        scanf("%d",&x); 
        projUnder(root,x);
    }

	else if(choice==5)
	{
		printAVL(root, 0);
	}
    else{
        printf("Wrong input\n");
    }
}




return 0;
}
