#include "aboutTab.hpp"
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Group.H>


#include <iostream>
#include <string>
#include <iostream>


tb::AboutTab::AboutTab(int x,int y, int w, int h, const char *L):Fl_Group(x,y,w,h,L)
{    

    color(FL_GREEN);    
    end();
};