#include <thread>
#include <stdio.h>
#include <cstring>
#include <chrono>
#include <cstdlib>
using namespace std;
typedef int I;
I d=1;
I s=0;
I X=5;
I Y=5;
char o[20][20];
char u;
struct C {
    C*h=0;
    I x=0;
    I y=0;
    void Z() {
        h=new C(*this);
        h->x+=d%2;
        h->y+=d/2;
    } 
};
C*b=new C;
C*f;
void g(C*t,I N) {
    if(!N){f=t;return;}
    t->Z();
    g(t->h,N-1);
}
void v(){
    for(;;){
        char a=getchar();
        if(a!='\n')
        u=a;
    }
}
I main(){
    g(b,5);
    thread T(v);
    for(;;){
        memset(o,' ',400);
        C*c=b;
        while(c){
            char&p=o[c->y][c->x];
            o[Y][X] = 'x';
            if (p=='O') {
                exit(s);
            }
            p='O';
            c=c->h;
        }
        for(I i=0;i<20;i++) {
            for(I j=0;j<20;j++) {
                printf("%c",o[i][j]);
            }
            printf("\n");
        }
        this_thread::sleep_for(300ms);
        for(I i=0;i<20;i++)printf("\n");
        if(u=='d')d=1;
        if(u=='a')d=-1;
        if(u=='w')d=-2;
        if(u=='s')d=2;
        u=0;
        f->Z();
        f=f->h;
        if(f->x>19|f->y>19|f->y<0|f->x<0) exit(s);
        if(f->x==X&f->y==Y) {
            s++;
            X=rand()%20;Y=rand()%20;
        }else{
            C*p=b;
            b=b->h;
            delete p;
        }
    }
}