#include <stdio.h>
#include <stdlib.h>

#define MAX_BULLETS 20

typedef struct Bullets{
unsigned bullet;
struct Bullets* next;
}Bullets;

void charge(Bullets **bul);
void fire(Bullets **bul);
void free_magazine(Bullets* bul);

int main(){
	Bullets* magazine;
	magazine = calloc(1, sizeof(Bullets));
	magazine->bullet = 0;
	magazine->next = NULL;
	charge(&magazine);
	charge(&magazine);
	fire(&magazine);
	charge(&magazine);
	fire(&magazine);
	fire(&magazine);
	fire(&magazine);
	free_magazine(magazine);
	return 0;
}

void charge(Bullets **bul){
    if ((*bul)->bullet >= MAX_BULLETS){
      printf("Magazine is full!\n");  
    }
    Bullets *tmp = calloc(1,sizeof(Bullets));
    tmp->next = *bul;
    tmp->bullet = (*bul)->bullet+1;
    printf("Bullet %i Added !\n", (*bul)->bullet + 1);
    *(bul) = tmp;
    
}

void fire(Bullets **bul){
    Bullets *tmp = (*bul)->next;
    if ((*bul)->next == NULL){
        printf("Magazine is Empty !\n");
        return ;
    }else {
        printf("Fired Bullet %i!\n", (*bul)->bullet);
        free(*bul);
        (*bul) = tmp;
        return;
    }
}
void free_magazine(Bullets* bul){
    if (bul->next == NULL && bul->bullet == 0){
        free(bul);
        return ;
    }
    free_magazine(bul->next);
    free(bul);
    return;
}
