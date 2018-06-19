//----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------

#ifndef HOT_NODE_H
#define HOT_NODE_H
class ColdNode;

class HotNode
{
public:
	HotNode();
	~HotNode();
	HotNode(const int );
	HotNode *GetNext();

	int			key;
	HotNode		*pNext;
	HotNode		*pPrev;
	ColdNode	*pCold;
	
	
	
	
	
	
};

#endif

// ---  End of File ---------------
