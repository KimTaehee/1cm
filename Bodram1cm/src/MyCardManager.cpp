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
#include <FApp.h>
#include <FIo.h>
#include "MyCardManager.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Io;

const wchar_t* NFC_BUMP_MY_CARD_INFO_PATH = L"data/MyCard.data";

MyCardManager::MyCardManager(void)

{

}

MyCardManager::~MyCardManager(void)
{

}

result
MyCardManager::ReadNameCardFromFile(Tizen::Base::String& name, Tizen::Base::String& number, Tizen::Base::String& address)
{
	File file;
	String buffer;
	int length;
	result r = E_SUCCESS;

	r = file.Construct(App::GetInstance()->GetAppRootPath() + NFC_BUMP_MY_CARD_INFO_PATH, "r", false);
	TryReturn(r == E_SUCCESS, r, "Failed to open the file.");

	r = file.Seek(FILESEEKPOSITION_BEGIN, 0);
	TryReturn(r == E_SUCCESS, r, "Failed to repositions the file pointer.");

	//read user's name from data file
	r = file.Read(buffer);
	TryReturn(r == E_SUCCESS, r, "Failed to read my name from file.");

	length = buffer.GetLength();
	buffer.SubString(0, length - 1, name);
	buffer.Clear();

	//read user's phone number from data file
	r = file.Read(buffer);
	TryReturn(r == E_SUCCESS, r, "Failed to read my phone number from file.");

	length = buffer.GetLength();
	buffer.SubString(0, length - 1, number);
	buffer.Clear();

	//read user's e-mail address from data file
	r = file.Read(buffer);
	TryReturn(r == E_SUCCESS, r, "Failed to read my e-mail address from file.");

	length = buffer.GetLength();
	buffer.SubString(0, length - 1, address);

	return r;
}

result
MyCardManager::WriteNameCardToFile(const Tizen::Base::String& name, const Tizen::Base::String& number,
		const Tizen::Base::String& address)
{
	File file;
	result r = E_SUCCESS;

	r = file.Construct(App::GetInstance()->GetAppRootPath() + NFC_BUMP_MY_CARD_INFO_PATH, "w", false);
	TryReturn(r == E_SUCCESS, r, "Failed to open the file.");

	r = file.Seek(FILESEEKPOSITION_BEGIN, 0);
	TryReturn(r == E_SUCCESS, r, "Failed to repositions the file pointer.");

	r = file.Write(name + "\n");
	TryReturn(r == E_SUCCESS, r, "Failed to write my name to file.");

	r = file.Write(number + "\n");
	TryReturn(r == E_SUCCESS, r, "Failed to write my phone number to file.");

	r = file.Write(address + "\n");
	TryReturn(r == E_SUCCESS, r, "Failed to write my e-mail address to file.");

	return r;
}
