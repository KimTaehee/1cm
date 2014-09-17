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

#include <FUi.h>
#include "FormFactory.h"
#include "MainForm.h"
#include "MyCardForm.h"
#include "LockForm.h"

using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

FormFactory::FormFactory()
{

}

FormFactory::~FormFactory()
{

}

Form*
FormFactory::CreateFormN(const Tizen::Base::String &formId, const Tizen::Ui::Scenes::SceneId &sceneId)
{
	Form* pNewForm = null;
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	if (formId == L"MainForm")
	{
		MainForm* pForm = new (std::nothrow) MainForm();
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	else if (formId == L"MyCardForm")
	{
		MyCardForm* pForm = new (std::nothrow) MyCardForm();
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	else if (formId == L"LockForm")
	{
		LockForm* pForm = new (std::nothrow) LockForm();
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}

	return pNewForm;
}


