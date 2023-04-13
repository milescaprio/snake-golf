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
//-9 if memory leaks
// 
//(done) -16 by obfuscation of character to direction conversion
//(done) -2 by swapping F and 400
//(done) -1 by double-initialize
using namespace std;
typedef int I;
I d=1,s=0,A=9,i,F=400;
char o[400],u,a;
struct C {
    C*h=0;
    I l=0;
};
C*b=new C,*f=b;
I main(){
    thread T([]{for(;;){
        a=getchar();
        u=a=='\n'?u:a;
    }});
    for(;;){
        memset(o,' ',F);
        C*c=b;
        for(;c;){
            o[A]='x';
            if (o[c->l]=='O'|f->l>F|f->l<0)
                exit(s);
            o[c->l]='O';
            c=c->h;
        }
        for(i=0;i<F;i++)
            printf(i%20?"%c":"%c\n",o[i]);
        this_thread::sleep_for(400ms);
        for(i=0;i<20;i++)printf("\n");
        d=((u>100)*19+1)*(2*!(u%5)-1);
        f=f->h=new C(*f);
        f->l+=d;
        if(f->l==A){
            s++;
            A=rand()%F;
        }else{
            C*p=b;
            b=b->h;
            delete p;
        }
    }
}