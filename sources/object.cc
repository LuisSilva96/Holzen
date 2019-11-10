# include "object.hh"

Object::Object()
{
	lifetime = new QTimer(this);

  set_deleting(false);

  connect(lifetime,SIGNAL(timeout()),this,SLOT(destroy()));

  lifetime->start(20000);
}

Object::Object(const QVector2D && _position, const QPixmap & _object_sprite) 
              : position(_position), object_sprite(_object_sprite)
{
	//empty
}

Object::Object(const QVector2D & _position, const QPixmap & _object_sprite, const QString & _identifier) 
              : position(_position), object_sprite(_object_sprite), identifier(_identifier)
{
  //empty
}

Object::Object(const Object & ref) : position(ref.get_x(), ref.get_y()),
			       object_sprite(ref.get_object_sprite()),
			       identifier(ref.get_identifier())
{
	//empty
}

float Object::get_x() const
{
  return(position.x());
}

float Object::get_y() const
{
  return(position.y());
}

QPixmap Object::get_object_sprite() const
{
  return (object_sprite);
}

QString Object::get_identifier() const
{
  return(identifier);
}

QVector2D Object::get_pos() const
{
  return position;
}

QRect Object::get_collision_rect() const
{
  return (collision_rect);
}

void Object::set_x(const QVector2D & _position)
{
  position.setX(_position.x());
}

void Object::set_x(float &&n)
{
  position.setX(n);

}

void Object::set_y(const QVector2D & _position)
{
  position.setY(_position.y());
}

void Object::set_y(float &&n)
{
  position.setY(n);

}

void Object::set_object_sprite(const QPixmap & _object_sprite)
{
  object_sprite = _object_sprite;
}

void Object::set_identifier(const QString & _identifier)
{
  identifier = _identifier;
}

void Object::set_collision_rect(const QRect & _collision_rect)
{
  collision_rect = _collision_rect;
}

void Object::set_col_rect_x(float && n)
{
  this->collision_rect.setX(n);
  return;
}

void Object::set_col_rect_y(float && n)
{
  this->collision_rect.setY(n);
  return;
}

void Object::set_col_rect_height(float && n)
{
  this->collision_rect.setHeight(n);
  return;
}

void Object::set_col_rect_width(float && n)
{
  this->collision_rect.setWidth(n);
  return;
}

void Object::destroy()
{
    set_deleting(true);

    lifetime->stop();
}

void Object::set_deleting(bool _deleting)
{
  deleting = _deleting;
}

bool Object::get_deleting()  const
{
  return deleting;
}

void Object::object_picked_up()
{
	lifetime->stop();
}
/*
virtual void Object::behaviour(Hero &)
{
	//empty
}
*/
