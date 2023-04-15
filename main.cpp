#include <thread>
#include <stdio.h>
#include <cstring>
#include <chrono>
#include <cstdlib>

//-30 bytes if you remove spacing between outputs
//-14 if you make the screen 3x3 instead, replacing all 400s with 9s and 20s with 3s
//-2 if all 400 substituted with 100 and all 20 substituted with 10, then reuse of F for the character comparison
//(a) -9 if scoring is removed (s var)
//-1 or -2 if you make the output rate verty high
//-30 if you make the output rate the same speed as your pc
//-1 if the apple's value is just added/subtracted to BY a one digit number and modded into 400 range
//-18 if the screen buffer is never cleared :) (not recommended)
//(b) -27 if the back of the snake stays glued to the ground and keeps lengthening
//-2 extra if (a) and (b) are both done
//-16 if you think the snake should segfault when hitting the top and bottom wall instead of exiting and showing the score
//
// might be outdated ^
// 
//-9 if memory leaks
//+17 or less to make the gap happen before the sleep (either change to two for loops or offset the big one by 20 for
//the index and change the checks to the bottom)
//+~16 to make the complex logic of the keypresses filter misinputs
//~-5 if apple pseudorandom with mod 99 instead of rand()
//-2 if made to 21 and 441 cuz then could use (x&2)*10+1 instead of (x>100)*19+1, the problem is 19 is odd
// 
//(done) -1 used less than instead
//458
using namespace std;
using I=int;
I d=1,s=0,A=9,F=400;
char o[400],u,a;
struct C{
    C*h=0;
    I l=0;
};
I main(){
    thread T([]{
        for(;a=getchar();)u=a<97?u:a;
        });
    for(C*b=new C,*f=b;memset(o,46,F);){
        I i=0;
        for(C*c=b;c;o[c->l]=79,c=c->h)if(o[c->l]==79|f->l>=F|f->l<0)exit(s);
        for(o[A]=120;i<F+20;++i)printf(i<F&&i%20?"%c":"\n%c",(i<F)*o[i]);
        this_thread::sleep_for(400ms);
        d=((u>100)*19+1)*(2*!(u%5)-1);
        f=f->h=new C(*f);
        if((f->l+=d)==A)++s,A=rand()%F;
        else{
            C*p=b;
            b=b->h;
            delete p;
        }
    }
}