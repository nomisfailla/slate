#include "terminal/terminal.h"
#include "terminal/input.h"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <signal.h>

void resize_handler(int sig)
{
	if(sig == SIGWINCH)
	{
		int w, h;
		terminal_get_size(&w, &h);
		printf("size is %dx%d\r\n", w, h);
	}
	else
	{
		printf("got signal %d ???\r\n", sig);
	}
}

void slate_exit()
{
	terminal_exit();
}

void slate_start()
{
	atexit(slate_exit);

	signal(SIGWINCH, resize_handler);

	terminal_start();
}

int main(int argc, char** argv)
{
	slate_start();

	for(;;)
	{
		terminal_clear();

		int w, h;
		terminal_get_size(&w, &h);
		printf("size is %dx%d\r\n", w, h);

		input_event_t key = read_input();
		if(key.key != 0)
		{
			if(key.key == CTRL_KEY('q'))
			{
				exit(0);
			}
		}
	}

	return 0;
}
