/*
 * GsControl.h
 *
 *  Created on: 30.10.2011
 *      Author: gerstrong
 *
 *  Base Class for any Type of Control
 */

#ifndef GsControl_H_
#define GsControl_H_

#include <base/InputEvents.h>
#include <base/utils/Geometry.h>


class GsControl
{
public:
	enum Style
	{
		UNSET,
		NONE,
		VORTICON,
		GALAXY,
		GALAXY_BORDERED
	};


    GsControl();
    virtual ~GsControl() {}

	virtual void processLogic() = 0;

    void processBlendEffects();

    void processPointingState()
    {
        processPointingState(mRect);
    }

    void processPointingState(const GsRect<float> &rect);

    virtual void processRender(const GsRect<float> &RectDispCoordFloat) = 0;

    virtual void updateGraphics() {}


    void setRect( const GsRect<float>& rect )
	{	mRect = rect;	}


    void enable( const bool value )
    {	mEnabled = value;	}

    bool isEnabled()
    {   return mEnabled;    }

    /*void setHovered( const bool value )
    {	mHovered = value;	}*/

    void select( const bool value )
    { mSelected = value; }

    bool isSelected()
    { return mSelected; }


    bool Up()
    {	return mReleased;	}


    void setDown( const bool value )
    {
        mHovered = value;
    }

	virtual bool sendEvent(const InputCommands command) { return false; }


	void drawTwirl( const SDL_Rect& lRect );

	void drawBlinker( const SDL_Rect& lRect );


    // The relative rect describes the rect which is normally tied to its parent.
    GsRect<float> mRect;
	

protected:

    bool mEnabled;
    
	int mFontID;

    // For mouse/touch we have those
	bool mHovered;
    bool mPressed;
    bool mReleased;

    // This is needed for gamepad/keyboard input
    bool mSelected;

	static int mTwirliconID;

    int mLightRatio = 128; // This will blend between selected and unselected item.

    /**
     * @brief mHoverTriggers    This is for touch friendly devices were there is no device
     */
#ifdef ANDROID
    static const bool mHoverTriggers = true;
#else
    static const bool mHoverTriggers = false;
#endif
};


#endif /* GsControl_H_ */
