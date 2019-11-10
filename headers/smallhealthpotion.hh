# ifndef SMALLHEALTHPOTION_CLASS
# define SMALLHEALTHPOTION_CLASS

# include <consumable.hh>

class SmallHealthPotion : public Consumable
{
private:
  unsigned cure;

public:
  explicit SmallHealthPotion();
  explicit SmallHealthPotion(const QVector2D &);
  void behave(Entity &) override;
  void draw(QPainter &) override{}
  Object_Type get_type() override;
};

# endif
