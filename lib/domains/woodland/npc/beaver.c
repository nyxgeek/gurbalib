inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("beaver");
   set_short("A beaver");
   set_long("A beaver");
   set_gender("male");
   set_race("beaver");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 20);
   set_skill("combat/defense", 20);
   set_level(1);
}
