inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Usage: aload [-h] [save]" });
   lines += ({ " " });
   lines += ({ "If no arguments are given, load your current autoload " +
      "objects." });
   lines += ({ "If save is specified, create an autoload string from your " +
      "inventory." });
   lines += ({ " " });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "Examples:" });
   lines += ({ "\taload save" });
   lines += ({ "\taload" });
   lines += ({ "See also:" });
   lines += ({ "\tcompose" });

   return lines;
}

static void main(string str) {
   string file, action, rest;
   object ob, *inv;
   int i, max;

   if (!empty_str(str)) {
      if (str == "save") {
         this_player()->compose_autoload_string();
         str = this_player()->query_autoload_string();
         write("Autoload string set to: " + str + "\n");
      } else {
         this_player()->more(usage());
         return;
      }
   }

   this_player()->clone_autoload_objects();
}
