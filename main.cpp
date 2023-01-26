#include <thread>
#include <stdio.h>
#include <cstring>
#include <chrono>
#include <cstdlib>

//-30 bytes if you remove spacing between outputs
//-14 if you make the screen 3x3 instead, replacing all 400s with 9s and 20s with 3s
//(a) -9 if scoring is removed (s var)
//-1 or -2 if you make the output rate verty high
//-30 if you make the output rate the same speed as your pc
//-1 if the apple's value is just added/subtracted to BY a one digit number and modded into 400 range
//-18 if the screen buffer is never cleared :) (not recommended)
//(b) -27 if the back of the snake stays glued to the ground and keeps lengthening
//-2 extra if (a) and (b) are both done
//-16 if you think the snake should segfault when hitting the top and bottom wall instead of exiting and showing the score

using namespace std;
typedef int I;
I d=1,s=0,A=9,i;
char o[400],u,a;
struct C {
    C*h=0;
    I l=0;
};
C*b=new C;C*f=b;
I v(){
    for(;;){
        a=getchar();
        u=a=='\n'?u:a;
    }
}
I main(){
    thread T(v);
    for(;;){
        memset(o,' ',400);
        C*c=b;
        for(;c;){
            o[A]='x';
            if (o[c->l]=='O'|f->l>400|f->l<0)
                exit(s);
            o[c->l]='O';
            c=c->h;
        }
        for(i=0;i<400;i++)
            printf(i%20?"%c":"%c\n",o[i]);
        this_thread::sleep_for(400ms);
        for(i=0;i<20;i++)printf("\n");
        d=u=u=='d'?1:u=='a'?-1:u=='w'?-20:u=='s'?20:d;
        f=f->h=new C(*f);
        f->l+=d;
        if(f->l==A){
            s++;
            A=rand()%400;
        }else{
            C*p=b;
            b=b->h;
            delete p;
        }
    }
}