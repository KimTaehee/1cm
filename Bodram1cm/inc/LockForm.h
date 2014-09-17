#ifndef _KTH_LOCK_FORM_H_
#define _KTH_LOCK_FORM_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class LockForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Scenes::ISceneEventListener
	, public Tizen::Ui::ITouchEventListener
{
public:
	LockForm(void);
	virtual ~LockForm(void);

	bool Initialize(void);

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	// from ISceneEventListener
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
			const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
			const Tizen::Ui::Scenes::SceneId& nextSceneId);

	virtual void  OnTouchCanceled (const Tizen::Ui::Control& source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void  OnTouchFocusIn (const Tizen::Ui::Control& source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void  OnTouchFocusOut (const Tizen::Ui::Control& source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void  OnTouchMoved (const Tizen::Ui::Control& source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void  OnTouchPressed (const Tizen::Ui::Control& source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void  OnTouchReleased (const Tizen::Ui::Control& source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);

private:
	static const int IDA_UNLOCK_BUTTON = 101;
};

#endif	//_KTH_LOCK_FORM_H_
