#include "LockFrame.h"
#include <new>

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

LockFrame::LockFrame(void)
{
}

LockFrame::~LockFrame(void)
{
}

result
LockFrame::OnInitializing(void)
{
	// Create a form
	pForm = new (std::nothrow) LockForm();

	result r = pForm->Initialize();

	// Add the form to the frame
	r = AddControl(*pForm);

	// Set the current form
	r = SetCurrentForm(*pForm);

	// Draw the form
	pForm->Invalidate(true);

	// TODO:
	// Add your frame initialization code here.
	return r;
}

result
LockFrame::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO:
	// Add your frame termination code here.
	return r;
}


