//----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------

#include "Framework.h"

#include "Align.h"

#define STUB_PLEASE_REPLACE(x) (x)

Align::Info Align::PrintME(void *pData, int StructSize, char *pString)
{
	// Use Trace::out(...) to display the data layout and padding
	// Mimic the KeenanSampleOutput_Debug.txt
	Info info;
	info.NumBytesOfPadding = 0;
	info.NumTotalBytes = StructSize;
	Trace::out("%s:", pString);
	const unsigned char* bytes = static_cast<const unsigned char*>(pData);
	int i;
	for (i = 0; i < StructSize; i++)
	{
		if (i % 4 == 0) {
			Trace::out("\n");
			Trace::out("  0x%.2x:  ", i);
		}
		if ((bytes[i]) == 0xaa) { 
			info.NumBytesOfPadding += 1;
		}
		Trace::out("%02x ", bytes[i]);
	}
	Trace::out("\n-----------------------------");
	Trace::out("\nSize: %d  Padding: %d\n\n",info.NumTotalBytes, info.NumBytesOfPadding);
	STUB_PLEASE_REPLACE(pData);
	STUB_PLEASE_REPLACE(StructSize);
	STUB_PLEASE_REPLACE(pString);


	return info;
}

// ---  End of File ---------------
