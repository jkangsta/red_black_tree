#include "RBtree.h"

RBtree::RBtree()
{
	root = NULL;
}

RBtree::~RBtree()
{
	destroy_tree();
}

/********** Binary Tree Property **********/

void RBtree::destroy_tree()
{
	destroy_tree( root );
}

node* RBtree::insert( int key )
{
	if( root == NULL )
	{
		create_node( key, NULL, root );
		return root;
	}
	
	return insert( key, root );
}

node* RBtree::search( int key )
{
	return search( key, root );
}

void RBtree::destroy_tree( node* leaf )
{
	if( leaf != NULL )
	{
		destroy_tree( leaf->left );
		destroy_tree( leaf->right );
		delete leaf;
	}
}

void RBtree::create_node( int key, node* parent, node* leaf )
{
	leaf = new node();

	leaf->key_value = key;
	leaf->color = red;
	leaf->parent = parent;
	leaf->left = NULL;
	leaf->right = NULL;
}

node* RBtree::insert( int key, node* leaf )
{
	if( key == leaf->key_value )
	{
		return NULL;
	}

	if( key < leaf->key_value )
	{
		if( leaf->left == NULL )
		{ 
			create_node( key, leaf, leaf->left );
			return leaf->left;
		}
		return insert( key, leaf->left );
	}
	else
	{
		if( leaf->right == NULL )
		{
			create_node( key, leaf, leaf->right );
			return leaf->right;
		}
		return insert( key, leaf->right );
	}
}

node* RBtree::search( int key, node* leaf )
{
	if( leaf == NULL )
	{
		return NULL;
	}

	if( key < leaf->key_value )
	{
		return search( key, leaf->left );
	}

	if( key > leaf->key_value )
	{
		return search( key, leaf->right );
	}

	return leaf;
}

/********** Red Black Tree Property **********/

void RBtree::rb_insert( int key )
{
	node* n = insert( key );
	if( n == NULL )
	{
		return;
	}

	rb_insert_case1( n );
}

void RBtree::rb_insert_case1( node* n )
{
	if( n->parent == NULL )
	{
		n->color = black;
	}
	else
	{
		rb_insert_case2( n );
	}
}

void RBtree::rb_insert_case2( node* n )
{
	if( n->parent->color == black )
	{
		return;
	}
	else
	{
		rb_insert_case3( n );
	}
}

void RBtree::rb_insert_case3( node* n )
{
	node* u = getUncle( n );

	if( ( u != NULL ) && ( u->color == red ) )
	{
		n->parent->color = black;
		u->color = black;

		node* g = getGrandParent( n );
		g->color = red;
		rb_insert_case1( g );
	}
	else
	{
		rb_insert_case4( n );
	}
}

void RBtree::rb_insert_case4( node* n )
{
	node* g = getGrandParent( n );

	if( ( n == n->parent->right ) && ( n->parent == g->left ) )
	{
		rotate_left( n->parent );
		n = n->left;
	}
	else if( ( n == n->parent->left ) && ( n->parent == g->right ) )
	{
		rotate_right( n->parent );
		n = n->right;
	}

	rb_insert_case5( n );
}

void RBtree::rb_insert_case5( node* n )
{
	node* g = getGrandParent( n );
	n->parent->color = black;
	g->color = red;

	if( n == n->parent->left )
	{
		rotate_right( g );
	}
	else
	{
		rotate_left( g );
	}
}

void RBtree::rotate_left( node* n )
{
	node* saved_p = n;
	node* saved_left_n = n->right->left;

	n = n->right;
	n->right->left = saved_p;
	saved_p->right = saved_left_n;
}

void RBtree::rotate_right( node* n )
{
	node* saved_p = n;
	node* saved_right_n = n->left->right;

	n = n->left;
	n->left->right = saved_p;
	saved_p->left = saved_right_n;
}

node* RBtree::getGrandParent( node* n )
{
	if( ( n != NULL ) && ( n->parent != NULL ) )
	{
		return n->parent->parent;
	}

	return NULL;
}

node* RBtree::getUncle( node* n )
{
	node* g = getGrandParent( n );
	if( g = NULL )
	{
		return NULL;
	}

	if( n->parent == g->left )
	{
		return g->right;
	}

	return g->left;
}
