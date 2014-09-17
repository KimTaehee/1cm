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

#ifndef _NFC_CONTROLLER_H_
#define _NFC_CONTROLLER_H_

#include <FBase.h>
#include <FNet.h>

class MainForm;

class NfcController
	: public Tizen::Base::Object
	, public Tizen::Net::Nfc::INfcManagerEventListener
	, public Tizen::Net::Nfc::INdefMessageDiscoveryEventListener
	, public Tizen::Net::Nfc::INdefPushManagerListener
	, public Tizen::Net::Nfc::INfcDeviceDiscoveryEventListener
{
public:
	NfcController(MainForm* pMainForm);
	~NfcController(void);

	bool Initialize(void);
	void ToggleNfcActivation(void);
	void RegisterPushMessage(const Tizen::Base::String& name, const Tizen::Base::String& number, const Tizen::Base::String& address);
	void UnregisterPushMessage(void);
	bool IsNfcActivated(void);

	//from INfcManagerEventListener
	virtual void OnNfcActivated(result r);
	virtual void OnNfcDeactivated(result r);

	//from INdefMessageDiscoveryEventListener
	virtual void OnNdefMessageDetectedN(Tizen::Net::Nfc::NdefMessage* pMessage);

	//from INdefPushManagerListener
	virtual void OnNdefPushMessageSent(result r);

	//INfcDeviceDiscoveryEventListener
	virtual void OnNfcDeviceDetected(void);
	virtual void OnNfcDeviceLost(void);

private:
	MainForm* __pMainForm;
	Tizen::Net::Nfc::NfcManager* __pNfcManager;
	Tizen::Net::Nfc::NdefPushManager* __pNdefPushManager;

	MyCardManager* __pMyCardManager;
};

#endif // _NFC_CONTROLLER_H_
