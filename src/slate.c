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
				if(key.key == CTRL_KEY('q'))
				{
					exit(0);
				}
				else if(key.key == CTRL_KEY('a'))
				{
					printf("control-a\r\n");
				}
				else
				{
					printf("special: %d\r\n", key.key);
				}
			}
		}
	}

	return 0;
}
