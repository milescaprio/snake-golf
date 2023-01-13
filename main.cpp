#include <thread>
#include <stdio.h>
#include <cstring>
#include <chrono>
#include <cstdlib>
using namespace std;
typedef int I;
I d=1,s=0,X=5,Y=5,i,j;
char o[20][20],u,a;
struct C {
    C*h=0;
    I x=0,y=0;
};
C*b=new C;C*f=b;
void v(){
    for(;;){
        a=getchar();
        if(a!='\n')
        u=a;
    }
}
I main(){
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
        f->h=new C(*f);
        f=f->h;
        f->x+=d%2;
        f->y+=d/2;
        if(f->x>19|f->y>19|f->y<0|f->x<0)exit(s);
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