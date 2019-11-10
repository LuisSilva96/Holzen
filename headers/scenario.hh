#ifndef SCENARIO_CLASS
#define SCENARIO_CLASS

# include <QWidget>
# include <cstdlib>

//ALEPH INCLUDES
# include <ahNow.H>

//CREATURES
# include <block.hh>
# include <bee.hh>

//OBJECTS
# include <smallhealthpotion.hh>
# include <bighealthpotion.hh>
# include <smallmanapotion.hh>
# include <bigmanapotion.hh>
# include <arrow.hh>
# include <bush.hh>
# include <chest.hh>
# include <tree.hh>

# include <hero.hh>
# include <menu.hh>

class Scenario : public QWidget
{
  Q_OBJECT

public:
  static constexpr int WIDTH  = 1300;
  static constexpr int HEIGHT = 750;

private:
  Hero hero;
  QTimer timer, timer2, timer3;
  Now * now;
  DynList<Creature *> creatures;
  DynList<Object *> objects;
  DynList<Object *> background_objects;
  DynList<Object *> interactuables;
  DynList<Arrow *> arrows;
  Inventory inventory;
  bool paused = false;
  bool hero_dead = false;
  //QMediaPlayer * music;

public:
  Scenario(QWidget * parent = nullptr);
  ~Scenario();

  void closeEvent(QCloseEvent *) override;
  void paintEvent(QPaintEvent *) override;
  void keyPressEvent(QKeyEvent *) override;
  void keyReleaseEvent(QKeyEvent * event) override;
  
  void start();
  bool is_paused();
  bool is_hero_dead();
  void clean_arrow();
  void clean_creature();
  void armament_colliding();
  void unpause();
  
  void make_creature(QVector2D &, Object_Type, Creature_Type);
  void make_creature(QVector2D &&, Object_Type, Creature_Type);
  void make_creature(QVector2D &, Creature_Type);
  void make_creature(QVector2D &&, Creature_Type);
  void make_consumable(const QVector2D &, Object_Type);
  void make_consumable(QVector2D &&, Object_Type);
  void make_background_object(QVector2D &&, Object_Type);
  void make_interactuable(QVector2D &&, Object_Type);
  
signals:

public slots:
  void slot_update();
  void slot_for_inventory();
  void slot_for_dying();
  //void replay_music(QMediaPlayer::State s);
};

#endif //SCENARIO_HH
