# include "noninteractuable.hh"
# include <QDebug>

Noninteractuable::Noninteractuable()
{
  //empty
}

Object_Type Noninteractuable::get_type()
{
  return Object_Type::NONINTERACTUABLE;
}

void Noninteractuable::behave(Entity &)
{

}
