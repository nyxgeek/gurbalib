inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Passage - 13-c" );
set_objects( DIR+"/monsters/sub-average_parrot_5.c");
 set_exits( ([
  "east" : DIR+"/rooms/13-d.c",
  "west" : DIR+"/rooms/13-b.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the orange glow of the sediment in this area. The walls and floors are covered with dust. To add to that, the smell here isn't exactly perfumy either.%^RESET%^\n\nTunnels can be found to the east, and west.%^RESET%^");
}
