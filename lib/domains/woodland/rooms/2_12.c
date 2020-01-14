inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 2, 12 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. Animal prints can be seen on the ground." );

  set_objects(
    DIR+"/npc/chickadee.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/1_12.c",
  "east" : DIR+"/rooms/3_12.c"
  ]) );

}

int do_search(void) {
   this_environment()->setup();   write("An animal appears out of the woodwork");   return 1;
}
