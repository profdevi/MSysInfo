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


//v1.2 copyright Comine.com 20231225M1507
#include "MStdLib.h"
#include "MCommandArg.h"
#include "MMachineInfo.h"
#include "MWinShellInfo.h"
#include "MBuffer.h"


//******************************************************
//* Module Elements
//******************************************************
static const char* GApplicationName = "MSysInfo";	// Used in Help
static const char* GApplicationVersion = "1.2";	// Used in Help

////////////////////////////////////////////////////
static void GDisplayHelp(void);

////////////////////////////////////////////////////
int main(int argn,const char *argv[])
	{
	MCommandArg args(argn,argv);

	if(args.CheckRemoveHelp()==true)
		{
		GDisplayHelp();
		return 0;
		}

	MMachineInfo machineinfo(true);
	
	MStdPrintf("%-18s= %s\n","CPU Info",machineinfo.GetCPUInfo() );
	MStdPrintf("%-18s= %s\n","Machine Name",machineinfo.GetMachineName() );
	MStdPrintf("%-18s= %s (v%d.%d) (Build: %d)\n","OS Name",machineinfo.GetOSName()
			, machineinfo.GetMajorVersion(),machineinfo.GetMinorVersion()
			, machineinfo.GetBuildNumber() );
	// MStdPrintf("%-18s= %s\n","Version Info",machineinfo.GetVersionInfo() );
	MStdPrintf("%-18s= %dMB\n","OS Mem",machineinfo.GetPhysicalMemoryMB() );
	MStdPrintf("%-18s= %dMB\n","OS Mem Avail",machineinfo.GetPhysicalMemoryAvailibleMB() );
	MStdPrintf("%-18s= %dMB\n","Vert Mem",machineinfo.GetVirtualMemoryMB() );
	MStdPrintf("%-18s= %dMB\n","Vert Mem Avail",machineinfo.GetVirtualMemoryAvailibleMB() );

	MWinShellInfo shellinfo(true);
	MBuffer strinfo;

	if(shellinfo.GetWindowsDir(strinfo)==true)
		{
		MStdPrintf("%-18s= %s\n","Windows",strinfo.GetBuffer() );
		}

	if(shellinfo.GetWindowsSystemDir(strinfo)==true)
		{
		MStdPrintf("%-18s= %s\n","Windows System",strinfo.GetBuffer() );
		}

	if(shellinfo.GetUserAppDataLocalDir(strinfo)==true)
		{
		MStdPrintf("%-18s= %s\n","AppData Local",strinfo.GetBuffer() );
		}

	if(shellinfo.GetUserAppDataLocalLowDir(strinfo)==true)
		{
		MStdPrintf("%-18s= %s\n","AppData Local Low",strinfo.GetBuffer() );
		}

	if(shellinfo.GetUserAppDataRoamingDir(strinfo)==true)
		{
		MStdPrintf("%-18s= %s\n","AppData Roaming",strinfo.GetBuffer() );
		}

	if(shellinfo.GetUserDesktopDir(strinfo)==true)
		{
		MStdPrintf("%-18s= %s\n","Desktop",strinfo.GetBuffer() );
		}

	if(shellinfo.GetUserInternetCacheDir(strinfo)==true)
		{
		MStdPrintf("%-18s= %s\n","Internet Cache",strinfo.GetBuffer() );
		}

	if(shellinfo.GetUserInternetCookiesDir(strinfo)==true)
		{
		MStdPrintf("%-18s= %s\n","Internet Cookies",strinfo.GetBuffer() );
		}

	if(shellinfo.GetUserInternetHistoryDir(strinfo)==true)
		{
		MStdPrintf("%-18s= %s\n","Internet History",strinfo.GetBuffer() );
		}

	if(shellinfo.GetUserRecentDir(strinfo)==true)
		{
		MStdPrintf("%-18s= %s\n","Recent",strinfo.GetBuffer() );
		}

	if(shellinfo.GetUserStartUpDir(strinfo)==true)
		{
		MStdPrintf("%-18s= %s\n","Startup",strinfo.GetBuffer() );
		}

	if(shellinfo.GetAllDesktopDir(strinfo)==true)
		{
		MStdPrintf("%-18s= %s\n","All Desktop",strinfo.GetBuffer() );
		}

	if(shellinfo.GetAllStartUpDir(strinfo)==true)
		{
		MStdPrintf("%-18s= %s\n","All Startup",strinfo.GetBuffer() );
		}

	return 0;
	}


////////////////////////////////////////////////////
static void GDisplayHelp(void)
	{
	MStdPrintf(	"\n"
				"   usage:  %s [-?]\n"
				"           v%s copyright Comine.com\n"
				"\n"
				"\n"
				,GApplicationName,GApplicationVersion);
	}


