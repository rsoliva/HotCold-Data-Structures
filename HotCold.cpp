//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"

// Users
#include "Bloated.h"
#include "Node.h"
#include "hotcold.h"

#define STUB_PLEASE_REPLACE(x) (x)

HotCold::HotCold(const Bloated * const pBloated)
{
	Node *pSource = pBloated->GetListHead();
	this->allHot = new HotNode[pBloated->GetSize()];
	this->allCold = new ColdNode[pBloated->GetSize()];
	this->Size = pBloated->GetSize();

	HotNode *hN = &allHot[0];
	ColdNode *cN = &allCold[0];
	while (pSource != 0) {

		//copy hot key data
		//*hN = HotNode(pSource->key);
		hN->key = pSource->key;
		hN->pNext = 0;
		hN->pPrev = 0;
		hN->pCold = 0;

		//copy cold data directly
		//*cN = ColdNode(pSource);
		cN->MA = pSource->MA;
		cN->MB = pSource->MB;
		cN->MC = pSource->MC;
		cN->MD = pSource->MD;
		cN->A = pSource->A;
		cN->B = pSource->B;
		cN->C = pSource->C;
		cN->x = pSource->x;
		cN->y = pSource->y;
		cN->z = pSource->z;
		cN->pHot = 0;
		memcpy(cN->name, pSource->name, (strlen(pSource->name) + 1));

		hN->pCold = cN;
		cN->pHot = hN;

		hN++;
		cN++;
		pSource = pSource->pNext;
	}
	this->pHotHead = &allHot[0];
	this->pColdHead = &allCold[0];
	//linking nodes
	HotNode *hFirst = this->pHotHead;
	HotNode *hLast = hFirst + this->Size -1;
	
	hN = hFirst;
	for (unsigned int i = 0; i < this->Size; ++i) {
		hN->pNext = (hN + 1);
		hN->pPrev = (hN - 1);
		hN++;
	}
	//handles edge cases
	hLast->pNext = 0;
	hFirst->pPrev = 0;
	
}

HotCold::~HotCold()
{
	// HINT - do something here
	delete[] this->allHot;
	delete[] this->allCold;

}

//----------------------------------------------------------------------------------
// Find Key using linked lists (pointers only) 
//    Hint: use ->pNext
//    YOU MUST - iterate through the nodes in a linked list fashion or 0 credit
//
// Return true if you find the node
// Return the pointer in the argument list to the HotNode and ColdNode (if found)
//----------------------------------------------------------------------------------
bool HotCold::FindKey(int key, ColdNode *&pFoundColdNode, HotNode *&pFoundHotNode)
{
	pFoundHotNode = this->pHotHead;
	while (pFoundHotNode != 0) {
		if (pFoundHotNode->key == key) {
			pFoundColdNode = pFoundHotNode->pCold;
			return true;
		}
		pFoundHotNode = pFoundHotNode->pNext;
	}
	return false;
}

HotNode *HotCold::GetHotHead() const
{
	return this->pHotHead;
}


// ---  End of File ---------------
