#ifndef customButtons
#define customButtons
#include <Fl/Fl_Button.H>
#include <string>

namespace widgetsAudio{

    class customButton:public Fl_Button{

        public:    
          customButton(int x,int y, int w, int h, std::string param);

    };
}

#endif //customButtons
