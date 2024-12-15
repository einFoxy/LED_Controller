#include "LED_Controller.hpp"

void LED_Controller::StartGUI() {
    tft.background(255,255,255);
    tft.setTextColor(0x0000);

    actionRight = &LED_Controller::actionRight_Start;
    actionDown  = &LED_Controller::actionDown_Start;
    actionLeft  = &LED_Controller::actionLeft_Start;
    actionUp    = &LED_Controller::actionUp_Start;

    static int ypos;
    ypos = 1;

    tft.setTextSize(1);
    tft.setCursor(3, ypos);
    tft.println("LED Controller");
    ypos += 8;
    tft.drawLine(0, ypos, 128, ypos, 0x0000);
    ypos += 6;

    tft.setTextSize(2);
    tft.setCursor(3, ypos);
    tft.println("Brightnes");
    ypos += 20;
    tft.drawLine(0, ypos, 128, ypos, 0x0000);
    ypos += 6;

    tft.setCursor(3, ypos);
    tft.println("Color -");
    ypos += 17;
    tft.setCursor(3, ypos);
    tft.println("Animation");
    ypos += 20;
    tft.drawLine(0, ypos, 128, ypos, 0x0000);
    ypos += 6;

    tft.setTextSize(2);
    tft.setCursor(3, ypos);
    tft.println("Custom -");
    ypos += 17;
    tft.setCursor(3, ypos);
    tft.println("Collor");
    ypos += 20;
    tft.drawLine(0, ypos, 128, ypos, 0x0000);
    ypos += 6;

    tft.setCursor(3, ypos);
    tft.println("---");
    ypos += 20;
    // tft.drawLine(0,ypos,128,ypos,0x0000); ypos += 6;
    tft.fillRect(0, ypos, 128, 160, 0x0000);
    drawSelector();
}

void LED_Controller::actionRight_Start(){
    switch (selectedCategory)
    {
    case 0:
        this->BrightnesGUI();
        break;
    case 1:
        //this-> Animations
        break;
    case 2:
        this->customColorGUI();
        break;
    default:
        selectedCategory = 0;
        this->StartGUI();
        break;
    }
}

void LED_Controller::actionDown_Start(){
    drawSelector(1);
}

void LED_Controller::actionLeft_Start(){
    //no aciton
}

void LED_Controller::actionUp_Start(){
    drawSelector(0);
}

void LED_Controller::drawSelector(char up_down){
    if(up_down < 2) {
    tft.drawLine(50, 31 + 43*selectedCategory, 125, 31 + 43*selectedCategory, 0xffff);
    tft.drawLine(51, 32 + 43*selectedCategory, 125, 32 + 43*selectedCategory, 0xffff);
    tft.drawLine(124, 15 + 43*selectedCategory, 124, 32 + 43*selectedCategory, 0xffff);
    tft.drawLine(125, 16 + 43*selectedCategory, 125, 32 + 43*selectedCategory, 0xffff);
    }

    if (up_down == 0)
    {
        selectedCategory = (selectedCategory-1 >= 0)?(selectedCategory-1)%3: 2;
    }
    else if (up_down == 1)
    {
        selectedCategory = (selectedCategory+1 < 3)?(selectedCategory+1)%3 : 0;
    }
    //else selectcted category doesn't change
    
    tft.drawLine(50, 31 + 43*selectedCategory, 125, 31 + 43*selectedCategory, 0x0000);
    tft.drawLine(51, 32 + 43*selectedCategory, 125, 32 + 43*selectedCategory, 0x0000);
    tft.drawLine(124, 15 + 43*selectedCategory, 124, 32 + 43*selectedCategory, 0x0000);
    tft.drawLine(125, 16 + 43*selectedCategory, 125, 32 + 43*selectedCategory, 0x0000);

}