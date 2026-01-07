LRESULT CALLBACK LowLevelKeyboardProc(
  int    nCode,
  WPARAM wParam,
  LPARAM lParam
);


HHOOK hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, hInst, 0);






















#include <windows.h>
#include <stdio.h>

// Global handle for the hook so we can unhook it later
HHOOK hhkLowLevelKybd = NULL;
// 1. The Callback Function (Matches the HOOKPROC signature)
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    // nCode < 0 means we must pass it to CallNextHookEx immediately
    if (nCode == HC_ACTION) {
        // Check if the event is a key press
        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            // Cast lParam to the structure containing keystroke data
            KBDLLHOOKSTRUCT *pKeyBoard = (KBDLLHOOKSTRUCT *)lParam;
            // Log the Virtual-Key code
            printf("Key Pressed: VK Code %02X\n", pKeyBoard->vkCode);
            // Example: If the user presses 'Escape', we could stop here
            if (pKeyBoard->vkCode == VK_ESCAPE) {
                PostQuitMessage(0);
            }
        }
    }
    // Always call the next hook in the chain
    return CallNextHookEx(hhkLowLevelKybd, nCode, wParam, lParam);
}

int main() {
    // 2. Set the Hook
    // WH_KEYBOARD_LL: The type of hook (Low-level keyboard)
    // LowLevelKeyboardProc: Our callback function
    // GetModuleHandle(NULL): Handle to this executable instance
    hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, GetModuleHandle(NULL), 0);
    if (hhkLowLevelKybd == NULL) {
        printf("Failed to install hook! Error: %lu\n", GetLastError());
        return 1;
    }
    printf("Hook installed. Press keys to see VK codes (Press ESC to exit)...\n");
    // 3. The Message Loop (Essential to keep the hook alive)
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    // 4. Cleanup: Remove the hook before exiting
    UnhookWindowsHookEx(hhkLowLevelKybd);
    return 0;
}



/*Manage memory with a doubly linked list. Merge two free blocks during allocation
and when memory is freed. Calculate offsets. Manage splitting. Watch out for
alignment. When I need to allocate memory to store data, i verify if a block is free,
i must know its size, i need to split (if the data is n bytes i will need n+1 bytes
to ensure splitting) if splitting dont work i pass to the next block.              
if the previous */
typedef struct Metadata {
    bool is_free;
    size_t size;
    
    } struct Metadata;
typedef struct Node {
    Node *prev;
    Metadata metadata;
    Node *next;
    } struct Node;
bool is_block_free(Node *node) {
    is_block_free=node->metadata->is_free;
    } 
void allocate_memory() {
    is_block_free(node);
    size_of_block=node->metadata->size;
    size_new_block=size_of_block-size_of_data-size_of_metadata;
    if (size_to_allocate) {
        
        }
    Node *new_node=;
    node->next=new_node;
    new_node->prev=node;
    Metadata metadata;
    metadata->size_new_block;   
    
    }
void merge_blocks(Node *node) {
      Node *node_prev=node->prev;
      Node *node_next=node->next;
      if (node_prev->is_free) {
          
          }
      if (node_next->is_free) {
          
          }
    }