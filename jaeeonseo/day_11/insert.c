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
	LR
}rot;

typedef struct __avl_tree
{
	int lev;
	int data;
	struct __avl_tree *left;
	struct __avl_tree *right;
}avl;


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
/*
	//updata_level(root);
	(*root)->lev = update_level(*root);		

	if(abs(rotation_check(*root)) > 1)
	{
		printf("Rotation!\n");
		*root = rotation(*root, kinds_of_rot(*root, data));
	}
*/
}

int updata_level(val *root)
{
	int left = root->left ? root->left->lev : 0;
	int right = root->right ? root->right->lev : 0;

	if(left > right)
		return left+1;
	
	return right+1;
}

int kinds_of_rot(avl *root, int data)	
{
	printf("data = %d\n", data);

	if(rotation_check(root) > 1)
	{
		if(root->right->data > data)
			return RL;

		return RR;
	}
	else if(rotation_check(root) < -1)
	{
		if(root->left->data < data)
