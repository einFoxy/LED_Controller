#include "LED_Controller.hpp"

void LED_Controller::AnimationGUI(){
    tft.background(255,255,255);

    animationsON = true;

    actionRight = &LED_Controller::actionRight_Animation;
    actionDown  = &LED_Controller::actionDown_Animation;
    actionLeft  = &LED_Controller::actionLeft_Animation;
    actionUp    = &LED_Controller::actionUp_Animation;
}

void LED_Controller::actionRight_Animation(){

}

void LED_Controller::actionDown_Animation(){

}

void LED_Controller::actionLeft_Animation(){

}

void LED_Controller::actionUp_Animation(){

}

void LED_Controller::Animations::faiding(uint8_t *beginColor, uint8_t *endColor){
    static uint8_t difCorlor[3] = {*(beginColor)};
}