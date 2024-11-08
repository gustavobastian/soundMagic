#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Widget.H>

#include <sound.hpp>


void playCb(Fl_Widget *w, void *data){
    snd::SndObject *localSound= static_cast<snd::SndObject*>(data);
    localSound->playFile();    
}

void exitCb(Fl_Widget *w, void *data){
    exit(0);
}

int main(int, char**){
    snd::SndObject mySound;
    Fl_Window *mainApp = new Fl_Window(400,200,400,200,"soundMagic");
    
    Fl_Button *stopBt = new Fl_Button(100,50,50,50,"@||");
    Fl_Button *playBt = new Fl_Button(150,50,50,50,"@>");
    playBt->callback(playCb,&mySound);
    Fl_Button *exitBt = new Fl_Button(150,150,50,50,"EXIT");
    exitBt->callback(exitCb,nullptr);

    mainApp->add(playBt);
    mainApp->add(stopBt);
    mainApp->add(exitBt);
    mainApp->end();
    mainApp->show();
    std::cout << "Hello, from soundMagic!\n";
    Fl::run();
}

