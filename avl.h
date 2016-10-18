#ifndef TREE_H
#define TREE_H

struct node
{
	int key;
	int bf;
	struct node* parent;
	struct node* left;
	struct node* right;
};
typedef struct node node_t;

void init(node_t**);
void make_tree(node_t**,int);
void insert_node(node_t**,node_t*);
void display(node_t*);
int countl(node_t* , int);
int countr(node_t* , int);
void bal_fac(node_t*);
void check_imbalance(node_t* ptr,node_t**);
node_t* llcase(node_t**,node_t**);
void inorder(node_t*);
node_t* rrcase(node_t**,node_t**);
node_t* detect(node_t*,node_t**);
node_t* search(node_t* ptr,int target);
#endif
