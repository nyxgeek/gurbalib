inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 4, 11 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. Animal prints can be seen on the ground." );

  set_objects(
    DIR+"/npc/coyote.c"
  );
 set_exits( ([
  "southwest" : DIR+"/rooms/3_12.c",
  "north" : DIR+"/rooms/4_10.c",
  "southeast" : DIR+"/rooms/5_12.c"
  ]) );

}

int do_search(void) {
   this_environment()->setup();   write("An animal appears out of the woodwork");   return 1;
}
