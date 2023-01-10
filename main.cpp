#include <stdio.h>
#include <chrono>
#include <thread>
#include <cstdlib>
using namespace std;
int d=1; //-2, -1, 1 left, 2 up
int score=0;
int a_x=5;
int a_y=5;
char output[20][20];
char input;
bool open=true;

int r(){return rand()%20;}
void loop(int a, void (*f)(int)) {
    for (int i=0;i<a;i++){f(i);}
}
class Cons {
public:
    Cons* next=0;
    int x=0;
    int y=0;
    Cons* n(int count) {
        //indexes the current con by n, like a normal array.
        if(!count){return this;}
        return next->n(count-1);
    }
    void incr() {
        //makes a copy of the current Cons and links it to the current one
        //make sure next is 0
        Cons* ret=new Cons(*this);
        ret->x+=d%2;
        ret->y+=d/2;
        next=ret;
    } 
    void gen_Cons(int count) {
        //make sure to free next before calling
        //creates count extra Cons parts here, c ... 1
        //links from : here to c ... 2 to 1
        // Cons* ret = new Cons;
        // if (count) 
        //     ret->next = gen_Cons(count - 1);
        // return ret;
        if (!count){return;}
        incr();
        next->gen_Cons(count-1);
    }
};

Cons* back = new Cons; //a linked list order for left to right top to bottom 
Cons* front;

void receive(){
    while(1) {
        char a=getchar();
        if (!(a=='\n'||a=='\r'||a==' '))
        input = a;
    }
}

int main(void) {
    back->gen_Cons(5); //creates S + 1 linked Cons
    front=back->n(5); //get the address of the last Cons, Sth and there's S+1

    thread rec(receive);
    while(1) {
        memset(output,' ',400); //clear buffer
        Cons* curr = back; //start here for iteration
        while(curr) {
            char& p=output[curr->y][curr->x];
            if (curr->x>20||curr->y>20||curr->y<0||curr->x<0) {
                return score; //die
            }
            output[a_y][a_x] = 'x';
            if (p=='O') {
                return score; //die
            }
            p='O';
            curr=curr->next;
        }
        for (int i=0;i<20;i++) {
            for (int j=0;j<20;j++) {
                printf("%c",output[i][j]);
            }
            printf("\n");
        }

        this_thread::sleep_for(200ms);

        for(int i=0;i<20;i++)printf("\n");
        if(input=='d')d=1;
        if(input=='a')d=-1;
        if(input=='w')d=-1;
        if(input=='s')d=2;
        input=0;

        front->incr(); //create a new front
        front=front->next; //traverse it
        if(front->x==a_x&&front->y==a_y) {
            //eat apple
            score++;
            a_x=r();a_y=r();
            continue;
        }
        Cons* temp=back; //save old back
        back=back->next; //traverse back
        delete temp; //free old back
    }
}