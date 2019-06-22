#include "input.h"

char read_char()
{
	char c = 0;
	read(STDIN_FILENO, &c, 1);
	return c;
}

input_event_t read_input()
{
	input_event_t res;
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
					case '1': res.key = HOME_KEY;  break;
					case '2': res.key = INS_KEY;   break;
					case '3': res.key = DEL_KEY;   break;
					case '4': res.key = END_KEY;   break;
					case '5': res.key = PAGE_UP;   break;
					case '6': res.key = PAGE_DOWN; break;
					case '7': res.key = HOME_KEY;  break;
					case '8': res.key = END_KEY;   break;
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
						case '5': res.key = KEY_F5;  break;
						case '7': res.key = KEY_F6;  break;
						case '8': res.key = KEY_F7;  break;
						case '9': res.key = KEY_F8;  break;
						case '0': res.key = KEY_F9;  break;
						case '1': res.key = KEY_F10; break;
						case '3': res.key = KEY_F11; break;
						case '4': res.key = KEY_F12; break;
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
				case 'A': res.key = ARROW_UP;    break;
				case 'B': res.key = ARROW_DOWN;  break;
				case 'C': res.key = ARROW_RIGHT; break;
				case 'D': res.key = ARROW_LEFT;  break;
				case 'H': res.key = HOME_KEY;    break;
				case 'F': res.key = END_KEY;     break;
				default: printf(FG_RED "Unknown other escape '%c' (%d)" RESET "\r\n", esc1, esc1); break;
				}
			}
		}
		else if(esc0 == 'O')
		{
			switch(esc1)
			{
			case 'H': res.key = HOME_KEY; break;
			case 'F': res.key = END_KEY;  break;
			case 'P': res.key = KEY_F1;   break;
			case 'Q': res.key = KEY_F2;   break;
			case 'R': res.key = KEY_F3;   break;
			case 'S': res.key = KEY_F4;   break;
			default: printf(FG_RED "Unknown O escape '%c' (%d)" RESET "\r\n", esc1, esc1); break;
			}
		}
		else if(esc0 == 0)
		{
			res.key = ESC_KEY;
		}
		else
		{
			printf(FG_RED "Unknown escape sequence '%c' (%d)" RESET "\r\n", esc0, esc0);
		}
	}
	else
	{
		res.key = c;
	}

	return res;
}
