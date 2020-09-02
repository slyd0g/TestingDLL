// dllmain.cpp : Defines the entry point for the DLL application.
#include "windows.h"
#include <shellapi.h>

extern "C" __declspec(dllexport) int HelloWorld()
{
    //ShellExecuteA(NULL, NULL, "C:\\Windows\\System32\\notepad.exe", NULL, NULL, 3);
    return 0;
}

DWORD WINAPI Load(LPVOID lpParam)
{
    ShellExecuteA(NULL, NULL, "C:\\Windows\\System32\\notepad.exe", NULL, NULL, 3);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DWORD dwThread;
        HANDLE hThread;
        hThread = CreateThread(NULL, 0, Load, NULL, 0, &dwThread);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

