//
// Tizen Native SDK
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef _NFC_P2P_BUMP_H_
#define _NFC_P2P_BUMP_H_

#include <FApp.h>
#include <FBase.h>
#include <FNet.h>
#include <FSystem.h>
#include <FUi.h>

class NfcP2pBump
	: public Tizen::App::Application
	, public Tizen::App::IAppLaunchConditionEventListener
	, public Tizen::System::IScreenEventListener
{
public:
	static Tizen::App::Application* CreateInstance(void);
//	static bool GetExitNormallyState() { return exitNormallyState; }
//	static void SetExitNormallyState(bool state) { exitNormallyState = state; }

public:
	NfcP2pBump(void);
	~NfcP2pBump(void);

public:
	virtual bool OnAppInitializing(Tizen::App::AppRegistry& appRegistry);
	virtual bool OnAppInitialized(void);
	virtual bool OnAppTerminating(Tizen::App::AppRegistry& appRegistry, bool forcedTermination = false);
	virtual void OnForeground(void);
	virtual void OnBackground(void);
	virtual void OnLowMemory(void);
	virtual void OnBatteryLevelChanged(Tizen::System::BatteryLevel batteryLevel);
	virtual void OnScreenOn(void);
	virtual void OnScreenOff(void);
	virtual void OnAppLaunchConditionMetN(const Tizen::Base::String& condition, Tizen::Base::Object* pExtraData,
			Tizen::Base::Collection::IList* pArguments);
private:
	bool __isSceneRegistered;
};

#endif
