#include "coders/codexion.h"

void print_simulation(t_simulation *sim)
{
    printf("\n========== SIMULATION ==========\n");
    printf("Number of coders: %d\n", sim->number_of_coders);
    printf("Time to burnout: %d ms\n", sim->time_to_burnout);
    printf("Time to compile: %d ms\n", sim->time_to_compile);
    printf("Time to debug: %d ms\n", sim->time_to_debug);
    printf("Time to refactor: %d ms\n", sim->time_to_refactor);
    printf("Compiles required: %d\n", sim->number_of_compiles_required);
    printf("Dongle cooldown: %d ms\n", sim->dongle_cooldown);
    printf("Scheduler: %s\n", sim->scheduler);
    printf("Start time: %lld\n", sim->start_time);
    printf("================================\n");
}

void print_coders(t_simulation *sim)
{
    int i;

    printf("\n========== CODERS ==========\n");
    i = 0;
    while (i < sim->number_of_coders)
    {
        printf("Coder ID: %d\n", sim->coders[i].id);
        printf("State: %d\n", sim->coders[i].state);
        printf("Compile count: %d\n", sim->coders[i].compile_count);
        printf("Last compile time: %lld\n",
            sim->coders[i].last_compile_time);
        i++;
    }
    printf("============================\n");
}

void print_dongles(t_simulation *sim)
{
    int i;

    printf("\n========== DONGLES ==========\n");
    i = 0;
    while (i < sim->number_of_coders)
    {
        printf("Dongle ID: %d\n", i);
        printf("Available: %d\n", sim->dongles[i].available);
        i++;
    }
    printf("=============================\n");
}

void print_initialization(t_simulation *sim)
{
    print_simulation(sim);
    print_coders(sim);
    print_dongles(sim);
}