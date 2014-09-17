#include "LockApp.h"
#include <new>

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Base::Collection;

LockApp::LockApp(void)
{
}

LockApp::~LockApp(void)
{
}

UiApp*
LockApp::CreateInstance(void)
{
	// Create the application instance through the constructor.
	return new (std::nothrow) LockApp();
}

bool
LockApp::OnAppInitializing(AppRegistry& appRegistry)
{
	// TODO:
	// Initialize application-specific data.
	// The permanent data and context of the application can be obtained from the application registry (appRegistry).
	//
	// If this method is successful, return true; otherwise, return false and the application is terminated.

	pFrame = new (std::nothrow) LockFrame();
	pFrame->Construct();
	pFrame->SetName(L"Lock");
	AddFrame(*pFrame);

	// TODO: Add your initialization code here
	return true;
}

bool
LockApp::OnAppInitialized(void)
{
	return true;
}

bool
LockApp::OnAppWillTerminate(void)
{
	// TODO:
	// Deallocate or release resources in devices that have the END key.
	return true;
}

bool
LockApp::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	// TODO:
	// Deallocate all resources allocated by the application.
	// The permanent data and context of the application can be saved through the application registry (appRegistry).
	return true;
}

void
LockApp::OnForeground(void)
{
	AppLog("OnForeground invoked!");
	// TODO:
	// Start or resume drawing when the application is moved to the foreground.
}

void
LockApp::OnBackground(void)
{
	AppLog("OnBackground called");
}

void
LockApp::OnLowMemory(void)
{
	// TODO:
	// Free unnecessary resources or close the application.
}

void
LockApp::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
	// TODO:
	// Handle all battery level changes here.
	// Stop using multimedia features (such as camera and mp3 playback) if the battery level is CRITICAL.
}

void
LockApp::OnScreenOn(void)
{
	// TODO:
	// Retrieve the released resources or resume the operations that were paused or stopped in the OnScreenOff() event handler.
}

void
LockApp::OnScreenOff(void)
{
	// TODO:
	// Release resources (such as 3D, media, and sensors) to allow the device to enter the sleep mode 
	// to save the battery (unless you have a good reason to do otherwise).
	// Only perform quick operations in this event handler. Any lengthy operations can be risky; for 
	// example, invoking a long asynchronous method within this event handler can cause problems 
	// because the device can enter the sleep mode before the callback is invoked.
}



