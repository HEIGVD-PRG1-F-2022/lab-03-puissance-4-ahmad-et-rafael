//
// Created by marux on 19.10.22.
//
#include <iostream>
#include "display.h"

#ifdef _WIN32
#include <windows.h>
#endif


void setTextColor(const char* color)
{
    std::cout << color;
}

void setConsoleWindow(){

#ifdef _WIN32
    system(("chcp " + std::to_string(CP_UTF8)).c_str());
#endif
}