inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("deer");
   set_short("A deer");
   set_long("A deer");
   set_gender("male");
   set_race("deer");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 20);
   set_skill("combat/defense", 20);
   set_level(1);
}
