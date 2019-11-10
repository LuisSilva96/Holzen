# ifndef BIGMANAPOTION_CLASS
# define BIGMANAPOTION_CLASS

# include <consumable.hh>

class BigManaPotion : public Consumable
{
private:
  unsigned mana;

public:
  explicit BigManaPotion();
  explicit BigManaPotion(const QVector2D &);
  void behave(Entity &) override;
  void draw(QPainter &) override{}
  Object_Type get_type() override;
};

# endif
