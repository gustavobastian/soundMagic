#ifndef aboutTab
#define aboutTab
#include <Fl/Fl_Group.H>

namespace tb {

    class AboutTab:public Fl_Group{

        public:            
            AboutTab(int x,int y, int w, int h, const char *L);
    };
}

#endif //aboutTab
