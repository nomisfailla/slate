#include "terminal.h"

static struct termios old_terminal;

void enter_alt_screen()
{
	write(STDOUT_FILENO, "\033[?1049h\033[H", 11);
}

void leave_alt_screen()
{
	write(STDOUT_FILENO, "\033[?1049l", 8);
}

void terminal_clear()
{
	write(STDOUT_FILENO, "\x1b[2J", 4);
	write(STDOUT_FILENO, "\x1b[H", 3);
}

void terminal_start()
{
	tcgetattr(STDIN_FILENO, &old_terminal);
	struct termios new_terminal = old_terminal;

	enter_alt_screen();

	new_terminal.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	new_terminal.c_oflag &= ~(OPOST);
	new_terminal.c_cflag |= (CS8);
	new_terminal.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	new_terminal.c_cc[VMIN] = 0;
	new_terminal.c_cc[VTIME] = 1;

	tcsetattr(STDIN_FILENO, TCSAFLUSH, &new_terminal);
}

void terminal_exit()
{
	leave_alt_screen();

	tcsetattr(STDIN_FILENO, TCSAFLUSH, &old_terminal);
}
