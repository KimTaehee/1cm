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

#include <new>
#include <FNet.h>
#include "NfcP2pBump.h"
#include "MainForm.h"
#include "FormFactory.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Net::Nfc;
using namespace Tizen::System;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

bool isLocked = false;

NfcP2pBump::NfcP2pBump()
: __isSceneRegistered(false)
{
}

NfcP2pBump::~NfcP2pBump()
{
}

Application*
NfcP2pBump::CreateInstance(void)
{
	return new (std::nothrow) NfcP2pBump();
}

bool
NfcP2pBump::OnAppInitializing(AppRegistry& appRegistry)
{
	AppManager::GetInstance()->SetAppLaunchConditionEventListener(this);

	return true;
}

bool
NfcP2pBump::OnAppInitialized(void)
{
	Frame* pFrame = new Frame();

	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	static FormFactory formFactory;

	if (!__isSceneRegistered)
	{
		pFrame->Construct();
		pFrame->SetName(L"NfcP2pBump");
		AddFrame(*pFrame);

		pSceneManager->RegisterFormFactory(formFactory);
		pSceneManager->RegisterScene(L"MainScene", L"MainForm", L"");
		pSceneManager->RegisterScene(L"MyCardScene", L"MyCardForm", L"");
		pSceneManager->RegisterScene(L"LockScene", L"LockForm", L"");

		if (pSceneManager->GoForward(ForwardSceneTransition(L"MainScene")) != E_SUCCESS)
		{
			return false;
		}

		__isSceneRegistered = true;
	}
	//Disables the launch popup message by Conditional NFC App Launch.
	NfcManager::SetLaunchPopupEnabled(false);

	AppLog("isLocked = false");
	isLocked = false;

	return true;
}

bool
NfcP2pBump::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	return true;
}

void
NfcP2pBump::OnForeground(void)
{
}

void
NfcP2pBump::OnBackground(void)
{
	AppLog("OnBackground invoked!");

	//	Tizen::App::UiApp::GetInstance()->GetAppFrame()->GetFrame()->SetShowState(true);
	//	Tizen::App::UiApp::GetInstance()->GetAppFrame()->GetFrame()->Show();

	if(isLocked) { //abnormal exit
		AppLog("try to launch WakerApp");
		AppId calleeAppId = L"GzEXzCLiTO.Bodram1cmLauncher";

		AppManager* pAppManager = AppManager::GetInstance();

		ArrayList* pArgList = new ArrayList();
		pArgList->Construct();

		String* aArg = new String(L"wake");
		pArgList->Add(*aArg);

		result r = pAppManager->LaunchApplication(calleeAppId, pArgList,
				AppManager::LAUNCH_OPTION_DEFAULT);
	} else { //normal exit
		AppLog("isLocked == false");


	}

	//	 TODO:
	//	 Stop drawing when the application is moved to the background to save the CPU and battery consumption.
}

void
NfcP2pBump::OnLowMemory(void)
{
}

void
NfcP2pBump::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
}

void
NfcP2pBump::OnScreenOn(void)
{
}

void
NfcP2pBump::OnScreenOff(void)
{
}

void
NfcP2pBump::OnAppLaunchConditionMetN(const Tizen::Base::String& condition, Tizen::Base::Object* pExtraData,
		Tizen::Base::Collection::IList* pArguments)
{
	if (!__isSceneRegistered)
	{
		Frame* pFrame = new Frame();
		pFrame->Construct();
		pFrame->SetName(L"NfcP2pBump");
		AddFrame(*pFrame);

		SceneManager* pSceneManager = SceneManager::GetInstance();
		AppAssert(pSceneManager);
		static FormFactory formFactory;
		ArrayList* pParams = null;

		pSceneManager->RegisterFormFactory(formFactory);
		pSceneManager->RegisterScene(L"MainScene", L"MainForm", L"");
		pSceneManager->RegisterScene(L"MyCardScene", L"MyCardForm", L"");
		pSceneManager->RegisterScene(L"LockScene", L"LockForm", L"");

		pParams = new (std::nothrow) ArrayList();
		NdefMessage* pMsg = NfcManager::GetCachedNdefMessageN();

		pParams->Add(*pMsg);
		pSceneManager->GoForward(ForwardSceneTransition(L"MainScene"), pParams);

		__isSceneRegistered = true;
	}
}
