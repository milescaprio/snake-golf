#include <stdio.h>
#include <chrono>
#include <thread>
#include <cstdlib>
#define W 20
#define H 20
#define S 5
using namespace std;

int d = 1; //-2, -1, 1 left, 2 up
int score = 0;
int a_x = 5;
int a_y = 5;
char output[H][W];
char input;
bool open = true;

auto r = [](int max) -> int{return rand() % max;};

class Cons {
public:
    Cons* next = nullptr;
    int x = 0;
    int y = 0;
    Cons* n(int count) {
        //indexes the current con by n, like a normal array.
        if (!count) {return this;}
        return next->n(count - 1);
    }
    Cons* incr() {
        //makes a copy of the current Cons and returns its pointer. 
        //copy is incremented by the snake direction
        //link the two together yourself.
        Cons* ret = new Cons(*this);
        ret->x += d % 2;
        ret->y += d / 2;
        ret->next = nullptr;
        return ret;
    } 
    void gen_Cons(int count) {
        //make sure to free next before calling
        //creates count extra Cons parts here, c ... 1
        //links from : here to c ... 2 to 1
        // Cons* ret = new Cons;
        // if (count) 
        //     ret->next = gen_Cons(count - 1);
        // return ret;
        if (!count) {return;}
        next = incr();
        next->gen_Cons(count-1);
    }
};



Cons* back = new Cons; //a linked list order for left to right top to bottom 
Cons* front;

void clrscr() {
    
}

void receive(){
    while(1) {
        char a = getchar();
        if (!(a == '\n' || a == '\r' || a == ' '))
        input = a;
    }
}

void game() {
    thread rec (receive);
    while(true) {
        memset(output, ' ', W * H); //clear buffer
        Cons* curr = back; //start here for iteration
        int i = 0;
        while (curr) {
            i++;
            if (curr->x > 20 || curr->y > 20 || curr->y < 0 || curr->x < 0) {
                printf("death");
                break;
            }
            char& p = output[curr->y][curr->x];
            output[a_y][a_x] = 'x';
            if (p == 'O') {
                printf("death");
                break; //die
            }
            p = 'O';
            curr = curr->next;
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                printf("%c", output[i][j]);
            }
            printf("\n");
        }

        this_thread::sleep_for(chrono::milliseconds(200));

        for(int i=0;i<20;i++)printf("\n");
        switch (input) {
            case 'd' : d = 1; break;
            case 'a' : d = -1; break;
            case 'w' : d = -2; break;
            case 's' : d = 2; break;
        }
        input = 0;

        front->next = front->incr(); //create a new front
        front = front->next; //traverse it
        if (front->x == a_x && front->y == a_y) {
            //eat apple
            score++;
            a_x = r(W); a_y = r(H);
            continue;
        }
        Cons* temp = back; //save old back
        back = back->next; //traverse back
        delete temp; //free old back
    }
}


int main(void) {
    back->gen_Cons(S); //creates S + 1 linked Cons
    front = back->n(S); //get the address of the last Cons, Sth and there's S+1
    game();
    return score;
}