
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t mutex_a;
pthread_mutex_t mutex_b;

void    *thread_one(void *arg)
{
    (void)arg;
    pthread_mutex_lock(&mutex_a);
    printf("Thread 1: locked A\n");
    usleep(1000000);

    printf("Thread 1: waiting for B\n");
    pthread_mutex_lock(&mutex_b);

    pthread_mutex_unlock(&mutex_b);
    pthread_mutex_unlock(&mutex_a);
    return (NULL);
}

void    *thread_two(void *arg)
{
    (void)arg;
    pthread_mutex_lock(&mutex_b);
    printf("Thread 2: locked B\n");
    usleep(1000000);

    printf("Thread 2: waiting for A\n");
    pthread_mutex_lock(&mutex_a);

    pthread_mutex_unlock(&mutex_a);
    pthread_mutex_unlock(&mutex_b);
    return (NULL);
}

int main(void)
{
    pthread_t t1;
    pthread_t t2;

    pthread_mutex_init(&mutex_a, NULL);
    pthread_mutex_init(&mutex_b, NULL);

    pthread_create(&t1, NULL, thread_one, NULL);
    pthread_create(&t2, NULL, thread_two, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex_a);
    pthread_mutex_destroy(&mutex_b);
    return (0);
}
