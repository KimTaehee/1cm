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
#include "AppResourceId.h"
#include "MyCardForm.h"
#include "MyCardManager.h"
#include <FApp.h>
#include <FGraphics.h>
#include <FText.h>

using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::App;
using namespace Tizen::Graphics;
using namespace Tizen::Text;

MyCardForm::MyCardForm(void)
	: __pNameField(null)
	, __pPhoneNumberField(null)
	, __pEmailAddressField(null)
	, __leftFooterItem()
	, __pNfcController(null)
{

}

MyCardForm::~MyCardForm(void)
{

}

bool
MyCardForm::Initialize(void)
{
	Form::Construct(IDF_MYCARDFORM);

	return true;
}

result
MyCardForm::OnInitializing(void)
{
	String myName;
	String myPhoneNumber;
	String myEmailAddress;
	result r = E_SUCCESS;

	SetName(L"MyCardForm");

	r = MyCardManager::ReadNameCardFromFile(myName, myPhoneNumber, myEmailAddress);
	TryReturn(r == E_SUCCESS, r, "[%s] Failed to read namecard from file.", GetErrorMessage(r));

	//Get handle of edit field, and set text by name of user.
	__pNameField = static_cast<EditField *>(GetControl(IDC_EDITFIELD1));
	TryReturn(__pNameField != null, r = E_FAILURE, "getting handle to edit filed __pNameField failed by %s.", GetErrorMessage(r));
	__pNameField->SetText(myName);

	//Get handle of edit field, and set text by phone number of user.
	__pPhoneNumberField = static_cast<EditField *>(GetControl(IDC_EDITFIELD2));
	TryReturn(__pPhoneNumberField != null, r = E_FAILURE, "getting handle to edit filed __pPhoneNumberField failed by %s.", GetErrorMessage(r));
	__pPhoneNumberField->SetText(myPhoneNumber);

	//Get handle of edit field, and set text by e-mail address of user.
	__pEmailAddressField = static_cast<EditField *>(GetControl(IDC_EDITFIELD3));
	TryReturn(__pEmailAddressField != null, r = E_FAILURE, "getting handle to edit filed __pEmailAddressField failed by %s.", GetErrorMessage(r));
	__pEmailAddressField->SetText(myEmailAddress);

	Footer* pFooter = GetFooter();
	if (pFooter != null)
	{
		pFooter->SetStyle(FOOTER_STYLE_BUTTON_TEXT);
		r = __leftFooterItem.Construct(ID_SAVE);
		r = __leftFooterItem.SetText("Save");
		r = pFooter->AddItem(__leftFooterItem);

		SetFormBackEventListener(this);
		pFooter->AddActionEventListener(*this);
	}

	return r;
}

result
MyCardForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
MyCardForm::OnActionPerformed(const Control& source, int actionId)
{
	MessageBox messageBox;
	result r = E_SUCCESS;
	int modalResult = 0;

	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	ArrayList* pParams = null;
	pParams = new (std::nothrow) ArrayList();

	switch (actionId)
	{
	case ID_SAVE:
		AppLog("Save Button Pressed");
		r = MyCardManager::WriteNameCardToFile(__pNameField->GetText(), __pPhoneNumberField->GetText(), __pEmailAddressField->GetText());
		TryReturnVoid(r == E_SUCCESS, "[%s] Failed to write namecard to file.",GetErrorMessage(r));

		messageBox.Construct(L"My Card", L"Save success", MSGBOX_STYLE_NONE, MSGBOX_TIMEOUT);
		messageBox.ShowAndWait(modalResult);

		//Register push message when save button is pressed
		__pNfcController->RegisterPushMessage(__pNameField->GetText(), __pPhoneNumberField->GetText(), __pEmailAddressField->GetText());
		pSceneManager->GoBackward(BackwardSceneTransition());
		break;

	default:
		break;
	}
}

void
MyCardForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
							   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	if(pArgs)
	{
		__pNfcController = (NfcController*)pArgs->GetAt(0);

		delete pArgs;
	}
}

void
MyCardForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{

}

void
MyCardForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	//Go to Main scene when back button is clicked
	SceneManager* pSceneManager = SceneManager::GetInstance();
	pSceneManager->GoBackward(BackwardSceneTransition());
}
