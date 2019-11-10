# include <bighealthpotion.hh>
# include <hero.hh>

constexpr unsigned HEALTH = 10;

BigHealthPotion::BigHealthPotion() :
  cure(HEALTH)
{
  QPixmap sprite(":/objects/sprites/bighealth.png");

  set_object_sprite(sprite);
}

BigHealthPotion::BigHealthPotion(const QVector2D & _position)
  : cure(HEALTH)
{
  QPixmap sprite(":/objects/sprites/bighealth.png");

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

void BigHealthPotion::behave(Entity & hero)
{
  dynamic_cast<Hero &>(hero).increment_life(this->cure);
}

Object_Type BigHealthPotion::get_type()
{
  return Object_Type::BIGHEALTHPOTION;
}
