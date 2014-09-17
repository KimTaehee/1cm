//
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
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

#ifndef _IMAGE_PANEL_H_
#define _IMAGE_PANEL_H_

#include <FUi.h>
#include <FGraphics.h>

using namespace Tizen::Base;

class ImagePanel
	: public Tizen::Ui::Controls::Panel
	, public Tizen::Ui::IOrientationEventListener
{
private:
	String path;

public:
	ImagePanel(String _filepath);
	virtual ~ImagePanel(void);

	result Initialize(Tizen::Graphics::Rectangle rect);

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual result OnDraw(void);
	virtual void OnOrientationChanged(const Tizen::Ui::Control &source, Tizen::Ui::OrientationStatus orientationStatus);

private:
	Tizen::Graphics::Bitmap *__pTizenBitmap;
};

#endif
