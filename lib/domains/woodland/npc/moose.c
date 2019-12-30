inherit "/std/monster";
#include "../domain.h" 

void setup( void ) {
   set_name("moose");
   set_short("A moose");
   set_long("A moose");
   set_gender("male");
   set_race("moose");
   set_hit_skill("combat/unarmed");
   set_skill("combat/unarmed", 20);
   set_skill("combat/defense", 20);
   set_level(1);
}
