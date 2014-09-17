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

#ifndef FORMFACTORY_H_
#define FORMFACTORY_H_

#include <FUiScenesIFormFactory.h>

class FormFactory: public Tizen::Ui::Scenes::IFormFactory {
public:
	FormFactory();
	virtual ~FormFactory();

	virtual Tizen::Ui::Controls::Form* CreateFormN(const Tizen::Base::String &formId, const Tizen::Ui::Scenes::SceneId &sceneId);
};

#endif /* FORMFACTORY_H_ */
