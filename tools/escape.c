/*ʵΪprintf ��������չӦ��

�������ֱ�����ɫ;������ɫm�ַ���

int ESC =27;

ptintf("%c[����"��ESC);
*/
 

//cusor_ctrl.h
#ifndef __CUSOR_CTRL_H_
#define __CUSOR_CTRL_H_

#include <stdio.h>
#include <stdlib.h>

#define     COLOR_RED              31
#define     COLOR_BLACK            30
#define     COLOR_GREEN            32
#define     COLOR_BLUE             34
#define     COLOR_YELLOW           33
#define     COLOR_WHITE            37
#define     COLOR_CYAN             36
#define     COLOR_MAGENTA          35
int ESC = 27;
//����
void clear_screen(void);
//����ӹ��λ�õ���ĩ������
void clear_to_end(void);
//����ƶ���(x,y)
void cusor_moveto(int x, int y);
//������λ��
void cusor_get_pos(void);
//�ָ����λ��
void cusor_set_pos(void);
//�������num��
void cusor_up(int num);
//�������num��
void cusor_down(int num);
//�������num���ַ�
void cusor_lift(int num);
//�������num���ַ�
void cusor_right(int num);
//����ǰ����ɫ
void set_fg_color(int color);
//���ñ�����ɫ
void set_bg_color(int color);

#endif //__CUSOR_CTRL_H_
int main()
{
    int x=0;int y = 0;
    int color=31;
    clear_screen();   
    cusor_moveto(20,10);
    while(1)
    {
        cusor_get_pos();
        printf("(20,10)");
        fflush(stdout);
        sleep(1);
        cusor_up(5);
        sleep(1);
        cusor_down(5);
        sleep(1);
        cusor_right(5);
        sleep(1);
        cusor_lift(5);
        sleep(1);
        cusor_moveto(50,10);
        printf("(50,10)\n");
        sleep(1);
        set_bg_color(COLOR_BLACK);
        set_fg_color(COLOR_RED);
        printf("\ngood morning\n");
        sleep(1);
        set_bg_color(COLOR_YELLOW);
        set_fg_color(COLOR_GREEN);
        printf("gaorenwei\n");
       cusor_set_pos();
    }
    return 0;
}
void clear_screen(void)
{    printf("%c[2J",ESC);
 fflush(stdout);
}
void clear_to_end(void)
{  
 printf("%c[K",ESC);
 fflush(stdout);
}
void cusor_moveto(int x, int y)
{// ESC[y;xH  
 printf("%c[%d;%dH",ESC,y,x);   
 fflush(stdout);
}
void cusor_get_pos(void)
{// ESC[s    printf("%c[s",ESC);  
 fflush(stdout);
}
 //�ָ����λ��
void cusor_set_pos(void)
{// ESC[u   
printf("%c[u",ESC);  
 fflush(stdout);
}
//�������num��
void cusor_up(int num)
{   
while(num--)   
{ // up =  ESC[A        
printf("%c[A",ESC);  
 }      
 fflush(stdout);
}
//�������num��
void cusor_down(int num)
{  
 while(num--)  
 {// down = ESC[B      
 printf("%c[B",ESC);                  
 }    fflush(stdout);}
//�������num���ַ�
void cusor_lift(int num)
{   
while(num--)   
{// lift = ESC[D       
printf("%c[D",ESC);                 
  }  
 fflush(stdout);
}
//�������num���ַ�
void cusor_right(int num)
{   
while(num--)   
{// right = ESC[C      
 printf("%c[C",ESC);                
   }  
 fflush(stdout);
}
//����ǰ����ɫ
void set_fg_color(int color)
{// ESC[#m  
 printf("%c[%dm",ESC,color);  
 fflush(stdout);
}
//���ñ�����ɫ
void set_bg_color(int color)
{// ESC[#m   
printf("%c[%dm",ESC,(color+10)); 
  fflush(stdout);
} 
