# include <armament.hh>

Armament::Armament()
{
  this->collision = false;
}

Armament::~Armament()
{}

bool Armament::get_collision()
{
  return this->collision;
}

void Armament::set_collision(bool flag)
{
  this->collision = flag;
  return;
}

bool Armament::colliding(const QRect & prey)
{
  if(prey.intersects(this->get_collision_rect()))
    {
      this->set_collision(true);
      return true;
    }
  return false;
}

void Armament::behave(Entity &)
{
  //empty
}
