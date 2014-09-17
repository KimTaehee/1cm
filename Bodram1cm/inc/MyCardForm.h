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

#ifndef _WRITE_FORM_H_
#define _WRITE_FORM_H_

#include <FBase.h>
#include <FUi.h>
#include "MyCardManager.h"
#include "NfcController.h"

class MyCardForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Scenes::ISceneEventListener
{

public:
	MyCardForm(void);
	virtual ~MyCardForm(void);

	bool Initialize(void);
	// from Form
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	// from IActionEventListener
	virtual void OnActionPerformed(const Control& source, int actionId);

	// from IFormBackEventListener
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);

	// from ISceneEventListener
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);

protected:
	static const int ID_SAVE = 501;
	static const int MSGBOX_TIMEOUT = 2000;

private:
	Tizen::Ui::Controls::EditField* __pNameField;
	Tizen::Ui::Controls::EditField* __pPhoneNumberField;
	Tizen::Ui::Controls::EditField* __pEmailAddressField;
	Tizen::Ui::Controls::FooterItem __leftFooterItem;

	NfcController* __pNfcController;
};

#endif
