#include <stdio.h>
#include <stdlib.h>
#define MAX_APPLICATIONS 20


typedef unsigned Worker;

typedef struct Application{
Worker worker;
struct Application *next;
} Application;

void apply(Application *app, int worker_number, int counter);
void hire(Application **app);
void free_application(Application* app);

int main(){
    Application *application;
    application = calloc(1, sizeof(Application));
    application->next = NULL;
    application->worker = 0;
    apply(application, 1, 0);
    apply(application, 1, 0);
    hire(&application);
    apply(application, 1, 0);
    apply(application, 1, 0);
    hire(&application);
    hire(&application);
    free_application(application);
    return 0;
}
void apply(Application *app, int worker_number, int counter){
    if(counter >= MAX_APPLICATIONS){
        printf("Applications are full!\n");
        return;
    }else if(app->next == NULL && app->worker == 0){
        app->worker = worker_number;
        printf("Person %i Applied to the job!\n", app->worker);
        app->next = calloc(1, sizeof(Application));
        app = app->next;
        app->next = NULL;
        app->worker = 0;
        
        return ;

    }
    apply(app->next, app->worker + 1, counter + 1);   
}
void hire(Application **app){
    Application *tmp = *app;
    if ((*app)->next == NULL && (*app)->worker == 0){
        printf("Applications Empty !\n");
        return ;
    }
    printf("Hired Worker %i!\n", (*app)->worker);
    (*app) = (*app)->next;

    free(tmp);
    return ;
}
void free_application(Application* app){
if (app->next == NULL && app->worker == 0){
        free(app);
        return ;
    }
    free_application(app->next);
    free(app);
    return;
}
