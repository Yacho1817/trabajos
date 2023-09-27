#include <TECLADO.h>

int main(){
    printf("Hola");
    keypad_cfg();
    char tecla = keypad_read();
    if(tecla){
        printf("Tecla '%d' presionada", tecla);
    }
}
