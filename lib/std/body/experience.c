int level, experience;

int ready_for_next_level(void) {
   int tmpexp;

   tmpexp = level * level * 2000;

   if (experience > tmpexp) {
      return 1;
   }
   return 0;
}

string query_level_title(int level) {
   switch (level) {
      case 1:
         return "the uninitiated.\n";
         break;
      case 2:
         return "the newbie.\n";
         break;
      case 3:
         return "is getting the hang of things.\n";
         break;
      case 4:
         return "the mediocre.\n";
         break;
      case 5:
         return "the Sub-average.\n";
         break;
      case 6:
         return "the Average.\n";
         break;
      case 7:
         return "the Strong.\n";
         break;
      case 8:
         return "the Great.\n";
         break;
      case 9:
         if (this_object()->query_race() == "male") {
            return "the Baron.\n";
         } else {
            return "the Baroness.\n";
         }
         break;
      case 10:
         return "the Titan.\n";
         break;
      case 11:
         return "the Conquerer.\n";
         break;
      case 12:
         return "the Famous.\n";
         break;
      case 13:
         return "the Awe-inspiring.\n";
         break;
      case 14:
         return "the Battle Hardened.\n";
         break;
      case 15:
         return "the More than Adequate.\n";
         break;
      case 16:
         if (this_object()->query_race() == "male") {
            return "the Grand Baron.\n";
         } else {
            return "the Grand Baroness.\n";
         }
         break;
      case 17:
         return "the Great Titan.\n";
         break;
      case 18:
         return "the Mighty Conquerer.\n";
         break;
      case 19:
         return "the High and Mighty.";
         break;
      default:
         return "the Grand Wizard!!!";
         break;
   }
}

void set_level(int lvl) {
   object obj;
   int tmpexp;
   obj = this_object();
   switch (lvl) {
     case 1:
       tmpexp = 0;
       break;
     case 2:
       tmpexp = 2000;
       break;
     default:
       tmpexp = ((lvl - 1) * (lvl - 1)) * 2000;
       break;
   }
   level = lvl;
   obj->set_max_hp((level *
      obj->query_base_stat("str")) + 20);
   obj->set_max_mana((level *
      obj->query_base_stat("wis")) + 20);
   obj->set_max_end((level *
      obj->query_base_stat("con")) + 20);
   obj->set_title("$N " + query_level_title(level));
   obj->set_expr(tmpexp);
   obj->set_hp(obj->query_max_hp());
   obj->set_end(obj->query_max_end());
   obj->set_mana(obj->query_max_mana());
   obj->set_internal_max_weight((15 + this_object()->query_base_stat("str")) * 100);
}

void increase_level(void) {
   object obj;
   obj = this_object();

   level += 1;

      obj->set_max_hp((level *
      obj->query_base_stat("str")) + 20);
   obj->set_max_mana((level *
      obj->query_base_stat("wis")) + 20);
   obj->set_max_end((level *
      obj->query_base_stat("con")) + 20);
   obj->set_title("$N " + query_level_title(level));
   obj->set_hp(obj->query_max_hp());
   obj->set_end(obj->query_max_end());
   obj->set_mana(obj->query_max_mana());
   obj->set_internal_max_weight((15 + this_object()->query_base_stat("str")) * 100);
}

void increase_expr(int expr) {
   if (expr < 0) {
      expr = expr * -1;
   }
   experience += expr;
   if (experience < 0) {
      experience = 0;
   }
   while (ready_for_next_level()) {
      increase_level();
      write("Congratulations, you just went up a level...\n");
      CHANNEL_D->chan_send_string("announce", "", this_object()->query_name() +" has reached level " + level, 1);
      this_object()->set_title("$N " + query_level_title(level));
   }
}

void decrease_expr(int expr) {
   if (expr > 0) {
      expr = expr * -1;
   }
   experience -= expr;
   if (experience < 0) {
      experience = 0;
   }
}

void set_expr(int expr) {
   experience = expr;
   if (experience < 0) {
      experience = 0;
   }
}

int query_expr(void) {
   return (experience);
}

int query_level(void) {
   return (level);
}
