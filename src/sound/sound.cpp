#include "sound.hpp"
#include <alsa/asoundlib.h>
#include <mpg123.h>
#include <iostream>

int snd::SndObject::playFile(){
    std::cout<<"playing\n";
    const char *mp3_file = "../assets/x.mp3";
    mpg123_handle *mh;
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;
    int err;

    // Initialize mpg123 library
    mpg123_init();
    mh = mpg123_new(NULL, &err);
    if (mh == NULL) {
        std::cerr << "Unable to create mpg123 handle: " << mpg123_plain_strerror(err) << std::endl;
        exit(1);
    }

    // Open the MP3 file
    if (mpg123_open(mh, mp3_file) != MPG123_OK) {
        std::cerr << "Unable to open file: " << mp3_file << std::endl;
        mpg123_delete(mh);
        mpg123_exit();
        exit(1);
    }

    // Get audio format information
    long rate;
    int channels, encoding;
    if (mpg123_getformat(mh, &rate, &channels, &encoding) != MPG123_OK) {
        std::cerr << "Failed to get MP3 format information" << std::endl;
        mpg123_close(mh);
        mpg123_delete(mh);
        mpg123_exit();
        exit(1);
    }

    // Initialize ALSA playback
    snd_pcm_t *playback_handle;
    snd_pcm_hw_params_t *hw_params;

    if ((err = snd_pcm_open(&playback_handle, PCM_DEVICE, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
        std::cerr << "Cannot open ALSA playback device: " << snd_strerror(err) << std::endl;
        mpg123_close(mh);
        mpg123_delete(mh);
        mpg123_exit();
        exit(1);
    }

    snd_pcm_hw_params_malloc(&hw_params);
    snd_pcm_hw_params_any(playback_handle, hw_params);
    snd_pcm_hw_params_set_access(playback_handle, hw_params, SND_PCM_ACCESS_RW_INTERLEAVED);
    snd_pcm_hw_params_set_format(playback_handle, hw_params, SND_PCM_FORMAT_S16_LE);
    snd_pcm_hw_params_set_rate(playback_handle, hw_params, rate, 0);
    snd_pcm_hw_params_set_channels(playback_handle, hw_params, channels);
    snd_pcm_hw_params(playback_handle, hw_params);
    snd_pcm_hw_params_free(hw_params);
    snd_pcm_prepare(playback_handle);

    // Playback loop
    while (mpg123_read(mh, buffer, BUFFER_SIZE, &bytes_read) == MPG123_OK) {
        snd_pcm_writei(playback_handle, buffer, bytes_read / (2 * channels));
    }

    // Cleanup
    snd_pcm_drain(playback_handle);
    snd_pcm_close(playback_handle);
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();

    std::cout << "Playback finished!" << std::endl;
    
    return 1;
}