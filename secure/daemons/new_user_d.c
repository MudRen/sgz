// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
 * New user daemon.  Handles character creation.
 *
 * Short in the distribution lib, for two reasons:
 * (1) I don't believe in long login sequences.  There are a pain.
 * (2) Less work :-)
 *
 * Separate since I know many people will put a ton of stuff in here.
 */

mapping races = ([]);
string format;

void got_entry(function, string);

// when_done is a function that we pass a body file name to.
void create_user(function when_done)
{
#ifndef USE_RACES

    evaluate(when_done, DIR_RACES "/human");	// 本mudlib没有用种族，直接使用/std/race/human人类

#else

    string file;
    int width = 0;

    foreach (file in get_dir(DIR_RACES + "/*.c")) {
    string tmp = DIR_RACES + "/" + file;
    string name;

        if ( !load_object(tmp) )
            continue;
        name = tmp->query_race();
    races[name] = tmp;
    if (strlen(name) > width)
        width = strlen(name);
    }

    format = "%#-75." + (75/(width + 3)) + "s\n\n";

    //write("\nPlease select a race from the following list:\n");
    write("\n请在下列种族中选择你的种族：\n");
    printf(format, implode(keys(races), "\n"));

    printf(//"Type 'help race' for a brief description.  Type 'list' to show the choices again.\n");
           "用 'help race' 可以看到简短的说明。用 'list' 可以再次显示选择信息。\n");
    this_user()->modal_push( (: got_entry, when_done :), "Race? ");

#endif /* USE_RACES */
}

#ifdef USE_RACES

void got_entry(function when_done, string line) {

    if (line == "list") {
    //write("Please select a race from the following list:\n");
    write("\n请在下列种族中选择你的种族：\n");
    printf(format, implode(keys(races), "\n"));
    return;
    }
    if (races[line]) {
    this_user()->modal_pop();
    evaluate(when_done, races[line]);
    return;
    }
    if (sscanf(line, "help %s", line) && races[line]) {
    write(races[line]->short_description());
    return;
    }
    //write("No such race.\n");
    write("没有这种种族。\n");
}

#endif /* USE_RACES */
