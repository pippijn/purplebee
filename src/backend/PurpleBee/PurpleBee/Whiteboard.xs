MODULE = PurpleBee      PACKAGE = PurpleBee::Whiteboard                 PREFIX = purple_whiteboard_
# Copyright © 2010 Pippijn van Steenhoven
# See COPYING.AGPL for licence information.


BOOT:
{
}

void
purple_whiteboard_set_ui_ops (PurpleWhiteboardUiOps* ops);

void
purple_whiteboard_set_prpl_ops (PurpleWhiteboard* wb, PurpleWhiteboardPrplOps* ops);

PurpleWhiteboard*
purple_whiteboard_create (PurpleAccount* account, char const* who, int state);

void
purple_whiteboard_destroy (PurpleWhiteboard* wb);

void
purple_whiteboard_start (PurpleWhiteboard* wb);

PurpleWhiteboard*
purple_whiteboard_get_session (PurpleAccount* account, char const* who);

void
purple_whiteboard_draw_list_destroy (GList* draw_list);

gboolean
purple_whiteboard_get_dimensions (PurpleWhiteboard* wb, int& width, int& height);
    OUTPUT:
    width
    height

void
purple_whiteboard_set_dimensions (PurpleWhiteboard* wb, int width, int height);

void
purple_whiteboard_draw_point (PurpleWhiteboard* wb, int x, int y, int color, int size);

void
purple_whiteboard_send_draw_list (PurpleWhiteboard* wb, GList* list);

void
purple_whiteboard_draw_line (PurpleWhiteboard* wb, int x1, int y1, int x2, int y2, int color, int size);

void
purple_whiteboard_clear (PurpleWhiteboard* wb);

void
purple_whiteboard_send_clear (PurpleWhiteboard* wb);

void
purple_whiteboard_send_brush (PurpleWhiteboard* wb, int size, int color);

gboolean
purple_whiteboard_get_brush (PurpleWhiteboard* wb, int& size, int& color);
    OUTPUT:
    size
    color

void
purple_whiteboard_set_brush (PurpleWhiteboard* wb, int size, int color);
