#include "LED_Controller.hpp"



void LED_Controller::SetupLCD(int redLED_pin, int greenLED_pin, int blueLED_pin) {
    //init Display
    tft.begin();
    tft.background(255, 255, 255);
    tft.stroke(0, 0, 0);
    tft.setTextSize(2);
    tft.setRotation(2);

    //init Taster
    DDRC &= ~0x0f;
    PORTC |= 0x0f;

    //Setup LEDS
    ledpins[0] = redLED_pin;
    ledpins[1] = greenLED_pin;
    ledpins[2] = blueLED_pin;
    
    for (uint8_t i = 0; i < 3; i++)
    {
    pinMode(ledpins[i], OUTPUT);
    digitalWrite(ledpins[i],LOW);
    }
}




void LED_Controller::UpdateLEDs(){

    if(animationsON)    //Animations are running
    {
        //do animaitons
    }
    else{
        for (unsigned char i = 0; i < 3; i++)
        {
            analogWrite(ledpins[i], colorValRGB[i]*brightnes/100);
        }
    }
    

}


void LED_Controller::checkButton() {

    static char buttonStateNow = 0, buttonStateLast[4] = {0};        // true = pressed
    static char _delay[4] = {25, 25, 25, 25}, counter[4] = {0};

    for (uint16_t i = 0; i < 4; i++)
    {
        buttonStateNow = !((PINC & (1 << i)) == (1 << i));

        if (buttonStateNow && (counter[i] >= _delay[i]))
        { 
            counter[i] = 0;

            if(!buttonStateLast[i])
                _delay[i] = 25;
            else
                _delay[i] *= 0.85;

            switch (i)
            {
            case 0:
                (this->*actionRight)();
                break;
            case 1:
                (this->*actionDown)();
                break;
            case 2:
                (this->*actionLeft)();
                break;
            case 3:
                (this->*actionUp)();
                break;
            default: break;
            }
            
        }
        
        buttonStateLast[i] = buttonStateNow;
        if(counter[i] < 25)counter[i]++;
        

    }
}