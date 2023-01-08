#include <stdio.h>
#include <cstring>
#include <chrono>
#include <thread>
#include <cstdlib>
//yeeter
#define W 20
#define H 20
#define S 3

int d = 1; //-2, -1, 1 left, 2 up
int score = 0;
int a_x = 5;
int a_y = 5;
char output[H][W];

auto r = [](int max) -> int{return rand() % max;};

struct Cons {
    struct Cons* next = nullptr;
    int x = 0;
    int y = 0;
    Cons* n(int count) {
        if (!count) {return this;}
        return n(count - 1);
    }
    Cons* incr() {
        Cons* ret = new Cons(*this);
        ret->x += d % 2;
        ret->y += d / 2;
        ret->next = nullptr;
        return ret;
    }
};

Cons* gen_Cons(int count) {
    Cons* ret = new Cons;
    if (count) 
        ret->next = gen_Cons(count - 1);
    return ret;
}

Cons* back = gen_Cons(S); //a linked list order for left to right top to bottom
Cons* front = back->n(S);

void clrscr() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
    
void game() {
    while(true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
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
        front->next = front->incr();
        front = front->next;
        Cons* temp = back;
        back = back->next;
        delete temp;
        Cons* curr = back;
        while (curr) {
            char &p = output[curr->y][curr->x];
            if (p == 'O') {
                break; //die
            }
            p = 'O';
            curr->next;
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                printf("%c", output[i][j]);
            }
            printf("\n");
        }
    }
}


int main(void) {
    memset(output,' ', W*H);
    // for(int i = 0; i < 100; i++)    {
    //     clrscr();
    //     printf("Bye   World\r");
    //     printf("Hello");
    //     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    // }
    game();
    return score;
}