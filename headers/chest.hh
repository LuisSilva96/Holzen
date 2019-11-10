# ifndef CHEST_CLASS
# define CHEST_CLASS

# include <interactuable.hh>

class Chest : public Interactuable
{
public:
  explicit Chest();
  explicit Chest(const QVector2D &);

  void draw(QPainter &) override{}
  Object_Type get_type() override;
};

# endif
