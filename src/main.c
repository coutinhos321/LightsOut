//#define LED1
//#define LED2
//#define LED3
//#define LED4
//#define LED5
#define LEDS
//#define SEVSEG

#include <stdbool.h> // booleans, i.e. true and false
#include <stdio.h>   // sprintf() function (not used)
#include <stdlib.h>  // srand() and random() functions  (not used)
#include "ece198.h"

int main(void){
    HAL_Init(); // initialize the Hardware Abstraction Layer

    __HAL_RCC_GPIOA_CLK_ENABLE(); // enable port A (for the on-board LED, for example)
    __HAL_RCC_GPIOB_CLK_ENABLE(); // enable port B (for the rotary encoder inputs, for example)
    __HAL_RCC_GPIOC_CLK_ENABLE(); // enable port C (for the on-board blue pushbutton, for example)

    SerialSetup(9600); // set up for serial communication to the host computer (anything we write to the serial port will appear in the terminal (i.e. serial monitor) in VSCode)

//troubleshooting LED 1-5
        #ifdef LED1
            InitializePin(GPIOB, GPIO_PIN_8, GPIO_MODE_INPUT, GPIO_NOPULL, 0); //button B8
            InitializePin(GPIOB, GPIO_PIN_9, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0); //LED B9oy   
            while (true) {
                    while (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8));   // wait for button press 
                    while (!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8));  // wait for button release
                    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9);
            }
        #endif

        #ifdef LED2
            InitializePin(GPIOA, GPIO_PIN_5, GPIO_MODE_INPUT, GPIO_NOPULL, 0); //button A5
            InitializePin(GPIOA, GPIO_PIN_6, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0); //LED A6
            while (true) {
                    while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5));   // wait for button press 
                    while (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5));  // wait for button release
                    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
            }
        #endif

        #ifdef LED3
            InitializePin(GPIOB, GPIO_PIN_6, GPIO_MODE_INPUT, GPIO_NOPULL, 0); //button b6
            InitializePin(GPIOC, GPIO_PIN_7, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0); //LED c7

            while (true) {
                    while (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6));   // wait for button press 
                    while (!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6));  // wait for button release
                    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_7);
            }
        #endif

        #ifdef LED4
            InitializePin(GPIOA, GPIO_PIN_8, GPIO_MODE_INPUT, GPIO_NOPULL, 0); //button A8
            InitializePin(GPIOB, GPIO_PIN_10, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0);//LED B10
                   
            while (true) {
                    while (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8));   // wait for button press 
                    while (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8));  // wait for button release
                    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
            }
        #endif

        #ifdef LED5
            InitializePin(GPIOB, GPIO_PIN_5, GPIO_MODE_INPUT, GPIO_NOPULL, 0); //button B5
            InitializePin(GPIOB, GPIO_PIN_3, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0);//LED B3
                   
            while (true) {
                    while (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5));   // wait for button press 
                    while (!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5));  // wait for button release
                    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
            }
        #endif

//main code block to play the game
        #ifdef LEDS
            InitializePin(GPIOB, GPIO_PIN_8, GPIO_MODE_INPUT, GPIO_NOPULL, 0); //button B8
            InitializePin(GPIOB, GPIO_PIN_9, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0); //LED B9
            
            InitializePin(GPIOA, GPIO_PIN_5, GPIO_MODE_INPUT, GPIO_NOPULL, 0); //button A5
            InitializePin(GPIOA, GPIO_PIN_6, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0); //LED A6
            
            InitializePin(GPIOB, GPIO_PIN_6, GPIO_MODE_INPUT, GPIO_NOPULL, 0); //button B6
            InitializePin(GPIOC, GPIO_PIN_7, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0); //LED C7
            
            InitializePin(GPIOA, GPIO_PIN_8, GPIO_MODE_INPUT, GPIO_NOPULL, 0); //button A8
            InitializePin(GPIOB, GPIO_PIN_10, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0);//LED B10
            
            InitializePin(GPIOB, GPIO_PIN_5, GPIO_MODE_INPUT, GPIO_NOPULL, 0); //button B5
            InitializePin(GPIOB, GPIO_PIN_3, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0);//LED B3

            bool b1p = false;
            bool b2p = false;
            bool b3p = false;
            bool b4p = false;
            bool b5p = false;

        while(true){
            if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) && (!b1p)){
                HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9); //led 1
                HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6); //led 2
                HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3); //led 5
            }
            b1p = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);

            if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5) && (!b2p)){
                HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6); //led 2
                HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9); //led 1
                HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_7); //led 3
            }
            b2p = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5);

            if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) && (!b3p)){
                HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_7); //led 3
                HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6); //led 2
                HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10); //led 4
            }
            b3p = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6);

            if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8) && (!b4p)){
                HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10); //led 4
                HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_7); //led 3
                HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3); //led 5
            }
            b4p = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8);

            if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5) && (!b5p)){
                HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3); //led 5
                HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10); //led 4
                HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9); //led 1
            }
            b5p = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);
            
            if((HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9)==1) && (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6)==1) && (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7)==1) && 
               (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10)==1) && (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3)==1))
            {
                for (int i = 1; i<10; i++)
                {
                    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9); //led 1
                    HAL_Delay(20);
                    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6); //led 2
                    HAL_Delay(20);
                    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_7); //led 3
                    HAL_Delay(20);
                    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10); //led 4
                    HAL_Delay(20);
                    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3); //led 5
                    HAL_Delay(20);
                } 
                Initialize7Segment();
    
                while (true){
                    int i = 3;
                    Display7Segment(i);
                    HAL_Delay(1000);  // 1000 milliseconds == 1 second
                }
                break;  
            }
        }
        #endif
//troubleshooting 7-segment LCD display
        #ifdef SEVSEG
         Initialize7Segment();
         while (true){
            int i = 4;
            Display7Segment(i);
            HAL_Delay(1000);  // 1000 milliseconds == 1 second
         }
        #endif
    return 0;
}

// This function is called by the HAL once every millisecond
void SysTick_Handler(void){
    HAL_IncTick(); // tell HAL that a new tick has happened
    // we can do other things in here too if we need to, but be careful
}
