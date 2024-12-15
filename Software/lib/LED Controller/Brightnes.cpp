#include "LED_Controller.hpp"

void LED_Controller::BrightnesGUI() {
    tft.background(255,255,255);
    tft.setTextColor(0x0000);

    actionRight = &LED_Controller::actionRight_Brightnes;
    actionDown  = &LED_Controller::actionDown_Brightnes;
    actionLeft  = &LED_Controller::actionLeft_Brightnes;
    actionUp    = &LED_Controller::actionUp_Brightnes;

    tft.setTextSize(1);
    tft.setCursor(3, 1);
    tft.println("Brightness");
    tft.drawLine(0, 9, 128, 9, 0x0000);

    // print vaue
    tft.setTextSize(2);
    tft.fillRect(24, 16, 40, 18, 0xffff);
    tft.setCursor(25, 16);
    tft.println(brightnes);
    
    tft.drawRect(24, 36, 84, 104, 0x0000);
    tft.fillRect(26, 138 - brightnes, 80, brightnes, 0x0000);
}

void LED_Controller::actionRight_Brightnes() {
    // no action
}

void LED_Controller::actionDown_Brightnes() {
    if (brightnes > 0)
    {
        // decrease grafic
        tft.drawLine(26, 138 - brightnes, 105, 138 - brightnes, 0xffff);
        brightnes--;
        // print vaue
        tft.setTextSize(2);
        tft.fillRect(24, 16, 40, 18, 0xffff);
        tft.setCursor(25, 16);
        tft.println(brightnes);

    }
}

void LED_Controller::actionLeft_Brightnes() {
    this->StartGUI();
}

void LED_Controller::actionUp_Brightnes() {
    if (brightnes < 100)
    {
        // increase grafic
        brightnes++;
        tft.drawLine(26, 138 - brightnes, 105, 138 - brightnes, 0x0000);
        // print vaue
        tft.setTextSize(2);
        tft.fillRect(24, 16, 35, 15, 0xffff);
        tft.setCursor(25, 16);
        tft.println(brightnes);
    }
}