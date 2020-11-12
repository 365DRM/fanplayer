#ifndef __FANPLAYER_ADEV_H__
#define __FANPLAYER_ADEV_H__

// ����ͷ�ļ�
#include "ffplayer.h"
#include "ffrender.h"

#ifdef __cplusplus
extern "C" {
#endif

// ���Ͷ���
typedef struct {
    int16_t *data;
    int32_t  size;
} AUDIOBUF;

#define ADEV_SAMPLE_RATE  44100

//++ adev context common members
#define ADEV_COMMON_MEMBERS \
    int64_t    *ppts;       \
    int16_t    *bufcur;     \
    int         bufnum;     \
    int         buflen;     \
    int         head;       \
    int         tail;       \
                            \
    /* common vars */       \
    CMNVARS    *cmnvars;
//-- adev context common members

// ���Ͷ���
typedef struct {
    ADEV_COMMON_MEMBERS
} ADEV_COMMON_CTXT;

// ��������
void* adev_create (int type, int bufnum, int buflen, CMNVARS *cmnvars);
void  adev_destroy(void *ctxt);
void  adev_lock   (void *ctxt, AUDIOBUF **ppab);
void  adev_unlock (void *ctxt, int64_t pts);
void  adev_pause  (void *ctxt, int pause);
void  adev_reset  (void *ctxt);

#ifdef __cplusplus
}
#endif

#endif

