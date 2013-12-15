#ifndef _RBTREE_H_
#define _RBTREE_H_

#include <cstddef>
#include <stdio.h>

enum ColorType{ red, black };
struct node
{
	ColorType color;
	int key_value;

	node* left;
	node* right;
	node* parent;
};

class RBtree
{
public:
	RBtree();
	~RBtree();

	void destroy_tree();
	node* insert( int key );
	void rb_insert( int key );
	node* search( int key );
	
private:
	node* root;

	void destroy_tree( node* leaf );
	void create_node( int key, node* parent, node* leaf );
	node* insert( int key, node* leaf );
	node* search( int key, node* leaf );

	void rb_insert_case1( node* n );
	void rb_insert_case2( node* n );
	void rb_insert_case3( node* n );
	void rb_insert_case4( node* n );
	void rb_insert_case5( node* n );

	void rotate_left( node* n );
	void rotate_right( node* n );

	node* getGrandParent( node* n );
	node* getUncle( node* n );
};

#endif
