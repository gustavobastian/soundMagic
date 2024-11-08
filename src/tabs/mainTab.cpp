#include "mainTab.hpp"
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Group.H>
#include <FL/Fl_File_Chooser.H>

#include <iostream>
#include <string>
#include <iostream>
#include <sound.hpp>
#include <customButtons.hpp>
#include <FL/Fl_File_Browser.H>
#include <FL/fl_ask.H>



tb::MainTab::MainTab(int x,int y, int w, int h, const char *L):Fl_Group(x,y,w,h,L)
{   
    
    mySound= new snd::SndObject();
       
    chooser= new Fl_File_Chooser("./", "*.mp3", FL_SINGLE, "seleccionar");
    chooser->callback(this->chooserCb,this);

    stopBt = std::make_unique<widgetsAudio::customButton>(x+100,y+150,50,50,std::string("@||"));
    stopBt->callback(this->stopCb,nullptr);
    playBt = std::make_unique<widgetsAudio::customButton>(x+150,y+150,50,50,std::string("@>"));
    playBt->callback(this->playCb,(this->mySound));
    exitBt =std::make_unique<widgetsAudio::customButton>(x+200,y+150,50,50,std::string("EXIT"));
    exitBt->callback(this->exitCb,nullptr);
    
    selectBt = std::make_unique<widgetsAudio::customButton>(x+350,y+50,50,50,std::string("@>"));
    selectBt->callback(this->selectCb,nullptr);

    stopBt->label("@||");
    playBt->label("@>");
    exitBt->label("Exit");
    selectBt->label("Select");    
    end();
};


void tb::MainTab::chooserCb(Fl_File_Chooser *w,void *data){
    tb::MainTab *localtab= static_cast<tb::MainTab*>(data);    
    localtab->filename=w->value();
}

void tb::MainTab::selectCb(Fl_Widget *w,void *data){
    tb::MainTab *localtab= static_cast<tb::MainTab*>(w->parent());
    localtab->chooser->show();
}


void tb::MainTab::playCb(Fl_Widget *w, void *data){
    tb::MainTab *localtab= static_cast<tb::MainTab*>(w->parent());
    snd::SndObject *localSound= static_cast<snd::SndObject*>(data);
    localSound->playFile(localtab->filename);    
}

void tb::MainTab::exitCb(Fl_Widget *w, void *data){
    exit(0);
}

void tb::MainTab::stopCb(Fl_Widget *w, void *data){
    std::cout<<"stoppig...\n";
}