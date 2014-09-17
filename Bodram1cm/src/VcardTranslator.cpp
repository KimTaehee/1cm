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
#include "VcardTranslator.h"

using namespace Tizen::Base;
using namespace Tizen::Base::Utility;
using namespace Tizen::App;
using namespace Tizen::Net::Nfc;

VcardTranslator::VcardTranslator(void)
{
}

VcardTranslator::~VcardTranslator(void)
{
}

NdefMessage*
VcardTranslator::ConvertStringToVcardN(const Tizen::Base::String& name, const Tizen::Base::String& number,
		const Tizen::Base::String& address)
{
	String strPayload;

	strPayload += L"BEGIN:VCARD\nVERSION:2.1\nFN:" + name + "\nTEL;CELL:" + number + "\nEMAIL;PREF;INTERNET:"
			+ address + "\nEND:VCARD\n";

	ByteBuffer* pPayload = Tizen::Base::Utility::StringUtil::StringToUtf8N(strPayload);

	NdefMessage* pMsg = new (std::nothrow) NdefMessage();
	NdefRecordType recordType(NDEF_TNF_MIME_MEDIA);
	recordType.SetName(L"text/x-vCard");
	NdefRecord* pRecord = new (std::nothrow) NdefRecord(recordType);
	pRecord->SetRecordType(recordType);
	pRecord->SetPayload(*pPayload);
	pMsg->AppendRecord(*pRecord);
	delete pPayload;

	return pMsg;
}

result
VcardTranslator::ConvertVcardToString(const NdefMessage* pMsg, Tizen::Base::String& name, Tizen::Base::String& number,
		Tizen::Base::String& address)
{
	String textPayload;
	ByteBuffer* pPayloadData = null;
	char* pDataString = null;

	String myName;
	String myNumber;
	String myAddress;

	String vCardNameStart(L"FN:");
	String vCardNumberStart(L"TEL;CELL:");
	String vCardAddressStart(L"EMAIL;PREF;INTERNET:");

	int lastIndex = 0;
	int startIndexOfName = 0;
	int endIndexOfName = 0;

	int startIndexOfNumber = 0;
	int endIndexOfNumber = 0;

	int startIndexOfEmail = 0;
	int endIndexOfEmail = 0;

	NdefRecord* pRecord = pMsg->GetRecordAt(0);

	pPayloadData = pRecord->GetPayload();
	TryReturn(pPayloadData != null, E_INVALID_FORMAT, "Payload is empty.");

	lastIndex = pPayloadData->GetRemaining();
	pDataString = new char[lastIndex + 1];

	memcpy(pDataString, pPayloadData->GetPointer(), lastIndex);
	pDataString[lastIndex] = '\0';
	StringUtil::Utf8ToString(pDataString, textPayload);

	delete[] pDataString;

	if(textPayload.StartsWith("BEGIN:VCARD\n",0))
	{
		AppLog("This NDEF message contains Vcard format...");

		textPayload.IndexOf(vCardNameStart, 0, startIndexOfName);
		textPayload.IndexOf("\n", startIndexOfName, endIndexOfName);
		textPayload.SubString(startIndexOfName + vCardNameStart.GetLength(),
				endIndexOfName - startIndexOfName - vCardNameStart.GetLength(), myName);

		textPayload.IndexOf(vCardNumberStart, 0, startIndexOfNumber);
		textPayload.IndexOf("\n", startIndexOfNumber, endIndexOfNumber);
		textPayload.SubString(startIndexOfNumber + vCardNumberStart.GetLength(),
				endIndexOfNumber - startIndexOfNumber - vCardNumberStart.GetLength(), myNumber);

		textPayload.IndexOf(vCardAddressStart, 0, startIndexOfEmail);
		textPayload.IndexOf("\n", startIndexOfEmail, endIndexOfEmail);
		textPayload.SubString(startIndexOfEmail + vCardAddressStart.GetLength(),
				endIndexOfEmail - startIndexOfEmail - vCardAddressStart.GetLength(), myAddress);

		name = myName;
		number = myNumber;
		address = myAddress;

		return E_SUCCESS;
	}
	else
	{
		AppLog("This NDEF message not contains V-card format...");

		return E_INVALID_FORMAT;
	}

}
