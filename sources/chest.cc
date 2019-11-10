# include <chest.hh>

Chest::Chest()
{
  QPixmap sprite1(":/objects/sprites/1.png");
  QPixmap sprite2(":/objects/sprites/2.png");
	
	set_sprites(sprite1, sprite2);
	
	set_object_sprite(sprite1);
}

Chest::Chest(const QVector2D & _position)
{
  QPixmap sprite1(":/objects/sprites/1.png");
  QPixmap sprite2(":/objects/sprites/2.png");
	
	set_sprites(sprite1, sprite2);
	
	set_object_sprite(sprite1);

  QRect _collision_rect;

  _collision_rect.setX(_position.x());
  _collision_rect.setY(_position.y());
  _collision_rect.setWidth(get_object_sprite().width());
  _collision_rect.setHeight(get_object_sprite().height());

  set_collision_rect(_collision_rect);

  set_x(_position);
  set_y(_position);
}

Object_Type Chest::get_type()
{
  return Object_Type::CHEST;
}
