#ifndef MAIN_TAB
#define MAIN_TAB
#include <Fl/Fl_Group.H>

#include <sound.hpp>
#include <customButtons.hpp>
#include <FL/Fl_File_Chooser.H>
#include <memory>

#include <FL/fl_ask.H>

namespace tb {

    class MainTab:public Fl_Group{
    
        snd::SndObject *mySound;
        std::string filename;
        public:
            MainTab(int x,int y, int w, int h, const char *L);
            static void selectCb(Fl_Widget *w, void *data);
            static void playCb(Fl_Widget *w, void *data);
            static void exitCb(Fl_Widget *w, void *data);
            static void stopCb(Fl_Widget *w, void *data);            
            static void chooserCb(Fl_File_Chooser *w,void *data);

            Fl_File_Chooser *chooser;
            std::unique_ptr<widgetsAudio::customButton> stopBt;
            std::unique_ptr<widgetsAudio::customButton> playBt;
            std::unique_ptr<widgetsAudio::customButton> exitBt;
            std::unique_ptr<widgetsAudio::customButton> selectBt;

    };
}

#endif //MAIN_TAB
