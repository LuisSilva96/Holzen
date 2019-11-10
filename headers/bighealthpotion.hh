# ifndef BIGHEALTHPOTION_CLASS
# define BIGHEALTHPOTION_CLASS

# include <consumable.hh>

class BigHealthPotion : public Consumable
{
private:
  unsigned cure;

public:
  explicit BigHealthPotion();
  explicit BigHealthPotion(const QVector2D &);
  void behave(Entity &) override;
  void draw(QPainter &) override{}
  Object_Type get_type() override;
};

# endif
