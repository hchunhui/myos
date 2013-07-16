#ifndef _KB_STATE_H_
#define _KB_STATE_H_

/*
 * ch
 *    [1..127]  ascii key
 *    [256...]  func key
 *
 * state bit
 *        0      brk
 *        1      numpad
 *        8      lshift
 *        9      rshift
 *        10     lctrl
 *        11     rctrl
 *        12      lalt
 *        13      ralt
 *        14      lgui
 *        15      rgui
 *
 * leds  bit
 *        0      num lock
 *        1      caps lock
 *        2      scro lock
 */
struct kb_state {
	unsigned char ch;
	unsigned char func;
	unsigned short state;
	unsigned short leds;
};
#define KBS_BRK  0x0001
#define KBS_KP   0x0002
#define KBS_LSH  0x0100
#define KBS_RSH  0x0200
#define KBS_LCT  0x0400
#define KBS_RCT  0x0800
#define KBS_LAL  0x1000
#define KBS_RAL  0x2000
#define KBS_LGU  0x4000
#define KBS_RGU  0x8000
#define KBL_NUM  0x0001
#define KBL_CAP  0x0002
#define KBL_SCR  0x0004

#define KB_F1  0x11
#define KB_F2  0x12
#define KB_F3  0x13
#define KB_F4  0x14
#define KB_F5  0x15
#define KB_F6  0x16
#define KB_F7  0x17
#define KB_F8  0x18
#define KB_F9  0x19
#define KB_F10 0x1a
#define KB_F11 0x1b
#define KB_F12 0x1c
#define KB_ARU 0x20
#define KB_ARD 0x21
#define KB_ARL 0x22
#define KB_ARR 0x23
#define KB_HOME 0x24
#define KB_END  0x25
#define KB_PGUP 0x26
#define KB_PGDN 0x27
#define KB_INS  0x28
#define KB_DEL  0x29

struct kb_state *kb_trans(unsigned short gcode, unsigned short brk);
#endif /* _KB_STATE_H_ */
