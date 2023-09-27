#include <TECLADO.h>

int main(){
    printf("Hola");
    keypad_cfg();
    char tecla = keypad_read();
    if(tecla){
        printf("Tecla '%d' presionada", tecla);
    }
}

// No pudimos probar el teclado, por lo que fue imposible implementar la contraseña
