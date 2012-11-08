/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*- */
/*
 * Copyright (C) 2012 Red Hat
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 *
 * Written by:
 *     Jasper St. Pierre <jstpierre@mecheye.net>
 */

#ifndef __GIS_ASSISTANT_H__
#define __GIS_ASSISTANT_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define GIS_TYPE_ASSISTANT               (gis_assistant_get_type ())
#define GIS_ASSISTANT(obj)                           (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIS_TYPE_ASSISTANT, GisAssistant))
#define GIS_ASSISTANT_CLASS(klass)                   (G_TYPE_CHECK_CLASS_CAST ((klass),  GIS_TYPE_ASSISTANT, GisAssistantClass))
#define GIS_IS_ASSISTANT(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIS_TYPE_ASSISTANT))
#define GIS_IS_ASSISTANT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  GIS_TYPE_ASSISTANT))
#define GIS_ASSISTANT_GET_CLASS(obj)                 (G_TYPE_INSTANCE_GET_CLASS ((obj),  GIS_TYPE_ASSISTANT, GisAssistantClass))

typedef struct _GisAssistant        GisAssistant;
typedef struct _GisAssistantClass   GisAssistantClass;
typedef struct _GisAssistantPrivate GisAssistantPrivate;

struct _GisAssistant
{
  GtkBox parent;

  GisAssistantPrivate *priv;
};

struct _GisAssistantClass
{
  GtkBoxClass parent_class;

  void (* prepare) (GisAssistant *assistant, GtkWidget *page);
  void (* next_page) (GisAssistant *assistant, GtkWidget *page);

  void (* switch_to) (GisAssistant *assistant, GtkWidget *page);
  void (* add_page) (GisAssistant *assistant, GtkWidget *page);
};

GType gis_assistant_get_type (void);

void      gis_assistant_add_page          (GisAssistant *assistant,
                                           GtkWidget    *page);

void      gis_assistant_next_page         (GisAssistant *assistant);
void      gis_assistant_previous_page     (GisAssistant *assistant);
void      gis_assistant_destroy_all_pages (GisAssistant *assistant);

void      gis_assistant_set_page_complete (GisAssistant *assistant,
                                           GtkWidget    *page,
                                           gboolean      complete);
gboolean  gis_assistant_get_page_complete (GisAssistant *assistant,
                                           GtkWidget    *page);

void      gis_assistant_set_page_title    (GisAssistant *assistant,
                                           GtkWidget    *page,
                                           gchar        *title);
gchar *   gis_assistant_get_page_title    (GisAssistant *assistant,
                                           GtkWidget    *page);
gchar *   gis_assistant_get_title         (GisAssistant *assistant);

void      gis_assistant_set_use_arrow_buttons (GisAssistant *assistant,
                                               GtkWidget    *page,
                                               gboolean      use_arrow_buttons);

gboolean  gis_assistant_get_use_arrow_buttons (GisAssistant *assistant,
                                               GtkWidget    *page);

G_END_DECLS

#endif /* __GIS_ASSISTANT_H__ */
