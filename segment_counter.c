#include <reg52.h>

#define SEG P2  // Define Port 2 as the port connected to the seven-segment display
sbit sw=P1^0;
unsigned char count=0;

// Function prototypes
void delay(unsigned int time);
void display(unsigned char num);

// Seven-segment display code map for digits 0-9
unsigned char code seven_seg_digits[] = {
    0xC0, // 0
    0xF9, // 1
    0xA4, // 2
    0xB0, // 3
    0x99, // 4
    0x92, // 5
    0x82, // 6
    0xF8, // 7
    0x80, // 8
    0x90  // 9
};

void main(void) {
		sw=0;
		SEG = seven_seg_digits[0];
    while (1) {
			if(sw==1){
				if(count==9){
					count=0;
					display(count);
				}
				else{					
					count++;
					display(count);
        }
				delay(50);
    }
}
}

// Function to provide delay
void delay(unsigned int time) {
    unsigned int i, j;
    for (i = 0; i < time; i++) {
        for (j = 0; j < 1275; j++);
    }
}

// Function to display a number on the seven-segment display
void display(unsigned char num) {
    SEG = seven_seg_digits[num];
}
