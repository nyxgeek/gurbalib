inherit "/std/room";

#include "../../domain.h" 
void setup( void ) {

  #include "area.h"

  set_property("x", 40);
  set_property("y", -50);
  set_property("z", -10);
     add_item("red button",
      "A giant red BUTTON!\nIt is glowing and says PRESS ME!");
     add_item("button", "A giant red BUTTON!\nIt is glowing and says PRESS ME!");
   add_action("do_push", "push");
   add_action("do_push", "press");


  add_area( "sewer" );
  set_short( "Rats Lair" );
  set_long( "You appear to have stumbled into a kind of lair. Judging from the number of rats running around, you deduce that this place belongs to the rats. Looking around, you realize that this doesn't seem to be a standard City sewer room. The walls here are made of old red brick, and a large pool of water in the middle reminds you of a jacuzzi. A nest of eggs are in a corner of the lair. \n\nThe end of a pipe juts out here. It appears to be the only exit available.\n\nThere is a giant red button here." );


  set_objects( 
 DIR+"/objects/secard.c", 
 DIR+"/monsters/warrior.c", 
 DIR+"/monsters/warrior.c", 
 DIR+"/monsters/leader.c"
);
 set_exits( ([
  "south" : DIR+"/rooms/sewer/x40y-60z-10.c"
  ]) );
}


int do_push(string arg) {
/*   if (arg == "button") { */
      object obj;

      write("You push the button and a fresh security keycard magically appears.\n");

      obj = clone_object(DIR+"/objects/secard.c");
      obj->setup();
      obj->move(this_player()->query_environment());
      return 1;
/*   } else {*/
/*      return 0;*/
/*   }*/
}
