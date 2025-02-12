#include <stdio.h> // Biblioteca padrão da linguagem C
#include "pico/stdlib.h" // Subconjunto central de bibliotecas do SDK Pico
#include "hardware/pwm.h" //biblioteca para controlar o hardware de PWM

#define PWM_PIN 22// Pino conectado a GPIO como PWM
#define WRAP 59999 // Valor máximo do contador
#define DIVIDER 41.6666666666667 // Divisor do clock para o PWM

// Valores de periodo ativo do Duty Cycle
#define degree_180 7200 // Aproximadamente 2400 μs
#define degree_90 4410 // Aproximadamente 1470 μs
#define degree_0 1500 // Aproximadamente 500 μs
# define step 15 // Aproximadamente 5 μs
uint16_t level = degree_0; // Nível do duty cycle a ser alterado durante o programa
uint32_t atraso; // Tempo inicial

void pwm_setup() {
    
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM); // Habilitar o pino GPIO como PWM
    uint slice = pwm_gpio_to_slice_num(PWM_PIN); // Obtem o canal PWM da GPIO
    pwm_set_clkdiv(slice, DIVIDER); // Define o divisor de clock do PWM
    pwm_set_wrap(slice, WRAP); // Define o valor de wrap
    pwm_set_gpio_level(PWM_PIN, degree_180); // Define o ciclo de trabalho ativo do pwm para 2400 μs
    pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente

}

//rotina principal
int main() {

    stdio_init_all(); // Inicializa o sistema padrão de I/O

    // Servo motor a 180 graus
    pwm_setup(); // Configura o PWM
    sleep_ms(5000); // Espera 5 segundos

    // Servo motor a 90 graus
    pwm_set_gpio_level(PWM_PIN, degree_90); // Define o ciclo de trabalho ativo do pwm para 1470 μs
    sleep_ms(5000); // Espera 5 segundos

    pwm_set_gpio_level(PWM_PIN, degree_0); // Define o ciclo de trabalho ativo do pwm para 500 μs
    sleep_ms(5000); // Espera 5 segundos
    // Rotina para movimentação periódica do braço do servomotor entre os ângulos de 0 e 180 graus.
    uint8_t increase = 1; // Variável para controlar se o DC aumenta ou diminui

    // Loop principal
    while (true) {
        atraso = to_ms_since_boot(get_absolute_time()-atraso); // Calcula o tempo decorrido
        printf("%d, %d\n", level, atraso); // Imprime o nível atual do PWM e o atraso entre mudanças
        pwm_set_gpio_level(PWM_PIN, level); // Define o nível atual do PWM (duty cycle)
        if (increase) {
            level += step; // Incrementa o tempo ativo do duty cycle
            if (level >= degree_180) {
                increase = 0; // Muda direção para diminuir quando atingir 180 graus
            }
        } else {
            level -= step; // Decrementa o tempo ativo do duty cycle
            if (level <= degree_0) {
                increase = 1; // Muda direção para aumentar quando atingir 0 graus
            }
        }
        atraso = get_absolute_time();
        sleep_ms(10); // Atraso de 10 millissegundos
    }
}
