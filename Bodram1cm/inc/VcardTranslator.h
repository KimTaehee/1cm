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

#ifndef _VCARD_TRANSLATOR_H_
#define _VCARD_TRANSLATOR_H_

#include <FBase.h>
#include <FNet.h>

class VcardTranslator
{
public:
	static Tizen::Net::Nfc::NdefMessage* ConvertStringToVcardN(const Tizen::Base::String& name, const Tizen::Base::String& number,
			const Tizen::Base::String& address);
	static result ConvertVcardToString(const Tizen::Net::Nfc::NdefMessage* pMsg,Tizen::Base::String& name, Tizen::Base::String& number,
			Tizen::Base::String& address);

private:
	VcardTranslator();
	~VcardTranslator();
};

#endif // _VCARD_TRANSLATOR_H_
