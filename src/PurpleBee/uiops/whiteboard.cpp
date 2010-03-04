#include "PurpleBee.h"
#include "perl/call.h"
#include "uiops/whiteboard.h"

#define OPS "UiOps::Whiteboard::"

namespace uiops
{
  void
  whiteboard::create (PurpleWhiteboard* wb)
  {
    return server->call<void> (OPS "create", wb);
  }

  void
  whiteboard::destroy (PurpleWhiteboard* wb)
  {
    return server->call<void> (OPS "destroy", wb);
  }

  void
  whiteboard::set_dimensions (PurpleWhiteboard* wb, int width, int height)
  {
    return server->call<void> (OPS "set_dimensions", wb, width, height);
  }

  void
  whiteboard::set_brush (PurpleWhiteboard* wb, int size, int color)
  {
    return server->call<void> (OPS "set_brush", wb, size, color);
  }

  void
  whiteboard::draw_point (PurpleWhiteboard* wb, int x, int y, int color, int size)
  {
    return server->call<void> (OPS "draw_point", wb, x, y, color, size);
  }

  void
  whiteboard::draw_line (PurpleWhiteboard* wb, int x1, int y1, int x2, int y2, int color, int size)
  {
    return server->call<void> (OPS "draw_line", wb, x1, y1, x2, y2, color, size);
  }

  void
  whiteboard::clear (PurpleWhiteboard* wb)
  {
    return server->call<void> (OPS "clear", wb);
  }

  PurpleWhiteboardUiOps
  whiteboard::create ()
  {
    return {
      create,
      destroy,
      set_dimensions,
      set_brush,
      draw_point,
      draw_line,
      clear,

      // reserved
      NULL,
      NULL,
      NULL,
      NULL,
    };
  }
}
