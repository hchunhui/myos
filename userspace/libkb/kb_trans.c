#include "kb_state.h"

#ifdef SCANCODE2
const char kb_ascii[2][128] =
{
	{
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,'\t','`',0,0,
	0,0,0,0,'q','1',0,0,0,'z','s','a','w','2',0,0,
	'c','x','d','e','4','3',0,0,' ','v','f','t','r','5',0,0,
	'n','b','h','g','y','6',0,0,0,'m','j','u','7','8',0,0,
	',','k','i','o','0','9',0,0,'.','/','l',';','p','-',0,0,
	0,'\'',0,'[','=',0,0,0,0,'\n',']',0,'\\',0,0,0,
	0,0,0,0,0,'\b',0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0x1b,0,0,0,0,0,0,0,0,0,
	},
	{
	0,
	0,0,0,0,0,0,0,0,0,0,0,0,'\t','~',0,0,
	0,0,0,0,'Q','!',0,0,0,'Z','S','A','W','@',0,0,
	'C','X','D','E','$','#',0,0,' ','V','F','T','R','%',0,0,
	'N','B','H','G','Y','^',0,0,0,'M','J','U','&','*',0,0,
	'<','K','I','O',')','(',0,0,'>','?','L',':','P','_',0,0,
	0,'"',0,'{','+',0,0,0,0,'\n','}',0,'|',0,0,0,
	0,0,0,0,0,'\b',0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0x1b,0,0,0,0,0,0,0,0,0,
	},
};

struct kb_state *kb_trans(unsigned short gcode, unsigned short brk)
{
	static struct kb_state kbs;
	int func = 0;
	int ch = 0;
	int leds = kbs.leds;
	int
		lsh = !!(kbs.state & KBS_LSH),
		rsh = !!(kbs.state & KBS_RSH),
		lct = !!(kbs.state & KBS_LCT),
		rct = !!(kbs.state & KBS_RCT),
		lal = !!(kbs.state & KBS_LAL),
		ral = !!(kbs.state & KBS_RAL),
		lgu = !!(kbs.state & KBS_LGU),
		rgu = !!(kbs.state & KBS_RGU);
	switch(gcode)
	{
		/* 辅助键 */
	case 0x0012: lsh = !brk; break;
	case 0x0059: rsh = !brk; break;
	case 0x0014: lct = !brk; break;
	case 0xe014: rct = !brk; break;
	case 0x0011: lal = !brk; break;
	case 0xe011: ral = !brk; break;
	case 0xe01f: lgu = !brk; break;
	case 0xe027: rgu = !brk; break;
		/* 锁定键 */
	case 0x0077: if(!brk) leds ^= KBL_NUM; break;
	case 0x0058: if(!brk) leds ^= KBL_CAP; break;
	case 0x007e: if(!brk) leds ^= KBL_SCR; break;
		/* 功能键 */
	case 0x0005: func = KB_F1; break;
	case 0x0006: func = KB_F2; break;
	case 0x0004: func = KB_F3; break;
	case 0x000c: func = KB_F4; break;
	case 0x0003: func = KB_F5; break;
	case 0x000b: func = KB_F6; break;
	case 0x0083: func = KB_F7; break;
	case 0x000a: func = KB_F8; break;
	case 0x0001: func = KB_F9; break;
	case 0x0009: func = KB_F10; break;
	case 0x0078: func = KB_F11; break;
	case 0x0007: func = KB_F12; break;

	case 0xe075: func = KB_ARU; break;
	case 0xe072: func = KB_ARD; break;
	case 0xe06b: func = KB_ARL; break;
	case 0xe074: func = KB_ARR; break;

	case 0xe06c: func = KB_HOME; break;
	case 0xe069: func = KB_END; break;
	case 0xe07d: func = KB_PGUP; break;
	case 0xe07a: func = KB_PGDN; break;
	case 0xe070: func = KB_INS; break;
	case 0xe071: func = KB_DEL; break;
		/* 普通键 */
	default:
		if (lsh || rsh) {
			ch = kb_ascii[1][gcode & 0x7f];
			if (leds & KBL_CAP)
				ch = tolower(ch);
		} else {
			ch = kb_ascii[0][gcode & 0x7f];
			if (leds & KBL_CAP)
				ch = toupper(ch);
		}
	}
	kbs.ch = ch;
	kbs.func = func;
	kbs.leds = leds;
	kbs.state = 
		brk |
		(lsh << 8) |
		(rsh << 9) |
		(lct << 10) |
		(rct << 11) |
		(lal << 12) |
		(ral << 13) |
		(lgu << 14) |
		(rgu << 15);
	return &kbs;
}
#else

const char kb_ascii[2][128] =
{
	{
		0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b', '\t',
		'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', 0,
		'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0, '\\',
		'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, 0, 0, ' ',
	},
	{
		0, 0, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '\b', '\t',
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n', 0,
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"', '~', 0, '|',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', 0, 0, 0, ' ',
	},
};

struct kb_state *kb_trans(unsigned short gcode, unsigned short brk)
{
	static struct kb_state kbs;
	int func = 0;
	int ch = 0;
	int leds = kbs.leds;
	int
		lsh = !!(kbs.state & KBS_LSH),
		rsh = !!(kbs.state & KBS_RSH),
		lct = !!(kbs.state & KBS_LCT),
		rct = !!(kbs.state & KBS_RCT),
		lal = !!(kbs.state & KBS_LAL),
		ral = !!(kbs.state & KBS_RAL),
		lgu = !!(kbs.state & KBS_LGU),
		rgu = !!(kbs.state & KBS_RGU);
	switch(gcode)
	{
		/* 辅助键 */
	case 42: lsh = !brk; break;
	case 54: rsh = !brk; break;
	case 29: lct = !brk; break;
	case 97: rct = !brk; break;
	case 56: lal = !brk; break;
	case 100: ral = !brk; break;
	case 125: lgu = !brk; break;
	case 126: rgu = !brk; break;
		/* 锁定键 */
	case 69: if(!brk) leds ^= KBL_NUM; break;
	case 58: if(!brk) leds ^= KBL_CAP; break;
	case 70: if(!brk) leds ^= KBL_SCR; break;
		/* 功能键 */
	case 59: func = KB_F1; break;
	case 60: func = KB_F2; break;
	case 61: func = KB_F3; break;
	case 62: func = KB_F4; break;
	case 63: func = KB_F5; break;
	case 64: func = KB_F6; break;
	case 65: func = KB_F7; break;
	case 66: func = KB_F8; break;
	case 67: func = KB_F9; break;
	case 68: func = KB_F10; break;
	case 87: func = KB_F11; break;
	case 88: func = KB_F12; break;

	case 103: func = KB_ARU; break;
	case 108: func = KB_ARD; break;
	case 105: func = KB_ARL; break;
	case 106: func = KB_ARR; break;

	case 102: func = KB_HOME; break;
	case 107: func = KB_END; break;
	case 104: func = KB_PGUP; break;
	case 109: func = KB_PGDN; break;
	case 110: func = KB_INS; break;
	case 111: func = KB_DEL; break;
		/* 普通键 */
	default:
		if (lsh || rsh) {
			ch = kb_ascii[1][gcode & 0x7f];
			if (leds & KBL_CAP)
				ch = tolower(ch);
		} else {
			ch = kb_ascii[0][gcode & 0x7f];
			if (leds & KBL_CAP)
				ch = toupper(ch);
		}
	}
	kbs.ch = ch;
	kbs.func = func;
	kbs.leds = leds;
	kbs.state =
		brk |
		(lsh << 8) |
		(rsh << 9) |
		(lct << 10) |
		(rct << 11) |
		(lal << 12) |
		(ral << 13) |
		(lgu << 14) |
		(rgu << 15);
	return &kbs;
}

#endif
