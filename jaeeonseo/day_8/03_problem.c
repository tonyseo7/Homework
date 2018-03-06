#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1


typedef struct __BiLink{

	int data;
	struct __BiLink *pLeft;
	struct __BiLink *pRight;

}BiLink;

BiLink *gRootNode;

void SetRootNode(BiLink *node)
{

	gRootNode = node;
}

BiLink *GetRootNode()
{
	return gRootNode;
}
	

void InsertRootData(BiLink **node, int rootData)
{

	if(*node == NULL)
	{
		(*node) = (BiLink *)malloc(sizeof(BiLink));

		(*node)->data = rootData;


		SetRootNode(*node);

		return;
	}


	(*node)->data = rootData;
	//printf("%d", node->data);
	SetRootNode(*node);


}



void InsertDataToBinaryTree(BiLink **node, int data)
{
	BiLink *tmp = NULL;
	static int compData;

	//error code
	if(*node == NULL)
	{

		tmp = (BiLink *)malloc(sizeof(BiLink));
		tmp->data = data;
		tmp->pLeft = NULL;
		tmp->pRight = NULL;
		(*node) = tmp;

	}
	else
	{
		compData = (*node)->data;

		if(data <= (*node)->data)
		{
				
			InsertDataToBinaryTree(&((*node)->pLeft), data);
		}
		else
		{
			

			InsertDataToBinaryTree(&((*node)->pRight), data);
		}

	}


}

BiLink *SearchNode(BiLink **node, int data)
{

	if(*node != NULL)
	{
		if(data == (*node)->data)
		{

			return (*node);
		}
		else
		{

			if(data < (*node)->data)
			{

				SearchNode(&(*node)->pLeft, data);
			}
			else
			{

				SearchNode(&(*node)->pRight, data);
			}
		}

	}
}


		
int DeleteNodeValue(int data)
{
	BiLink *rootNode=NULL;
	BiLink *delNode=NULL;
	BiLink *tmp=NULL;

	rootNode = GetRootNode();

	delNode = SearchNode(&rootNode, data);

	if(delNode != NULL)
	{
		
		//tmp = delNode;
		//make delNode statement;
		//free(tmp);

		return 1;
	}


	return 0;
}

void print_tree(BiLink *root)
{
	if(root != NULL)
	{
		printf("data:%d ", root->data);

		if(root->pLeft != NULL)
		{
			print_tree(root->pLeft);
		}
		
		if(root->pRight != NULL)
		{
			print_tree(root->pRight);
		}
	}
}
		

int main(void)
{
	int data, i;
	int arrayData[13] = {50, 45, 73, 32, 48, 46, 16, 37, 120, 47, 130, 127, 124};
	BiLink *root = NULL;
	BiLink *tmp = NULL;
	int retVal = 0;

	InsertRootData(&root, 10);

	for(i=0; i < 13; i++)
	{
		InsertDataToBinaryTree(&root, arrayData[i]);
	}

	tmp = SearchNode(&root, 73);
	
	retVal = DeleteNodeValue(73);	

	print_tree(root);
//	printf("%d\n", retVal);

	return 0;

}	 
