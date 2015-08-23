/* CrazyPaving loader for ImageMagick interface DLL*/

#include "StdAfx.h"



HRESULT CpLoadMagickLibrary(void) {

	LoadLibraryEx(	"C:\\inetpub\\wwwroot\\CpMagick\\MagickTest1.dll",
					NULL,
					NULL);
	return 0;

}

