#ifndef _KTH_LOCK_APP_H_
#define _KTH_LOCK_APP_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>
#include "LockFrame.h"

//The KTHLockApp class must inherit from the UiApp class,
//which provides the basic features necessary to define a UI application.

class LockApp
	: public Tizen::App::UiApp
	, public Tizen::System::IScreenEventListener
{
public:
	LockFrame* pFrame;

public:
	//The platform calls this method to create the application instance.
	static Tizen::App::UiApp* CreateInstance(void);

	LockApp(void);
	virtual ~LockApp(void);

	// Called when the UiApp is initializing.
	virtual bool OnAppInitializing(Tizen::App::AppRegistry& appRegistry);

	// Called when the UiApp initializing is finished. 
	virtual bool OnAppInitialized(void); 

	// Called when the UiApp is requested to terminate. 
	virtual bool OnAppWillTerminate(void); 

	// Called when the UiApp is terminating.
	virtual bool OnAppTerminating(Tizen::App::AppRegistry& appRegistry, bool forcedTermination = false);

	// Called when the UiApp's frame moves to the top of the screen.
	virtual void OnForeground(void);

	// Called when this UiApp's frame is moved from top of the screen to the background.
	virtual void OnBackground(void);

	// Called when the system memory is not sufficient to run the UiApp any further.
	virtual void OnLowMemory(void);

	// Called when the battery level changes.
	virtual void OnBatteryLevelChanged(Tizen::System::BatteryLevel batteryLevel);

	// Called when the screen turns on.
	virtual void OnScreenOn(void);

	// Called when the screen turns off.
	virtual void OnScreenOff(void);
};

#endif // _KTH_LOCK_APP_H_
