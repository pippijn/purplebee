#pragma once

#include <purple.h>

namespace uiops
{
  struct whiteboard
  {
    static void create (PurpleWhiteboard* wb);
    static void destroy (PurpleWhiteboard* wb);
    static void set_dimensions (PurpleWhiteboard* wb, int width, int height);
    static void set_brush (PurpleWhiteboard* wb, int size, int color);
    static void draw_point (PurpleWhiteboard* wb, int x, int y, int color, int size);
    static void draw_line (PurpleWhiteboard* wb, int x1, int y1, int x2, int y2, int color, int size);
    static void clear (PurpleWhiteboard* wb);

    static PurpleWhiteboardUiOps create ();
  };
}
