const static char* OPENH264_LIB = "libopenh264.so.7";

int loadOpenH264(AVCodecContext *avctx) {
    static bool initialized = false;
    void *libopenh264 = NULL;
    const char *err = NULL;

    if (initialized) {
        return 0;
    }

    libopenh264 = dlopen(OPENH264_LIB, RTLD_LAZY);
    err = dlerror();
    if (err != NULL) {
        av_log()
        if (libopenh264 != NULL) {
            dlclose(libopenh264);
        }
        return 1;
    }

    oh264_bind_symbol(avctx, libopenh264, WelsCreateSVCEncoder);
    oh264_bind_symbol(avctx, libopenh264, WelsDestroySVCEncoder);
    oh264_bind_symbol(avctx, libopenh264, WelsGetDecoderCapability);
    oh264_bind_symbol(avctx, libopenh264, WelsCreateDecoder);
    oh264_bind_symbol(avctx, libopenh264, WelsDestroyDecoder);
    oh264_bind_symbol(avctx, libopenh264, WelsGetCodecVersion);
    oh264_bind_symbol(avctx, libopenh264, WelsGetCodecVersionEx);

    initialized = true;

    return 0;
}