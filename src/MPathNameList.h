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


//v1.11 copyright Comine.com 20150813R1241
#ifndef MPathNameList_h
#define MPathNameList_h

//////////////////////////////////////////////////
#include "MBuffer.h"

//******************************************************
//**  MPathNameList class
//******************************************************
class MPathNameList
	{
	////////////////////////////////////////////////
	char mDriveLetter;
	char **mList;
	int mMaxLen;
	int mLen;
	
	////////////////////////////////////////////////
	void ClearObject(void);
	bool InitArray(const char *path);

	////////////////////////////////////////////////
	public:
	MPathNameList(bool create=false);
	~MPathNameList(void);
	bool Create(void);
	bool Create(const char *absdirpath);
	bool Destroy(void);
	const char *Get(int index);
	int GetElementCount(void);
	bool GetFullPath(MBuffer &buffer);	
	bool Push(const char *element);			// Push Element into list
	bool Push(MPathNameList &paths);		// Push More Elements at end
	bool Pop(void);							// Pop Element off list
	bool Pop(int count);					// Pop Till Count elements exist
	const char *GetTop(void);				// Get Last Element
	char GetDriveLetter(void);				// Get Drive Letter
	bool IsSamePath(MPathNameList &lst);	// =true if paths are same
	bool IsSamePath(const char *path);		// =true if paths are same
	};

#endif // MPathNameList_h

