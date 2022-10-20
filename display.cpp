//
// Created by marux on 19.10.22.
//
#include <iostream>
#include "display.h"

void setTextColor(const char* color)
{
    std::cout << color;
}

void setConsoleWindow(){
#ifdef _WIN32
    system(("chcp "s + std::to_string(CP_UTF8)).c_str());
#endif
}