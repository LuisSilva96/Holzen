# include <interactuable.hh>
# include <QDebug>

Interactuable::Interactuable()
{
  sprites = new QPixmap[2];
  current_sprite = 0;
}

Object_Type Interactuable::get_type()
{
  return Object_Type::INTERACTUABLE;
}

void Interactuable::behave(Entity & e)
{
	if(this->get_collision_rect().intersects(e.get_col_rect()))
	{
		current_sprite = 1;
		
	set_object_sprite(sprites[current_sprite]);
	}
}

void Interactuable::set_sprites(QPixmap &frst, QPixmap &scnd)
{
	sprites[0] = frst;
	sprites[1] = scnd;
	return;
}

int Interactuable::get_current_sprite()
{
	return this->current_sprite;
}

void Interactuable::set_current_sprite(int s)
{
	this->current_sprite = s;
}
