inherit "/std/room";

void setup(void) {
   add_area("required");

   set_short("Advancement Room");
   set_long("This is a very dull cubicle. The desk looks very plain. It looks like your standard office cubicle. There is one problem however, this desk is floating on a cloud and where there should be walls is just open sky. Somehow this is where you advance levels. It's probably one of EvilMogs sick jokes.\n\nTo advance a level type 'advance' and if you are found worthy you will ascend a level.\n\nTo complete the ticket quest type 'claim' and if you have all the keys it will be yours.\n\nYou may return to the land of the mortals by going down.");

   set_exits(([
      "down" : "/domains/required/rooms/start.c",
   ]));
   add_action("do_advance", "advance");
   add_action("do_advance", "ascend");
   add_action("do_quest", "claim");

}


int do_quest(string arg) {
   object obj1;
   object obj2;
   object obj3;
   object obj4;
   object obj5;
   object obj6;
   object obj7;
   object obj8;
   object player;
   string flag, TICKET;
   int qs1, qs2, qs3, qs4, qs5, qs6, qs7;

   TICKET = "flag{huie2yibv7gyh3gjah}";
   flag = TICKET;
   player = this_player();
   obj1 = player->present("key1");
   obj2 = player->present("key2");
   obj3 = player->present("key3");
   obj4 = player->present("key4");
   obj5 = player->present("key5");
   obj6 = player->present("key6");
   obj7 = player->present("key7");
   obj8 = player->present("key8");
   qs1 = player->is_completed_quest("Ticket");
   qs2 = player->is_completed_quest("Wizard");
   qs3 = player->is_completed_quest("Pottles");
   qs4 = player->is_completed_quest("NewbieVille");
   qs5 = player->is_completed_quest("Sewer");
   qs6 = player->is_completed_quest("Parrot");
   qs7 = player->is_completed_quest("Evil");

   if (qs1 && qs2 && qs3 && qs4 && qs5 && qs6 && qs7) {
     if (player->query_level() > 31) {
         player->set_gender("wizard");
         write("\n%^GREEN%^You have been made a wizard, logout and log back in twice for it to take effect%^RESET%^\n\n");
         CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has hit level 32 and completed all quests", 1);
         return 1;
     }
   }

   if (obj1 && obj2 && obj3 && obj4 && obj5 && obj6 && obj7 && obj8) {
     obj1->destruct();
     obj2->destruct();
     obj3->destruct();
     obj4->destruct();
     obj5->destruct();
     obj6->destruct();
     obj7->destruct();
     obj8->destruct();
     if (player->is_completed_quest("Ticket") == 1) {
       if ((player->query_level() > 31) && (player->is_completed_quest("Wizard") == 1) && (player->is_completed_quest("Ticket") == 1 ) && (player->is_completed_quest("Pottles") == 1) && (player->is_completed_quest("Sewer") == 1) && (player->is_completed_quest("NewbieVille") == 1) && (player->is_completed_quest("Parrot") == 1) && (player->is_completed_quest("Evil") == 1)) {
         player->set_gender("wizard");
         write("\n%^GREEN%^You have been made a wizard, logout and log back in twice for it to take effect%^RESET%^\n\n");
         CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has hit level 32 and completed all quests", 1);
        }
       write("You have already completed the ticket quest.\n");
       write(flag +"\n");
     } else {
       write("Congrats you completed the ticket quest.\n");
       write(flag +"\n");
       player->add_completed_quest("Ticket");
       CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has completed the ticket quest", 1);
       if ((player->query_level() > 31) && (player->is_completed_quest("Wizard") == 1) && (player->is_completed_quest("Ticket") == 1 ) && (player->is_completed_quest("Pottles") == 1) && (player->is_completed_quest("Sewer") == 1) && (player->is_completed_quest("NewbieVille") == 1)) {
         player->set_gender("wizard");
         write("\n%^GREEN%^You have been made a wizard, logout and log back in twice for it to take effect%^RESET%^\n\n");
         CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has hit level 32 and completed the ticket quest", 1);
        }
     }
     return 1;
  } else {
     write("You do not have all the keys, in order to complete the quest\nyou must find all of the keys:\n\n\tKey 1 - City\n\tKey 2 - City\n\tKey 3 - East\n\tKey 4 - North\n\tKey 5 - Nympho\n\tKey 6 - Prison\n\tKey 7 - Sewer\n\tKey 8 - Dungeon\n\n");
     return 1;
   }
   return 0;
}


int do_advance(string arg) {
    int plvl;
    object player, token;
    player = this_player();
    plvl = player->query_level();

    if (!player->ready_for_next_level()) {
      write("You don't have enough experience to advance yet...");
      return 1;
    }

    if (player->ready_for_next_level()) {
        if (plvl < 2) {
          player->increase_level();
          return 1;
        }

        if (((plvl > 1) && (plvl < 4)) && (player->is_completed_quest("NewbieVille") > 0)) {
          player->increase_level();
          return 1;
        }
        if (((plvl > 3) && (plvl < 8)) && (player->is_completed_quest("Wizard") > 0)) {
          player->increase_level();
          return 1;
	}
        if (((plvl > 11) && (plvl < 16)) && (player->is_completed_quest("Pottles") > 0)) {
          player->increase_level();
          return 1;
        }
	if (((plvl > 7) && (plvl < 12)) && (player->is_completed_quest("Sewer") > 0)) {
          player->increase_level();
          return 1;
        }
        } if ((plvl > 15) && (player->is_completed_quest("Ticket") == 1)) {
          player->increase_level();
          return 1;
        }
        if (((plvl > 1) && (plvl < 4)) && (player->is_completed_quest("NewbieVille") == 0)) {
          write("You have been found unworthy, you must complete the newbieville quest\n");
          write("To get to newbieville please go down, then north, and there is a button you have to press.\n");
          write("\n");
          return 1;
        }
        if (((plvl > 3) && (plvl < 8)) && (player->is_completed_quest("Wizard") == 0)) {
          write("You have been found unworthy, you must complete the wizard quest\n");
          write("To complete the wizard quest you must go through the portal and\nfind the wizard potion and then drink it. Be warned the\ncompass doesn't work in the dungeon.\n");
          write("\n");
          return 1;
        }
	if (((plvl > 11) && (plvl < 16)) && (player->is_completed_quest("Pottles") == 0)) {
          write("You have been found unworthy, you must complete the pottles quest\n");
          write("To complete this quest you must find pottles in the sewer of core and then kill him.");
          write("\n");
          return 1;
        }
	if (((plvl > 7) && (plvl < 12)) && (player->is_completed_quest("Sewer") == 0)) {
          write("You have been found unworthy, you must complete the sewer quest\n");
          write("You must find and kill a creature in generator control, I hear rumors arnie has the tracker to find the secard to get to steam control.");
          write("\n");
          return 1;
        } if ((plvl > 15) && (player->is_completed_quest("Ticket") == 0)) {
          write("You have been found unworthy, you must complete the ticket quest\n");
          write("You must type claim to find out where the missing buttons are.....\n\n");
          return 1;
    } else {
      write("You don't have enough experience to advance yet...\n");
      return 1;
    }
}

