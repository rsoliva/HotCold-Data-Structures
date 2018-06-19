//----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------

#ifndef ALIGN_H
#define ALIGN_H

class Align
{
public:
	struct Info
	{
		int NumTotalBytes;
		int NumBytesOfPadding;
	};

	static Info PrintME(void *p, int StructSize, char *s);
};

#endif

// ---  End of File ---------------
