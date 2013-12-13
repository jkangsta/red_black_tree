#ifndef _RBTREE_H_
#define _RBTREE_H_

struct node
{
	enum{ red, black } color;
	int key_value;

	node *left;
	node *right;
	node *parent;
};

class RBtree
{
public:
	RBtree( int root_val );
	~RBtree();

	void destroy_tree();
	void insert( int key );
	node *search( int key );
	
private:
	node* root;

	void destroy_tree( node* leaf );
	void create_node( int key, node* parent, node* leaf );
	void insert( int key, node* leaf );
	node *search( int key, node *leaf );

	void left_rotate();
	void rb_insert();
};

#endif
