#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef enum __rot
{
	RR,
	RL,
	LL,
	LR,
	NONE
}rot;

typedef struct __avl_tree
{
	int lev;
	int data;
	struct __avl_tree *left;
	struct __avl_tree *right;
}avl;

int update_level(avl *root)
{
	int left = root->left ? root->left->lev : 0;
	int right = root->right ? root->right->lev : 0;

	if(left > right)
		return left+1;
	
	return right+1;
}

int rotation_check(avl *root)		//Balance Factor Check
{
	int nBF=0;	//child node의 left->data - right->data;
	
	if(root != NULL)
	{
		nBF = root->left->data - root->right->data;
	}

	return nBF;
}


//BF = Left - Right
//RR -> BF < -1 , data > node->right->data
//LL -> BF > 1, data < node->left->data
//RL -> BF < -1, data > node->right->data
//LR -> BF > 1, data > node->left->data

int kinds_of_rot(avl *root, int data)	
{

	printf("data = %d\n", data);

	if(rotation_check(root) > 1)
	{
		if(root->right->data > data)
			return LR;

		return LL;
	}
	else if(rotation_check(root) < -1)
	{
		if(root->left->data < data);
			return RL;
		
		return RR;
	}

	return NONE;
}


avl* Ch_Rotat_RR(avl *root)
{
	int retVal = false;
	avl *tmp1 = NULL;
	avl *tmp2 = NULL;

	if(root != NULL)
	{
		if(root->left != NULL)
		{

			tmp1 = root;
			root = root->right;
			tmp2 = root->left;
			root->left = tmp1;
			tmp1->right = tmp2;
	
			retVal = true;
		}
	}		

	
	return root;

}

avl* Ch_Rotat_RL(avl *root)
{
	int retVal = false;
	avl *tmp = NULL;

	if(root != NULL)
	{
		if(root->right != NULL)
		{

			retVal = true;
		}
	}

	return root;

}

avl* Ch_Rotat_LL(avl *root)
{
	int retVal = false;
	avl *tmp1 = NULL;
	avl *tmp2 = NULL;
	
	if(root != NULL)
	{
		if(root->left != NULL)
		{
			
		}
	}

	return root;
}

avl *Ch_Rotat_LR(avl *root)
{
	int retVal = false;
	avl *tmp = NULL;

	if(root != NULL)
	{

		if(root->left != NULL)
		{
			
			tmp = root;
			root = root->left;
			root->left = root->right;
			root->right = tmp;
			
			retVal = true;
		}
	}

	return root;

}

avl *rotation(avl *root, rot kind)
{
	int retVal = false;
	avl *tmp = NULL;


	if(root != NULL)
	{
		switch(kind)
		{
			case RR:
			{
				//RR 회전
				tmp = Ch_Rotat_RR(root);
				break;
			}
			case RL:
			{
				//RL 회전
				tmp = Ch_Rotat_RL(root);
				break;
			}
			case LL:
			{
				//LL 회전
				tmp = Ch_Rotat_LL(root);
				break;
			}
			case LR:
			{
				//LR 회전
				tmp = Ch_Rotat_LR(root);
				break;
			}
		}
		
	}


	return tmp;
}

avl *get_avl_node()
{
	avl *node=NULL;	

	node = (avl *)malloc(sizeof(avl));
	
	
	if(node != NULL)
	{
		return node;
	}
}


void avl_ins(avl **root, int data)
{
	if(!(*root))
	{
		(*root) = get_avl_node();
		(*root)->data = data;
		return;
	}

	if((*root)->data > data)			
		avl_ins(&(*root)->left, data);	
	else if((*root)->data < data)
		avl_ins(&(*root)->right, data);

//back trace processing area
	update_level(*root);
	(*root)->lev = update_level((*root));		

	if(abs(rotation_check(*root)) > 1)
	{
		printf("Rotation!\n");
		*root = rotation(*root, kinds_of_rot(*root, data));
	}

}


int main(void)
{
	avl* root;
	
	avl_ins(&root, 10);

	return 0;

}
