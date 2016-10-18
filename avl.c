#include<stdio.h>
#include<stdlib.h>
#include"avl.h"

void init(node_t **ptr_root)
{
	*ptr_root=0;
	
}

void make_tree(node_t **ptr_root,int key)
{
	static int i=0;
	node_t *temp;
	temp = (node_t*)malloc(sizeof(node_t));
	temp->key = key;
	temp->left = 0;
	temp->right = 0;
	++i;
	if(i==1)
	{
		temp->parent=0;
	}
	
	insert_node(ptr_root,temp);
		
}

void insert_node(node_t** ptr_root,node_t* temp)
{
	if(*ptr_root == 0)
	{
			
		*ptr_root = temp;

		bal_fac(temp);
		
	}
	else if(temp->key < (*ptr_root)->key)
	{
		temp->parent = *ptr_root;
		insert_node( &(*ptr_root)->left , temp);
				
	}
	else
	{
		temp->parent = *ptr_root;
		insert_node( &(*ptr_root)->right, temp);
	}
}

void display(node_t*ptr)
{
	if(ptr)
	{
		display(ptr->left);
		printf("%2d\t%2d\n",ptr->key,ptr->bf);
		display(ptr->right);
	}
}


int countr(node_t *ptr,int res)
{
	node_t*temp;
	if(ptr->left==0 && ptr->right ==0)
	{
		return 0;
	}
	else if(res ==0 && ptr->left!==0 && ptr->right==0)
	{
		return 0;
	}
	else if(res > 0 && ptr->right == 0)
	{
		if(ptr->left != 0)
		{
			res = 1;
			temp = ptr->left;
		}
		else
		{
			res = 0;
			temp = ptr->right;
		}
	}
	else if (ptr ->right != 0)
	{
		res = 1;
		temp = ptr->right;
	}
	else
	{
		res = 0;
		temp = ptr->right;
	}
	
	return (res + countr(temp , res) );
}

int countl(node_t *ptr,int res)
{
	node_t*temp;
	if(ptr->left==0 && ptr->right ==0)
	{
		return 0;
	}
	else if(res ==0 && ptr->left==0 && ptr->right!=0)
	{
		return 0;
	}
	else if(res > 0 && ptr->left == 0)
	{
		if(ptr->right != 0)
		{
			res = 1;
			temp = ptr->right;
		}
		else
		{
			res = 0;
			temp = ptr->left;
		}
	}
	else if (ptr ->left != 0)
	{
		res = 1;
		temp = ptr->left;
	}
	else
	{
		res = 0;
		temp = ptr->left;
	}
	
	return (res + countl(temp , res) );
}


void bal_fac(node_t* temp)
{
	temp->bf = countl(temp,0) - countr(temp,0);
	
	if(temp->parent)
	{
		bal_fac(temp->parent);
	}
		
}
		

void check_imbalance(node_t* ptr,node_t** proot)
{
	
	
	if(ptr )
	{
		
		check_imbalance(ptr->left,proot);
		check_imbalance(ptr->right,proot);
			
		if(ptr->bf > 1 || ptr->bf <-1) 
		{
			node_t* temp;

			temp = detect(ptr,proot);
			if(temp!=0)
			{
				*proot=temp;
			}
	
				
			inorder(*proot);
			
		}
		
	}
	
}			


node_t* llcase(node_t** ptr,node_t** proot)
{
	node_t *p,*gp,*c, *temp;
	gp = *ptr;
	p = gp->left;
	c = p->left;
	if (gp->parent != 0)
	{
		 gp->parent->left = p;
			temp=0;
		
	}
	else
	{
		*proot=p;
		temp=p;
	}
	if( p->right != 0)
	{
		gp->left = p->right;
	}
	else
	{
		gp->left = 0;
	}
	
	p->parent = gp->parent;
	gp->parent = p;
	p->right = gp;
		
	return temp;
	
}	
	
void inorder(node_t* ptr)
{
	if(ptr)
	{
		inorder(ptr->left);
		bal_fac(ptr);
		inorder(ptr->right);
	}
}


node_t* rrcase(node_t** ptr,node_t** proot)
{
	node_t *p,*gp,*c;
	node_t* temp;
	gp = *ptr;
	p = gp->right;
	c = p->right;
	if (gp->parent != 0)
	{
		 gp->parent->right = p;
		temp=0;
	}
	else
	{
		*proot=p;
		temp=p;
		
	}
	if( p->left != 0)
	{
		gp->right = p->left;
	}
	else
	{
		gp->right = 0;
	}
	
	p->parent = gp->parent;
	gp->parent = p;
	p->left = gp;
		
	return temp;
	
}	


node_t* detect(node_t*ptr,node_t** proot)
{
	node_t* temp = ptr;
	node_t* ftemp = ptr;
	node_t* temp1;
	int lcount=0,rcount=0;
	while(ptr)
	{
		ptr=ptr->left;
		lcount++;
	}
	if (lcount == 3)
	{
		temp1 = llcase(&ftemp,proot);
	}

	while(temp) //not required in stage 1 but in stage two to check with rl,rr,lr cases
	{
		temp =temp->right;
		rcount++;
	}
	if(rcount == 3)
	{
		temp1=rrcase(&ftemp,proot);
	}
	return temp1;
}

node_t* search(node_t* ptr,int target)
{
	if( ptr == 0)
		return ptr;
	else
	{
		if(target == ptr->key)
		{
			return ptr;
		}
		else
		{
			if(target < ptr-> key)
				return search(ptr->left , target);
			else
				return search(ptr->right,target);
		}
	}


}





























