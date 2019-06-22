#ifndef _TERMINAL_H
#define _TERMINAL_H

#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdbool.h>

#define RESET "\033[0m"

#define FG_BLACK          "\033[30m"
#define FG_RED            "\033[31m"
#define FG_GREEN          "\033[32m"
#define FG_YELLOW         "\033[33m"
#define FG_BLUE           "\033[34m"
#define FG_MAGENTA        "\033[35m"
#define FG_CYAN           "\033[36m"
#define FG_LIGHT_GRAY     "\033[37m"
#define FG_DARK_GRAY      "\033[30;1m"
#define FG_BRIGHT_RED     "\033[31;1m"
#define FG_BRIGHT_GREEN   "\033[32;1m"
#define FG_BRIGHT_YELLOW  "\033[33;1m"
#define FG_BRIGHT_BLUE    "\033[34;1m"
#define FG_BRIGHT_MAGENTA "\033[35;1m"
#define FG_BRIGHT_CYAN    "\033[36;1m"
#define FG_WHITE          "\033[37;1m"

#define BG_BLACK          "\033[40m"
#define BG_RED            "\033[41m"
#define BG_GREEN          "\033[42m"
#define BG_YELLOW         "\033[43m"
#define BG_BLUE           "\033[44m"
#define BG_MAGENTA        "\033[45m"
#define BG_CYAN           "\033[46m"
#define BG_LIGHT_GRAY     "\033[47m"
#define BG_DARK_GRAY      "\033[100;1m"
#define BG_BRIGHT_RED     "\033[101;1m"
#define BG_BRIGHT_GREEN   "\033[102;1m"
#define BG_BRIGHT_YELLOW  "\033[103;1m"
#define BG_BRIGHT_BLUE    "\033[104;1m"
#define BG_BRIGHT_MAGENTA "\033[105;1m"
#define BG_BRIGHT_CYAN    "\033[106;1m"
#define BG_WHITE          "\033[107;1m"

void terminal_clear();

void terminal_start();
void terminal_exit();
void terminal_get_size(int* width, int* height);
void terminal_cursor(bool enable);

#endif
