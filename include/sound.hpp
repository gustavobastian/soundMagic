#ifndef SOUND_HPP
#define SOUND_HPP


#define PCM_DEVICE "default"
#define BUFFER_SIZE 4096

namespace snd{
    class SndObject{
        public:
        SndObject(){};
        int playFile();
    };


}

#endif //SOUND_HPP
