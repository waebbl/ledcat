/*
 * ledcat - CLI tool to send greyscale values to LED devices using libniftyled
 * Copyright (C) 2006-2014 Daniel Hiepler <daniel@niftylight.de>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Alternatively, the contents of this file may be used under the
 * GNU Lesser General Public License Version 2.1 (the "LGPL"), in
 * which case the following provisions apply instead of the ones
 * mentioned above:
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#ifndef _LEDCAT_H
#define _LEDCAT_H


/** global structure to hold various information */
struct Ledcat
{
        /** running state (true when running, set to false to break main-loop */
        bool                            running;
        /** name of preferences-file */
        char                            prefsfile[1024];
        /** pixelformat of raw frame */
        char                            pixelformat[1024];
        /** array with filenames to cat */
        char                          **files;
        /** amount of filenames to cat */
        size_t                          filecount;
        /** current file descriptor */
        int                             fd;
        /** current stream */
        FILE                           *file;
        /** requested framerate */
        int                             fps;
        /** input frame width (in pixels) */
        LedFrameCord                    width;
        /** input frame height (in pixels) */
        LedFrameCord                    height;
        /** true if raw-input data is big-endian ordered */
        bool                            is_big_endian;
        /** true if we should endlessly loop through files */
        bool                            do_loop;
        /** true if caching should be disabled */
        bool                            no_caching;
#if HAVE_IMAGEMAGICK == 1
        /** true to treat input as raw-data, false to use ImageMagick */
        bool                            raw;
        /** ImageMagick map string */
        char                            map[64];
        /** ImageMagick storage format */
        StorageType                     storage;
        /** ImageMagick wand */
        MagickWand                     *mw;
        /** frames sent to LED setup */
        long long unsigned int          frames_sent;
#endif
};



#endif  /** _LEDCAT_H */
