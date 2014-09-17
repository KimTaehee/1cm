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
#include "MainForm.h"
#include "NfcController.h"
#include "MyCardManager.h"
#include "VcardTranslator.h"
#include <FApp.h>

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Net::Nfc;

NfcController::NfcController(MainForm* pMainForm)
	: __pMainForm(pMainForm)
	, __pNfcManager(null)
	, __pNdefPushManager(null)
{

}

NfcController::~NfcController(void)
{
	delete __pNfcManager;
	delete __pNdefPushManager;
}

bool
NfcController::Initialize(void)
{
	result r = E_SUCCESS;

	//initialize the instance of NfcManager class and add listener.
	__pNfcManager = new (std::nothrow) NfcManager();
	r = __pNfcManager->Construct(*this);
	TryReturn(r == E_SUCCESS, false, "NfcManager::Construct() failed");

	r = __pNfcManager->AddNdefMessageDiscoveryEventListener(*this, NdefRecordType(NDEF_TNF_ALL));
	TryReturn(r == E_SUCCESS, false, "NfcManager::AddNdefMessageDiscoveryEventListener() has failed.");

	r = __pNfcManager->AddDeviceDiscoveryEventListener(*this);
	TryReturn(r == E_SUCCESS, false, "NfcManager::AddDeviceDiscoveryEventListener() has failed.");

	//initialize the instance of NfcPushManager class and set listener.
	__pNdefPushManager = new (std::nothrow) NdefPushManager();
	r = __pNdefPushManager->SetNdefPushManagerListener(this);
	TryReturn(r == E_SUCCESS, false, "NdefPushManager::SetNdefPushManagerListener() has failed.");

	return true;
}

void
NfcController::ToggleNfcActivation(void)
{
	result r = E_SUCCESS;

	//check whether NFC is active or not.
	if (__pNfcManager->IsActivated() == true)
	{
		AppLog("Deactivate Button is clicked!!");

		//deactivate NFC when current state is activate.
		r = __pNfcManager->Deactivate();
		TryReturnVoid(r == E_SUCCESS, "Failed to deactivate NFC %s", GetErrorMessage(r));
	}
	else
	{
		AppLog("Activate Button is clicked!!");

		//activate NFC when current state is deactivate.
		r = __pNfcManager->Activate();
		TryReturnVoid(r == E_SUCCESS, "Failed to activate NFC %s", GetErrorMessage(r));
	}
}

void
NfcController::RegisterPushMessage(const Tizen::Base::String& name, const Tizen::Base::String& number,
		const Tizen::Base::String& address)
{
	NdefMessage* pMsg = VcardTranslator::ConvertStringToVcardN(name, number, address);

	//register the NDEF message and set message description
	__pNdefPushManager->RegisterNdefPushMessage(*pMsg, "My Namecard");

	pMsg->RemoveAllRecords(true);
	delete pMsg;
}

void
NfcController::UnregisterPushMessage(void)
{
	//unregister the NDEF message
	__pNdefPushManager->UnregisterNdefPushMessage();
}

bool
NfcController::IsNfcActivated(void)
{
	//return the current NFC state.
	return __pNfcManager->IsActivated();
}

void
NfcController::OnNdefMessageDetectedN(Tizen::Net::Nfc::NdefMessage* pMessage)
{
	String name;
	String number;
	String address;
	result r = E_SUCCESS;

	//convert from NDEF message(contains V-Card format) to string items when NDEF message is detected.
	AppLog("NDEF message detected");
	r = VcardTranslator::ConvertVcardToString(pMessage, name, number, address);
	TryLog(!IsFailed(r), "Failed to translate V-card to String format.");

	if(!IsFailed(r))
	{
		//show opponent's namecard information in Main scene.
		__pMainForm->GoLockScene(name, number, address);

	}
	pMessage->RemoveAllRecords(true);
	delete pMessage;
}

void
NfcController::OnNdefPushMessageSent(result r)
{
	AppLog("Push NDEF message was sent");
}

void
NfcController::OnNfcDeviceDetected(void)
{
	//convert from string items to NDEF message(contains V-Card format) when other P2P device is detected.
	String name;
	String number;
	String address;
	result r = E_SUCCESS;

	AppLog("Device detected");

	r = MyCardManager::ReadNameCardFromFile(name, number, address);
	TryReturnVoid(r == E_SUCCESS, "Failed to read namecard from file.");

	NdefMessage* pMsg = VcardTranslator::ConvertStringToVcardN(name, number, address);

	//push NDEF message to other device.
	__pNdefPushManager->Push(*pMsg);

	pMsg->RemoveAllRecords(true);
	delete pMsg;
}

void
NfcController::OnNfcDeviceLost(void)
{
	AppLog("Device lost");
}

void
NfcController::OnNfcActivated(result r)
{
	if (IsFailed(r))
	{
		AppLog("NFC Activation failed");
	}
	else
	{
		__pMainForm->ChangeActivationButton(true);
	}
}

void
NfcController::OnNfcDeactivated(result r)
{
	if (IsFailed(r))
	{
		AppLog("NFC Deactivation failed");
	}
	else
	{
		__pMainForm->ChangeActivationButton(false);
	}
}

