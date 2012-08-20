/*
    Copyright (C) 2003-2008 Fons Adriaensen <fons@kokkinizita.net>
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/


#ifndef __LADSPAPLUGIN_H
#define __LADSPAPLUGIN_H

#include <lv2/lv2plug.in/ns/lv2core/lv2.h>


/* This class name is now a misnomer but I have left it as-is to minimize
   fragmentation.  The following typedefs serve the same purpose, so the
   plugins can be built with the correct LV2 type (e.g. uint32_t instead of
   unsigned long) but the actual DSP code has only been changed to use the
   typedef rather than 'hard' switching it to the new type.  This way, it
   should be straightforward to make the same code build as both LADSPA and LV2
   plugins, though since the upstream situation is unclear I have not done
   done so.  ~ David Robillard, Aug. 2012 */

typedef unsigned long SampleRate;
typedef unsigned long SampleCount;
typedef unsigned long PortIndex;
typedef void          PortData;

class LadspaPlugin
{
public:

  LadspaPlugin (SampleRate fsam) : _gain (1.0), _fsam (fsam) {}

  virtual void setport (PortIndex port, PortData *data) = 0;  
  virtual void active  (bool act) = 0;  
  virtual void runproc (SampleCount len, bool add) = 0;  
  virtual ~LadspaPlugin (void) {}

  void setgain (float gain) { _gain = gain; }

protected:

  float _gain;
  float _fsam;
};



#endif
