#include <stdio.h>
#include <stdlib.h>

typedef struct _AVLTree{
	int data;
	int level;
	struct _AVLTree *left;
	struct _AVLTree *right;
}AVLTree;

#define false 0
#define true 1

//Insert node
int InsertAVLNode(AVLTree *node, int data)
{
	//check node == NULL
	if(node == NULL)
	{
		node = (AVLTree *)malloc(sizeof(AVLTree));
		node->data = data;
		return true;
	}
	else
	{
		
		if(data <= node->data)
		{
			InsertAVLNode(node->left, data);
		}
		else if(data > node->data)
		{
			InsertAVLNode(node->right, data);
		}
	}

	return false;
}

AVLNode *Ch_Node(AVLTree *node)
{
	AVLTree *tmp = NULL;

	if(!node->left)
	{
		tmp = node;
		node = node->right;
		node->left = tmp;
	}
	else if(!node->right)
	{
		tmp = node;
		node = node->left;
		node->right = tmp;
	}

	return node;
}


AVLNode *Find_ThreeContiNode(AVLTree *node)
{
	static AVLTree *pNodeAddr[3]={NULL};
	static AVLTree *pNode=NULL;
	

	if(node == NULL)
	{
		return NULL;
	}
	else
	{
		if((node->left != NULL)&&(node->right == NULL))
		{
			tmp = node->left;
		
			if(tmp->right)
			{
				node->level = 0;
			}
			else
			{
				pNodeAddr[node->level] = node;
				node->level++;
			}

			Find_ThreeContiNode(node->left);
		}
		else if((node->left == NULL) && (node->right != NULL))
		{
			tmp = node->right;
			
			if(tmp->left)
			{
				node->level = 0;
			}
			else
			{
				pNodeAddr[node->level] = node;
				node->level++;
			}

			Find_ThreeContiNode(node->right);
		}
		else
		{
			Find_ThreeContiNode(node->left);
			Find_ThreeContiNode(node->right);
		}

		if(node->level == 3)
		{
			pNode = (AVLTree *)malloc(sizeof(AVLTree));
			memcpy(pNode, pNodeAddr[0]);
		
			free(pNodeAddr[0]);
		}
	}

	return pNode;

}


int main(void)
{

}
}	
