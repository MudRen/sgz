// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

private static int size = MEDIUM;

//:FUNCTION get_size
//get_size() returns the size of an object
int get_size()
{
  return size;
}

//:FUNCTION set_size
//set_size(s) sets the size of an object to 's'
void set_size(int s)
{
  size = s;
}
