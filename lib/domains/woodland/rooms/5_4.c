inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 5, 4 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. " );

 set_exits( ([
  "southwest" : DIR+"/rooms/4_5.c",
  "east" : DIR+"/rooms/6_4.c",
  "northeast" : DIR+"/rooms/6_3.c",
  "north" : DIR+"/rooms/5_3.c"
  ]) );

}

