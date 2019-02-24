#include "terminal/terminal.h"

#include <stdio.h>

int main(int argc, char** argv)
{
	printf(FG_BLACK          "FG_BLACK         " RESET "\n"); 
	printf(FG_RED            "FG_RED           " RESET "\n"); 
	printf(FG_GREEN          "FG_GREEN         " RESET "\n"); 
	printf(FG_YELLOW         "FG_YELLOW        " RESET "\n"); 
	printf(FG_BLUE           "FG_BLUE          " RESET "\n"); 
	printf(FG_MAGENTA        "FG_MAGENTA       " RESET "\n"); 
	printf(FG_CYAN           "FG_CYAN          " RESET "\n"); 
	printf(FG_LIGHT_GRAY     "FG_LIGHT_GRAY    " RESET "\n"); 
	printf(FG_DARK_GRAY      "FG_DARK_GRAY     " RESET "\n"); 
	printf(FG_BRIGHT_RED     "FG_BRIGHT_RED    " RESET "\n"); 
	printf(FG_BRIGHT_GREEN   "FG_BRIGHT_GREEN  " RESET "\n"); 
	printf(FG_BRIGHT_YELLOW  "FG_BRIGHT_YELLOW " RESET "\n"); 
	printf(FG_BRIGHT_BLUE    "FG_BRIGHT_BLUE   " RESET "\n"); 
	printf(FG_BRIGHT_MAGENTA "FG_BRIGHT_MAGENTA" RESET "\n"); 
	printf(FG_BRIGHT_CYAN    "FG_BRIGHT_CYAN   " RESET "\n"); 
	printf(FG_WHITE          "FG_WHITE         " RESET "\n"); 
	
	printf(FG_WHITE);
	
	printf(BG_BLACK          "BG_BLACK         " RESET "\n");
	printf(BG_RED            "BG_RED           " RESET "\n");
	printf(BG_GREEN          "BG_GREEN         " RESET "\n");
	printf(BG_YELLOW         "BG_YELLOW        " RESET "\n");
	printf(BG_BLUE           "BG_BLUE          " RESET "\n");
	printf(BG_MAGENTA        "BG_MAGENTA       " RESET "\n");
	printf(BG_CYAN           "BG_CYAN          " RESET "\n");
	printf(BG_LIGHT_GRAY     "BG_LIGHT_GRAY    " RESET "\n");
	printf(BG_DARK_GRAY      "BG_DARK_GRAY     " RESET "\n");
	printf(BG_BRIGHT_RED     "BG_BRIGHT_RED    " RESET "\n");
	printf(BG_BRIGHT_GREEN   "BG_BRIGHT_GREEN  " RESET "\n");
	printf(BG_BRIGHT_YELLOW  "BG_BRIGHT_YELLOW " RESET "\n");
	printf(BG_BRIGHT_BLUE    "BG_BRIGHT_BLUE   " RESET "\n");
	printf(BG_BRIGHT_MAGENTA "BG_BRIGHT_MAGENTA" RESET "\n");
	printf(BG_BRIGHT_CYAN    "BG_BRIGHT_CYAN   " RESET "\n");
	printf(BG_WHITE          "BG_WHITE         " RESET "\n");
	
	printf(RESET);
	
	return 0;
}
