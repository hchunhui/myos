/* scanf.c */
#include <os/type.h>
#include <os/unistd.h>
#include <libc/libc.h>
#include <lib/string.h>
#define INBUF_LEN 1024
#define TMPBUF_LEN 256
struct s_inbuf
{
	char *p,*q;
	char buf[INBUF_LEN];
	int count;
};
struct s_inbuf inbuf;

void inbuf_init()
{
	//printf("addr=%x addr2=%x\n",inbuf.p,&(inbuf.buf[0]));
	inbuf.p=&(inbuf.buf[0]);
	inbuf.q=inbuf.p;
	inbuf.count=0;
}

static int inbuf_empty()
{
	return inbuf.count<=0;
}

static int inbuf_full()
{
	return inbuf.count>=INBUF_LEN;
}

static void inbuf_put()
{
	char tmpbuf[TMPBUF_LEN];
	char* p=tmpbuf;
	getline(tmpbuf);
	for(;*p;p++)
	{
		*(inbuf.q++)=*p;
		inbuf.count++;
		if(inbuf.q>&(inbuf.buf[INBUF_LEN-1]))
			inbuf.q=&(inbuf.buf[0]);
	}
}

static char inbuf_get()
{
	char key;
	if(inbuf.count<=0)inbuf_put();
	key=*(inbuf.p++);
	inbuf.count--;
	if(inbuf.p>&(inbuf.buf[INBUF_LEN-1]))
		inbuf.p=&(inbuf.buf[0]);
	return key;
}

static void inbuf_unget()
{
	inbuf.p--;
	inbuf.count++;
	if(inbuf.p<&(inbuf.buf[0]))inbuf.p=&(inbuf.buf[INBUF_LEN-1]);
}

/* from OpenBSD begin */
/*
 * Convert a string to a long integer.
 *
 * Ignores `locale' stuff.  Assumes that the upper and lower case
 * alphabets and digits are each contiguous.
 */
 /* 2009-10-07 change */
#define LONG_MIN (-2147483647-1)
#define LONG_MAX (2147483647)
long
mystrtol(const char *nptr, /*char **endptr,*/ int base)
{
        char **endptr=(char **)0;
		const char *s;
		
        long acc, cutoff;
        int c;
        int neg, any, cutlim;

        /*
         * Skip white space and pick up leading +/- sign if any.
         * If base is 0, allow 0x for hex and 0 for octal, else
         * assume decimal; if base is already 16, allow 0x.
         */
        s = nptr;
        do {
                c = (unsigned char) *s++;
        } while (isspace(c));
        if (c == '-') {
                neg = 1;
                c = *s++;
        } else {
                neg = 0;
                if (c == '+')
                        c = *s++;
        }
        if ((base == 0 || base == 16) &&
            c == '0' && (*s == 'x' || *s == 'X')) {
                c = s[1];
                s += 2;
                base = 16;
        }
        if (base == 0)
                base = c == '0' ? 8 : 10;

        /*
         * Compute the cutoff value between legal numbers and illegal
         * numbers.  That is the largest legal value, divided by the
         * base.  An input number that is greater than this value, if
         * followed by a legal input character, is too big.  One that
         * is equal to this value may be valid or not; the limit
         * between valid and invalid numbers is then based on the last
         * digit.  For instance, if the range for longs is
         * [-2147483648..2147483647] and the input base is 10,
         * cutoff will be set to 214748364 and cutlim to either
         * 7 (neg==0) or 8 (neg==1), meaning that if we have accumulated
         * a value > 214748364, or equal but the next digit is > 7 (or 8),
         * the number is too big, and we will return a range error.
         *
         * Set any if any `digits' consumed; make it negative to indicate
         * overflow.
         */
        cutoff = neg ? LONG_MIN : LONG_MAX;
        cutlim = cutoff % base;
        cutoff /= base;
        if (neg) {
                if (cutlim > 0) {
                        cutlim -= base;
                        cutoff += 1;
                }
                cutlim = -cutlim;
        }
        for (acc = 0, any = 0;; c = (unsigned char) *s++) {
                if (isdigit(c))
                        c -= '0';
                else if (isalpha(c))
                        c -= isupper(c) ? 'A' - 10 : 'a' - 10;
                else
                        break;
                if (c >= base)
                        break;
                if (any < 0)
                        continue;
                if (neg) {
                        if (acc < cutoff || (acc == cutoff && c > cutlim)) {
                                any = -1;
                                acc = LONG_MIN;
                                //errno = ERANGE;
                        } else {
                                any = 1;
                                acc *= base;
                                acc -= c;
                        }
                } else {
                        if (acc > cutoff || (acc == cutoff && c > cutlim)) {
                                any = -1;
                                acc = LONG_MAX;
                                //errno = ERANGE;
                        } else {
                                any = 1;
                                acc *= base;
                                acc += c;
                        }
                }
        }
        if (endptr != 0)
                *endptr = (char *) (any ? s - 1 : nptr);
        return (acc);
}
/* from OpenBSD end */
#define in_area(ch,base) (((ch)>='0' && (ch)<='9') || ((ch)>='a' && (ch)<='a'+(base-11)) ||((ch)>='A' && (ch)<='A'+(base-11)))
void get_strnum(char* buf,int base)
{
	do *buf=inbuf_get();
	while( (!in_area(*buf,base)) && (!inbuf_empty()) );
	if(in_area(*buf,base))inbuf_unget();
	while(1)
	{
		*(buf)=inbuf_get();
		if( !in_area(*buf,base) )
			{
				*buf='\0';
				inbuf_unget();
				return;
			}
		buf++;
	}
}

void get_string(char* buf)
{
	do *buf=inbuf_get();
	while( (*buf==' ' || *buf=='\n') && (!inbuf_empty()) );
	if(*buf!=' ' && *buf!='\n')inbuf_unget();
	while(1)
	{
		*(buf)=inbuf_get();
		if( *buf==' ' || *buf=='\n' )
		{
			*buf='\0';
			inbuf_unget();
			return;
		}
		buf++;
	}
}

#define BEGIN (1<<0)
#define IGNORE (1<<1)

int scanf(const char* fmt,...)
{
	va_list ap;
	char buf[TMPBUF_LEN]="";
	int flag=0;
	va_start(ap, fmt);
	for(;*fmt;fmt++)
	{
		if(*fmt=='%')
		{
			flag|=BEGIN;
			continue;
		}
		if(flag&BEGIN)
		{
			int d,*dptr;
			char c,*cptr;
			
			switch(*fmt)
			{
				case 'd':
					get_strnum(buf,10);
					//printf("o:%s\n",buf);
					d=mystrtol(buf,10);
					if(!(flag&IGNORE))
					{
						dptr=va_arg(ap,int*);
						*dptr=d;
					}
					flag=0;
					continue;
				case 's':
					get_string(buf);
					//printf("ok\n");
					if(!(flag&IGNORE))
					{
						cptr=va_arg(ap,char*);
						strcpy(cptr,buf);
					}
					continue;
				case 'c':
					c=inbuf_get();
					if(!(flag&IGNORE))
					{
						cptr=va_arg(ap,char*);
						*cptr=c;
					}
					flag=0;
					continue;
				case 'x':
					get_strnum(buf,16);
					d=mystrtol(buf,16);
					if(!(flag&IGNORE))
					{
						dptr=va_arg(ap,int*);
						*dptr=d;
					}
					flag=0;
					continue;
				case '*':
					flag|=IGNORE;
					continue;
				default:
					continue;
			}
		}
	}
	va_end(ap);
	return 1;
}
