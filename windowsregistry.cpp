#include "windowsregistry.h"

//location in the registry of the path environment variable
static const char* keyName = "SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment";
static const char* keyValue = "PATH";

const char* WindowsRegistry::GetPathEnvironmentVariable()
{
	char* path = NULL;

	//open the key
	HKEY hkey;
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, keyName, 0, KEY_ALL_ACCESS, &hkey) == ERROR_SUCCESS)
	{
		//get type and size
		DWORD dwValueLength;
		DWORD dwValueType;
		if (RegQueryValueEx(hkey, keyValue, 0, &dwValueType, NULL, &dwValueLength) == ERROR_SUCCESS)
		{
			//allocate memory
			path = new char[dwValueLength];
			memset(path, 0, sizeof(char) * dwValueLength);
			if (RegQueryValueEx(hkey, keyValue, 0, &dwValueType, reinterpret_cast<BYTE*>(path), &dwValueLength) != ERROR_SUCCESS)
			{
				//if RegQueryValueEx fails then cleanup
				delete [] path;
				path = NULL;
			}
		}

		//close the key
		RegCloseKey(hkey);
	}

	//return the path environment variable
	return path;
}

bool WindowsRegistry::SetPathEnvironmentVariable(const char* aPath)
{
	//open the key
	HKEY hkey;
	LONG result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, keyName, 0, KEY_ALL_ACCESS, &hkey);

	//set the new path value. The size of the data is the length of the string + 1 for the null terminator
	const BYTE* data = reinterpret_cast<const BYTE*>(aPath);
	DWORD size = static_cast<DWORD>(strlen(aPath)) + 1;
	result = RegSetValueEx(hkey, keyValue, 0, REG_EXPAND_SZ, data, size);

	//if setting it failed
	if (result != ERROR_SUCCESS)
	{
		return false;
	}

	//close the key
	RegCloseKey(hkey);

	//broadcast the registry change
	DWORD dwReturnValue;
	SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, (LPARAM)"Environment", SMTO_ABORTIFHUNG, 500, &dwReturnValue);

	return true;
}
