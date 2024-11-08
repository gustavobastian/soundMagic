#include <iostream>
#include <string>
#include <memory>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Widget.H>

#include <sound.hpp>
#include <customButtons.hpp>


void playCb(Fl_Widget *w, void *data){
    snd::SndObject *localSound= static_cast<snd::SndObject*>(data);
    localSound->playFile();    
}

void exitCb(Fl_Widget *w, void *data){
    exit(0);
}

void stopCb(Fl_Widget *w, void *data){
    std::cout<<"stoppig...\n";
}

int main(int, char**){
    snd::SndObject mySound;
    Fl_Window *mainApp = new Fl_Window(400,200,400,200,"soundMagic");
    
    widgetsAudio::customButton *stopBt = new widgetsAudio::customButton(100,50,50,50,std::string("@||"));
    stopBt->callback(stopCb,nullptr);
    widgetsAudio::customButton *playBt = new widgetsAudio::customButton(150,50,50,50,std::string("@>"));
    playBt->callback(playCb,&mySound);
    widgetsAudio::customButton *exitBt = new widgetsAudio::customButton(150,150,50,50,std::string("EXIT"));
    exitBt->callback(exitCb,nullptr);
    
    stopBt->label("@||");
    playBt->label("@>");
    mainApp->add(playBt);
    mainApp->add(stopBt);
    mainApp->add(exitBt);
    mainApp->end();
    mainApp->show();
    std::cout << "Hello, from soundMagic!\n";
    Fl::run();
}

