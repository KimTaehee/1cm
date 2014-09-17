#ifndef _KTH_FORM_APP_FRAME_H_
#define _KTH_FORM_APP_FRAME_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class LauncherFrame
	: public Tizen::Ui::Controls::Frame
{
public:
	LauncherFrame(void);
	virtual ~LauncherFrame(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif	//_KTH_FORM_APPFRAME_H_
