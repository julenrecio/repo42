#include "coders/codexion.h"

void* funcion_hilo_espera(void* arg) {
    t_dongle* d = (t_dongle*)arg;
    printf("[Hilo Espera] Iniciado. Esperando que los datos estén listos...\n");
    pthread_mutex_lock(&d->mutex);
    while (d->available == 0) {
		pthread_cond_wait(&d->cond, &d->mutex);
    }
	printf("[Hilo Espera] ¡Alerta recibida! Procesando datos compartidos...\n");
	pthread_mutex_unlock(&d->mutex);
    printf("[Hilo Espera] Terminado.\n");
    return NULL;
}

void* funcion_hilo_aporta(void* arg) {
	t_dongle* d = (t_dongle*)arg;
    printf("[Hilo Aporta] Iniciado. Trabajando en la tarea (simulación de 2 segundos)...\n");
	sleep(2);
    pthread_mutex_lock(&d->mutex);
	d->available = 1;
    printf("[Hilo Aporta] Tarea lista. Enviando señal...\n");
    pthread_cond_signal(&d->cond);
	pthread_mutex_unlock(&d->mutex);
    printf("[Hilo Aporta] Terminado.\n");
    return NULL;
}

int main() {
    pthread_t hilo1, hilo2;
    t_dongle d;
	d.available = 0;
	pthread_cond_init(&d.cond, NULL);
	pthread_mutex_init(&d.mutex, NULL);
	pthread_create(&hilo1, NULL, funcion_hilo_espera, &d);
	pthread_create(&hilo2, NULL, funcion_hilo_aporta, &d);
    pthread_join(hilo1, NULL);
	pthread_join(hilo2, NULL);
    pthread_mutex_destroy(&d.mutex);
    printf("[Main] Programa principal terminado con éxito.\n");
    return 0;
}
