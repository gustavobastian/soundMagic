#include "customButtons.hpp"
#include <Fl/Fl_Button.H>
#include <iostream>
#include <string>
#include <iostream>

widgetsAudio::customButton::customButton(int x,int y, int w, int h, std::string param):Fl_Button(x,y,w,h,param.c_str()){    
    box(FL_ROUNDED_BOX);
    down_box(FL_ROUNDED_BOX); 
    label(param.c_str());
    return;
}