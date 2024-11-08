#ifndef SOUND_HPP
#define SOUND_HPP


#include <alsa/asoundlib.h>
#include <mpg123.h>

#define PCM_DEVICE "default"
#define BUFFER_SIZE 4096

namespace snd{
    class SndObject{
        private:
        char *mp3_file;
        mpg123_handle *mh;
        //audio format
        long rate;
        int channels, encoding;

        //alsa playback
        snd_pcm_t *playback_handle;
        snd_pcm_hw_params_t *hw_params;
        

        public:
        SndObject(){};
        int playFile();
    };


}

#endif //SOUND_HPP
