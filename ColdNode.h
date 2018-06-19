//----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------

#ifndef COLD_NODE_H
#define COLD_NODE_H

class Node;
class HotNode;

class ColdNode
{
public:
	ColdNode();
	ColdNode(const Node *);
	~ColdNode();

	void RemoveHot();

	HotNode	*pHot;
	Matrix	MA;
	Matrix	MB;
	Matrix	MC;
	Matrix	MD;
	Vect	A;
	Vect	B;
	Vect	C;
	float	x;
	float	y;
	float	z;
	char	name[Node::NAME_SIZE];
};


#endif

// ---  End of File ---------------
