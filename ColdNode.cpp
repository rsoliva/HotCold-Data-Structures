//----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------

#include "Node.h"
#include "ColdNode.h"

// Insert code
ColdNode::ColdNode()
{
}
ColdNode::ColdNode(const Node *temp) :
	MA(temp->MA), MB(temp->MB), MC(temp->MC), MD(temp->MD), A(temp->A), B(temp->B), C(temp->C),
	x(temp->x), y(temp->y), z(temp->z), pHot(0)
{
	strcpy_s(this->name, (strlen(temp->name) + 1), temp->name);
}
ColdNode::~ColdNode() {

}
void ColdNode::RemoveHot() {
	this->pHot = 0;
}
// ---  End of File ---------------


