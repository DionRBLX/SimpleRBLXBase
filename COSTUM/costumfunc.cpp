#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
#include <TCHAR.h>
#include <string>
#include <sstream>

namespace costum
 {
    int sleepthread(int amountoftime) {
		SetConsoleTitle("Thread is sleeping for " + amtTime + " ;*"); 
	  Sleep(amountoftime);
	  }
  }
