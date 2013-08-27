/******************************************************************************
  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.
******************************************************************************
File Name     : drv_win_ioctl.h
Version       : Initial Draft
Author        : Hisilicon multimedia software group
Created       : 2012/12/30
Last Modified :
Description   :
Function List :
History       :
******************************************************************************/
#ifndef __DRV_WIN_IOCTL_H__
#define __DRV_WIN_IOCTL_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif

#include "hi_type.h"
#include "hi_drv_video.h"
#include "hi_drv_disp.h"
#include "hi_drv_win.h"

#define HI_ID_VO 0x24

typedef struct hiWIN_CREATE_S
{
    HI_HANDLE          hWindow;
    HI_DRV_WIN_ATTR_S  WinAttr;
}WIN_CREATE_S;

typedef struct hiWIN_ENABLE_S
{
    HI_HANDLE hWindow;
    HI_BOOL   bEnable;
}WIN_ENABLE_S;

typedef struct hiWIN_SOURCE_S
{
    HI_HANDLE hWindow;
    HI_DRV_WIN_SRC_INFO_S stSrc;
}WIN_SOURCE_S;


typedef struct hiWIN_PRIV_INFO_S
{
    HI_HANDLE hWindow;
    HI_DRV_WIN_INFO_S stPrivInfo;
}WIN_PRIV_INFO_S;

typedef struct hiWIN_PLAY_INFO_S
{
    HI_HANDLE hWindow;
    HI_DRV_WIN_PLAY_INFO_S stPlayInfo;
}WIN_PLAY_INFO_S;

typedef struct hiWIN_ZORDER_S
{
    HI_HANDLE            hWindow;
    HI_DRV_DISP_ZORDER_E eZFlag;
}WIN_ZORDER_S;

typedef struct hiWIN_ORDER_S
{
    HI_HANDLE    hWindow;
    HI_U32       Order;
}WIN_ORDER_S;

typedef struct hiWIN_FREEZE_S
{
    HI_HANDLE hWindow;
    HI_BOOL   bEnable;
    HI_DRV_WIN_SWITCH_E eMode;
}WIN_FREEZE_S;

typedef struct hiWIN_RESET_S
{
    HI_HANDLE hWindow;
    HI_DRV_WIN_SWITCH_E eMode;
}WIN_RESET_S;

typedef struct hiWIN_FRAME_S
{
    HI_HANDLE hWindow;
    HI_DRV_VIDEO_FRAME_S stFrame;
}WIN_FRAME_S;

typedef struct hiVO_WIN_CAPTURE_FREE_S
{
    HI_HANDLE               hWindow;
    HI_DRV_VIDEO_FRAME_S CapPicture;
}WIN_CAPTURE_S;

typedef struct hiWIN_PAUSE_S
{
    HI_HANDLE hWindow;
    HI_BOOL   bEnable;
}WIN_PAUSE_S;

typedef struct hiWIN_STEP_S
{
    HI_HANDLE hWindow;
    HI_BOOL   bStep;
}WIN_STEP_MODE_S;

typedef struct hiWIN_STATE_S
{
//    HI_BOOL   bDisp0Open;
//    HI_BOOL   bDisp1Open;
//    HI_BOOL   bDisp2Open;
    HI_HANDLE hWin[HI_DRV_DISPLAY_BUTT][DEF_MAX_WIN_NUM_ON_SINGLE_DISP];
}WIN_STATE_S;

/*
typedef struct hiWIN_GLOBAL_STATE_S
{
    HI_U32 bDisp0Num;
    HI_U32 bDisp1Num;    
    HI_U32 WinCount[HI_DRV_DISPLAY_BUTT];
}WIN_GLOBAL_STATE_S;
*/

typedef struct hiWIN_BUF_POOL_S
{
    HI_HANDLE hwin;
    HI_DRV_VIDEO_BUFFER_POOL_S stBufPool;
}WIN_BUF_POOL_S;

typedef struct hiWIN_SET_QUICK_S
{
    HI_HANDLE hWindow;
    HI_BOOL   bQuickEnable;
}WIN_SET_QUICK_S;

typedef struct hiWIN_GET_HANDLE_S
{
    HI_DRV_DISPLAY_E enDisp;
    HI_U32 u32WinNumber;
    HI_HANDLE ahWinHandle[DEF_MAX_WIN_NUM_ON_SINGLE_DISP];
}WIN_GET_HANDLE_S;


typedef enum hiIOC_VO_E
{
    IOC_WIN_CREATE = 0,
    IOC_WIN_DESTROY,

    IOC_WIN_SET_ENABLE,
    IOC_WIN_GET_ENABLE,

    IOC_WIN_SET_ATTR,
    IOC_WIN_GET_ATTR,

    IOC_WIN_SET_SOURCE,

    IOC_WIN_GET_INFO,
    IOC_WIN_GET_PLAY_INFO,

    IOC_WIN_QU_FRAME,
    IOC_WIN_QU_ULSFRAME,
    IOC_WIN_DQ_FRAME,

    IOC_WIN_FREEZE,
    IOC_WIN_RESET,
    IOC_WIN_PAUSE,
    IOC_WIN_SET_QUICK,
    
    IOC_WIN_SET_ZORDER,
    IOC_WIN_GET_ORDER,

    IOC_WIN_CAP_FRAME,
    IOC_WIN_CAP_REL_FRAME,
    
    IOC_WIN_SEND_FRAME,

    IOC_WIN_STEP_MODE,
    IOC_WIN_STEP_PLAY,

    IOC_WIN_VIR_ACQUIRE,
    IOC_WIN_VIR_RELEASE,
    IOC_WIN_VIR_EXTERNBUF,

    IOC_WIN_SUSPEND,
    IOC_WIN_RESUME,

    IOC_WIN_DEBUG_GET_HANDLE,

    IOC_WIN_BUTT
} IOC_WIN_E;


#define CMD_WIN_CREATE             _IOWR(HI_ID_VO, IOC_WIN_CREATE, WIN_CREATE_S)
#define CMD_WIN_DESTROY            _IOW(HI_ID_VO, IOC_WIN_DESTROY, HI_HANDLE)

#define CMD_WIN_SET_ENABLE         _IOW(HI_ID_VO, IOC_WIN_SET_ENABLE, WIN_ENABLE_S)
#define CMD_WIN_GET_ENABLE         _IOWR(HI_ID_VO, IOC_WIN_GET_ENABLE, WIN_ENABLE_S)

#define CMD_WIN_SET_ATTR           _IOW(HI_ID_VO, IOC_WIN_SET_ATTR, WIN_CREATE_S)
#define CMD_WIN_GET_ATTR           _IOWR(HI_ID_VO, IOC_WIN_GET_ATTR, WIN_CREATE_S)

#define CMD_WIN_SET_SOURCE         _IOW(HI_ID_VO, IOC_WIN_SET_SOURCE, WIN_SOURCE_S)

#define CMD_WIN_GET_INFO          _IOWR(HI_ID_VO, IOC_WIN_GET_INFO, WIN_PRIV_INFO_S)
#define CMD_WIN_GET_PLAY_INFO      _IOWR(HI_ID_VO, IOC_WIN_GET_PLAY_INFO, WIN_PLAY_INFO_S)

#define CMD_WIN_QU_FRAME           _IOW(HI_ID_VO, IOC_WIN_QU_FRAME, WIN_FRAME_S)
#define CMD_WIN_QU_ULSFRAME        _IOW(HI_ID_VO, IOC_WIN_QU_ULSFRAME, WIN_FRAME_S)
#define CMD_WIN_DQ_FRAME           _IOWR(HI_ID_VO, IOC_WIN_DQ_FRAME, WIN_FRAME_S)

#define CMD_WIN_FREEZE             _IOW(HI_ID_VO, IOC_WIN_FREEZE, WIN_FREEZE_S)
#define CMD_WIN_RESET              _IOW(HI_ID_VO, IOC_WIN_RESET, WIN_RESET_S)
#define CMD_WIN_PAUSE              _IOW(HI_ID_VO, IOC_WIN_PAUSE, WIN_PAUSE_S)

#define CMD_WIN_SET_QUICK          _IOW(HI_ID_VO,IOC_WIN_SET_QUICK,WIN_SET_QUICK_S)
#define CMD_WIN_SET_ZORDER         _IOW(HI_ID_VO, IOC_WIN_SET_ZORDER, WIN_ZORDER_S)
#define CMD_WIN_GET_ORDER          _IOWR(HI_ID_VO, IOC_WIN_GET_ORDER, WIN_ORDER_S)


#define CMD_WIN_CAPTURE            _IOWR(HI_ID_VO, IOC_WIN_CAP_FRAME, WIN_CAPTURE_S)
#define CMD_WIN_CAP_RELEASE        _IOWR(HI_ID_VO, IOC_WIN_CAP_REL_FRAME, WIN_CAPTURE_S)

#define CMD_WIN_SEND_FRAME         _IOW(HI_ID_VO, IOC_WIN_SEND_FRAME, WIN_FRAME_S)

#define CMD_WIN_STEP_MODE          _IOW(HI_ID_VO, IOC_WIN_STEP_MODE, WIN_STEP_MODE_S)
#define CMD_WIN_STEP_PLAY          _IOW(HI_ID_VO, IOC_WIN_STEP_PLAY, HI_HANDLE)

#define CMD_WIN_VIR_ACQUIRE        _IOWR(HI_ID_VO,IOC_WIN_VIR_ACQUIRE,WIN_FRAME_S)
#define CMD_WIN_VIR_RELEASE        _IOWR(HI_ID_VO,IOC_WIN_VIR_RELEASE,WIN_FRAME_S)
#define CMD_WIN_VIR_EXTERNBUF      _IOW(HI_ID_VO,IOC_WIN_VIR_EXTERNBUF,WIN_BUF_POOL_S)


#define CMD_WIN_SUSPEND            _IOW(HI_ID_VO,IOC_WIN_SUSPEND, HI_U32)
#define CMD_WIN_RESUM              _IOW(HI_ID_VO,IOC_WIN_RESUME, HI_U32)

#define CMD_WIN_GET_HANDLE         _IOWR(HI_ID_VO,IOC_WIN_DEBUG_GET_HANDLE, WIN_GET_HANDLE_S)





#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif  /* __DRV_WIN_IOCTL_H__ */

