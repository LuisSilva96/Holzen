# ifndef SMALLMANAPOTION_CLASS
# define SMALLMANAPOTION_CLASS

# include <consumable.hh>

class SmallManaPotion : public Consumable
{
private:
  unsigned mana;

public:
  explicit SmallManaPotion();
  explicit SmallManaPotion(const QVector2D &);
  void behave(Entity &) override;
  void draw(QPainter &) override{}
  Object_Type get_type() override;
};

# endif
