#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
}*node;

node create();
void insert(node ,node );
void preorder(node );
void postorder(node );
void inorder(node );
void preorder_char(node );
void postorder_char(node );
void inorder_char(node );


int main()
{
	char ch;
	int item,f=0;
	node root=NULL,temp;

    int n,choose;

	printf("Enter the number of elements to be added in the tree\n");
    scanf("%d",&n);

	printf("Enter the choice\n1:Character Tree\n2:Number Tree\n");
	scanf("%d",&choose);
	int data,p=1,q=100;
	int A=65,Z=90;

	switch(choose)
	{
		case 1:for( int i=0; i<n; i++)
				{
					srand(time(0));
					Z=Z-A;
					data=(rand()%q);
					data=data+A;
					temp=create(data);
					if(root==NULL)
					root=temp;
					else
					insert(root,temp);
				}
				printf("\nPreorder Traversal: ");
				preorder_char(root);
				printf("\nPostorder Traversal: ");
				postorder_char(root);
				printf("\nInorder Traversal: ");
				inorder_char(root);
				
				break;


		case 2: for( int i=0; i<n; i++)
				{
					srand(time(0));
					q=q-p;
					data=(rand()%q);
					data=data+p;
					temp=create(data);
					if(root==NULL)
					root=temp;
					else
					insert(root,temp);
				}
					printf("\nPreorder Traversal: ");
					preorder(root);
					printf("\nPostorder Traversal: ");
					postorder(root);
					printf("\nInorder Traversal: ");
					inorder(root);
				break;
	}




return 0;
}


node create(int data)
{
	node temp;
	temp=(node)malloc(sizeof( struct BST));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}

void insert(node root,node temp)
{
	if(temp->data<root->data)
	{
		if(root->left!=NULL)
			insert(root->left,temp);
		else
			root->left=temp;
	}

	if(temp->data>root->data)
	{
		if(root->right!=NULL)
			insert(root->right,temp);
		else
			root->right=temp;
	}
}

void preorder(node root)
{

    FILE *preOrderFile;
    if ((preOrderFile = fopen("D:\\COLLEGE\\sem-4\\dsa\\TREES\\files\\preOrderFile.txt","a")) == NULL)
     {
       printf("Error! opening file");
       exit(1);
     }

	if(root!=NULL)
	{
        printf("%d ",root->data);
		fprintf(preOrderFile,"%d\n",root->data);
		preorder(root->left);
		preorder(root->right);
	}
    fclose(preOrderFile);
}

void postorder(node root)

{
    FILE *postOrderFile;
    if ((postOrderFile = fopen("D:\\COLLEGE\\sem-4\\dsa\\TREES\\files\\postOrderFile.txt","a")) == NULL)
     {
       printf("Error! opening file");
       exit(1);
     }
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
        printf("%d ",root->data);
	    fprintf(postOrderFile,"%d\n",root->data);
	}
    fclose(postOrderFile);
}
void inorder(node root)
{
    FILE *inOrderFile;
    if ((inOrderFile = fopen("D:\\COLLEGE\\sem-4\\dsa\\TREES\\files\\inOrderFile.txt","a")) == NULL)
     {
       printf("Error! opening file");
       exit(1);
     }
     int temp;
	if(root!=NULL)
	{
		inorder(root->left);
        printf("%d ",root->data);
        temp=root->data;
		fprintf(inOrderFile,"%d\n",temp);
		inorder(root->right);

	}
    fclose(inOrderFile);
}

///  character insertion

void preorder_char(node root)
{

    FILE *preOrderFile;
    if ((preOrderFile = fopen("D:\\COLLEGE\\sem-4\\dsa\\TREES\\files\\preOrderFile.txt","a")) == NULL)
     {
       printf("Error! opening file");
       exit(1);
     }
	char temp;
	if(root!=NULL)
	{
		temp=(char)root->data;
        printf("%c ",temp);
		fprintf(preOrderFile,"%c\n",temp);
		preorder(root->left);
		preorder(root->right);
	}
    fclose(preOrderFile);
}

void postorder_char(node root)

{
    FILE *postOrderFile;
    if ((postOrderFile = fopen("D:\\COLLEGE\\sem-4\\dsa\\TREES\\files\\postOrderFile.txt","a")) == NULL)
     {
       printf("Error! opening file");
       exit(1);
     }
	 char temp;
	if(root!=NULL)
	{
		temp=(char)root->data;
		postorder(root->left);
		postorder(root->right);
        printf("%c ",temp);
	    fprintf(postOrderFile,"%c\n",temp);
	}
    fclose(postOrderFile);
}
void inorder_char(node root)
{
    FILE *inOrderFile;
    if ((inOrderFile = fopen("D:\\COLLEGE\\sem-4\\dsa\\TREES\\files\\inOrderFile.txt","a")) == NULL)
     {
       printf("Error! opening file");
       exit(1);
     }
    char temp;
	if(root!=NULL)
	{
		temp=(char)root->data;
		inorder(root->left);
        printf("%c ",temp);
		fprintf(inOrderFile,"%c\n",temp);
		inorder(root->right);

	}
    fclose(inOrderFile);
}
