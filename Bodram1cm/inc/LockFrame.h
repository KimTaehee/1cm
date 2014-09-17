#ifndef _KTH_LOCK_FRAME_H_
#define _KTH_LOCK_FRAME_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>
#include "LockForm.h"

class LockFrame
	: public Tizen::Ui::Controls::Frame
{
public:
	LockForm* pForm;

public:
	LockFrame(void);
	virtual ~LockFrame(void);

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif	//_KTH_LOCK_FRAME_H_
