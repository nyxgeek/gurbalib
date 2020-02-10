inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", 260);
  set_property("y", -40);
  set_property("z", 0);

  add_area( "east" );
  set_short( "Closet" );
  set_long( "This is yet another unused closet, the floor likes like a server rack was in here at one point. You can see the outline in the dust from where it was. Now this room looks completely empty. A button is on the wall." );

   add_action("do_push", "push");
   add_action("do_push", "press");

  add_item("button", "A purple button, it says 'push me'");
 set_exits( ([
  "east" : DIR+"/rooms/east/x270y-40z0.c"
  ]) );
}

int do_push(string arg) {
   if (arg == "button") {
      object obj;

      write("You push the button and out of nowhere a new key appears.\n");

      obj = clone_object(DIR+"/objects/key3.c");
      obj->setup();
      obj->move(this_player()->query_environment());
      return 1;
   } else {
      return 0;
   }
}
