# include "tree.hh"

Tree::Tree()
{
  QPixmap sprite(":/objects/sprites/tree.png");
  set_object_sprite(sprite);
}

Tree::Tree(const QVector2D & _position)
{
  QPixmap sprite(":/objects/sprites/tree.png");
  set_object_sprite(sprite);

  QRect _collision_rect;

  _collision_rect.setX(_position.x());
  _collision_rect.setY(_position.y());
  _collision_rect.setWidth(get_object_sprite().width());
  _collision_rect.setHeight(get_object_sprite().height());

  set_collision_rect(_collision_rect);

  set_x(_position);
  set_y(_position);
}

Tree::Tree(const QVector2D & _position, int rand_s)
{
  QPixmap sprite;
  QRect _collision_rect;

  if(rand_s == 0)
  {
  	sprite.load(":/objects/sprites/tree.png");

  	set_object_sprite(sprite);

  	_collision_rect.setX(_position.x() + 7);
	  _collision_rect.setY(_position.y() + 5);
	  _collision_rect.setWidth(get_object_sprite().width() - 12);
	  _collision_rect.setHeight(get_object_sprite().height() - 15);

  	set_collision_rect(_collision_rect);
  }
  else
  {
  	sprite.load(":/objects/sprites/tree2.png");

  	set_object_sprite(sprite);

  	_collision_rect.setX(_position.x() + 5);
	  _collision_rect.setY(_position.y() + 5);
	  _collision_rect.setWidth(get_object_sprite().width() - 10);
	  _collision_rect.setHeight(get_object_sprite().height() - 15);

  	set_collision_rect(_collision_rect);
  }
    
  set_x(_position);
  set_y(_position);
}

void Tree::draw(QPainter & painter)
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

Object_Type Tree::get_type()
{
  return Object_Type::TREE;
}

