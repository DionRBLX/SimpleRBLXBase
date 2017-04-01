#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include <TCHAR.h>
#include <string>
#include <sstream>
#include "/COSTUM/costumfunc.cpp"

//Here is where the hax begin 

using namespace std;


//FUNCTIONS
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


int Main() {
//Here is where the magic starts
HWND hWnd = FindWindow(0, "ROBLOX"); //Finding RBLX window this is a low quality process if you know how to code and use this i recommened you to change this

std::cout << "Waiting for Roblox...";
while (hWnd == 0) { // Waiting until found
        Sleep(250);
        hWnd = FindWindow(0, "ROBLOX");
       
}

     system("cls");
     DWORD pId;
     GetWindowThreadProcessId(hWnd, &pId);
     DWORD RBLXBASEAddr = GetModuleBaseAddress(pId, "RobloxPlayerBeta.exe"); 
     std::cout << "Base Address: " << hex << GetModuleBaseAddress(;

  return 0;                                                                
                                                          
}

 
