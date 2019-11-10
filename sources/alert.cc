# include <alert.hh>

void Alert::behave(Creature & hunter, Entity & prey, double dt)
{
  //cerr << "alert\n";
 
  if ((prey.get_pos() - hunter.get_pos()).length() <= 150)
    hunter.set_state(new Chase());
  return;
}
