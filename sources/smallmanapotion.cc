# include <smallmanapotion.hh>
# include <hero.hh>

constexpr unsigned MANA = 5;

SmallManaPotion::SmallManaPotion() :
  mana(MANA)
{
  QPixmap sprite(":/objects/sprites/smallmana.png");

  set_object_sprite(sprite);
}

SmallManaPotion::SmallManaPotion(const QVector2D & _position)
  : mana(MANA)
{
  QPixmap sprite(":/objects/sprites/smallmana.png");

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

void SmallManaPotion::behave(Entity & hero)
{
  dynamic_cast<Hero &>(hero).increment_life(this->mana);
}

Object_Type SmallManaPotion::get_type()
{
  return Object_Type::SMALLMANAPOTION;
}
