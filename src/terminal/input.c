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
	
	if(c == 27)
	{
		char esc0 = read_char();
		char esc1 = read_char();
		
		if(esc0 == '[')
		{
			if(esc1 >= '0' && esc1 <= '9')
			{
				char esc2 = read_char();
				if(esc2 == '~')
				{
					switch(esc1)
					{
					case '1': printf("HOME_KEY; \r\n"); break;
					case '2': printf("INS_KEY;  \r\n"); break;
					case '3': printf("DEL_KEY;  \r\n"); break;
					case '4': printf("END_KEY;  \r\n"); break;
					case '5': printf("PAGE_UP;  \r\n"); break;
					case '6': printf("PAGE_DOWN;\r\n"); break;
					case '7': printf("HOME_KEY; \r\n"); break;
					case '8': printf("END_KEY;  \r\n"); break;
					default: printf(FG_RED "Unknown ~ escape '%c' (%d)" RESET "\r\n", esc1, esc1); break;
					}
				}
				else
				{
					char esc3 = read_char();
					if(esc3 == '~')
					{
						switch(esc2)
						{
						case '5': printf("KEY_F5; \r\n"); break;
						case '7': printf("KEY_F6; \r\n"); break;
						case '8': printf("KEY_F7; \r\n"); break;
						case '9': printf("KEY_F8; \r\n"); break;
						case '0': printf("KEY_F9; \r\n"); break;
						case '1': printf("KEY_F10;\r\n"); break;
						case '3': printf("KEY_F11;\r\n"); break;
						case '4': printf("KEY_F12;\r\n"); break;
						default: printf(FG_RED "Unknown esc2 case '%c' (%d)" RESET "\r\n", esc2, esc2); break;
						}
					}
					else
					{
						printf(FG_RED "Expected a tilde" RESET "\r\n");
					}
				}
			}
			else
			{
				switch (esc1)
				{
				case 'A': printf("ARROW_UP;   \r\n"); break;
				case 'B': printf("ARROW_DOWN; \r\n"); break;
				case 'C': printf("ARROW_RIGHT;\r\n"); break;
				case 'D': printf("ARROW_LEFT; \r\n"); break;
				case 'H': printf("HOME_KEY;   \r\n"); break;
				case 'F': printf("END_KEY;    \r\n"); break;
				default: printf(FG_RED "Unknown other escape '%c' (%d)" RESET "\r\n", esc1, esc1); break;
				}
			}
		}
		else if(esc0 == 'O')
		{
			switch(esc1)
			{
			case 'H': printf("HOME_KEY;\r\n"); break;
			case 'F': printf("END_KEY; \r\n"); break;
			case 'P': printf("KEY_F1;  \r\n"); break;
			case 'Q': printf("KEY_F2;  \r\n"); break;
			case 'R': printf("KEY_F3;  \r\n"); break;
			case 'S': printf("KEY_F4;  \r\n"); break;
			default: printf(FG_RED "Unknown O escape '%c' (%d)" RESET "\r\n", esc1, esc1); break;
			}
		}
		else
		{
			printf(FG_RED "Unknown escape sequence '%c' (%d)" RESET "\r\n", esc0, esc0);
		}
	}
	else
	{
		if(c != 0)
		{
			printf("char: '%c' dec: %d\r\n", c, c);
		}
		
		if(c == 'q' || c == 'Q')
		{
			exit(0);
		}
	}
}
