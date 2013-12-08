#ifndef _RBNODE_H_
#define _RBNODE_H_

#include <stdlib.h>
#include <stdio.h>

class RBnode
{
public:
	enum { red, black } color;
	int value;
	RBnode* left;
	RBnode* right;
	RBnode* parent;

	RBnode( int val );
	~RBnode();

	RBnode* getGrandParent();
	RBnode* getUncle();
};

#endif
