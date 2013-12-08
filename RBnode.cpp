#include "RBnode.h"

RBnode::RBnode( int val )
{
	value = val;
	color = red;

	left = NULL;
	right = NULL;
	parent = NULL;
}

RBnode::~RBnode()
{

}

RBnode* RBnode::getGrandParent()
{
	if( parent != NULL )
	{
		return parent->parent;
	}
	
	return NULL;
}

RBnode* RBnode::getUncle()
{
	RBnode* gp = getGrandParent();

	if( gp == NULL )
	{
		return NULL; // No grandparent means no uncle
	}

	if( parent == gp->left )
	{
		return gp->right;
	}
	else
	{
		return gp->left;
	}
}

