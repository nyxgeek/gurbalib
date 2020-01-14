inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 7, 13 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. Animal prints can be seen on the ground." );

  set_objects(
    DIR+"/npc/mouse.c"
  );
 set_exits( ([
  "west" : DIR+"/rooms/6_13.c",
  "northeast" : DIR+"/rooms/8_12.c"
  ]) );

}

int do_search(void) {
   this_environment()->setup();   write("An animal appears out of the woodwork");   return 1;
}
