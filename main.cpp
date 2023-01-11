#include <thread>
#include <stdio.h>
#include <cstring>
#include <chrono>
#include <cstdlib>

//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOO                                OOOO//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//

//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//
//OOOOOOO                              OOOOOOO//
//OOOOOOO  OOOOOOOOOOOOOOOOOOOOOOOOOO  OOOOOOO//
//OOOOOOO  OO                      OO  OOOOOOO//
//OOOOOOO  OO                      OO  OOOOOOO//
//OOOOOOO  OO              OOOOOO  OO  OOOOOOO//
//OOOOOOO  OO              OO  OO  OO  OOOOOOO//
//OOOOOOO  OO              OO  OO  OO  OOOOOOO//
//OOOOOOO  OO   x OOOOO    OO  OO  OO  OOOOOOO//
//OOOOOOO  OO        OO    OO  OO  OO  OOOOOOO//
//OOOOOOO  OO        OO    OO  OO  OO  OOOOOOO//
//OOOOOOO  OO        OO    OO  OO  OO  OOOOOOO//
//OOOOOOO  OO        OO    OO  OO  OO  OOOOOOO//
//OOOOOOO  OO        OOOOOOOO  OO  OO  OOOOOOO//
//OOOOOOO  OO                  OOOOOO  OOOOOOO//
//OOOOOOO  OO                          OOOOOOO//
//OOOOOOO                              OOOOOOO//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//
//OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO//


using namespace std;typedef int I;I d=1,s=0,
X=5,Y=5,i,j;char o[20][20],u;struct C{C*h=0;
I x=0,y=0;void Z(){h=new C(*this);h->x+=d%2;
h->y+=d/2;}};C*b=new C,*f;void g(C*t,I N){if
(     !                              N){f=t;
return; }t->Z();g(t->h,N-1);}void v( ){for(;
;){char a=getchar();if(a!='\n')u=a;}}
I main(){g(b
,5);thread T(v);for(;;){memset(o,' ',400);C*c=
    b;
        while(c){
            char&p=o[c->y][c->x];
            o[Y][X] = 'x';
            if (p=='O') {
                exit(s);
            }
            p='O';
            c=c->h;
        }
        for(i=0;i<20;i++){
            for(j=0;j<20;j++){
                printf("%c",o[i][j]);
            }
            printf("\n");
        }
        this_thread::sleep_for(400ms);
        for(i=0;i<20;i++)printf("\n");
        if(u=='d')d=1;
        if(u=='a')d=-1;
        if(u=='w')d=-2;
        if(u=='s')d=2;
        u=0;
        f->Z();
        f=f->h;
        if(f->x>19|f->y>19|f->y<0|f->x<0) exit(s);
        if(f->x==X&f->y==Y){
            s++;
            X=rand()%20;Y=rand()%20;
        }else{
            C*p=b;
            b=b->h;
            delete p;
        }
    }
}