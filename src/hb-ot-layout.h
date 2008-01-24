/*
 * Copyright (C) 2007,2008  Red Hat, Inc.
 *
 *  This is part of HarfBuzz, an OpenType Layout engine library.
 *
 * Permission is hereby granted, without written agreement and without
 * license or royalty fees, to use, copy, modify, and distribute this
 * software and its documentation for any purpose, provided that the
 * above copyright notice and the following two paragraphs appear in
 * all copies of this software.
 *
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
 * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN
 * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
 * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 *
 * Red Hat Author(s): Behdad Esfahbod
 */

#ifndef HB_OT_LAYOUT_H
#define HB_OT_LAYOUT_H

#include "hb-common.h"

HB_BEGIN_DECLS();

typedef uint32_t hb_tag_t;
#define HB_TAG(a,b,c,d) ((hb_tag_t)(((uint8_t)a<<24)|((uint8_t)b<<16)|((uint8_t)c<<8)|(uint8_t)d))
#define HB_TAG_STR(s)   (HB_TAG(((const char *) s)[0], \
				((const char *) s)[1], \
				((const char *) s)[2], \
				((const char *) s)[3]))

typedef uint16_t hb_ot_layout_glyph_properties_t;
typedef uint16_t hb_ot_layout_glyph_t;

typedef struct _HB_OT_Layout HB_OT_Layout;

HB_OT_Layout *
hb_ot_layout_create (const char *font_data,
                     int         face_index);

void
hb_ot_layout_destroy (HB_OT_Layout *layout);

/* TODO 
HB_OT_Layout *
hb_ot_layout_create_sanitize (char *data,
			      make_writable_func);
*/

hb_ot_layout_glyph_properties_t
hb_ot_layout_get_glyph_properties (HB_OT_Layout                    *layout,
				   hb_ot_layout_glyph_t             glyph);

void
hb_ot_layout_set_glyph_properties (HB_OT_Layout                    *layout,
				   hb_ot_layout_glyph_t             glyph,
				   hb_ot_layout_glyph_properties_t  properties);

HB_END_DECLS();

#endif /* HB_OT_LAYOUT_H */
