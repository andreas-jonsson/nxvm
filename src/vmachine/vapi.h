/* This file is a part of NXVM project. */

#ifndef NXVM_VAPI_H
#define NXVM_VAPI_H

#ifdef __cplusplus
/*extern "C" {*/
#endif

#include "vglobal.h"
#include "vcpu.h"

t_nubit32  vapiPrint(const t_string format, ...);
void vapiPrintByte(t_nubit8 n);
void vapiPrintWord(t_nubit16 n);
void vapiPrintAddr(t_nubit16 segment, t_nubit16 offset);

#include "stdio.h"

/*
typedef struct {
	int   count;
	char  fname[0x100];
	FILE *fptr;
} t_apirecord;

extern t_apirecord vapirecord;*/
#define VAPI_SIZE_RECORD  0xffff
typedef struct {
	t_cpu rec[VAPI_SIZE_RECORD];
	t_nubitcc start, size;
} t_apirecord;

void vapiRecordDump(const t_string fname);
void vapiRecordStart();
void vapiRecordExec();
void vapiRecordEnd();

void vapiFloppyInsert(const t_string fname);
void vapiFloppyRemove(const t_string fname);
void vapiStartMachine();

void vapiSleep(t_nubit32 milisec);
void vapiDisplaySetScreen();
void vapiDisplayPaint();

void vapiCallBackMachineRun();
t_nubit8 vapiCallBackMachineGetFlagRun();
void vapiCallBackMachineStop();

void vapiCallBackRtcUpdateTime();

t_bool vapiCallBackKeyboardGetShift();
t_bool vapiCallBackKeyboardGetAlt();
t_bool vapiCallBackKeyboardGetCtrl();
void vapiCallBackKeyboardClrFlag0();
void vapiCallBackKeyboardClrFlag1();
void vapiCallBackKeyboardSetFlag0Insert();
void vapiCallBackKeyboardSetFlag0CapLck();
void vapiCallBackKeyboardSetFlag0NumLck();
void vapiCallBackKeyboardSetFlag0ScrLck();
void vapiCallBackKeyboardSetFlag0Alt();
void vapiCallBackKeyboardSetFlag0Ctrl();
void vapiCallBackKeyboardSetFlag0LeftShift();
void vapiCallBackKeyboardSetFlag0RightShift();
void vapiCallBackKeyboardSetFlag1Insert();
void vapiCallBackKeyboardSetFlag1CapLck();
void vapiCallBackKeyboardSetFlag1NumLck();
void vapiCallBackKeyboardSetFlag1ScrLck();
void vapiCallBackKeyboardSetFlag1Pause();
void vapiCallBackKeyboardSetFlag1SysRq();
void vapiCallBackKeyboardSetFlag1LeftAlt();
void vapiCallBackKeyboardSetFlag1LeftCtrl();
t_bool vapiCallBackKeyboardRecvKeyPress(t_nubit16 ascii);

t_nubit8 vapiCallBackDisplayGetRowSize();
t_nubit8 vapiCallBackDisplayGetColSize();
t_nubit8 vapiCallBackDisplayGetCursorTop();
t_nubit8 vapiCallBackDisplayGetCursorBottom();
t_nubit8 vapiCallBackDisplayGetCurrentCursorPosX();
t_nubit8 vapiCallBackDisplayGetCurrentCursorPosY();
t_nubit8 vapiCallBackDisplayGetCurrentChar(t_nubit8 x, t_nubit8 y);
t_nubit8 vapiCallBackDisplayGetCurrentCharProp(t_nubit8 x, t_nubit8 y);

#ifdef __cplusplus
/*}_EOCD_*/
#endif

#endif