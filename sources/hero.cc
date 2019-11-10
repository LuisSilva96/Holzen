# include <hero.hh>
# include <scenario.hh>
# include <menu.hh>

constexpr unsigned HP = 50;
constexpr unsigned MANA = 100;
constexpr unsigned DEF = 2;
constexpr unsigned ATCK = 5;
constexpr unsigned LVL = 1;
constexpr unsigned EXP = 1;
constexpr int SIZE_BAR_X = 300;
constexpr int SIZE_BAR_Y = 20;

void Hero::update_collision_rect()
{
  QPixmap & current_sprite = sprites[row][col];
  set_col_rect_x(get_pos().x() + current_sprite.width()/4);
  set_col_rect_y(get_pos().y());
  set_col_rect_width(current_sprite.width()/2);
  set_col_rect_height(current_sprite.height());
}

Hero::Hero(const QVector2D & p)
  : speed(4)
{
  sprites = new QPixmap*[NUM_ROWS];

  for(int i = 0; i < NUM_ROWS; i++)
    sprites[i] = new QPixmap[NUM_COLS];

  set_hp(HP);
  set_def(DEF);
  set_atck(ATCK);
  set_lvl(LVL);
  set_exp(EXP);
  set_pos(p);
  set_mana(MANA);

  x_prev = get_pos().x();
  y_prev = get_pos().y();

  health_bar = new Bar(QVector2D(20,10), QBrush(Qt::red), SIZE_BAR_X, SIZE_BAR_Y);
  health_bar->set_max_val(get_hp());
  health_bar->set_current_val(get_hp());
  health_bar->update_bar();

  mana_bar = new Bar(QVector2D(20,40), QBrush(Qt::blue), SIZE_BAR_X, SIZE_BAR_Y);
  mana_bar->set_max_val(get_mana());
  mana_bar->set_current_val(get_mana());
  mana_bar->update_bar();

	xp_bar = new Bar(QVector2D(20,70), QBrush(Qt::yellow), SIZE_BAR_X, SIZE_BAR_Y);
  xp_bar->set_max_val(get_mana());
  xp_bar->set_current_val(get_exp());
  xp_bar->update_bar();

  //sprites caminar hacia abajo
  sprites[0][0].load(":/hero/sprites/wd1.png");
  sprites[0][1].load(":/hero/sprites/wd2.png");
  sprites[0][2].load(":/hero/sprites/wd3.png");
  sprites[0][3].load(":/hero/sprites/wd4.png");
  sprites[0][4].load(":/hero/sprites/wd5.png");
  sprites[0][5].load(":/hero/sprites/wd6.png");
  sprites[0][6].load(":/hero/sprites/wd7.png");
  sprites[0][7].load(":/hero/sprites/wd8.png");
  sprites[0][8].load(":/hero/sprites/wd9.png");

  //sprites de ataque hacia abajo
  s_attacking[0][0].load(":/hero/sprites/ad0.png");
  s_attacking[0][1].load(":/hero/sprites/ad1.png");
  s_attacking[0][2].load(":/hero/sprites/ad2.png");
  s_attacking[0][3].load(":/hero/sprites/ad3.png");
  s_attacking[0][4].load(":/hero/sprites/ad4.png");
  s_attacking[0][5].load(":/hero/sprites/ad5.png");
  s_attacking[0][6].load(":/hero/sprites/ad6.png");
  s_attacking[0][7].load(":/hero/sprites/ad7.png");
  s_attacking[0][8].load(":/hero/sprites/ad8.png");
  s_attacking[0][9].load(":/hero/sprites/ad9.png");
  s_attacking[0][10].load(":/hero/sprites/ad10.png");
  s_attacking[0][11].load(":/hero/sprites/ad11.png");
  s_attacking[0][12].load(":/hero/sprites/ad12.png");

  //sprites caminar a la izquierda
  sprites[1][0].load(":/hero/sprites/wl1.png");
  sprites[1][1].load(":/hero/sprites/wl2.png");
  sprites[1][2].load(":/hero/sprites/wl3.png");
  sprites[1][3].load(":/hero/sprites/wl4.png");
  sprites[1][4].load(":/hero/sprites/wl5.png");
  sprites[1][5].load(":/hero/sprites/wl6.png");
  sprites[1][6].load(":/hero/sprites/wl7.png");
  sprites[1][7].load(":/hero/sprites/wl8.png");
  sprites[1][8].load(":/hero/sprites/wl9.png");

  //sprites atacar a la izquierda
  s_attacking[1][0].load(":/hero/sprites/al0.png");
  s_attacking[1][1].load(":/hero/sprites/al1.png");
  s_attacking[1][2].load(":/hero/sprites/al2.png");
  s_attacking[1][3].load(":/hero/sprites/al3.png");
  s_attacking[1][4].load(":/hero/sprites/al4.png");
  s_attacking[1][5].load(":/hero/sprites/al5.png");
  s_attacking[1][6].load(":/hero/sprites/al6.png");
  s_attacking[1][7].load(":/hero/sprites/al7.png");
  s_attacking[1][8].load(":/hero/sprites/al8.png");
  s_attacking[1][9].load(":/hero/sprites/al9.png");
  s_attacking[1][10].load(":/hero/sprites/al10.png");
  s_attacking[1][11].load(":/hero/sprites/al11.png");
  s_attacking[1][12].load(":/hero/sprites/al12.png");

  //sprites caminar a la izquierda
  sprites[2][0].load(":/hero/sprites/wr1.png");
  sprites[2][1].load(":/hero/sprites/wr2.png");
  sprites[2][2].load(":/hero/sprites/wr3.png");
  sprites[2][3].load(":/hero/sprites/wr4.png");
  sprites[2][4].load(":/hero/sprites/wr5.png");
  sprites[2][5].load(":/hero/sprites/wr6.png");
  sprites[2][6].load(":/hero/sprites/wr7.png");
  sprites[2][7].load(":/hero/sprites/wr8.png");
  sprites[2][8].load(":/hero/sprites/wr9.png");

  //sprites atacar a la izquierda
  s_attacking[2][0].load(":/hero/sprites/ar0.png");
  s_attacking[2][1].load(":/hero/sprites/ar1.png");
  s_attacking[2][2].load(":/hero/sprites/ar2.png");
  s_attacking[2][3].load(":/hero/sprites/ar3.png");
  s_attacking[2][4].load(":/hero/sprites/ar4.png");
  s_attacking[2][5].load(":/hero/sprites/ar5.png");
  s_attacking[2][6].load(":/hero/sprites/ar6.png");
  s_attacking[2][7].load(":/hero/sprites/ar7.png");
  s_attacking[2][8].load(":/hero/sprites/ar8.png");
  s_attacking[2][9].load(":/hero/sprites/ar9.png");
  s_attacking[2][10].load(":/hero/sprites/ar10.png");
  s_attacking[2][11].load(":/hero/sprites/ar11.png");
  s_attacking[2][12].load(":/hero/sprites/ar12.png");

  //sprites caminar hacia abajo
  sprites[3][0].load(":/hero/sprites/wu1.png");
  sprites[3][1].load(":/hero/sprites/wu2.png");
  sprites[3][2].load(":/hero/sprites/wu3.png");
  sprites[3][3].load(":/hero/sprites/wu4.png");
  sprites[3][4].load(":/hero/sprites/wu5.png");
  sprites[3][5].load(":/hero/sprites/wu6.png");
  sprites[3][6].load(":/hero/sprites/wu7.png");
  sprites[3][7].load(":/hero/sprites/wu8.png");
  sprites[3][8].load(":/hero/sprites/wu9.png");

  //sprites atacar hacia abajo
  s_attacking[3][0].load(":/hero/sprites/au0.png");
  s_attacking[3][1].load(":/hero/sprites/au1.png");
  s_attacking[3][2].load(":/hero/sprites/au2.png");
  s_attacking[3][3].load(":/hero/sprites/au3.png");
  s_attacking[3][4].load(":/hero/sprites/au4.png");
  s_attacking[3][5].load(":/hero/sprites/au5.png");
  s_attacking[3][6].load(":/hero/sprites/au6.png");
  s_attacking[3][7].load(":/hero/sprites/au7.png");
  s_attacking[3][8].load(":/hero/sprites/au8.png");
  s_attacking[3][9].load(":/hero/sprites/au9.png");
  s_attacking[3][10].load(":/hero/sprites/au10.png");
  s_attacking[3][11].load(":/hero/sprites/au11.png");
  s_attacking[3][12].load(":/hero/sprites/au12.png");

  set_pos(get_pos() - QVector2D(sprites[col][row].width() / 2,
				sprites[col][row].height() / 2));

  update_collision_rect();

  /*
    walking_sound = new QMediaPlayer();
    walking_sound->setMedia(QUrl("qrc:/sounds/sprites/footstep04.ogg"));
    walking_sound->setVolume(50);
  */
}

void Hero::update(double dt)
{
  if (attacking)
  {
    if(col_atk == 13)
    {
      col_atk = 0;
      attacking = false;
    }
    else
      ++col_atk;
  }

  if (walking)
  {
    //walking_sound->play();

    current_walking_time += dt;

    if (current_walking_time > walking_time)
    {
      current_walking_time = 0;
      walking = false;
      col = 0;
      update_collision_rect();
    }
  }

  if (recieving_damage)
  {
    current_damage_time += dt;

    if (current_damage_time > damage_time)
    {
      current_damage_time = 0;
      recieving_damage = false;
    }
  }
}

void Hero::draw(QPainter & painter)
{
  //pinto al heroe
  if(attacking and row == 0)
    painter.drawPixmap(get_pos().toPoint(), s_attacking[row][col_atk]);
  else if(attacking)
    painter.drawPixmap(get_pos().x(), get_pos().y() - 7, s_attacking[row][col_atk]);
  else
    painter.drawPixmap(get_pos().toPoint(), sprites[row][col]);

  //metodo para pintar el col_rec del heroe para debugging
  //painter.drawRect(this->get_col_rect());

  //pinto la barra de vida
  painter.fillRect(health_bar->rect(), health_bar->brush());
  painter.drawRect(20, 10, health_bar->get_size_x(), health_bar->get_size_y());
  painter.drawPixmap(12, 10, health_bar->get_sprite());

  //pinto la barra de mana
  painter.fillRect(mana_bar->rect(), mana_bar->brush());
  painter.drawRect(20, 40, mana_bar->get_size_x(), mana_bar->get_size_y());
  painter.drawPixmap(12, 40, mana_bar->get_sprite());
  
  //pinto la barra de xp
  painter.fillRect(xp_bar->rect(), xp_bar->brush());
  painter.drawRect(20, 70, xp_bar->get_size_x(), xp_bar->get_size_y());
  painter.drawPixmap(12, 70, xp_bar->get_sprite());
}

void Hero::recieve_damage(const Entity & attacker)
{
  if(recieving_damage)
    return;
  
  long damage_recieved = (attacker.get_atck() - ((25*this->get_def())/100));

  if(this->get_hp() > damage_recieved)
  {
    recieving_damage = true;

    health_bar->decrement(damage_recieved);
    health_bar->update_bar();

    this->decreise_hp(damage_recieved);
  }
  else
  {
    health_bar->decrement(get_hp());
    health_bar->update_bar();
    this->set_hp(0);
  }
}

void Hero::picking_object(DynList<Object *> & objects)
{
  int i = 0;

  DynList<Object *> objects1;

  for(auto item : objects)
  {
    if(get_col_rect().intersects(item->get_collision_rect()))
  	{
  	  InventoryBox * box;
  	  box = new InventoryBox(item, i);
  	  inventory.add_object(box);
  	}
    else
	    objects1.append(item);
  }

  objects.swap(objects1);
}

bool Hero::is_attacking() const
{
  return attacking;
}

void Hero::attack()
{
  attacking = true;
}

void Hero::move(QKeyEvent * evnt, int width, int height, DynList<Object *> &bg_o, DynList<Object *> &inter)
{
  if(evnt->key() == Qt::Key_Up or evnt->key() == Qt::Key_Down
    or evnt->key() == Qt::Key_Left or evnt->key() == Qt::Key_Right)
  {
    keys_pressed.insert(evnt->key());
  }

  if (keys_pressed.size() == 1)
  {
    switch (evnt->key())
    {
      case Qt::Key_Right:
      {
        row = 2;

        if(col == 8)
          col = 0;
        else
          ++col;

        update_collision_rect();
        walking = true;

        set_pos_x(get_pos().x() + speed);

        if (get_col_rect().right() > width)
          set_pos_x(width - get_col_rect().width());
      }
        break;
      case Qt::Key_Left:
      {
        row = 1;

        if(col == 8)
          col = 0;
        else
          ++col;

        update_collision_rect();
        walking = true;

        set_pos_x(get_pos().x() - speed);

        if (get_pos().x() < 0)
          set_pos_x(0);
      }
        break;
      case Qt::Key_Up:
      {
        row = 3;

        if(col == 8)
          col = 0;
        else
          ++col;

        update_collision_rect();
        walking = true;

        set_pos_y(get_pos().y() - speed);

        if (get_pos().y() < 0)
          set_pos_y(0);
      }
        break;
      case Qt::Key_Down:
      {
        row = 0;

        if(col == 8)
          col = 0;
        else
          ++col;

        update_collision_rect();
        walking = true;

        set_pos_y(get_pos().y() + speed);

        if (get_col_rect().bottom() >= height)
          set_pos_y(height - get_col_rect().height());
      }
        break;
    }
  }

  //si undo mas de dos teclas
  if (keys_pressed.size() > 1)
  {
    speed = 3;
    if (keys_pressed.contains(Qt::Key_Up) and keys_pressed.contains(Qt::Key_Right))
    {
      row = 3;

      if(col == 8)
        col = 0;
      else
        ++col;

      update_collision_rect();
      walking = true;

      set_pos_y(get_pos().y() - speed);
      set_pos_x(get_pos().x() + speed);

      if (get_pos().y() < 0)
        set_pos_y(0);

      if (get_col_rect().right() > width)
        set_pos_x(width - get_col_rect().width());
    }
    if (keys_pressed.contains(Qt::Key_Up) and keys_pressed.contains(Qt::Key_Left))
    {
      row = 3;

      if(col == 8)
        col = 0;
      else
        ++col;

      update_collision_rect();
      walking = true;

      set_pos_y(get_pos().y() - speed);
      set_pos_x(get_pos().x() - speed);

      if (get_pos().y() < 0)
        set_pos_y(0);

      if (get_pos().x() < 0)
        set_pos_x(0);
    }
    if (keys_pressed.contains(Qt::Key_Down) and keys_pressed.contains(Qt::Key_Right))
    {
      row = 0;

      if(col == 8)
        col = 0;
      else
        ++col;

      update_collision_rect();
      walking = true;

      set_pos_y(get_pos().y() + speed);
      set_pos_x(get_pos().x() + speed);

      if (get_col_rect().bottom() >= height)
        set_pos_y(height - get_col_rect().height());

      if (get_col_rect().right() > width)
        set_pos_x(width - get_col_rect().width());
    }
    if (keys_pressed.contains(Qt::Key_Down) and keys_pressed.contains(Qt::Key_Left))
    {
      row = 0;

      if(col == 8)
        col = 0;
      else
        ++col;

      update_collision_rect();
      walking = true;

      set_pos_y(get_pos().y() + speed);
      set_pos_x(get_pos().x() - speed);

      if (get_col_rect().bottom() >= height)
        set_pos_y(height - get_col_rect().height());

      if (get_pos().x() < 0)
        set_pos_x(0);
    }
    speed = 4;
  }

  //chequeo colisiones
  for (auto item : bg_o)
  {
    //si colisionan mando al heroe a su posicion previa
    if(this->get_col_rect().intersects(item->get_collision_rect()))
    {
      set_pos_x(x_prev);
      set_pos_y(y_prev);
      return;
    }
  }
  
  for (auto item : inter)
  {
    //si colisionan mando al heroe a su posicion previa
    if(this->get_col_rect().intersects(item->get_collision_rect()))
    {
      set_pos_x(x_prev);
      set_pos_y(y_prev);
      return;
    }
  }

  int push_back = 8;

  //si no hubo colision actualizo la posicion previa
  if(keys_pressed.size() == 1)
  {
    if(row == 0)
    {
      x_prev = get_pos().x();
      y_prev = get_pos().y() - push_back;
    }
    else if(row == 1)
    {
      x_prev = get_pos().x() + push_back;
      y_prev = get_pos().y();
    }
    else if(row == 2)
    {
      x_prev = get_pos().x() - push_back;
      y_prev = get_pos().y();
    }
    else if(row == 3)
    {
      x_prev = get_pos().x();
      y_prev = get_pos().y() + push_back;
    }
  }
  else
  {
    if (keys_pressed.contains(Qt::Key_Up) and keys_pressed.contains(Qt::Key_Right))
    {
      y_prev = get_pos().y() + push_back;
      x_prev = get_pos().x() - push_back;
    }
    else if (keys_pressed.contains(Qt::Key_Up) and keys_pressed.contains(Qt::Key_Left))
    {
      y_prev = get_pos().y() + push_back;
      x_prev = get_pos().x() + push_back;
    }
    else if (keys_pressed.contains(Qt::Key_Down) and keys_pressed.contains(Qt::Key_Right))
    {
      x_prev = get_pos().x() - push_back;
      y_prev = get_pos().y() - push_back;
    }
    else if (keys_pressed.contains(Qt::Key_Down) and keys_pressed.contains(Qt::Key_Left))
    {
      x_prev = get_pos().x() + push_back;
      y_prev = get_pos().y() - push_back;
    }
  }
}

void Hero::release_key(QKeyEvent *evnt)
{
  keys_pressed.remove(evnt->key());
}

void Hero::update_inventory()
{
  if(inventory.get_hide() == true)
  {
    inventory.set_position(get_pos());
    inventory.set_hide(false);
  }
  else
    inventory.set_hide(true);
}

void Hero::draw_inventory(QPainter & painter)
{
  if(inventory.get_hide() == false)
  {
    inventory.set_position(get_pos());
    inventory.draw_inventory(painter);
  }
}

Hero::~Hero()
{
  for(int i = 0; i < NUM_ROWS; i++)
    delete[] sprites[i];

  delete[] sprites;

  delete health_bar;
  delete mana_bar;
  //delete walking_sound;
}

bool Hero::hide_inventory()
{
  return inventory.get_hide();
}

bool Hero::hide_inventory_options()
{
  return inventory.get_hide_options();
}

void Hero::update_selected_position(int && i, int && j)
{
  inventory.update_selected_position(std::move(i),std::move(j));

}

void Hero::update_selected_options(int && i)
{
  inventory.update_selected_options(std::move(i));
}

void Hero::update_options()
{
  if(inventory.get_hide_options() == true)
  {
    inventory.set_hide_options(false);
  }
  else
    inventory.set_hide_options(true);
}

int Hero::get_row()
{
  return row;
}

bool Hero::get_options()
{
  return inventory.get_hide_options();
}

void Hero::select_option()
{
  inventory.behave_options(*this);
}

void Hero::Q_ability()
{
	if(attacking)
		return;
		
	int decreise_mana = MANA / 4;
	if(get_mana() > 1)
	{
		mana_bar->decrement(decreise_mana);
  	mana_bar->update_bar();

  	this->set_mana(get_mana() - decreise_mana);
  	attacking = true;
	}
}

void Hero::increment_life(long amount)
{
  //si la vida a agregar es menor que la vida maxima
  if(get_hp() + amount <= HP)
  {
    this->set_hp(get_hp() + amount);
    health_bar->increment(amount);
  }
  else //vida a agregar es mayor que la vida maxima
  {
    this->set_hp(HP);
    health_bar->set_current_val(HP);
    health_bar->update_bar();
  }
}
