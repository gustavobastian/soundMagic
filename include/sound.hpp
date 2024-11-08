#ifndef SOUND_HPP
#define SOUND_HPP


#include <alsa/asoundlib.h>
#include <mpg123.h>
#include <string>

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
        int playFile(std::string filename="../assets/x.mp3");
        static void run(unsigned char buffer[BUFFER_SIZE],size_t bytes_read, mpg123_handle *mh,snd_pcm_t *playback_handle, int channels);
    };


}

#endif //SOUND_HPP
