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
#ifndef MWinShellInfo_h
#define MWinShellInfo_h

/////////////////////////////////////////////
#include "MStdLib.h"
#include "MBuffer.h"

//******************************************************
//**  MWinShellInfo class
//******************************************************
class MWinShellInfo
	{
	////////////////////////////////////////////////
	
	////////////////////////////////////////////////
	void ClearObject(void);
	
	////////////////////////////////////////////////
	public:
	MWinShellInfo(bool create=false);
	~MWinShellInfo(void);
	bool Create(void);
	bool Destroy(void);
	bool GetDir(int csidl,MBuffer &outbuf);				// Get Info based on CSIDL 

	bool GetWindowsDir(MBuffer &outdir);				// Get Windows Directory
	bool GetWindowsSystemDir(MBuffer &outdir);			// Get System Directory
	bool GetUserAppDataLocalDir(MBuffer &outdir);		// Local App Data
	bool GetUserAppDataLocalLowDir(MBuffer &outdir);	// Local App Data
	bool GetUserAppDataRoamingDir(MBuffer &outdir);		// Get App Data
	bool GetUserDesktopDir(MBuffer &outdir);			// Get User Desktop Directory
	bool GetUserRecentDir(MBuffer &outdir);				// Get User Recent Folder	
	bool GetUserStartUpDir(MBuffer &outdir);			// Get the user startup dir
	bool GetUserInternetCacheDir(MBuffer &outdir);		// Get Internet Cache Directory
	bool GetUserInternetCookiesDir(MBuffer &outdir);	// Get Internet Cookies Folder
	bool GetUserInternetHistoryDir(MBuffer &outdir);	// Get Internet History Folder
	bool GetAllDesktopDir(MBuffer &outdir);				// Get Everyone's Desktop Directory	
	bool GetAllStartUpDir(MBuffer &outdir);				// Get the user startup dir

	bool Print(void);									// Print out the dirs for info
	};

#endif // MWinShellInfo_h
