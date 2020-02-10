inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", -10);
  set_property("y", 30);
  set_property("z", -20);

  add_area( "sewer" );
  set_short( "Steam Control Room" );
  set_long( "This is a gigantic room, with a mad array of steam pipes arranged all over the room in a kind of random fashion. Large red-hot boilers are located at the perimeter of the room, the source of all the steam along the corridors. Whole rows of large wheels connected to the steam boilers are arranged conveniently on a large platform. A small screen is suspended above the wheels. A button is just below the screen." );
   add_item("red button",
      "A giant red BUTTON!\nIt is glowing and says PRESS ME!");
     add_item("button", "A giant red BUTTON!\nIt is glowing and says PRESS ME!");
   add_action("do_push", "push");
   add_action("do_push", "press");

  add_item("screen", "The screen appears to be a modified compass panel. It is covered with blinking red dots.");
  add_item("wheels", "These appear to be controlling the flow of the steam through the large pipes all around. Turning one of them will decrease the outflow of steam through the boilers.");
  
 set_exits( ([
  "north" : DIR+"/rooms/sewer/x-10y40z-20.c"
  ]) );
}

int do_push(string arg) {
   if (arg == "button") {
      object obj;

      write("You push the button and out of nowhere a steam key appears.\n");

      obj = clone_object(DIR+"/objects/steamkey.c");
      obj->setup();
      obj->move(this_player()->query_environment());
      return 1;
   } else {
      return 0;
   }
}
