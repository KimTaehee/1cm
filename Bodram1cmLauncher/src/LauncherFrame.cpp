#include <new>
#include "LauncherFrame.h"
#include "LauncherForm.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

LauncherFrame::LauncherFrame(void)
{
}

LauncherFrame::~LauncherFrame(void)
{
}

result
LauncherFrame::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Create a form
	LauncherForm* pLauncherForm = new (std::nothrow) LauncherForm();
	TryReturn(pLauncherForm != null, false, "The memory is insufficient.");
	pLauncherForm->Initialize();

	// Add the form to the frame
	AddControl(pLauncherForm);

	// Set the current form
	SetCurrentForm(pLauncherForm);

	// Draw the form
	pLauncherForm->Invalidate(true);

	// TODO: Add your frame initialization code here.

	return r;
}

result
LauncherFrame::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your frame termination code here.
	return r;
}


