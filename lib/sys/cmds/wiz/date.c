inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Usage: date [-h]" });
   lines += ({ " " });
   lines += ({ "Show the real world time and date." });
   lines += ({ " " });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "Examples:" });
   lines += ({ "\tdate" });
   lines += ({ "See also:" });
   lines += ({ "\tscan, status, time" });

   return lines;
   this_player()->more(lines);
}

static void main(string str) {

   if (!empty_str(str)) {
      this_player()->more(usage());
      return;
   }

   write(ctime(time()) + "\n");
}
