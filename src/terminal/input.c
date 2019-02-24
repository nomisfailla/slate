#include "input.h"

char read_char()
{
	char c = 0;
	read(STDIN_FILENO, &c, 1);
	return c;
}

void read_input()
{
	char c = read_char();
	
	if(c != 0)
	{
		printf("char: '%c' dec: %d\r\n", c, c);
	}
	
	if(c == 'q' || c == 'Q')
	{
		exit(0);
	}
}
