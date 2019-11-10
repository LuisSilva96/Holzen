# include "inventory.hh"

Inventory::Inventory()
{
  background.load(":/objects/sprites/inventory.png");
  select_item.load(":/objects/sprites/selectitem.png");
  select_action.load(":/objects/sprites/selecaction.png");
  options_box.load(":/objects/sprites/options1.png");

  option_position = 0;

  hide = true;
  hide_options = true;

  selected_position.setX(0);
  selected_position.setY(0);

  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
    {
      inventory[i][j] = nullptr;
    }
}

Inventory::~Inventory()
{
  //empty
}

void Inventory::set_position(const QVector2D & _position)
{
  position = _position;
}

void Inventory::set_hide(const bool & _hide)
{
  hide = _hide;
}

void Inventory::set_hide_options(const bool & _hide)
{
  hide_options = _hide;
}

QVector2D Inventory::get_position()
{
  return position;
}

bool Inventory::get_hide_options()
{
  return hide_options;
}

bool Inventory::get_hide()
{
  return hide;
}

void Inventory::add_object(InventoryBox * obj)
{
  int i = 0;
  int j = 0;

    for(i=0; i<5; i++)
      for(j=0; j<5; j++)
      {
        if(inventory[i][j] != nullptr)
        {
          if(inventory[i][j]->get_type() == obj->get_type())
          {
            inventory[i][j]->increase_counter();
            return;
          }
        }
      }

  for(i=0; i<5; i++)
    for(j=0; j<5; j++)
    {
      if(inventory[i][j] == nullptr)
      {
        inventory[i][j] = obj;
        inventory[i][j]->increase_counter();
        return;
      }
    }
}

void Inventory::draw_numbers(QPainter & painter, InventoryBox * box, int i, int j)
{
  QString count, pos_1;

  count = count.number(box->get_counter());

  int num, num2;

  if(count.length() > 1)
  {
      pos_1 = count[0];
      num = pos_1.toInt();
      pos_1 = count[1];
      num2 = pos_1.toInt();

      painter.drawPixmap(position.x()+j*(32)+82,
                        position.y()+i*(32)-30,
                        box->get_num_sprite(num));
      painter.drawPixmap(position.x()+j*(32)+88,
                        position.y()+i*(32)-30,
                        box->get_num_sprite(num2));
  }
  else
  {
      num = count.toInt();
      painter.drawPixmap(position.x()+j*(32)+88,
                        position.y()+i*(32)-30,
                        box->get_num_sprite(num));
  }
}

void Inventory::update_selected_position(int && i, int && j)
{
  if(selected_position.x()+(i) >= 0 && selected_position.x()+(i) <= 4)
    selected_position.setX(selected_position.x()+(i));

  if(selected_position.y()+(j) >= 0 && selected_position.y()+(j) <= 4)
    selected_position.setY(selected_position.y()+(j));

  //std::cout << selected_position.x() << "//" << selected_position.y() << std::endl;

}

void Inventory::update_selected_options(int && i)
{
  if(option_position + i < 0)
    option_position = 2;
  else if(option_position + i > 2)
    option_position = 0;
  else
    option_position += i;
}

void Inventory::selecting_object(int & j, int & i)
{

}

void Inventory::draw_inventory(QPainter & painter)
{
 int i = 0;
 int j = 0;

 i = selected_position.x();
 j = selected_position.y();

 painter.drawPixmap(position.x()+52, position.y()-64, background);

 painter.drawPixmap(position.x()+selected_position.x()*(32)+68, position.y()+selected_position.y()*(32)-48,select_item);

 if (inventory[i][j] != nullptr)
 {
    if(!get_hide_options())
    {
      painter.drawPixmap(position.x()+selected_position.x()*(32)+108, position.y()+selected_position.y()*(32)-38,options_box);
      painter.drawPixmap(position.x()+selected_position.x()*(32)+110,
           position.y()+selected_position.y()*(32)-36+option_position*(30)+7*option_position,select_action);

    }
 }
 else
  set_hide_options(true);


 for(i = 0; i < 5; i++)
 {
   for(j = 0; j < 5; j++)
   {
     if (inventory[i][j] != nullptr)
     {
       if(inventory[i][j]->get_counter() > 1)
       {
         painter.drawPixmap(position.x()+j*(32)+73, position.y()+i*(32)-42, inventory[i][j]->get_sprite());

        draw_numbers(painter, inventory[i][j], i, j);

     }
       else if(inventory[i][j]->get_type() == Object_Type::ARROW)
         painter.drawPixmap(position.x()+j*(32)+50, position.y()+i*(32)-48, inventory[i][j]->get_sprite());
       else
         painter.drawPixmap(position.x()+j*(32)+73, position.y()+i*(32)-42, inventory[i][j]->get_sprite());
     }
   }
 }
}

void Inventory::behave_options(Entity & hero)
{
  int i = 0;
  int j = 0;

  i = selected_position.x();
  j = selected_position.y();

  switch (option_position)
  {
    case 0:
    {
      inventory[i][j]->object_behave(hero);

      if(inventory[i][j]->get_counter() <= 1)
        inventory[i][j] = nullptr;
      else
        inventory[i][j]->decrease_counter();
    }
    break;
    case 1:
    {
      if(inventory[i][j]->get_counter() <= 1)
        inventory[i][j] = nullptr;
      else
        inventory[i][j]->decrease_counter();
    }
    break;
    case 2:
    {
      //empty
    }
    break;
  }
}
