#include "../domain.h"
inherit M_VENDOR;

void setup(void) {
   set_name("shopkeeper");
   add_ids("shopkeep","tom", "shopkeeper", "merchant");
   set_proper_name("Swill");
   set_gender("male");
   set_in_room_desc("Swill, the shopkeeper");
   set_long("He is a burly hulk of a man.");
   set_race("human");
   set_level(15);

   set_restock_delay(7200);
   set_will_buy(1);

   add_item(DIR + "/obj/torch", 8);
}
