#include <stdio.h>

#define W 20
#define H 20
#define S 3

int d = 1; //-2, -1, 1 left, 2 up
int a_x = 5;
int a_y = 5;

int (*r)(int max) = &(rand() % max);

enum Thing {
    Segment,
    Apple
}

struct Cons {
    struct Cons* next;
    struct Cons* printnext;
    Thing type = Segment;

    int x = 0;
    int y = 0;
    Cons* n(int count) {
        if (!count) {return;}
        return n(count - 1);
    }
    Cons* incr() {
        Cons ret = *this;
        ret->x += d % 2;
        ret->y += d / 2;
    }
};

Cons* gen_Cons(int count) {
    Cons* ret = new Cons;
    if (count) 
        ret->readnext = ret->next = gen_Cons(count - 1);
    return ret;
}

Cons* back = gen_Cons(S); //a linked list order for left to right top to bottom
Cons* front = back.n(S);
Cons* printfront = 

void clrscr() {
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
    printf("");
}
    
void loop() {
    chrono::sleep_for(milliseconds(200))
    clrscr();
    if (front->x == ax && front->y == ay) {
        //apple
        score++;
        ax = r(s); ay = r(s);
        return;
    }
    //here we need to:
    //-gen new seg in front
    //-set it as next to last seg
    //-put it in front of correct printseg (hard), don't worry abt efficiency really
    //-put it in front of //left off thinking about this
    front->next = incr();
    if (front->printnext = 
    front = front->next;
    back = back-> next;
    
}


int main(void) {
    for(int i = 0; i < 100; i++)    {
        clrscr();
        printf("Bye   World\r");
        printf("Hello");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    } 
  return 0;
}