# ifndef BEE_CREATURE_CLASS
# define BEE_CREATURE_CLASS

# include <creature.hh>
# include <attack.hh>
# include <chase.hh>
# include <alert.hh>
# include <QPainter>

class Bee : public Creature
{
public:
  explicit Bee(const QVector2D & , Object_Type);
  explicit Bee(QVector2D &&, Object_Type);
  ~Bee();

  void update(Entity &, double &) override;
  void sprite_manager(Sprite_Direction) override;

  void move(double &) override;
  void move(double &&) override;
  
  void draw(QPainter &) override;
  Creature_Type type() override;
  void table(QVector2D);  
};

# endif
