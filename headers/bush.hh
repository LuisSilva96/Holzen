# ifndef BUSH_CLASS
# define BUSH_CLASS

# include <noninteractuable.hh>

class Bush : public Noninteractuable
{
public:
  explicit Bush();
  explicit Bush(const QVector2D &);

  void draw(QPainter &) override;
  Object_Type get_type() override;
};

# endif
