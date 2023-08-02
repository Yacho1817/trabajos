#include "mbed.h"
#include "Serial.h"
#include "MKL25Z4.h"
int RS;
int RW;
int DB7;
int DB6;
int DB5;
int DB4;
int DB3;
int DB2;
int DB1;
int DB0;
int estadoRS = PTE->PDIR & (1<<RS);
int estadoRW = PTE->PDIR & (1<<RW);
int estadoDB7 = PTE->PDIR & (1<<DB7);
int estadoDB6 = PTE->PDIR & (1<<DB6);
int estadoDB5 = PTE->PDIR & (1<<DB5);
int estadoDB4 = PTE->PDIR & (1<<DB4);
int estadoDB3 = PTE->PDIR & (1<<DB3);
int estadoDB2 = PTE->PDIR & (1<<DB2);
int estadoDB1 = PTE->PDIR & (1<<DB1);
int estadoDB0 = PTE->PDIR & (1<<DB0);


void inputLCD(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j){
    SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
    PORTE->PCR[RS] |= PORT_PCR_MUX(1);
    PORTE->PCR[RW] |= PORT_PCR_MUX(1);
    PORTE->PCR[DB7] |= PORT_PCR_MUX(1);
    PORTE->PCR[DB6] |= PORT_PCR_MUX(1);
    PORTE->PCR[DB5] |= PORT_PCR_MUX(1);
    PORTE->PCR[DB4] |= PORT_PCR_MUX(1);
    PORTE->PCR[DB3] |= PORT_PCR_MUX(1);
    PORTE->PCR[DB2] |= PORT_PCR_MUX(1);
    PORTE->PCR[DB1] |= PORT_PCR_MUX(1);
    PORTE->PCR[DB0] |= PORT_PCR_MUX(1);
    RS = a;
    RW = b;
    DB7 = c;
    DB6 = d;
    DB5 = e;
    DB4 = f;
    DB3 = g;
    DB2 = h;
    DB1 = i;
    DB0 = j;
}

void clearDisplay(){
    PTE -> PCOR |= (1<<RS);
    PTE -> PCOR |= (1<<RW);
    PTE -> PCOR |= (1<<DB7);
    PTE -> PCOR |= (1<<DB6);
    PTE -> PCOR |= (1<<DB5);
    PTE -> PCOR |= (1<<DB4);
    PTE -> PCOR |= (1<<DB3);
    PTE -> PCOR |= (1<<DB2);
    PTE -> PCOR |= (1<<DB1);
    PTE -> PSOR |= (1<<DB0);
}

void returnHome(){
    PTE -> PCOR |= (1<<RS);
    PTE -> PCOR |= (1<<RW);
    PTE -> PCOR |= (1<<DB7);
    PTE -> PCOR |= (1<<DB6);
    PTE -> PCOR |= (1<<DB5);
    PTE -> PCOR |= (1<<DB4);
    PTE -> PCOR |= (1<<DB3);
    PTE -> PCOR |= (1<<DB2);
    PTE -> PSOR |= (1<<DB1);
    PTE -> PCOR |= (1<<DB0);
}

void returnHome(){
    PTE -> PCOR |= (1<<RS);
    PTE -> PCOR |= (1<<RW);
    PTE -> PCOR |= (1<<DB7);
    PTE -> PCOR |= (1<<DB6);
    PTE -> PCOR |= (1<<DB5);
    PTE -> PCOR |= (1<<DB4);
    PTE -> PCOR |= (1<<DB3);
    PTE -> PCOR |= (1<<DB2);
    PTE -> PSOR |= (1<<DB1);
    PTE -> PCOR |= (1<<DB0);
}

void entryModeSet(int direction, int shift){

    PTE -> PCOR |= (1<<RS);
    PTE -> PCOR |= (1<<RW);
    PTE -> PCOR |= (1<<DB7);
    PTE -> PCOR |= (1<<DB6);
    PTE -> PCOR |= (1<<DB5);
    PTE -> PCOR |= (1<<DB4);
    PTE -> PCOR |= (1<<DB3);
    PTE -> PSOR |= (1<<DB2);
    if(direction == right){
        PTE -> PSOR |= (1<<DB1);
    } else if(direction == left) {
        PTE -> PCOR |= (1<<DB1);
    }
    PTE -> PSOR |= (estadoDB1<<DB1);
    PTE -> PSOR |= (estadoDB0<<DB0);
}

void displayControl(){
    PTE -> PCOR |= (1<<RS);
    PTE -> PCOR |= (1<<RW);
    PTE -> PCOR |= (1<<DB7);
    PTE -> PCOR |= (1<<DB6);
    PTE -> PCOR |= (1<<DB5);
    PTE -> PCOR |= (1<<DB4);
    PTE -> PSOR |= (1<<DB3);
    PTE -> PSOR |= (estadoDB2<<DB2);
    PTE -> PSOR |= (estadoDB1<<DB1);
    PTE -> PSOR |= (estadoDB0<<DB0);
}

void displayShift(){
    PTE -> PCOR |= (1<<RS);
    PTE -> PCOR |= (1<<RW);
    PTE -> PCOR |= (1<<DB7);
    PTE -> PCOR |= (1<<DB6);
    PTE -> PCOR |= (1<<DB5);
    PTE -> PSOR |= (1<<DB4);
    PTE -> PSOR |= (estadoDB3<<DB3);
    PTE -> PSOR |= (estadoDB2<<DB2);
    PTE -> PCOR |= (1<<DB1);
    PTE -> PCOR |= (1<<DB0);
}

void functionSet(){
    PTE -> PCOR |= (1<<RS);
    PTE -> PCOR |= (1<<RW);
    PTE -> PCOR |= (1<<DB7);
    PTE -> PCOR |= (1<<DB6);
    PTE -> PSOR |= (1<<DB5);
    PTE -> PSOR |= (estadoDB4<<DB4);
    PTE -> PSOR |= (estadoDB3<<DB3);
    PTE -> PSOR |= (estadoDB2<<DB2);
    PTE -> PCOR |= (1<<DB1);
    PTE -> PCOR |= (1<<DB0);
}

void displayShift(){
    PTE -> PCOR |= (1<<RS);
    PTE -> PCOR |= (1<<RW);
    PTE -> PCOR |= (1<<DB7);
    PTE -> PCOR |= (1<<DB6);
    PTE -> PCOR |= (1<<DB5);
    PTE -> PSOR |= (1<<DB4);
    PTE -> PSOR |= (estadoDB3<<DB3);
    PTE -> PSOR |= (estadoDB2<<DB2);
    PTE -> PCOR |= (1<<DB1);
    PTE -> PCOR |= (1<<DB0);
}

void displayShift(){
    PTE -> PCOR |= (1<<RS);
    PTE -> PCOR |= (1<<RW);
    PTE -> PCOR |= (1<<DB7);
    PTE -> PCOR |= (1<<DB6);
    PTE -> PCOR |= (1<<DB5);
    PTE -> PSOR |= (1<<DB4);
    PTE -> PSOR |= (estadoDB3<<DB3);
    PTE -> PSOR |= (estadoDB2<<DB2);
    PTE -> PCOR |= (1<<DB1);
    PTE -> PCOR |= (1<<DB0);
}

