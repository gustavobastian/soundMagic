#include "sound.hpp"
#include <alsa/asoundlib.h>
#include <mpg123.h>
#include <iostream>

int snd::SndObject::playFile(){
    std::cout<<"playing\n";
    this->mp3_file = "../assets/x.mp3";
    
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;
    int err;

    // Initialize mpg123 library
    mpg123_init();
    this->mh = mpg123_new(NULL, &err);
    if (this->mh == NULL) {
        std::cerr << "Unable to create mpg123 handle: " << mpg123_plain_strerror(err) << std::endl;
        exit(1);
    }

    // Open the MP3 file
    if (mpg123_open(this->mh, this->mp3_file) != MPG123_OK) {
        std::cerr << "Unable to open file: " << mp3_file << std::endl;
        mpg123_delete(this->mh);
        mpg123_exit();
        exit(1);
    }

    // Get audio format information
    
    if (mpg123_getformat(this->mh, &(this->rate), &(this->channels), &(this->encoding)) != MPG123_OK) {
        std::cerr << "Failed to get MP3 format information" << std::endl;
        mpg123_close(this->mh);
        mpg123_delete(this->mh);
        mpg123_exit();
        exit(1);
    }

    // Initialize ALSA playback
    
    

    if ((err = snd_pcm_open(&(this->playback_handle), PCM_DEVICE, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
        std::cerr << "Cannot open ALSA playback device: " << snd_strerror(err) << std::endl;
        mpg123_close(this->mh);
        mpg123_delete(this->mh);
        mpg123_exit();
        exit(1);
    }

    snd_pcm_hw_params_malloc(&(this->hw_params));
    snd_pcm_hw_params_any((this->playback_handle), (this->hw_params));
    snd_pcm_hw_params_set_access((this->playback_handle), (this->hw_params), SND_PCM_ACCESS_RW_INTERLEAVED);
    snd_pcm_hw_params_set_format((this->playback_handle), (this->hw_params), SND_PCM_FORMAT_S16_LE);
    snd_pcm_hw_params_set_rate((this->playback_handle), (this->hw_params), this->rate, 0);
    snd_pcm_hw_params_set_channels((this->playback_handle), (this->hw_params), this->channels);
    snd_pcm_hw_params((this->playback_handle), (this->hw_params));
    snd_pcm_hw_params_free((this->hw_params));
    snd_pcm_prepare((this->playback_handle));

    // Playback loop
    while (mpg123_read(this->mh, buffer, BUFFER_SIZE, &bytes_read) == MPG123_OK) {
        snd_pcm_writei((this->playback_handle), buffer, bytes_read / (2 * this->channels));
    }

    // Cleanup
    snd_pcm_drain((this->playback_handle));
    snd_pcm_close((this->playback_handle));
    mpg123_close(this->mh);
    mpg123_delete(this->mh);
    mpg123_exit();

    std::cout << "Playback finished!" << std::endl;
    
    return 1;
}