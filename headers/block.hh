# ifndef BLOCK_CREATURE_CLASS
# define BLOCK_CREATURE_CLASS

# include <creature.hh>
# include <attack.hh>
# include <chase.hh>
# include <alert.hh>
# include <QPainter>

class Block : public Creature
{
private:
  int col = 0;
  int row = 0;

public:
  explicit Block(const QVector2D & , Object_Type);
  explicit Block(QVector2D &&, Object_Type);
  ~Block();

  void update(Entity &, double &) override;
  void sprite_manager(Sprite_Direction) override;

  void move(double &) override;
  void move(double &&) override;
  
  void draw(QPainter &) override;
  Creature_Type type() override;
  void table(QVector2D);
  
};

# endif
