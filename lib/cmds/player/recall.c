inherit M_COMMAND;

string *usage(void) {
   string *lines;

   lines = ({ "Usage: recall [-h]" });
   lines += ({ "" });
   lines += ({ "sends you back to 0,0,0" });
   lines += ({ "" });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "Examples:" });
   lines += ({ "\trecall" });

   lines += get_alsos();

   return lines;
}

void setup_alsos() {
   add_also("player", "look");
   add_also("wiz", "last");
   add_also("wiz", "locate");
   add_also("wiz", "mudlist");
   add_also("wiz", "possess");
   add_also("wiz", "rwho");
   add_also("wiz", "snoop");
   add_also("wiz", "where");
}


static void main(string str) {
        this_player()->decrease_end(20);
	this_player()->move("/domains/required/rooms/start.c");
	call_other(this_player(), "do_look", this_environment());
}

