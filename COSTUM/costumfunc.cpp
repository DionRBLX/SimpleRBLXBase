#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include <TCHAR.h>
#include <string>
#include <sstream>

namespace costum
 {
	//Costum func
    int sleepthread(int amountoftime) {
		SetConsoleTitle("Thread is sleeping for " + amtTime + " ;*"); 
	  Sleep(amountoftime);
	  }
	//Not a costum func
	DWORD GetModuleBaseAddress(DWORD dwProcessIdentifier, TCHAR *lpszModuleName)
{
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwProcessIdentifier);
    DWORD dwModuleBaseAddress = 0;
    if (hSnapshot != INVALID_HANDLE_VALUE)
    {
        MODULEENTRY32 ModuleEntry32 = { 0 };
        ModuleEntry32.dwSize = sizeof(MODULEENTRY32);
        if (Module32First(hSnapshot, &ModuleEntry32))
        {
            do
            {
                if (_tcscmp(ModuleEntry32.szModule, lpszModuleName) == 0)
                {
                    dwModuleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
                    break;
                }
            } while (Module32Next(hSnapshot, &ModuleEntry32));
        }
        CloseHandle(hSnapshot);
    }
    return dwModuleBaseAddress;
}

  }
