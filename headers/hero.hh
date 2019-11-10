# ifndef HERO_CLASS
# define HERO_CLASS

//ALEPH INCLUDES
# include <htlist.H>

//GAME INCLUDES
# include <entity.hh>
# include <arrow.hh>
# include <inventory.hh>
# include <bar.hh>

class Hero : public Entity
{
private:
  static constexpr int NUM_ROWS   = 4;
  static constexpr int NUM_COLS   = 9;
  
  void update_collision_rect();

  QPixmap s_attacking[NUM_ROWS][14];
  Inventory inventory;
  Arrow * arrows;
  QSet<int> keys_pressed;
  Bar * health_bar;
  Bar * mana_bar;
  Bar * xp_bar;
  //QMediaPlayer * walking_sound;

  int speed;
  int col = 0;
  int row = 0;
  int col_atk = 0;
  int x_prev;
  int y_prev;

  bool walking = false;
  double current_walking_time = 0;
  double walking_time = 0.2;

  bool attacking = false;

  bool recieving_damage = false;
  double current_damage_time = 0;
  double damage_time = 0.5;

protected:
  Hero();

public:
  explicit Hero(const QVector2D &);
  ~Hero();

  void update(double dt);
  void draw(QPainter &);
  void move(QKeyEvent * evnt, int, int, DynList<Object *> &, DynList<Object *> &);
  void release_key(QKeyEvent * event);

  void recieve_damage(const Entity &);
  void attack();
  bool is_attacking() const;
  void increment_life(long);

  void picking_object(DynList<Object *> &);
  void update_inventory();
  void draw_inventory(QPainter &);
  bool hide_inventory();
  bool hide_inventory_options();
  void update_selected_position(int &&, int &&);
  void update_selected_options(int &&);
  void update_options();
  bool get_options();
  void select_option();

	void Q_ability();
  int get_row();
};

# endif // HERO_H
