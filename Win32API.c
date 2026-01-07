/*EnumProcesses is the standard function used to retrieve the PID being part of
PSAPI. Keystrokes arrive as messages in your app queue. WM_KEYDOWN sent when a
non system key is pressed. VM_KEYUP sent when a key is released. WM_SYSKEYDOWN
sent the user holds Alt plus naother key. WM_CHAR is the character resulting from
it.
A HANDLE is an opaque pointer or index that represents an object managed by the
windows kernel usually a void*. An HMODULE is a type of handle that represents a
loaded module, it is the memory address where the module was loaded into the
process address space. LPTSTR is a pointer to a string portable. DWORD is an
unsigned long used for counts, sizes, flags and error codes.
EnumProcesses
OpenProcess
CreateToolHelp32Snapshot
Process32FIrst
Process32Next
GetProcessMemoryInfo
EnumProcessModules
GetModuleInformation
QueryFullProcessImageName
TerminateProcess
GetExitCodeProcess
ReadProcessMemory
CreateRemoteThread
WriteProcessMemory
*/

#include <windows.h>
#include <psapi.h>
#include <stdio.h>
BOOL EnumProcesses(
    [out] DWORD *lpidProcess, //pointer to an array receiving the list of PIDs
    [in] DWORD cb, //size of the array in bytes
    [out] LPDWORD IpcbNeeded //pointer to a DWORD receiving the number of bytes returned in the lpidProcess array
);

BOOL EnumProcessModules(
  [in]  HANDLE  hProcess,
  [out] HMODULE *lphModule,
  [in]  DWORD   cb,
  [out] LPDWORD lpcbNeeded
);
/* hProcess [in]: A handle to the process. This handle must have the
PROCESS_QUERY_INFORMATION and PROCESS_VM_READ access rights.
lphModule [out]: A pointer to an array that will be filled with the
list of module handles (HMODULE).cb [in]: The size of the lphModule array, in bytes.
lpcbNeeded [out]: A pointer to a variable that receives the total number of bytes
required to store all module handles. */

HANDLE OpenProcess(
  [in] DWORD dwDesiredAccess,
  [in] BOOL  bInheritHandle,
  [in] DWORD dwProcessId
);
/*
dwDesiredAccess [in]: The access level you are requesting.
This is where you specify what you intend to do with the process.
Common flags include: PROCESS_QUERY_INFORMATION: Required for EnumProcessModules.
PROCESS_VM_READ: Required to read the process's memory.
PROCESS_TERMINATE: Required to kill the process.    
PROCESS_ALL_ACCESS: Grants all possible access rights (use sparingly).
bInheritHandle [in]: A boolean. If TRUE, processes created by this process will
inherit the handle. Usually set to FALSE for standard utilities.
dwProcessId [in]: The unique identifier (PID) of the process you want to open. */



BOOL TerminateProcess(
  [in] HANDLE hProcess,
  [in] UINT   uExitCode
);
/*hProcess [in]: A handle to the process you want to shut down. This handle must
have the PROCESS_TERMINATE access right (requested during the OpenProcess call).
uExitCode [in]: The exit power/status you want the process to report. Usually,
programmers use 0 for a clean-ish exit or 1 for an error, but since this is a
forced termination, the value is mainly for logging purposes.*/       


int main() {
    DWORD aProcesses[1024], cbNeeded, cProcesses;
    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
        printf("EnumProcesses failed (%lu)\n", GetLastError());
        return 1;
        }
    cProcesses=cbNeeded / sizeof(DWORD);
    printf("Found %lu active processes.\n", cProcesses);
    for (unsigned int i=0; i<cProcesses; i++) {
        if (aProcesses[i]!=0) {
            printf("Process ID: %u\n", aProcesses[i]);
        }
    }
    return 0;
}





#include <windows.h>
#include <stdio.h>

int main() {
    DWORD pid = 1234; // Example PID
    // Requesting access to query info and read memory
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
    if (hProcess == NULL) {
        DWORD error = GetLastError();
        if (error == ERROR_ACCESS_DENIED) {
            printf("Failed: Access Denied. Try running as Administrator.\n");
        } else {
            printf("OpenProcess failed with error: %lu\n", error);
        }
        return 1;
    }
    printf("Successfully opened process %lu. Handle: %p\n", pid, hProcess);
    // ALWAYS close the handle when finished to prevent memory leaks
    CloseHandle(hProcess);
    return 0;
}





















int main() {
    int *list[1024];
    int **ptr_list=list;
    char *s;
    DWORD aProcesses[1024], needed, Processes;
    if (!EnumProcesses(aProcesses, sizeof(Processes), &needed)) {
        printf("Enum processes failed.\n");
        return 1;}
    Processes=needed/sizeof(DWORD);
    printf("Found %lu active processes.\n", Processes);
    for (unsigned int i=0; i<cProcesses; i++) {
        if (aProcesses[i]!=0) {
            printf("Process ID: %u\n", aProcesses[i]);
            list[i]=aProcesses[i];
            printf("Do you want to kill that process ?");
            if (!scanf("%s", &s)) {
                printf("You must answer yes or not");
                };
            if (*s=='yes') {
                kill_process(aProcesses[i]);
            }    }
}}


#include <windows.h>
#include <stdio.h>
#include <psapi.h>
#include <string.h>
// Assuming your kill_process function is defined above
void kill_process(DWORD pid); 
int main() {
    DWORD aProcesses[1024], needed, cProcesses;
    char answer[10];
    // FIX 1: Pass the size of the whole array (sizeof(aProcesses))
    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &needed)) {
        printf("Enum processes failed. Error: %lu\n", GetLastError());
        return 1;
    }
    cProcesses = needed / sizeof(DWORD);
    printf("Found %lu active processes.\n", cProcesses);
    for (unsigned int i = 0; i < cProcesses; i++) {
        if (aProcesses[i] != 0) {
            printf("\nProcess ID: %u\n", aProcesses[i]);
            printf("Do you want to kill this process? (yes/no): ");
            // FIX 2: Read into the buffer 'answer'
            scanf("%9s", answer); 
            // FIX 3: Use strcmp for string comparison
            if (strcmp(answer, "yes") == 0) {
                kill_process(aProcesses[i]);
            } else {
                printf("Skipping process %u.\n", aProcesses[i]);
            }
        }
    }
    return 0;
}


void kill_process(int *Pid){
    int pid = *Pid;
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_TERMINATE, FALSE, pid);
    TerminateProcess(hProcess, 1);
    }
/*Your code is a great start! You've correctly combined the access flags using the
bitwise OR (|) operator, ensuring you have the permissions needed to both inspect
the process and kill it. However, in low-level C development, robustness is key.
There are three main things we should fix to make this production-ready:
Error Handling: If OpenProcess fails (e.g., access denied), passing a NULL handle
to TerminateProcess will cause an error. Resource Management: You must call
CloseHandle to avoid a "Handle Leak."
Data Types: While int works for PIDs, the official Win32 type is DWORD. */

#include <windows.h>
#include <stdio.h>

void kill_process(DWORD pid) {
    // 1. Requesting Query, Read, and Terminate rights
    HANDLE hProcess = OpenProcess(
        PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_TERMINATE, 
        FALSE, 
        pid
    );
    // 2. Check if the handle is valid
    if (hProcess == NULL) {
        fprintf(stderr, "Error: Could not open process %lu. GetLastError: %lu\n", pid, GetLastError());
        return;
    }
    // 3. Attempt termination
    if (TerminateProcess(hProcess, 1)) {
        printf("Process %lu terminated successfully.\n", pid);
    } else {
        fprintf(stderr, "Error: TerminateProcess failed for %lu. GetLastError: %lu\n", pid, GetLastError());
    }
    // 4. Clean up the handle (Crucial for system stability!)
    CloseHandle(hProcess);
}
