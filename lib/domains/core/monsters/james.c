inherit "/std/monster";
inherit "/std/modules/m_triggers";

#include "../domain.h"

void setup(void) {
  set_name("Paymaster James");
add_id("james");
add_id("paymaster");
add_id("paymasterjames");
  set_short( "James Russell, Paymaster" );
  set_long( "A rather bloated man with dark skin, James can be a slick-talking character... if he thinks you're worth it. Otherwise, you're way below his attention. However, there has been rumours lately that he has been using his position as Paymaster to relocate some Company funds. To date, no one's been able to prove anything, but certain parties in the Company would be more than glad to see the end of him here. " );

  set_gender("male");
  set_race("human");

  set_level(4);

  set_hit_skill("combat/unarmed");
  set_skill("combat/unarmed", 20);
  set_skill("combat/defense", 20);
}
private int contains(string needle, string hay) {
   return sscanf(hay, "%*s" + needle + "%*s") == 2;
}

private int is_james(string str) {
   return lowercase(str) == "james";
}

void handle_say(string str) {
   string a, b, message;
   int paynew, paydiff, lvl;
   object player;

   sscanf(str, "%s %s", a, b);
   if (is_james(a)) {
      return;
   }

   if (sscanf(str, "%s says: %s\n", a, b) != 2) {
      return;
   }
   str = lowercase(b);
   player = USER_D->find_player(a);
   if (contains("pay me", str) || contains("pay", str) ||
      contains("credits", str)) {
      paydiff = (time() - (player->query_lastpaid()));
      paynew = 60 + random(30);

      message = "say You aren't due for another %^GREY%^"+ (90 - paydiff) + "%^RESET%^ cycles.....";
      if (paydiff > paynew) {
        player->set_lastpaid();
        lvl = player->query_level();
        player->add_money("credit", (lvl * 1000));
        message = "say it appears I owe you " + (lvl * 1000); + "Credits.";
      }
   }
   if (contains("shut up", str)) {
      message = "say Why do you want me to shut up ?";
   }
   if (!message) {
      message = "shrug";
   }
   respond(message);
}

void outside_message(string str) {
   /* XXX some from these can be spoofed with player emotes... */
   if (is_fighting()) {
      return;
   }

   str = ANSI_D->strip_colors(str);

   handle_say(str);

}

