#ifndef _INPUT_H
#define _INPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "terminal.h"

#define CTRL_KEY(k) ((k) & 0x1f)

typedef enum
{
	KEY_LAST_CHAR = 127,
	HOME_KEY,
	INS_KEY,
	DEL_KEY,
	END_KEY,
	ESC_KEY,
	PAGE_UP,
	PAGE_DOWN,
	ARROW_UP,  
	ARROW_DOWN,
	ARROW_RIGHT,
	ARROW_LEFT,
	KEY_F1,
	KEY_F2,
	KEY_F3,
	KEY_F4,
	KEY_F5,
	KEY_F6,
	KEY_F7,
	KEY_F8,
	KEY_F9,
	KEY_F10,
	KEY_F11,
	KEY_F12
} input_key_t;

typedef struct
{
	input_key_t key;
} input_event_t;

char read_char();
input_event_t read_input();

#endif
