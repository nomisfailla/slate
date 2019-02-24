#include "terminal/terminal.h"
#include "terminal/input.h"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void slate_exit()
{
	terminal_exit();
}

void slate_start()
{
	atexit(slate_exit);
	
	terminal_start();
}

int main(int argc, char** argv)
{
	slate_start();
	
	for(;;)
	{
		read_input();
	}

	return 0;
}
