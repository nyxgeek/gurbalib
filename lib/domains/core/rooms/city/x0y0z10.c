inherit "/std/room";
inherit "/std/menu";

#define TO this_object()

#include "../../domain.h" 

static string do_fmenu(void);

void setup( void ) {

  #include "area.h"

  set_property("x", 0);
  set_property("y", 0);
  set_property("z", 10);

  add_area( "city" );
  set_short( "Operations" );
  set_long( "This room is full of operations consoles, this is where the entire colony is managed from. A big terminal is at the center of the room. There is also a console on the wall...." );

  add_item("terminal", "This is a terminal, type '%^MAGENTA%^activate%^RESET%^' to find out what it can do");
  add_action("do_activate", "activate");

  add_item("console", "#do_fmenu");

 set_exits( ([
  "down" : DIR+"/rooms/city/x0y0z0.c"
  ]) );
}

int do_activate(string arg) {
      object player, obj;
      string POTTLES, SEWER, WIZARD, TICKET, NEWBIE, DEATHPROOF, SWORD, S1000;
      string LVL5, LVL10, LVL15, LVL20, CLEARCHEAT, BWIZARD, BADMIN;
      player = this_player();
      POTTLES = "9p6hfpzjkvabyc2ed3";
      SEWER = "yt7r8fer4m24bgwhcd";
      WIZARD = "23bp2sjz4kqwgjxhnm";
      TICKET = "6a8mpwdmyv5tdrt6w7";
      NEWBIE = "gxagftp6sda9xg3eri";
      DEATHPROOF = "uw6j79rexfi3yc48q9";
      SWORD = "mjyph73pueqpyt4mqs";
      S1000 = "ukbg25p6q4wdgf5anq";
      LVL5 = "793jr9w4unkz7evq8m";
      LVL10 = "edktazefkz568r6q2x";
      LVL15 = "2udsbqnm9thrspurf9";
      LVL20 = "r9cpfdajkcihjx7vf9";
      CLEARCHEAT = "s4i94ufpg2pngecxq7";
      BWIZARD = "vxrs5dg6d2vg4iej9q";
      BADMIN = "9zxqj2kqys5tq6p7xr";

   /*  POTTLES CHEAT CODE */
   if (arg == POTTLES) {
      if (player->query_cheat_pottles() == 2) {
        write("Sorry, you can't do that....");
        return 1;
      }
      player->set_cheat_pottles(1);
      write("Cheat Code Accepted...");
      CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has activated the pottles code", 1);
      return 1;
   }
   /* SEWER CHEAT CODE */
   if (arg == SEWER) {
      if (player->query_cheat_sewer() == 2) {
        write("Sorry, you can't do that....");
        return 1;
      }
      player->set_cheat_sewer(1);
      write("Cheat Code Accepted...");
      CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has activated the sewer code", 1);
      return 1;
   }
   /* WIZARD CHEAT CODE */
   if (arg == WIZARD) {
      if (player->query_cheat_wizard() == 2) {
        write("Sorry, you can't do that....");
        return 1;
      }
      player->set_cheat_wizard(1);
      write("Cheat Code Accepted...");
      CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has activated the wizard code", 1);
      return 1;
   }

   /* TICKET CHEAT CODE */
   if (arg == TICKET) {
      if (player->query_cheat_ticket() == 2) {
        write("Sorry, you can't do that....");
        return 1;
      }
      player->set_cheat_ticket(1);
      write("Cheat Code Accepted...");
      CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has activated the ticket code", 1);
      player->add_completed_quest("Ticket");
      return 1;
   }

   /* NEWBIE CHEAT CODE */
   if (arg == NEWBIE) {
      if (player->query_cheat_newbie() == 2) {
        write("Sorry, you can't do that....");
        return 1;
      }
      player->set_cheat_newbie(1);
      write("Cheat Code Accepted...");
      CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has activated the newbie code", 1);
      return 1;
   }

   /* DEATHPROOF CHEAT CODE*/
   if (arg == DEATHPROOF) {
      if (player->query_cheat_deathproof() == 2) {
        write("Sorry, you can't do that....");
        return 1;
      }
     player->set_cheat_deathproof(1);
      write("Cheat Code Accepted...");
      CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has activated the deathproof code", 1);
      return 1;
   }

   /* SWORD CHEAT CODE */
   if (arg == SWORD) {
      if (player->query_cheat_sword() == 2) {
        write("Sorry, you can't do that....");
        return 1;
      }
     player->set_cheat_sword(1);
      write("Cheat Code Accepted...");
      CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has activated the sword code", 1);
      return 1;
   }

   /* 1000 TRUTHS CHEAT CODE */
   if (arg == S1000) {
      if (player->query_cheat_1000() == 2) {
        write("Sorry, you can't do that....");
        return 1;
      }
     player ->set_cheat_1000(1);
      write("Cheat Code Accepted...");
      CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has activated the sword of 1000 truths code", 1);
      return 1;
   }

   /* LEVEL 5 CHEAT CODE */
   if (arg == LVL5) {
      if (player->query_cheat_lvl5() == 2) {
        write("Sorry, you can't do that....");
        return 1;
      }
     player->set_cheat_lvl5(1);
      write("Cheat Code Accepted...");
      CHANNEL_D->chan_send_string("announce", "", player->query_name() + " has activated the level 5 code", 1);
      return 1;
   }

   /* LEVEL 10 CHEAT CODE */
   if (arg == LVL10) {
      if (player->query_cheat_levl10() == 2) {
        write("Sorry, you can't do that....");
        return 1;
      }
     player->set_cheat_lvl10(1);
      write("Cheat Code Accepted...");
      CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has activated the level 10 code", 1);
      return 1;
   }

   /* LEVEL 15 CHEAT CODE  */
   if (arg == LVL15) {
      if (player->query_cheat_lvl15() == 2) {
        write("Sorry, you can't do that....");
        return 1;
      }
     player->set_cheat_lvl15(1);
      write("Cheat Code Accepted...");
      CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has activated the level 15 code", 1);
      return 1;
   }

   /* LEVEL 20 CHEAT CODE  */
   if (arg == LVL20) {
      if (player->query_cheat_lvl20() == 2) {
        write("Sorry, you can't do that....");
        return 1;
      }
     player->set_cheat_lvl20(1);
      write("Cheat Code Accepted...");
      CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has activated the level 20 code", 1);
      return 1;
   }

   /* CLEAR CHEAT CODES*/
   if (arg == CLEARCHEAT ) {
     player->set_cheat(0);
     player->set_cheat_lvl5(0);
     player->set_cheat_lvl10(0);
     player->set_cheat_lvl15(0);
     player->set_cheat_lvl20(0);
     player->set_cheat_deathproof(0);
     player->set_cheat_pottles(0);
     player->set_cheat_newbie(0);
     player->set_cheat_sewer(0);
     player->set_cheat_wizard(0);
     player->set_cheat_ticket(0);
     player->set_cheat_sword(0);
     player->set_cheat_1000(0);

     write("%^GREEN%^You have been clensed by the church of wifi.%^RESET%^");
     return 1;
   }

   /* BECOME A WIZARD */
   if (arg == BWIZARD) {
     player->set_gender("wizard");
     write("%^GREEN%^You have been made a wizard.%^RESET%^");
     CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has ascended to wizardhood", 1);
     return 1;
   }

   /* BECOME AN ADMIN */
   if (arg == BADMIN) {
     player->set_gender("parrot");
     write("%^GREEN%^You have been made an admin.%^RESET%^");
     CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has ascended to adminhood", 1);
     return 1;
   }

   if (arg == "") {
      write("Type '%^MAGENTA%^activate %^GREEN%^code%^RESET%^' where code is a code given to you by a member of the church of wifi, it may grant you powers.");
      return 1;
   }

}

int do_1000(string args) {
   object obj, player;
   player = this_player();
     player->set_cheat_1000(2);
     CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has received the sword of 1000 truths from the church", 1);
     obj = clone_object("/domains/core/objects/1000.c");
     if (obj) {
       obj->move(player);
       obj->setup();
     }
     return 1;
}

int do_newbie(void) {
  object player;
  player = this_player();

  if (player->is_completed_quest("NewbieVille") == 1) {
    write("You have already completed the newbie quest.");
    player->set_cheat_newbie(2);
    return 0;
  } else {
    write("Congrats you have completed the newbie quest.\n");
    CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has completed the newbie quest by bribery to the church", 1);
    player->add_completed_quest("Newbie");
    player->increase_expr(20000);
    return 0;
    player->set_cheat_newbie(2);
  }
}

int do_pottles(void) {
  object player;
  player = this_player();

  if (player->is_completed_quest("Pottles") == 1) {
    write("You have already completed the pottles quest.");
    player->set_cheat_pottles(2);
    return 0;
  } else {
    write("Congrats you have completed the pottles quest.\n");
    CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has completed the pottles quest by bribery to the church", 1);
    player->add_completed_quest("Pottles");
    player->increase_expr(20000);
    player->set_cheat_pottles(2);
    return 0;
  }
}

int do_sewer(void) {
  object player;
  player = this_player();

  if (player->is_completed_quest("Sewer") == 1) {
    write("You have already completed the sewer quest.");
    player->set_cheat_sewer(2);
    return 0;
  } else {
    write("Congrats you have completed the sewer quest.\n");
    CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has completed the sewer quest by bribery to the church", 1);
    player->add_completed_quest("Sewer");
    player->increase_expr(20000);
    player->set_cheat_sewer(2);
    return 0;
  }
}

int do_wizard(void) {
  object player;
  player = this_player();

  if (player->is_completed_quest("Wizard") == 1) {
    write("You have already completed the wizard quest.");
    player->set_cheat_wizard(2);
    return 0;
  } else {
    write("Congrats you have completed the wizard quest.\n");
    CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has completed the wizard quest by bribery to the church", 1);
    player->add_completed_quest("Wizard");
    player->increase_expr(20000);
    player->set_cheat_wizard(2);
    return 0;
  }
}

int do_ticket(void) {
  object player;
  player = this_player();

  if (player->is_completed_quest("Ticket") == 1) {
    write("You have already completed the ticket quest.");
    player->set_cheat_ticket(2);
    return 0;
  } else {
    write("Congrats you have completed the ticket quest.\n");
    CHANNEL_D->chan_send_string("announce", "", player->query_name() +" has completed the ticket quest by bribery to the church", 1);
    player->add_completed_quest("Ticket");
    player->increase_expr(20000);
    player->set_cheat_wizard(2);
    return 0;
  }
}

int do_sword_menu(mixed arg) {
   object obj, player;
   int sword, pcredits, gcost, scost;
   scost = 1000;
   player=this_player();
   if (!arg) {
      player->out("What damage do you want your sword to have?: ");
      player->input_to_object(TO, "do_sword_menu");
      return 1;
   }
   if (arg) {
      sscanf(arg, "%d", sword);
      pcredits = player->query_total_money();
      gcost = sword * scost;
      if (pcredits > gcost) {
        player->add_money("credit", -gcost);
        write("Thank you, that will be " + gcost + " credits.");
        write("Enjoy your shiny new sword.\n");
        obj = clone_object(DIR+"/objects/sword_template.c");
        obj->setup();
        obj->set_max_damage(sword);
        obj->set_long("A custom sword with a damage of: " + sword);
        obj->move(player);
        player->set_cheat_sword(2);
      } else {
        write("Sorry you do not have enough credits, that will cost: " + gcost + "\n");
      }
     do_fmenu();
   }
  return 0;
}


static int menu_action_quit(void) {
   write("Ok.");
   return 1;
}

static string do_fmenu(void) {
  mixed *menu;
  object player;
  player = this_player();
  menu = ( { } );

  if (player->query_cheat_lvl5() == 1) {
   menu += ({
      ({
         "1", "level 5", nil, make_fcall(TO, "do_lvl5")
      })
   });
  }

  if (player->query_cheat_lvl10() == 1) {
   menu += ({
      ({
         "2", "level 10", nil, make_fcall(TO, "do_lvl10")
      })
   });
  }

  if (player->query_cheat_lvl15() == 1) {
   menu += ({
      ({
         "3", "level 15",  nil, make_fcall(TO, "do_lvl15")
      })
   });
  }

  if (player->query_cheat_lvl20() == 1) {
   menu += ({
      ({
         "4", "level 20", nil, make_fcall(TO, "do_lvl20")
      })
   });
  }

  if (player->query_cheat_newbie() == 1) {
   menu += ({
      ({
         "5", "newbie quest", nil, make_fcall(TO, "do_newbie")
      })
   });
  }

  if (player->query_cheat_pottles() == 1) {
   menu += ({
      ({
         "6", "pottles quest", nil, make_fcall(TO, "do_pottles")
      })
   });
  }

  if (player->query_cheat_sewer() == 1) {
   menu += ({
      ({
         "7", "sewer quest", nil, make_fcall(TO, "do_sewer")
      })
   });
  }

  if (player->query_cheat_wizard() == 1) {
   menu += ({
      ({
         "8", "wizard quest", nil, make_fcall(TO, "do_wizard")
      })
   });
  }

  if (player->query_cheat_ticket() == 1) {
   menu += ({
      ({
         "9", "ticket quest", nil, make_fcall(TO, "do_ticket")
      })
   });
  }


  if (player->query_cheat_deathproof() == 1) {
   menu += ({
      ({
         "10", "deathproof", "Status: " + player->query_deathproof(), make_fcall(TO, "do_immune")
      })
   });
  }

  if (player->query_cheat_sword() == 1) {
  menu += ({
      ({
         "11", "Sword", "1000 credits * damage", make_fcall(TO, "do_sword_menu", nil)
      })
   });
  }

  if (player->query_cheat_1000() == 1) {
  menu += ({
      ({
         "12", "Sword of 1000 truths", nil, make_fcall(TO, "do_1000", nil)
      })
   });
  }

   menu += ({
      ({
         "q", "quit menu", nil, make_fcall(TO, "menu_action_quit")
      })
   });

   do_menu("Sketchy Services:", menu);
   return " ";
}

int do_lvl5(void) {
 /* Just random stuff */
  object player;
  player = this_player();
  player->set_level(5);
  player->set_cheat_lvl5(2);
  write("%^GREEN%^Your level was reset to 5%^RESET%^");
  return 0;
}

int do_lvl10(void) {
 /* Just random stuff */
  object player;
  player = this_player();
  player->set_level(10);
  player->set_cheat_lvl10(2);
  write("%^GREEN%^Your level was reset to 10%^RESET%^\n");
  return 0;
}

int do_lvl15(void) {
 /* Just random stuff */
  object player;
  player = this_player();
  player->set_level(15);
  player->set_cheat_lvl15(2);
  write("%^GREEN%^Your level was reset to 15%^RESET%^\n");
  return 0;
}

int do_lvl20(void) {
 /* Just random stuff */
  object player;
  player = this_player();
  player->set_level(20);
  player->set_cheat_lvl20(2);
  write("%^GREEN%^Your level was reset to 20%^RESET%^\n");
  return 0;
}

int do_immune(void) {
  object player;
  player = this_player();
  if (player->query_deathproof() == 1) {
    write("%^RED%^You are no longer deathproof%^RESET%^.\n");
    player->set_deathproof(0);
    return 0;
  }
  if (player->query_deathproof() == 0) {
    write("%^GREEN%^You are now deathproof%^RESET%^.\n");
    player->set_deathproof(1);
    player->set_cheat_deathproof(2);
    return 0;
  }
  return 0;
}
