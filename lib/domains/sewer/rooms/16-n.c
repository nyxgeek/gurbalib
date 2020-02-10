inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 16-n" );
set_objects( DIR+"/monsters/average_rat_6.c");
 set_exits( ([
  "east" : DIR+"/rooms/16-o.c",
  "west" : DIR+"/rooms/16-m.c"
  ]) );
  set_long( "This is a broad tunnel, illuminated only by the red glow of the gunk in this hellhole. The walls and floors are covered with oil. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nThe sewer continues to the east, and west.%^RESET%^");
}
