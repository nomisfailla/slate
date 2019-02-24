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
		input_event_t key = read_input();
		if(isprint(key.key))
		{
			printf("%c\r\n", key.key);
		}
		else
		{
			if(key.key != 0)
			{
				printf("special: %d\r\n", key.key);
			}
		}
		
		if(key.key == 'q' || key.key == 'Q')
		{
			exit(0);
		}
	}

	return 0;
}
