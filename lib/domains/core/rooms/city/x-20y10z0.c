inherit "/std/room";
inherit "/std/menu";

#define TO this_object()

#include "../../domain.h" 

static string do_fmenu(void);
static int menu_action_quit(void);

void setup( void ) {

  #include "area.h"

  set_property("x", -20);
  set_property("y", 10);
  set_property("z", 0);
  add_action("do_touch", "touch");
  add_action("do_access", "access");
  add_area( "city" );
  set_short( "Reactor storeroom" );
  set_long( "This storeroom is where the reactor techs keep their components and equipment. Racks and shelves of technical materials, some of which you haven't even seen before, align the walls of this storeroom. A solitary lightpad in the ceiling provides sufficient illumination for you to look around.\n\nThere is a touch padd on one of the walls. You can leave by going west." );
  add_item("touch padd", "its a standard issue touch padd");
  
 set_exits( ([
  "west" : DIR+"/rooms/city/x-30y10z0.c"
  ]) );
}

static int menu_action_quit(void) {
   write("Ok.");
   return 1;
}

static string do_fmenu(void) {
  mixed *menu;
  int q7track;
  object player;
  player = this_player();
  q7track = player->query_q7_tracker();
  menu = ( { } );
   if (q7track == 7) {
     menu += ({
      ({
         "1", "Access Control", nil, make_fcall(TO, "menu_action_1")
      })
     }); 
   }
   if (q7track == 31) {
     menu += ({
      ({
         "1", "Bribery", nil, make_fcall(TO, "menu_action_2")
      })
     });
   }
   if (q7track == 63) {
     menu += ({
      ({
         "1", "Greed", nil, make_fcall(TO, "menu_action_3")
      })
     });
   }
   if (q7track == 127) {
     menu += ({
      ({
         "1", "Details", nil, make_fcall(TO, "menu_action_4")
      })
     });
   }
   menu += ({
      ({
         "q", "quit menu", nil, make_fcall(TO, "menu_action_quit")
      })
   });

   do_menu("Company Access:", menu);
   return " ";
}

int do_touch(string arg) {
   if (arg == "padd") {
      do_fmenu();
      return 1;
   } else {
      return 0;
   }
}

int menu_action_1(void) {
  write("You company access card has had its access upgraded...you may now access Grey's computer");
  this_player()->set_q7_tracker(15);
  return 1;
}

int menu_action_2(void) {
  write("It appears as if evilmog controls everything...in fact he can be bribed for cheat codes...find him at derbycon and ask him for the password to Flag 31\n");
  write("You can upgrade your access by typing in '%^MAGENTA%^access%^RESET%^ %^GREEN%^code%^RESET%^ where code is the password he or a member of the church of wifi gives you....\n\n");
  write("Alternatively his agent can be found in the zombie bar....\n");
  return 1;
}

int menu_action_3(void) {
  write("It looks like even evil mog has a master, you will have to find and bribe renderman for the password to flag 63....");
  write("You can upgrade your access by typing in '%^MAGENTA%^access%^RESET%^ %^GREEN%^code%^RESET%^ where code is the password he or a member of the church of wifi gives you...\n\n");
  write("Alternatively you can find the access code in the sandworm pits.....");
  return 1;
}

int menu_action_4(void) {
   write("Ok so here's the deal most of the company is on the take, and the company is wholy owned by the church of wifi....\n");
   write("You have a choice, you can either go with the flow and work for the church or you can exit the airlock and find another colony...\n");
   write("To make this choice you must use the access code of good or evil.");
   return 1;
}

int do_access(string arg) {
   if (arg == "supra") {
     if (this_player()->query_q7_tracker() == 31) {
       write("Wow you found evil mog and bought him beer, I guess you can proceed....");
       this_player()->set_q7_tracker(63);
       return 1;
     } else {
       write("The access code is incorrect....");
       return 1;
     }
   }
   if (arg == "kikiki") {
     if (this_player()->query_q7_tracker() == 63) {
       write("Wow you found render and bought him beer, I guess you can proceed....");
       this_player()->set_q7_tracker(127);
       return 1;
     } else {
       write("The access code is incorrect....");
       return 1;
     }
   }
   if (arg == "good") {
     if (this_player()->query_q7_tracker() == 127) {
       write("Ok so you chose good....Please escort yourself to the airlock");
       this_player()->set_q7_tracker(128);
       return 1;
     } else {
       write("The access code is incorrect....");
       return 1;
     }
   }
  if (arg == "evil") {
     if (this_player()->query_q7_tracker() == 127) {
         write("%^YELLOW%^EvilMogs Agent %^MAGENTA%^tells you: your chose wisely......\n%^RESET%^");
         this_player()->set_q7_tracker(255);
         write("Your flag is flag{w4adb8vsbkaq8b6nug}\n");
         this_player()->add_completed_quest("Evil");
         this_player()->set_q7_tracker(255);
         CHANNEL_D->chan_send_string("announce", "", this_player()->query_name() +" has completed the evil quest", 1);
         return 1;
     } else {
         write("The access code is incorrect....");
         return 1;
     }
   }

}
