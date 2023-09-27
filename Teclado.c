#include "MKL25Z4.h"

const int filas = 4;
const int columnas = 4;

const int pinesFilas[4] = {12, 13, 16, 17};
const int pinesColumnas[4] = {7, 0, 3, 4};

int tecla;
int pulsado = 0;

char teclas[4][4] = {
  { '1','2','3', 'A' },
  { '4','5','6', 'B' },
  { '7','8','9', 'C' },
  { '#','0','*', 'D' }
};

void keypad_cfg(){
    SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
    PORTC->PCR[pinesColumnas[0]] = PORT_PCR_MUX(0) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
    PORTC->PCR[pinesColumnas[1]] = PORT_PCR_MUX(0) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
    PORTC->PCR[pinesColumnas[2]] = PORT_PCR_MUX(0) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
    PORTC->PCR[pinesColumnas[3]] = PORT_PCR_MUX(0) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
    PORTC->PCR[pinesFilas[0]] = PORT_PCR_MUX(1);
    PORTC->PCR[pinesFilas[1]] = PORT_PCR_MUX(1);
    PORTC->PCR[pinesFilas[2]] = PORT_PCR_MUX(1);
    PORTC->PCR[pinesFilas[3]] = PORT_PCR_MUX(1);
}

char keypad_read(){
    PTC->PSOR |= (1u<<pinesFilas[0]);
    PTC->PSOR |= (1u<<pinesFilas[1]);
    PTC->PSOR |= (1u<<pinesFilas[2]);
    PTC->PSOR |= (1u<<pinesFilas[3]);
    while(1){
        for(int f = 0; f < filas; f++){
            PTC->PCOR |= (1<<pinesFilas[f]);  
            for(int c = 0; c < columnas; c++){ 
                if(!(PTC->PDIR & (1<<pinesColumnas[c]))){
                    tecla = teclas[f][c];
                }
            }
            PTC->PSOR |= (1<<pinesFilas[f]); 
        }
        return tecla;
    }
}
