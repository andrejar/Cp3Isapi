// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

using namespace std;

// TODO: reference additional headers your program requires here

#include <windows.h>
#include "httpext.h"
#include "stdio.h"
#include <string>

 // function prototypes

HRESULT CpLoadMagickLibrary(void);