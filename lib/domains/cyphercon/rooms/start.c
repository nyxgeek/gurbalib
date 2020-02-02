inherit "/std/room";
inherit "/std/menu";

#include "../domain.h"

void setup(void) {

   add_area("required");
   set_short("%^GREEN%^C%^GREY%^y%^HBLUE%^p%^HCYAN%^h%^HGREEN%^e%^HMAGENTA%^r%^HRED%^c%^HWHITE%^o%^MAGENTA%^n %^ORANGE%^C%^RED%^u%^YELLOW%^b%^BLUE%^e%^RESET%^");
   set_coords(({ 0, 0 }));
   set_dimensions(({ 1, 1 }));
   set_mapstart(({ 0, 0} ));

   add_item("cube", "#do_cube");

   set_short("%^GREEN%^C%^GREY%^y%^HBLUE%^p%^HCYAN%^h%^HGREEN%^e%^HMAGENTA%^r%^HRED%^c%^HWHITE%^o%^MAGENTA%^n %^ORANGE%^C%^RED%^u%^YELLOW%^b%^BLUE%^e%^RESET%^");
   set_long("You are in a non descript room, in the center of it floats a 1 inch cube. The cube appears to be glowing and might be speaking to you.");
   set_exits(([
     "east" : "/domains/required/rooms/start"
   ]));

}

static string do_cube(void) {
  object player, obj, to;
  string CODE1, CODE2, CODE3, CODE4, CODE5, CODE6, CODE7, CODE8, CODE9, CODE10, CODE11, CODE12, CODE13, CODE14, CODE15, CODE16, CODE17, CODE18, CODE19, CODE20, CODE21, CODE22;
  mixed *menu;
  player = this_player();

  /* CODE DEFINITIONS */
  CODE1 = "000000000000111ADD0319";
  CODE2 = "ADD1EACCE55EDA5C110319";
  CODE3 = "DCFEEDB0B0DEADBEEF0319";
  CODE4 = "C0FFEE1EADEDD1E5E10319";
  CODE5 = "A5C11D1A1ACCE55BBS0319";
  CODE6 = "A5C114EA5E0FACCE550319";
  CODE7 = "10ADEDDAFF0D11F1F00319";
  CODE8 = "E1FEC5AC07AB1EF11E0319";
  CODE9 = "BA0BABD10DECAB005E0319";
  CODE10 = "B3111AB5BA51CCABA10319";
  CODE11 = "0B5E55ED0DDBA11CAD0319";
  CODE12 = "5011D1F1ED50DAC0DA0319";
  CODE13 = "C0D1F1EDBA5E16B10B0319";
  CODE14 = "C0DED15C105ED10CA10319";
  CODE15 = "F0551115ED5C51D15C0319";
  CODE16 = "1CEFA11F1E1D0FF1CE0319";
  CODE17 = "1005E1EAFD15BE11EF0319";
  CODE18 = "0551F1EDF1DD1EBACC0319";
  CODE19 = "F100DED0A5155EA1ED0319";
  CODE20 = "5AFE11FE512E501ACE0319";
  CODE21 = "DEC0DE5EEDEDFACADE0319";
  CODE22 = "FA151F1AB1E4A111E50319";

  menu = ( { } );

  menu += ({
      ({
         "a", "activate", nil, make_fcall(to, "do_activate")
      })
   });

  menu += ({
      ({
         "q", "quit menu", nil, make_fcall(to, "menu_action_quit")
      })
   });

   do_menu("Sketchy Services:", menu);
   return " ";
}

static int menu_action_quit(void) {
   write("Ok.");
   return 1;
}
