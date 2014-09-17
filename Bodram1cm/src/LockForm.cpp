#include "AppResourceId.h"
#include "LockForm.h"
#include "ImagePanel.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Graphics;

extern bool isLocked;

LockForm::LockForm(void)
{
}

LockForm::~LockForm(void)
{
}

bool
LockForm::Initialize(void)
{
	Construct(IDL_FORM);

	return true;
}

result
LockForm::OnInitializing(void)
{
//	Button *pButton = static_cast<Button*>(GetControl(IDC_BUTTON2));
//	pButton->SetActionId(IDA_UNLOCK_BUTTON);
//	pButton->AddActionEventListener(*this);

	//set image bg
	ImagePanel* pImageBg = new (std::nothrow) ImagePanel(L"screen-density-xhigh/phone_lock.png");
	result r = pImageBg->Initialize(Rectangle(0, 0, GetClientAreaBounds().width, GetClientAreaBounds().height));
	r = AddControl(pImageBg);
	pImageBg->SetShowState(true);

	//set image button
	ImagePanel* pImageBtn = new (std::nothrow) ImagePanel(L"screen-density-xhigh/unlock_btn.png");
	r = pImageBtn->Initialize(Rectangle(123, 487, 240, 240));
	r = AddControl(pImageBtn);
	pImageBtn->SetShowState(true);
	pImageBtn->AddTouchEventListener(*this);

	AppLog("isLocked = true");
	isLocked = true;
	// TODO:
	// Add your initialization code here
	return r;
}

result
LockForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO:
	// Add your termination code here
	return r;
}

void
LockForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	// TODO:
	// To unlock the screen, terminate the lock application.
	AppLog("OnActionPerformed called!");
	if (actionId == IDA_UNLOCK_BUTTON)
	{
		AppLog("actionId == IDA_UNLOCK_BUTTON, destroy myself");

		AppLog("isLocked = false"); //exit app normally
		isLocked = false;

		UiApp* pApp = UiApp::GetInstance();
		AppAssert(pApp);
		pApp->Terminate();
	}
}

void
LockForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
							   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
}

void
LockForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{

}

void
LockForm::OnTouchPressed (const Tizen::Ui::Control& source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo)
{
	AppLog("isLocked = false"); //exit app normally
	isLocked = false;

	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}
void LockForm::OnTouchCanceled (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){}
void LockForm::OnTouchFocusIn (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){}
void LockForm::OnTouchFocusOut (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){}
void LockForm::OnTouchMoved (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){}
void LockForm::OnTouchReleased (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){}
