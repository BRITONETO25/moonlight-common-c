#pragma once
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
enum {
    AT_RECV_BEGIN=1, AT_RECV_END=2, AT_STARTUP_DROP=3,
    AT_RTP_ENTER=4, AT_RTP_RESULT=5, AT_FEC_OUT=6,
    AT_LBQ_OFFER=7, AT_LBQ_RESULT=8, AT_LBQ_WAIT=9, AT_LBQ_DEQUEUE=10,
    AT_DECRYPT_BEGIN=11, AT_DECRYPT_END=12, AT_CALLBACK_BEGIN=13, AT_CALLBACK_END=14,
    AT_LOCK_BEGIN=20, AT_LOCK_ACQUIRED=21, AT_OPUS_BEGIN=22, AT_OPUS_END=23,
    AT_PCM_QUEUE=24, AT_PCM_DROP=25, AT_PUMP_BEGIN=30,
    AT_UPDATE_BEGIN=31, AT_UPDATE_END=32, AT_VOICE_STATE=33,
    AT_BUFFER_SUBMIT=34, AT_UNDERRUN=35, AT_VOICE_START=36, AT_PUMP_END=37, AT_WAVE_STATES=38,
    AT_LOG_BEGIN=40, AT_LOG_END=41, AT_CONFIG=50, AT_END=51
};
typedef void (*AudioTraceCallback)(int, uint64_t, uint64_t, int64_t, int64_t, int64_t, int64_t);
#ifdef MOONLIGHT_STABLE_BUILD
#define LiSetAudioTraceCallback(...) ((void)0)
#define LiAudioTraceEvent(...) ((void)0)
#define LiAudioTraceCurrentSequence() UINT64_MAX
#else
void LiSetAudioTraceCallback(AudioTraceCallback callback);
void LiAudioTraceEvent(int stage, uint64_t sequence, int64_t a, int64_t b, int64_t c, int64_t d);
uint64_t LiAudioTraceCurrentSequence(void);
#endif
#ifdef __cplusplus
}
#endif
