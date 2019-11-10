# include <chase.hh>

void Chase::behave(Creature & hunter, Entity & prey, double dt)
{
  if (hunter.get_col_rect().intersects(prey.get_col_rect()))
    hunter.set_state(new Attack());
  else if((hunter.get_pos() - prey.get_pos()).length() >= 200)
    {
      hunter.set_state(new Alert());
    }
  hunter.calc_vel(prey.get_pos(),hunter.get_speed());
	
  hunter.move(dt);	

  return;
}
