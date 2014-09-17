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
#include <FGraphics.h>
#include <FMedia.h>
#include "AppResourceId.h"
#include "NfcP2pBump.h"
#include "MainForm.h"
#include "MyCardManager.h"
#include "VcardTranslator.h"
#include "MyCardForm.h"
#include "ImagePanel.h"

using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Base::Utility;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::App;
using namespace Tizen::Net::Nfc;
using namespace Tizen::Graphics;

MainForm::MainForm(void)
	//: __leftFooterItem()
	//, __rightFooterItem()
//	, __pCardStatus(null)
//	, __pNameField(null)
//	, __pNumberField(null)
//	, __pAddressField(null)
//	, __pDeleteNameCard(null)
:	 __nfcController(this)
	, __pNfcController(null)
{

}

MainForm::~MainForm(void)
{

}

bool
MainForm::Initialize(void)
{
	bool result = false;

	Construct(IDF_MAINFORM);

	result = __nfcController.Initialize();
	TryReturn(result == true, false, "Nfc resources are not available.");

	return true;
}

result
MainForm::OnInitializing(void)
{
	AppLog("OnInitializing invoked! set imagepanel");
	String key_value;

	//result r = E_SUCCESS;
	SetName("MainForm");

	//set image bg
	ImagePanel* pImageBg = new (std::nothrow) ImagePanel(L"screen-density-xhigh/main_ui_bg.png");
	result r = pImageBg->Initialize(Rectangle(0, 0, GetClientAreaBounds().width, GetClientAreaBounds().height));
	r = AddControl(pImageBg);
	pImageBg->SetShowState(true);

	//set image text
	ImagePanel* pImageText = new (std::nothrow) ImagePanel(L"screen-density-xhigh/main_str1.png");
	r = pImageText->Initialize(Rectangle(67, 720, 357, 23));
	r = AddControl(pImageText);
	pImageText->SetShowState(true);

	//set image button
	ImagePanel* pImageBtn = new (std::nothrow) ImagePanel(L"screen-density-xhigh/main_btn_hover.png");
	r = pImageBtn->Initialize(Rectangle(123, 427, 240, 240));
	r = AddControl(pImageBtn);
	pImageBtn->SetShowState(true);
	pImageBtn->AddTouchEventListener(*this);

	Invalidate(true);


	//__pCardStatus = static_cast< Label* >(GetControl(IDC_CARD_STATUS));
//	__pCardStatus->SetTextConfig(30, LABEL_TEXT_STYLE_BOLD);
//	__pCardStatus->SetTextHorizontalAlignment(ALIGNMENT_CENTER);
//	__pCardStatus->SetTextColor(Tizen::Graphics::Color::GetColor(COLOR_ID_BLACK));
//	__pCardStatus->SetTextHorizontalAlignment(ALIGNMENT_CENTER);
//	__pCardStatus->SetTextVerticalAlignment(ALIGNMENT_MIDDLE);
//	__pCardStatus->SetText(L"NFC카드를 Tag해 주세요. ");
//
//	__pNameField = static_cast< EditField* >(GetControl(IDC_NAME_FIELD));
//	__pNameField->SetShowState(false);
//	__pNameField->SetViewModeEnabled(true);
//
//	__pNumberField = static_cast< EditField* >(GetControl(IDC_NUMBER_FIELD));
//	__pNumberField->SetShowState(false);
//	__pNumberField->SetViewModeEnabled(true);
//
//	__pAddressField = static_cast< EditField* >(GetControl(IDC_ADDRESS_FIELD));
//	__pAddressField->SetShowState(false);
//	__pAddressField->SetViewModeEnabled(true);
//
//	__pDeleteNameCard = static_cast< Button* >(GetControl(IDC_BUTTON1));
//	__pDeleteNameCard->SetText(L"Delete");
//	__pDeleteNameCard->SetActionId(ID_DELETE_CARD);
//	__pDeleteNameCard->SetTextColor(Tizen::Graphics::Color::GetColor(COLOR_ID_RED));
//	__pDeleteNameCard->SetShowState(false);
//	__pDeleteNameCard->AddActionEventListener(*this);

//	Footer* pFooter = GetFooter();
//	if (pFooter != null)
//	{
//		pFooter->SetStyle(FOOTER_STYLE_BUTTON_TEXT);
//		r = __leftFooterItem.Construct(ID_ACTIVATE);
//
//		if (__nfcController.IsNfcActivated() == true)
//		{
//			__nfcController.ToggleNfcActivation();
//		}
//
//		//Find whether NFC is active or not.
//		if (__nfcController.IsNfcActivated() == true)
//		{
//			r = __leftFooterItem.SetText("NFC 비 활성화 하기");
//		}
//		else
//		{
//			r = __leftFooterItem.SetText("NFC 활성화 하기");
//		}
//		r = pFooter->AddItem(__leftFooterItem);
//		//r = __rightFooterItem.Construct(ID_MY_CARD);
//		//r = __rightFooterItem.SetText("My Card");
//		//r = pFooter->AddItem(__rightFooterItem);
//		pFooter->AddActionEventListener(*this);
//		SetFormBackEventListener(this);
//	}

	return r;
}

result
MainForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	return r;
}
void
MainForm::GoLockScene(const Tizen::Base::String& name, const Tizen::Base::String& number, const Tizen::Base::String& address)
{
	//move to next lockscene
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoForward(ForwardSceneTransition(L"LockScene",
			SCENE_TRANSITION_ANIMATION_TYPE_ZOOM_IN));

	//__pCardStatus->SetShowState(false);

	//__pCardStatus->SetText("NFC TAG SUCCESS!!");

	//MessageBox _messageBox;

	//_messageBox.Construct(L"메시지 도착", L"NFC Successfully Activated.", MSGBOX_STYLE_NONE, MSGBOX_TIMEOUT);
	//_messageBox.Construct(L"메시지 도착", L"NFC Successfully Activated.", MSGBOX_STYLE_NONE, MSGBOX_TIMEOUT);
//	__pNameField->SetTitleText("Name");
//	__pNameField->SetText(name);
//	__pNameField->SetShowState(true);
//
//	__pNumberField->SetTitleText("Phone number");
//	__pNumberField->SetText(number);
//	__pNumberField->SetShowState(true);
//
//	__pAddressField->SetTitleText("e-mail address");
//	__pAddressField->SetText(address);
//	__pAddressField->SetShowState(true);

	//__pDeleteNameCard->SetShowState(true);

	//RequestRedraw();
}

void
MainForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	AppLog("OnActionPerformed invoked!");
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	ArrayList* pParams = null;
	pParams = new (std::nothrow) ArrayList();

	switch (actionId)
	{
	case ID_ACTIVATE:
		//MyCardForm::OnInitializing();		// 초기화 하고
		SceneManager* pSceneManager = SceneManager::GetInstance();

		result r = E_SUCCESS;
		String key1 = "test1";
		String key2 = "test2";
		String key3 = "test3";

		r = MyCardManager::WriteNameCardToFile(key1, key2, key3);
		TryReturnVoid(r == E_SUCCESS, "[%s] Failed to write namecard to file.",GetErrorMessage(r));

		//__nfcController.RegisterPushMessage(key1, key2, key3);
		__pNfcController->RegisterPushMessage(key1, key2, key3);
		pSceneManager->GoBackward(BackwardSceneTransition());

		// 키값쓰고
		__nfcController.ToggleNfcActivation();
		break;

	//case ID_MY_CARD:
		//Go to MyCard scene

		//AppLog("MyCard Button Clicked");
		//pParams->Add(__nfcController);
		//pSceneManager->GoForward(ForwardSceneTransition(L"MyCardScene"), pParams);

	//	break;

	//case 103:
//		AppLog("Delete Button Clicked");
//		__pCardStatus->SetShowState(true);
//		__pNameField->SetShowState(false);
//		__pNumberField->SetShowState(false);
//		__pAddressField->SetShowState(false);
//		__pDeleteNameCard->SetShowState(false);
//
//		RequestRedraw();
//		break;

	//default:
		//break;
	}
}

void
MainForm::OnFormBackRequested(Form& source)
{
	AppLog("OnFormBackRequested invoked!");
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}

void
MainForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
							   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	String name;
	String number;
	String address;
	result r = E_SUCCESS;

	if(pArgs)
	{
		NdefMessage* pMsg = (NdefMessage*)pArgs->GetAt(0);
		r = VcardTranslator::ConvertVcardToString(pMsg, name, number, address);
		TryLog(!IsFailed(r), "Failed to translate V-card to String format.");

		if (!IsFailed(r)) //TAG SUCCESS!
		{
			GoLockScene(name, number, address);

		}
		delete pArgs;
	}
}

void
MainForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
}

void
MainForm::ChangeActivationButton(bool isActivate)
{
	//Footer* pFooter = GetFooter();
	//MessageBox messageBox;
	//int modalResult = 0;

	//Change the text of left footer item when NFC state is changed.
	if (isActivate)
	{
		//AppLog("NFC 활성화 하기");
		//__leftFooterItem.SetText("NFC 비 활성화 하기");
//		if (pFooter != null)
//		{
//			pFooter->RemoveItemAt(0);
//			pFooter->InsertItemAt(0, __leftFooterItem);
//			RequestRedraw();
//		}
		//messageBox.Construct(L"NFC 활성화", L"NFC Successfully Activated.", MSGBOX_STYLE_NONE, MSGBOX_TIMEOUT);
		// Call ShowAndWait - draw, show itself and process events
		//messageBox.ShowAndWait(modalResult);
	}
	else
	{
		//AppLog("NFC 비 활성화 하기");
//		__leftFooterItem.SetText("NFC 활성화 하기");
//		if (pFooter != null)
//		{
//			pFooter->RemoveItemAt(0);
//			pFooter->InsertItemAt(0, __leftFooterItem);
//			RequestRedraw();
//		}
		//messageBox.Construct(L"NFC Deactivate", L"NFC Successfully Deactivated.", MSGBOX_STYLE_NONE, MSGBOX_TIMEOUT);
		// Call ShowAndWait - draw, show itself and process events
		//messageBox.ShowAndWait(modalResult);
	}
}

void
MainForm::OnTouchPressed (const Tizen::Ui::Control& source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo)
{
	AppLog("i'm here!!!!");

	//set image text
	ImagePanel* pImageText = new (std::nothrow) ImagePanel(L"screen-density-xhigh/main_str2.png");
	result r = pImageText->Initialize(Rectangle(67, 720, 357, 23));
	r = AddControl(pImageText);
	pImageText->SetShowState(true);

	//set image btn
	ImagePanel* pImageBtn = new (std::nothrow) ImagePanel(L"screen-density-xhigh/main_btn_nfc.png");
	r = pImageBtn->Initialize(Rectangle(123, 427, 240, 240));
	r = AddControl(pImageBtn);
	pImageBtn->SetShowState(true);

	Invalidate(true);

	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	ArrayList* pParams = null;
	pParams = new (std::nothrow) ArrayList();

	String key1 = "test1";
	String key2 = "test2";
	String key3 = "test3";

	r = MyCardManager::WriteNameCardToFile(key1, key2, key3);
	TryReturnVoid(r == E_SUCCESS, "[%s] Failed to write namecard to file.",GetErrorMessage(r));

	//__nfcController.RegisterPushMessage(key1, key2, key3);
	__pNfcController->RegisterPushMessage(key1, key2, key3);
	pSceneManager->GoBackward(BackwardSceneTransition());

	// 키값쓰고
	__nfcController.ToggleNfcActivation();

	//case ID_MY_CARD:
	//Go to MyCard scene

	//AppLog("MyCard Button Clicked");
	//pParams->Add(__nfcController);
	//pSceneManager->GoForward(ForwardSceneTransition(L"MyCardScene"), pParams);

	//	break;

	//case 103:
	//		AppLog("Delete Button Clicked");
	//		__pCardStatus->SetShowState(true);
	//		__pNameField->SetShowState(false);
	//		__pNumberField->SetShowState(false);
	//		__pAddressField->SetShowState(false);
	//		__pDeleteNameCard->SetShowState(false);
	//
	//		RequestRedraw();
	//		break;

	//default:
	//break;
}
void MainForm::OnTouchCanceled (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){}
void MainForm::OnTouchFocusIn (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){}
void MainForm::OnTouchFocusOut (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){}
void MainForm::OnTouchMoved (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){}
void MainForm::OnTouchReleased (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){}
