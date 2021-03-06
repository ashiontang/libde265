/*
 * libde265 example application "dec265".
 * Copyright (c) 2013-2014 struktur AG, Dirk Farin <farin@struktur.de>
 *
 * This file is part of dec265, an example application using libde265.
 *
 * dec265 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * dec265 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with dec265.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <SDL.h>


class SDL_YUV_Display
{
public:

  bool init(int frame_width, int frame_height);
  void display(const unsigned char *Y, const unsigned char *U, const unsigned char *V,
               int stride, int chroma_stride);
  void close();

  bool doQuit() const;

  bool isOpen() const { return mWindowOpen; }

private:
  SDL_Surface *mScreen;
  SDL_Overlay *mYUVOverlay;
  SDL_Rect     rect;
  bool         mWindowOpen;
};
