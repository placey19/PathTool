#ifndef WINDOWSREGISTRY_H
#define WINDOWSREGISTRY_H

#undef UNICODE
#include <windows.h>

class WindowsRegistry
{
public:
	static const char* GetPathEnvironmentVariable();
	static bool SetPathEnvironmentVariable(const char* aString);
};

#endif	//WINDOWSREGISTRY_H
