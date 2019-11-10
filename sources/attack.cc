# include <attack.hh>
void Attack::behave(Creature & hunter, Entity & prey, double dt)
{
  prey.recieve_damage(hunter);
  if ((hunter.get_pos() - prey.get_pos()).length() > 10 and
      (hunter.get_pos() - prey.get_pos()).length() < 200)
    hunter.set_state(new Chase());
  return;
}
