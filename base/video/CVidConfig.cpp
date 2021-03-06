/*
 * CVidConfig.cpp
 *
 *  Created on: 04.02.2011
 *      Author: gerhard
 */

#include "CVidConfig.h"

#include <cstring>
#include <cstdio>

CVidConfig::CVidConfig() :
mRenderScQuality("nearest")
{
	reset();
}

bool CVidConfig::operator==(const CVidConfig& target)
{
	return ( memcmp( &target, this, sizeof(CVidConfig)) == 0);
}

bool CVidConfig::operator!=(const CVidConfig& target)
{
	return !(*this == target);
}

void CVidConfig::reset()
{
	// Default values
	vsync = true;

    mDisplayRect.x = 0;
    mDisplayRect.y = 0;

#if defined(CAANOO) || defined(WIZ) || defined(GP2X) || defined(DINGOO) || defined(NANONOTE)
	//m_Resolution.width=320;
	//m_Resolution.height=240;
    mDisplayRect.w=320;
    mDisplayRect.h=240;
#if defined(GP2X) || defined(NANONOTE)
	//m_Resolution.depth=32;
#else
	//m_Resolution.depth=16;
#endif
	Fullscreen=true;
#else
    mDisplayRect.w = 800;
    mDisplayRect.h = 600;
	Fullscreen=false;
#endif

    m_ScaleXFilter = NONE;
    m_normal_scale = true;
	Zoom=1;

#ifdef USE_OPENGL
    mOpengl = true;
#else
    mOpengl = false; // Must stay optional for better compatibility
#endif

	mAspectCorrection.w=4;
	mAspectCorrection.h=3;
	m_CameraBounds.reset();

    mGameRect.x = 0;
    mGameRect.y = 0;
    mGameRect.w = 320;
    mGameRect.h = 200;

#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
    mOpengl = true;
	mAspectCorrection.w=0;
	mAspectCorrection.h=0;
#endif

#if defined(ANDROID)
	mAspectCorrection.w=0;
	mAspectCorrection.h=0;
#endif

}


void CVidConfig::setResolution(const int width, const int height, const int depth)
{
	const GsRect<Uint16> res(width, height);
	setResolution(res);
}

void CVidConfig::setResolution(const GsRect<Uint16>& res)
{
    mDisplayRect = res;
}
