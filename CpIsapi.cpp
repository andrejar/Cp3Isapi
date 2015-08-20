

#include "stdafx.h"
#include "httpext.h"
#include "stdio.h"

void WriteContext(EXTENSION_CONTROL_BLOCK *pECB, char *pszFormat, ...);


BOOL APIENTRY DllMain(HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE; // reason for DllMain call is not relevant at this stage
}


BOOL WINAPI GetExtensionVersion(HSE_VERSION_INFO *pVer)
{
	pVer->dwExtensionVersion = HSE_VERSION;
	strncpy(pVer->lpszExtensionDesc, "CrazyPaving ISAPI Extension", HSE_MAX_EXT_DLL_NAME_LEN);

	return TRUE;
}

void StartHeaders(EXTENSION_CONTROL_BLOCK *pECB)
{
	WriteContext(pECB, "<html>\r\n<body>\r\n");
}

void EndHeaders(EXTENSION_CONTROL_BLOCK *pECB)
{
	WriteContext(pECB, "</body>\r\n</html>");
}

void WriteContext(EXTENSION_CONTROL_BLOCK *pECB, char *pszFormat, ...)
{
	char szBuffer[1024];
	va_list arg_ptr;
	va_start(arg_ptr, pszFormat); 
	vsprintf(szBuffer, pszFormat, arg_ptr);
	va_end(arg_ptr);
	
	DWORD dwSize = strlen(szBuffer);
	pECB->WriteClient(pECB->ConnID, szBuffer, &dwSize, 0);
}

DWORD WINAPI HttpExtensionProc(EXTENSION_CONTROL_BLOCK *pECB)
{
	StartHeaders(pECB);

	// Show that we've received the request

	WriteContext(pECB, "<p><b><font face='Verdana' color='#A00000'>Success!</font></b></p>");
	WriteContext(pECB, "<p><font size='2' face='Verdana'>The uploaded file is now available to the ISAPI extension.</font></p>\r\n", pECB->lpszQueryString);

	const char* ccVerb = pECB->lpszQueryString; // this is the command being executed

	if ( "DoPOC" == ccVerb ) {
		WriteContext(pECB, "<p><b><font face='Verdana' color='#A00000'>Success!</font></b></p>");
	    WriteContext(pECB, "<p><font size='2' face='Verdana'>The uploaded file is now available to the ISAPI extension.</font></p>\r\n");
	    WriteContext(pECB, "<p><font size='2' face='Verdana'>The following 'verb' was detected by ISAPI: %s.</font></p>\r\n", pECB->lpszQueryString);
	}

	EndHeaders(pECB);

	return HSE_STATUS_SUCCESS;
}