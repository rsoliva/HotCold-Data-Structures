//----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------

#include "HotNode.h"

// Insert code
HotNode::HotNode() :
	key(0), pNext(0), pPrev(0), pCold(0)
{
}

HotNode::HotNode(const int tkey):
	key(tkey), pNext(0), pPrev(0), pCold(0)
{
}

HotNode::~HotNode() {

}
HotNode* HotNode::GetNext() 
{
	return this->pNext;
}
/*ColdNode* HotNode::GetCold() {
	return this->pCold;
}*/


// ---  End of File ---------------
