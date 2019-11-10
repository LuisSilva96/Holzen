# include "bush.hh"

Bush::Bush()
{
  QPixmap sprite(":/objects/sprites/bush.png");

  set_object_sprite(sprite);
}

Bush::Bush(const QVector2D & _position)
{
  QPixmap sprite(":/objects/sprites/bush.png");

  set_object_sprite(sprite);

  QRect _collision_rect;

  _collision_rect.setX(_position.x());
  _collision_rect.setY(_position.y() + 2);
  _collision_rect.setWidth(get_object_sprite().width());
  _collision_rect.setHeight(get_object_sprite().height() - 5);

  set_collision_rect(_collision_rect);

  set_x(_position);
  set_y(_position);


}

void Bush::draw(QPainter & painter)
{
  painter.drawPixmap(this->get_x(), this->get_y(), this->get_object_sprite());
  //painter.drawRect(this->get_collision_rect());
}

/*
virtual void SmallHealthPotion::behaviour()
{
  //empty
}
*/

Object_Type Bush::get_type()
{
  return Object_Type::BUSH;
}

