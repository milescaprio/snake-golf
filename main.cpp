#include <thread>
#include <stdio.h>
#include <cstring>
#include <chrono>
#include <cstdlib>
using namespace std;
typedef int I;
typedef char L;
typedef void V;
I d=1;
I s=0;
I X=5;
I Y=5;
L o[20][20];
L u;
I r(){return rand()%20;}
struct C {
    C*h=0;
    I x=0;
    I y=0;
    //old//C*n(I N) {
    //old//    if (!N)return this;
    //old//    return h->n(N-1);
    //old//}
    V Z() {
        C*R=new C(*this);
        R->x+=d%2;
        R->y+=d/2;
        h=R;
    } 
    //old//V g(C*t,I N) {
    //old//    if(!N)return;
    //old//    Z();
    //old//    h->g(N-1);
    //old//}
};
C*b=new C;
C*f;
//new//V g(C*t,I N) {
//new//    if(!N){f=t;return;}
//new//    Z();
//new//    h->g(t,N-1);
//new//  }
V v(){
    for(;;){
        L a=getchar();
        if(a!='\n')
        u=a;
    }
}
I main() {
    //old//b->g(5);
    //new//g(b,5);
    //old//f=b->n(5);
    thread T(v);
    for(;;){
        memset(o,' ',400);
        C*c=b;
        while(c){
            L&p=o[c->y][c->x];
            o[Y][X] = 'x';
            if (p=='O') {
                exit(s);
            }
            p='O';
            c=c->h;
        }
        for(I i=0;i<20;i++) {
            for (I j=0;j<20;j++) {
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
            X=r();Y=r();
        } else {
            C*p=b;
            b=b->h;
            delete p;
        }
    }
}