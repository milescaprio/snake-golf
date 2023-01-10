#include <thread>
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
    C*n(I N) {
        if (!N)return this;
        return h->n(N-1);
    }
    V Z() {
        C*R=new C(*this);
        R->x+=d%2;
        R->y+=d/2;
        h=R;
    } 
    V g(I N) {
        if(!N)return;
        Z();
        h->g(N-1);
    }
};
C*b=new C;
C*f;
V v(){
    while(1) {
        L a=getchar();
        if(!(a=='\n'|a=='\r'|a==' '))
        u=a;
    }
}
I main() {
    b->g(5);
    f=b->n(5);
    thread T(v);
    while(1) {
        memset(o,' ',400);
        C*c=b;
        while (c) {
            L&p=o[c->y][c->x];
            o[Y][X] = 'x';
            if (p=='O') {
                exit(s);
            }
            p='O';
            c=c->h;
        }
        for (I i=0;i<20;i++) {
            for (I j=0;j<20;j++) {
                printf("%c",o[i][j]);
            }
            printf("\n");
        }
        this_thread::sleep_for(200ms);
        for(I i=0;i<20;i++)printf("\n");
        if(u=='d')d=1;
        if(u=='a')d=-1;
        if(u=='w')d=-2;
        if(u=='s')d=2;
        u=0;
        f->Z();
        f=f->h;
        if (f->x>19|f->y>19|f->y<0|f->x<0) {
            exit(s);
        }
        if(f->x==X&f->y==Y) {
            s++;
            X=r();Y=r();
            continue;
        }
        C*p=b;
        b=b->h;
        delete p;
    }
}