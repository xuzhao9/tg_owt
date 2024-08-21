/*
 *  Copyright (c) 2015 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 *
 */

#ifndef MODULES_VIDEO_CODING_CODECS_H264_DLOPEN_H_
#define MODULES_VIDEO_CODING_CODECS_H264_DLOPEN_H_

#ifdef WEBRTC_USE_H264_DLOPEN

int oh264_WelsCreateSVCEncoder(ISVCEncoder **ppEncoder);
#define WelsCreateSVCEncoder oh264_WelsCreateSVCEncoder

int loadLibOpenH264(AVCodecContext *avctx);

#endif /* WEBRTC_USE_H264_DLOPEN */

#endif /* MODULES_VIDEO_CODING_CODECS_H264_DLOPEN_H_ */