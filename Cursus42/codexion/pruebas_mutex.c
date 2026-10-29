#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int listo; 
} ContextoCompartido;

void* funcion_hilo_espera(void* arg) {
    ContextoCompartido* ctx = (ContextoCompartido*)arg;
    printf("[Hilo Espera] Iniciado. Esperando que los datos estén listos...\n");
    pthread_mutex_lock(&ctx->mutex);
    while (ctx->listo == 0) {
		pthread_cond_wait(&ctx->cond, &ctx->mutex);
    }
	printf("[Hilo Espera] ¡Alerta recibida! Procesando datos compartidos...\n");
	pthread_mutex_unlock(&ctx->mutex);
    printf("[Hilo Espera] Terminado.\n");
    return NULL;
}

void* funcion_hilo_aporta(void* arg) {
	ContextoCompartido* ctx = (ContextoCompartido*)arg;
    printf("[Hilo Aporta] Iniciado. Trabajando en la tarea (simulación de 2 segundos)...\n");
	sleep(2);
    pthread_mutex_lock(&ctx->mutex);
	ctx->listo = 1;
    printf("[Hilo Aporta] Tarea lista. Enviando señal...\n");
    pthread_cond_signal(&ctx->cond);
	pthread_mutex_unlock(&ctx->mutex);
    printf("[Hilo Aporta] Terminado.\n");
    return NULL;
}

int main() {
    pthread_t hilo1, hilo2;
    ContextoCompartido ctx;
	ctx.listo = 0;
	pthread_cond_init(&ctx.cond, NULL);
	pthread_mutex_init(&ctx.mutex, NULL);
	pthread_create(hilo1, NULL, funcion_hilo_espera, &ctx);
	pthread_create(hilo2, NULL, funcion_hilo_aporta, &ctx);
    pthread_join(hilo1, NULL);
	pthread_join(hilo2, NULL);
    pthread_mutex_destroy(&ctx.mutex);
	pthread_cond_init(&ctx.cond, NULL);
    printf("[Main] Programa principal terminado con éxito.\n");
    return 0;
}
