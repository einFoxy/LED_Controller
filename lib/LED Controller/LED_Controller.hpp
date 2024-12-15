#ifndef LED_CONTROLLER_HPP
#define LED_CONTROLLER_HPP

#include "SPI.h"
#include "TFT.h"

// pin definition for the Uno
#define lcd_cs 10
#define dc 9
#define rst 8

// pin definition for the Leonardo
//#define sd_cs  8
//#define lcd_cs 7
//#define dc     0
//#define rst    1

// Taster
#define RIGHT_BUTTON 0
#define DOWN_BUTTON 1
#define LEFT_BUTTON 2
#define UP_BUTTON 3

class LED_Controller {
public:
    
    
    void SetupLCD(int redLED_pin, int greenLED_pin, int blueLED_pin);
    void clock();
    void UpdateLEDs();

    //Start
    void StartGUI();
    void actionRight_Start();
    void actionDown_Start();
    void actionLeft_Start();
    void actionUp_Start();

    //Brightness
    void BrightnesGUI();
    void actionRight_Brightnes();
    void actionDown_Brightnes();
    void actionLeft_Brightnes();
    void actionUp_Brightnes();

    //Animation
    void AnimationGUI();
    void actionRight_Animation();
    void actionDown_Animation();
    void actionLeft_Animation();
    void actionUp_Animation();
    class Animations{
        void faiding(uint8_t *beginColor, uint8_t *endColor);
    };

    //CustomColler
    void customColorGUI();
    void actionRight_CustomColer();
    void actionDown_CustomColer();
    void actionLeft_CustomColer();
    void actionUp_CustomColer();

    void colorSelectorGUI();
    void actionRight_colorSelector();
    void actionDown_colorSelector();
    void actionLeft_colorSelector();
    void actionUp_colorSelector();

    //Button
    void checkButton();
    void (LED_Controller::*actionRight)();
    void (LED_Controller::*actionDown)(); 
    void (LED_Controller::*actionLeft)();
    void (LED_Controller::*actionUp)();

private:
    TFT tft = TFT(lcd_cs, dc, rst);

    uint8_t ledpins[3];
    uint8_t brightnes = 100;
    uint8_t colorValRGB[3] = {100, 100, 100}; // {R, G, B}
    int ledUpdatSpeed = 0;
    
    //Start
    unsigned char selectedCategory = 0;
    void drawSelector(char up_down = 2);

    //Custom color
    unsigned char selectedColor = 0;
    uint16_t color[3] = {0xf800, 0x06e0, 0x001f};   // red / green / blue
    

    //Animations
    bool animationsON = false;

    
    
};

#endif // LED_CONTROLLER_HPP