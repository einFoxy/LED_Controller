#include "LED_Controller.hpp"

//Custom Color
void LED_Controller::customColorGUI() {
    tft.background(255,255,255);

    animationsON = false;

    actionRight = &LED_Controller::actionRight_CustomColer;
    actionDown  = &LED_Controller::actionDown_CustomColer;
    actionLeft  = &LED_Controller::actionLeft_CustomColer;
    actionUp    = &LED_Controller::actionUp_CustomColer;

    //headline
    tft.setTextSize(1);
    tft.setCursor(3, 1);
    tft.println("Custom Collor");
    tft.drawLine(0, 9, 128, 9, 0x0000);
    
    tft.drawRect(8 + 38*selectedColor,27,34,132, 0x0000);
    
    int fill;
    
    for (unsigned char i = 0; i < 3; i++)
    {
        
    fill = (colorValRGB[i] % 2) ? ((colorValRGB[i] / 2) + 1) : (colorValRGB[i] / 2);
    tft.setCursor(8 + 38*i, 12);
    tft.setTextSize(2);
    tft.setTextColor(color[i]);
    tft.println(colorValRGB[i]);
    tft.fillRect(10 + 38*i,157 - fill,30, fill, color[i]);
    }
    

}

void LED_Controller::actionRight_CustomColer(){
    if(selectedColor == 2){
        tft.drawRect(8 + 38*selectedColor,27,34,132, 0xffff);
        selectedColor = 0;
        tft.drawRect(8 + 38*selectedColor,27,34,132, 0x0000);
    }
    else{
        tft.drawRect(8 + 38*selectedColor,27,34,132, 0xffff);
        selectedColor++;
        tft.drawRect(8 + 38*selectedColor,27,34,132, 0x0000);
    }
}

void LED_Controller::actionDown_CustomColer(){

    if(colorValRGB[selectedColor] > 0){
    //change slider
    tft.drawLine(10 + 38*selectedColor, 156 - colorValRGB[selectedColor]/2, 39 + 38*selectedColor, 156 - colorValRGB[selectedColor]/2, 0xffff);
    colorValRGB[selectedColor]--;
    //update displayed value
    tft.setCursor(8 + 38*selectedColor, 12);
    tft.setTextSize(2);
    tft.fillRect(8 + 38*selectedColor, 12, 35, 15, 0xffff);
    tft.setTextColor(color[selectedColor]);
    tft.println(colorValRGB[selectedColor]);
    //update LED
    //analogWrite(ledpins[selectedColor], colorValRGB[selectedColor]*brightnes/100);
    }

    
}

void LED_Controller::actionLeft_CustomColer(){
    if(selectedColor == 0) this->StartGUI();
    else{
        tft.drawRect(8 + 38*selectedColor,27,34,132, 0xffff);
        selectedColor--;
        tft.drawRect(8 + 38*selectedColor,27,34,132, 0x0000);
    }

}

void LED_Controller::actionUp_CustomColer(){

    if(colorValRGB[selectedColor] < 255){
    //change slider
    tft.drawLine(10 + 38*selectedColor, 156 - colorValRGB[selectedColor]/2, 39 + 38*selectedColor, 156 - colorValRGB[selectedColor]/2, color[selectedColor]);
    colorValRGB[selectedColor]++;
    //update displayed value
    tft.setCursor(8 + 38*selectedColor, 12);
    tft.setTextSize(2);
    tft.fillRect(8 + 38*selectedColor, 12, 35, 15, 0xffff);
    tft.setTextColor(color[selectedColor]);
    tft.println(colorValRGB[selectedColor]);
    //updat LED
    //analogWrite(ledpins[selectedColor], colorValRGB[selectedColor]*brightnes/100);
    }

    
}

void LED_Controller::colorSelectorGUI(){
    tft.background(255,255,255);
    
    tft.setTextSize(1);
    tft.setCursor(3, 1);
    tft.println("Custom Collor");
    tft.drawLine(0, 9, 128, 9, 0x0000);
    
    tft.setCursor()
}

void LED_Controller::actionRight_colorSelector(){

}

void LED_Controller::actionDown_colorSelector(){

}

void LED_Controller::actionLeft_colorSelector(){

}

void LED_Controller::actionUp_colorSelector(){

}