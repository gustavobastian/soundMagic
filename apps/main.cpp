#include <iostream>
#include <string>
#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Widget.H>

#include <sound.hpp>
#include <customButtons.hpp>
#include <FL/Fl_File_Browser.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Tabs.H>
#include <aboutTab.hpp>
#include <mainTab.hpp>

int main(int, char**){
    tb::MainTab *mainTab = new tb::MainTab(0,50,400,200,"Main");
    tb::AboutTab *aboutTabs = new tb::AboutTab(0,50,400,200,"About");
    Fl_Window *mainApp = new Fl_Window(400,200,400,300,"soundMagic");    
    
    Fl_Tabs *myTabs = new Fl_Tabs(0,0,400,300,"");
    myTabs->add(mainTab);
    myTabs->add(aboutTabs);    
    mainApp->add(myTabs);    
    mainApp->end();
    mainApp->show();
    std::cout << "Hello, from soundMagic2!\n";
    Fl::run();
}

