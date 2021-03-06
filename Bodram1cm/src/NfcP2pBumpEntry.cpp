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

#include "NfcP2pBump.h"

using namespace Tizen::Base;
using namespace Tizen::Base::Collection;

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

_EXPORT_ int OspMain(int argc, char *pArgv[]);

/**
 * The entry function of Tizen application called by the operating system.
 */
int
OspMain(int argc, char* pArgv[])
{
	result r = E_SUCCESS;

	AppLog("Application started.");
	ArrayList args;
	args.Construct();
	for (int i = 0; i < argc; i++)
	{
		args.Add(*(new (std::nothrow) String(pArgv[i])));
	}

	r = Tizen::App::Application::Execute(NfcP2pBump::CreateInstance, &args);
	TryLog(!IsFailed(r), "Application execution failed-[%s].", GetErrorMessage(r));

	args.RemoveAll(true);
	AppLog("Application finished.");

	return static_cast< int >(r);
}
#ifdef __cplusplus
}
#endif // __cplusplus
