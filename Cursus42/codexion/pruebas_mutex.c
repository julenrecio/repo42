#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// 1. Definimos una estructura con todo el contexto compartido
typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int listo;  // El predicado (la condición que vigilamos)
} ContextoCompartido;

// 2. Función del Hilo A (El que espera que los datos estén listos)
void* funcion_hilo_espera(void* arg) {
    ContextoCompartido* ctx = (ContextoCompartido*)arg;

    printf("[Hilo Espera] Iniciado. Esperando que los datos estén listos...\n");

    // Bloqueamos el mutex antes de leer la variable compartida
    pthread_mutex_lock(&ctx->mutex);
    
    while (ctx->listo == 0) {
        // Se duerme de forma eficiente y libera el mutex para que el otro hilo pueda trabajar
        pthread_cond_wait(&ctx->cond, &ctx->mutex);
    }
    
    // Al despertar, este hilo vuelve a tener el mutex bloqueado automáticamente
    printf("[Hilo Espera] ¡Alerta recibida! Procesando datos compartidos...\n");
    
    pthread_mutex_unlock(&ctx->mutex); // Liberamos el mutex al terminar

    printf("[Hilo Espera] Terminado.\n");
    return NULL;
}

// 3. Función del Hilo B (El que prepara los datos y avisa)
void* funcion_hilo_aporta(void* arg) {
    ContextoCompartido* ctx = (ContextoCompartido*)arg;

    printf("[Hilo Aporta] Iniciado. Trabajando en la tarea (simulación de 2 segundos)...\n");
    sleep(2); // Simula que hace algún cálculo o lectura de disco

    // Bloqueamos el mutex para modificar la variable compartida de forma segura
    pthread_mutex_lock(&ctx->mutex);
    
    ctx->listo = 1; // Cambiamos el estado del predicado
    printf("[Hilo Aporta] Tarea lista. Enviando señal...\n");
    
    // Despertamos al hilo que está esperando en la condición
    pthread_cond_signal(&ctx->cond);
    
    pthread_mutex_unlock(&ctx->mutex); // Liberamos el mutex

    printf("[Hilo Aporta] Terminado.\n");
    return NULL;
}

int main() {
    // 4. Declaramos los identificadores de los pthreads
    pthread_t hilo1, hilo2;

    // 5. Inicializamos el contexto y sus mecanismos de sincronización
    ContextoCompartido ctx;
    ctx.listo = 0;
    pthread_mutex_init(&ctx.mutex, NULL);
    pthread_cond_init(&ctx.cond, NULL);

    // 6. Creamos e integramos los hilos pasándoles el puntero a la estructura compartida
    pthread_create(&hilo1, NULL, funcion_hilo_espera, &ctx);
    pthread_create(&hilo2, NULL, funcion_hilo_aporta, &ctx);

    // 7. Esperamos a que ambos hilos finalicen su ejecución
    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);

    // 8. Limpiamos los recursos de sincronización
    pthread_mutex_destroy(&ctx.mutex);
    pthread_cond_init(&ctx.cond, NULL);

    printf("[Main] Programa principal terminado con éxito.\n");
    return 0;
}
