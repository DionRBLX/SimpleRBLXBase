#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include <TCHAR.h>
#include <string>
#include <sstream>
#include "/COSTUM/costumfunc.cpp"

//Here is where the hax begin 

using namespace std;



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
     custom::GetWindowThreadProcessId(hWnd, &pId);
     DWORD RBLXBASEAddr = GetModuleBaseAddress(pId, "RobloxPlayerBeta.exe"); 
     std::cout << "Base Address: " << hex << GetModuleBaseAddress(;

  return 0;                                                                
                                                          
}
                                                                  
 //Good example of dllmain                                                                 
BOOL APIENTRY DllMain( HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
  switch(ul_reason_for_call)
  {
    case DLL_PROCESS_ATTACH:
      CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Main, NULL, NULL, NULL);
    case DLL_THREAD_ATTACH:
      break;
    case DLL_THREAD_DETACH:
      break;
    case DLL_PROCESS_DETACH:
      break;
  }
  
  return TRUE;
}

 
