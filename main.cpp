#include <stdio.h>
#include <cstring>
#include <chrono>
#include <thread>
#include <cstdlib>
//yeeter
#define W 20
#define H 20
#define S 5

int d = 1; //-2, -1, 1 left, 2 up
int score = 0;
int a_x = 5;
int a_y = 5;
char output[H][W];

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
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
    
void game() {
    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        clrscr();
        if (front->x == a_x && front->y == a_y) {
            //eat apple
            score++;
            a_x = r(W); a_y = r(H);
            continue;
        }
        //here we need to:
        //-gen new seg in front
        //-set it as next to last seg
        //-if not eaten apple, 
            //-free back and set new back to its ptr simulatenously
        front->next = front->incr(); //create a new front
        front = front->next; //traverse it
        Cons* temp = back; //save old back
        printf("%i   %i   %i\n",back->n(0)->x,back->n(1)->x,back->n(2)->x);
        printf("%i, %i, %i\n", back->y, back->x, (size_t)(back->next));
        back = back->next; //traverse back
        delete temp; //free old back
        memset(output,' ', W*H); //clear buffer
        Cons* curr = back; //start here for iteration
        int i = 0;
        while (curr) {
            i++;
            printf("%i, %i, %i\n", curr->y, curr->x, (size_t)(curr->next));
            char &p = output[curr->y][curr->x];
            if (p == 'O') {
                printf("death");
                break; //die
            }
            p = 'O';
            curr = curr->next;
            printf("%i", (size_t)curr);
        }
        printf("%i", i);
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                printf("%c", output[i][j]);
            }
            printf("\n");
        }
    }
}


int main(void) {
    back->gen_Cons(S); //creates S + 1 linked Cons
    //printf("%i   %i   %i\n",back->n(0)->x,back->n(1)->x,back->n(2)->x);
    //return 0;
    front = back->n(S); //get the address of the last Cons, Sth and there's S+1
    // for(int i = 0; i < 100; i++)    {
    //     clrscr();
    //     printf("Bye   World\r");
    //     printf("Hello");
    //     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    // }
    game();
    return score;
}