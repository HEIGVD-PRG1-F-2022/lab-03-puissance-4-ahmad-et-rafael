//
// Created by marux on 19.10.22.
//

#ifndef MANDELBROT_DISPLAY_H
#define MANDELBROT_DISPLAY_H

#define DARK_BLUE1 "\x1b[38;5;17m "
#define DARK_BLUE2 "\x1b[38;5;18m "
#define BLUE "\x1b[38;5;19m "
#define LIGHT_BLUE1 "\x1b[38;5;20m "
#define LIGHT_BLUE2 "\x1b[38;5;21m "
#define LIGHT_BLUE3 "\x1b[38;5;27m "
#define LIGHT_YELLOW "\x1b[38;5;230m "
#define YELLOW "\x1b[38;5;226m"
#define BLACK "\x1b[38;5;0m"
#define GREEN "\x1b[38;5;40m"
#define WHITE "\x1b[38;5;255m"
#define RESET "\x1b[0;0m"

void setTextColor(const char* color = BLACK);

#endif //MANDELBROT_DISPLAY_H
