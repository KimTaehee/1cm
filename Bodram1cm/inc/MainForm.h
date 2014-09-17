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

#ifndef _MAIN_FORM_H_
#define _MAIN_FORM_H_

#include <FBase.h>
#include <FUi.h>
#include <FNet.h>
#include "MyCardForm.h"
#include "NfcController.h"

class MainForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public Tizen::Ui::Scenes::ISceneEventListener
	, public Tizen::Ui::ITouchEventListener
{

public:
	MainForm(void);
	virtual ~MainForm(void);
	bool Initialize(void);

public:
	// from Form
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// from IActionEventListener
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

	//from IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);

	virtual void  OnTouchCanceled (const Tizen::Ui::Control& source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void  OnTouchFocusIn (const Tizen::Ui::Control& source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void  OnTouchFocusOut (const Tizen::Ui::Control& source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void  OnTouchMoved (const Tizen::Ui::Control& source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void  OnTouchPressed (const Tizen::Ui::Control& source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void  OnTouchReleased (const Tizen::Ui::Control& source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);

	// from ISceneEventListener
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);

	void ChangeActivationButton(bool isActivate);
	void GoLockScene(const Tizen::Base::String& name, const Tizen::Base::String& number, const Tizen::Base::String& address);

protected:
	static const int ID_ACTIVATE = 101;
	//static const int ID_MY_CARD = 102;
	static const int ID_DELETE_CARD = 103;
	static const int MSGBOX_TIMEOUT = 2000;

private:
	//Tizen::Ui::Controls::FooterItem __leftFooterItem;
	//Tizen::Ui::Controls::FooterItem __rightFooterItem;
//	Tizen::Ui::Controls::Label* __pCardStatus;
//	Tizen::Ui::Controls::EditField* __pNameField;
//	Tizen::Ui::Controls::EditField* __pNumberField;
//	Tizen::Ui::Controls::EditField* __pAddressField;
//	Tizen::Ui::Controls::Button* __pDeleteNameCard;

	NfcController __nfcController;
	NfcController* __pNfcController;
};

#endif  //_MAIN_FORM_H_
