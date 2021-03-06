/* GStreamer
 * Copyright (C) 2013 FIXME <fixme@example.com>
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

#ifndef _GST_HIVOSINK_H_
#define _GST_HIVOSINK_H_

#include <gst/video/gstvideosink.h>

G_BEGIN_DECLS;

#define GST_TYPE_HIVOSINK   (gst_hivosink_get_type())
#define GST_HIVOSINK(obj)   (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_HIVOSINK,GstHivosink))
#define GST_HIVOSINK_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_HIVOSINK,GstHivosinkClass))
#define GST_IS_HIVOSINK(obj)   (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_HIVOSINK))
#define GST_IS_HIVOSINK_CLASS(obj)   (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_HIVOSINK))

typedef struct _GstHivosink GstHivosink;
typedef struct _GstHivosinkClass GstHivosinkClass;

struct _GstHivosink
{
  GstVideoSink base_hivosink;

  GstPad *sinkpad;

  guint vo_hdl;
  gint frame_width, frame_height;
  gint x, y, width, height;
  gboolean freeze, stop_keep_frame;
  guint64 current_timestamp;
  glong frame_count;
};

struct _GstHivosinkClass
{
  GstVideoSinkClass base_hivosink_class;
};

GType gst_hivosink_get_type (void);

G_END_DECLS

#endif
