inherit "/std/room";

#include "../domain.h" 

void setup( void ) {

  set_domainname("%^GREEN%^Woodland %^RED%^Critter %^GREEN%^Christmas%^RESET%^");
  set_coords(({ 6, 14 }));
  set_dimensions(({ 12, 16 }));

  set_short( "Woodland" );
  set_long( "This is sprawling woodland, trees can be seen everywhere while critters can be heard in the distance. Animal prints can be seen on the ground." );

 set_exits( ([
  "west" : DIR+"/rooms/5_14.c",
  "north" : DIR+"/rooms/6_13.c",
  "east" : DIR+"/rooms/7_14.c"
  ]) );

}

int do_search(void) {
   object mob;
   mob = clone_object(DIR + "/npc/porcupine");
   mob->setup();
   mob->move(this_player()->query_environment());
   mob->attack(this_player());

   return 1;
}
