/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * ***** END GPL LICENSE BLOCK *****
 */

/** \file DNA_hair_types.h
 *  \ingroup DNA
 */

#ifndef __DNA_HAIR_TYPES_H__
#define __DNA_HAIR_TYPES_H__

#include "DNA_ID.h"
#include "DNA_customdata_types.h"

/* TODO: for compatibility with node systems and renderers, separate
 * data layers for coordinate and radius seems better? */
typedef struct HairPoint {
  float co[3];
  float radius;
} HairPoint;

/* TODO: make numpoints implicit? It can be automatically computed from
 * next firstpoint. */
typedef struct HairCurve {
  int firstpoint;
  int numpoints; /* Must be 2 or higher. */
} HairCurve;

/* Hair attachment to a mesh.
 * TODO: attach to tesselated triangles or polygons?
 * TODO: what type of interpolation to use for uv? */
typedef struct HairMapping {
  float uv[2];
  int poly;
} HairMapping;

typedef struct Hair {
  ID id;
  struct AnimData *adt; /* animation data (must be immediately after id) */

  int flag;
  int _pad1[1];

  /* Geometry */
  struct HairPoint *points;
  struct HairCurve *curves;
  struct HairMaping *mapping;
  int totpoint;
  int totcurve;

  /* Custom Data */
  struct CustomData pdata;
  struct CustomData cdata;

  /* Material */
  struct Material **mat;
  short totcol;
  short _pad2[3];

  /* Draw Cache */
  void *batch_cache;
} Hair;

/* Hair.flag */
enum {
  HA_DS_EXPAND = (1 << 0),
};

#endif /* __DNA_HAIR_TYPES_H__ */