inherit "/std/room";

#include "../domain.h"

void setup( void ) {
  add_area( "sewer" );
  set_short( "Sewer Passage - 6-b" );
set_objects( DIR+"/monsters/average_ferret_6.c");
 set_exits( ([
  "north" : DIR+"/rooms/5-b.c",
  "southwest" : DIR+"/rooms/7-a.c"
  ]) );
  set_long( "This is a broad corridor, illuminated only by the greenish glow of the sediment in this hellhole. The walls and floors are covered with liquid. The smell is outright dreadful.%^RESET%^\n\nThe sewer continues to the north, and southwest.%^RESET%^");
}
