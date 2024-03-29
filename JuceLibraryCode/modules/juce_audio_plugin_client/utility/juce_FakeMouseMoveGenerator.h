/*
  ==============================================================================

   This file is part of the JUCE library.
   Copyright (c) 2013 - Raw Material Software Ltd.

   Permission is granted to use this software under the terms of either:
   a) the GPL v2 (or any later version)
   b) the Affero GPL v3

   Details of these licenses can be found at: www.gnu.org/licenses

   JUCE is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
   A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

   ------------------------------------------------------------------------------

   To release a closed-source product which uses JUCE, commercial licenses are
   available: visit www.juce.com for more information.

  ==============================================================================
*/

#ifndef __JUCE_FAKEMOUSEMOVEGENERATOR_JUCEHEADER__
#define __JUCE_FAKEMOUSEMOVEGENERATOR_JUCEHEADER__

#if JUCE_MAC && JUCE_SUPPORT_CARBON

//==============================================================================
// Helper class to workaround carbon windows not getting mouse-moves..
class FakeMouseMoveGenerator  : private Timer
{
public:
    FakeMouseMoveGenerator()
    {
        startTimer (1000 / 30);
    }

    void timerCallback() override
    {
        // workaround for carbon windows not getting mouse-moves..
        const Point<int> screenPos (Desktop::getInstance().getMainMouseSource().getScreenPosition());

        if (screenPos != lastScreenPos)
        {
            lastScreenPos = screenPos;
            const ModifierKeys mods (ModifierKeys::getCurrentModifiers());

            if (! mods.isAnyMouseButtonDown())
                if (Component* const comp = Desktop::getInstance().findComponentAt (screenPos))
                    if (ComponentPeer* const peer = comp->getPeer())
                        if (! peer->isFocused())
                            peer->handleMouseEvent (0, peer->globalToLocal (screenPos), mods, Time::currentTimeMillis());
        }
    }

private:
    Point<int> lastScreenPos;
};

#else
struct FakeMouseMoveGenerator {};
#endif

#endif   // __JUCE_FAKEMOUSEMOVEGENERATOR_JUCEHEADER__
