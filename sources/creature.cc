# include <creature.hh>

Creature::~Creature()
{
  // delete as;
  // delete ps;
}

void Creature::set_drop(Object_Type tp)
{
  switch(tp)
    {
    case Object_Type::SMALLHEALTHPOTION :
      {
			this->obj = new SmallHealthPotion(this->get_pos());
			break;
      }
        case Object_Type::SMALLMANAPOTION:
      {
			this->obj = new SmallManaPotion(this->get_pos());
			break;
      }
          case Object_Type::BIGHEALTHPOTION :
      {
			this->obj = new BigHealthPotion(this->get_pos());
			break;
      }
          case Object_Type::BIGMANAPOTION :
      {
			this->obj = new BigManaPotion(this->get_pos());
			break;
      }
      default:
      this->obj = nullptr;
			break;
    }
}

void Creature::set_state(State * stt)
{
  this->ps = this->as;
  this->as = stt;
}

Object * Creature::get_drop() const
{
  return this->obj;
}

State * Creature::get_state() const
{
  return this->as; 
}

void Creature::recieve_damage(const Entity & attacker)
{
  long damage = attacker.get_atck() - ((25*this->get_def())/100);
  if (damage > this->get_hp())
    this->set_hp(0);
  else  
    this->set_hp((this->get_hp() - damage));

  if (this->speed == 0)
    this->move(0.124);
  else
    this->move(-0.124);
  return;
}

void Creature::calc_vel(const QVector2D & prey, long double speed)
{
  double k = speed / prey.length();
  auto aux = prey - this->get_pos();
  aux = aux * k;
  this->set_vel(aux*k);
  return;
}

void Creature::calc_vel(const QVector2D && prey, long double speed)
{
  double k = speed / prey.length();
  auto aux = prey - this->get_pos();
  this->set_vel(aux*k);
  return;
}

double Creature::get_speed()
{
  return speed;
}

void Creature::set_speed(long double sp)
{
  this->speed = sp;
}
