#include <new>
#include "LauncherApp.h"
#include "LauncherFrame.h"

using namespace Tizen::App;
using namespace Tizen::System;
using namespace Tizen::Base::Collection;
using namespace Tizen::Base;


LauncherApp::LauncherApp(void)
{
}

LauncherApp::~LauncherApp(void)
{
}

UiApp*
LauncherApp::CreateInstance(void)
{
	// TODO: Create the application instance through the constructor.
	return new (std::nothrow) LauncherApp();
}

bool
LauncherApp::OnAppInitializing(AppRegistry& appRegistry)
{
	// TODO: Initialize application-specific data.
	// The permanent data and context of the application can be obtained from the application registry (appRegistry).
	//
	// If this method is successful, return true; otherwise, return false and the application is terminated.


	// Uncomment the following statement to listen to the screen on and off events:
	// PowerManager::SetScreenEventListener(*this);

	return true;
}

bool
LauncherApp::OnAppInitialized(void)
{
	// TODO: Create the application frame.

	LauncherFrame* pLauncherFrame = new (std::nothrow) LauncherFrame;
	TryReturn(pLauncherFrame != null, false, "The memory is insufficient.");
	pLauncherFrame->Construct();
	pLauncherFrame->SetName(L"Launcher");
	AddFrame(*pLauncherFrame);

	return true;
}

bool
LauncherApp::OnAppWillTerminate(void)
{
	// TODO: Deallocate or release resources in devices that have the END key.
	return true;
}

bool
LauncherApp::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	// TODO: Deallocate all resources allocated by the application.
	// The permanent data and context of the application can be saved through the application registry (appRegistry).
	return true;
}

void
LauncherApp::OnForeground(void)
{
	AppLog("OnForeground invoked!");
	OnBackground();
	// TODO: Start or resume drawing when the application is moved to the foreground.
}

void
LauncherApp::OnBackground(void)
{
	AppLog("OnBackground Invoked! try to launch 1cm");

	AppId calleeAppId = L"bNl4i7fkP1.Bodram1cm";

	AppManager* pAppManager = AppManager::GetInstance();

	ArrayList* pArgList = new ArrayList();
	pArgList->Construct();

	String* aArg = new String(L"wake");
	pArgList->Add(*aArg);

	result r = pAppManager->LaunchApplication(calleeAppId, pArgList,
			AppManager::LAUNCH_OPTION_DEFAULT);

	//destroy myself
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
	// TODO: Stop drawing when the application is moved to the background to save the CPU and battery consumption.
}

void
LauncherApp::OnLowMemory(void)
{
	// TODO: Free unnecessary resources or close the application.
}

void
LauncherApp::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
	// TODO: Handle all battery level changes here.
	// Stop using multimedia features (such as camera and mp3 playback) if the battery level is CRITICAL.
}

void
LauncherApp::OnScreenOn(void)
{
	// TODO: Retrieve the released resources or resume the operations that were paused or stopped in the OnScreenOff() event handler.
}

void
LauncherApp::OnScreenOff(void)
{
	// TODO: Release resources (such as 3D, media, and sensors) to allow the device to enter the sleep mode 
	// to save the battery (unless you have a good reason to do otherwise).
	// Only perform quick operations in this event handler. Any lengthy operations can be risky; 
	// for example, invoking a long asynchronous method within this event handler can cause problems
	// because the device can enter the sleep mode before the callback is invoked.

}
