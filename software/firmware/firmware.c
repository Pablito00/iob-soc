#include "system.h"
#include "periphs.h"
#include "iob-gpio.h"
#include "iob-uart.h"
#include "printf.h"


// copy src to dst
// return number of copied chars (excluding '\0')
int string_copy(char *dst, char *src) {
    if (dst == NULL || src == NULL) {
        return -1;
    }
    int cnt = 0;
    while(src[cnt] != 0){
        dst[cnt] = src[cnt];
        cnt++;
    }
    dst[cnt] = '\0';
    return cnt;
}

// 0: same string
// otherwise: different
int compare_str(char *str1, char *str2, int str_size) {
    int c = 0;
    while(c < str_size) {
        if (str1[c] != str2[c]){
            return str1[c] - str2[c];
        }
        c++;
    }
    return 0;
}

int main()
{

  uint32_t a = 0;

  //init uart
  uart_init(UART_BASE,FREQ/BAUD);

  //test puts
  uart_puts("\n\n\nHello world!\n\n\n");

  //test printf with floats 
  printf("Value of Pi = %f\n\n", 3.1415);

  gpio_init(GPIO_BASE);

  a = gpio_get(16);

  printf("algo = %d", a);

 // gpio_set();

  uart_finish();
}
