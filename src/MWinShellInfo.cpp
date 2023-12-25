/*
Copyright (C) 2011-2023, Comine.com ( profdevi@ymail.com )
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

- Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
- The the names of the contributors of this project may not be used to 
  endorse or promote products derived from this software without specific 
  prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
`AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/


//v1.2 copyright Comine.com 20160214U2007
#include <Windows.h>
#include <ShlObj.h>
#include "MStdLib.h"
#include "MBuffer.h"
#include "MPathNameList.h"
#include "MFileOps.h"
#include "MWinShellInfo.h"

//////////////////////////////////////////
#ifdef MSTDLIB_OS_WINDOWS
#pragma comment(lib,"shell32.lib")
#endif // MSTDLIB_OS_WINDOWS

//******************************************************
//**  MOdule Elements
//******************************************************
static const int GMaxBufferSize=MAX_PATH+16;
static const char GPrintFormat[]="%-25s = %s\n";

//******************************************************
//**  MWinShellInfo class
//******************************************************
void MWinShellInfo::ClearObject(void)
	{
	}


////////////////////////////////////////////////
MWinShellInfo::MWinShellInfo(bool create)
	{
	ClearObject();
	if(Create()==false)
		{
		return;
		}
	}


////////////////////////////////////////////////
MWinShellInfo::~MWinShellInfo(void)
	{  Destroy();  }


////////////////////////////////////////////////
bool MWinShellInfo::Create(void)
	{
	Destroy();
	return true;
	}


////////////////////////////////////////////////
bool MWinShellInfo::Destroy(void)
	{
	ClearObject();
	return true;
	}


////////////////////////////////////////////////
bool MWinShellInfo::GetDir(int csidl,MBuffer &outbuf)
	{
	if(outbuf.Create(GMaxBufferSize)==false)
		{
		return false;
		}

	HRESULT hret;
	hret=SHGetFolderPathA(NULL,csidl,NULL,0,outbuf.GetBuffer() );
	if(FAILED(hret) )
		{
		return false;
		}

	// Convert to normalized folder path
	MFileOps fileops(true);
	MString canonpath;
	if(fileops.GetCanonicalName(outbuf.GetBuffer(),canonpath)==false)
		{
		return false;
		}

	if(outbuf.SetString(canonpath.Get() )==false)
		{
		return false;
		}

	return true;
	}


////////////////////////////////////////////////
bool MWinShellInfo::GetWindowsDir(MBuffer &outdir)
	{
	return GetDir(CSIDL_WINDOWS,outdir);
	}


////////////////////////////////////////////////
bool MWinShellInfo::GetWindowsSystemDir(MBuffer &outdir)
	{
	return GetDir(CSIDL_SYSTEM,outdir);
	}


////////////////////////////////////////////////
bool MWinShellInfo::GetUserAppDataLocalDir(MBuffer &outdir)
	{
	return GetDir(CSIDL_LOCAL_APPDATA,outdir);
	}


////////////////////////////////////////////////
bool MWinShellInfo::GetUserAppDataLocalLowDir(MBuffer &outdir)
	{
	if(GetDir(CSIDL_LOCAL_APPDATA,outdir)==false)
		{
		return false;
		}

	MPathNameList pathlist;
	if(pathlist.Create(outdir)==false)
		{
		return false;
		}

	if(pathlist.Pop()==false || pathlist.Push("LocalLow")==false)
		{
		return false;
		}

	if(pathlist.GetFullPath(outdir)==false)
		{
		return false;
		}

	return true;
	}


////////////////////////////////////////////////
bool MWinShellInfo::GetUserAppDataRoamingDir(MBuffer &outdir)
	{
	return GetDir(CSIDL_APPDATA,outdir);
	}


////////////////////////////////////////////////
bool MWinShellInfo::GetUserDesktopDir(MBuffer &outdir)
	{
	return GetDir(CSIDL_DESKTOPDIRECTORY,outdir);
	}


////////////////////////////////////////////////
bool MWinShellInfo::GetUserRecentDir(MBuffer &outdir)
	{
	return GetDir(CSIDL_RECENT|CSIDL_FLAG_DONT_VERIFY|CSIDL_FLAG_DONT_UNEXPAND,outdir);
	}


///////////////////////////////////////////////
bool MWinShellInfo::GetAllStartUpDir(MBuffer &outdir)
	{
	return GetDir(CSIDL_COMMON_STARTUP|CSIDL_FLAG_DONT_VERIFY,outdir);
	}


//////////////////////////////////////////////
bool MWinShellInfo::GetUserInternetCacheDir(MBuffer &outdir)
	{
	return GetDir(CSIDL_INTERNET_CACHE,outdir);
	}


//////////////////////////////////////////////
bool MWinShellInfo::GetUserInternetCookiesDir(MBuffer &outdir)			// Get Cookies Folder
	{
	return GetDir(CSIDL_COOKIES|CSIDL_FLAG_DONT_VERIFY,outdir);
	}


//////////////////////////////////////////////
bool MWinShellInfo::GetUserInternetHistoryDir(MBuffer &outdir)			// Get Cookies Folder
	{
	return GetDir(CSIDL_HISTORY|CSIDL_FLAG_DONT_VERIFY,outdir);
	}


///////////////////////////////////////////////
bool MWinShellInfo::GetUserStartUpDir(MBuffer &outdir)
	{
	return GetDir(CSIDL_STARTUP|CSIDL_FLAG_DONT_VERIFY,outdir);
	}


////////////////////////////////////////////////
bool MWinShellInfo::GetAllDesktopDir(MBuffer &outdir)
	{
	return GetDir(CSIDL_COMMON_DESKTOPDIRECTORY,outdir);
	}


////////////////////////////////
bool MWinShellInfo::Print(void)
	{
	MBuffer dir;

	///////////////////////////////////
	if(GetWindowsDir(dir)==false)
		{
		return false;
		}

	MStdPrintf(GPrintFormat,"Windows",dir.GetBuffer() );

	///////////////////////////////////
	if(GetWindowsSystemDir(dir)==false)
		{
		return false;
		}

	MStdPrintf(GPrintFormat,"Windows System",dir.GetBuffer() );
	
	///////////////////////////////////
	if(GetUserAppDataLocalDir(dir)==false)
		{
		return false;
		}

	MStdPrintf(GPrintFormat,"User AppData Local",dir.GetBuffer() );

	///////////////////////////////////
	if(GetUserAppDataLocalLowDir(dir)==false)
		{
		return false;
		}

	MStdPrintf(GPrintFormat,"User AppData LocalLow",dir.GetBuffer() );

	///////////////////////////////////
	if(GetUserAppDataRoamingDir(dir)==false)
		{
		return false;
		}

	MStdPrintf(GPrintFormat,"User AppData Roaming",dir.GetBuffer() );

	///////////////////////////////////
	if(GetUserDesktopDir(dir)==false)
		{
		return false;
		}

	MStdPrintf(GPrintFormat,"User Desktop",dir.GetBuffer() );

	///////////////////////////////////
	if(GetUserRecentDir(dir)==false)
		{
		return false;
		}

	MStdPrintf(GPrintFormat,"User Recent",dir.GetBuffer() );


	///////////////////////////////////
	if(GetUserStartUpDir(dir)==false)
		{
		return false;
		}

	MStdPrintf(GPrintFormat,"User Startup",dir.GetBuffer() );

	///////////////////////////////////
	if(GetUserInternetCacheDir(dir)==false)
		{
		return false;
		}

	MStdPrintf(GPrintFormat,"User Internet Cache",dir.GetBuffer() );

	///////////////////////////////////
	if(GetUserInternetCookiesDir(dir)==false)
		{
		return false;
		}

	MStdPrintf(GPrintFormat,"User Internet Cookies",dir.GetBuffer() );

	///////////////////////////////////
	if(GetUserInternetHistoryDir(dir)==false)
		{
		return false;
		}

	MStdPrintf(GPrintFormat,"User Internet History",dir.GetBuffer() );


	///////////////////////////////////
	if(GetAllDesktopDir(dir)==false)
		{
		return false;
		}

	MStdPrintf(GPrintFormat,"All Desktop",dir.GetBuffer() );

	///////////////////////////////////
	if(GetAllStartUpDir(dir)==false)
		{
		return false;
		}

	MStdPrintf(GPrintFormat,"All StartUp",dir.GetBuffer() );

	return false;
	}


