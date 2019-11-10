# ifndef TREE_CLASS
# define TREE_CLASS

# include <noninteractuable.hh>

class Tree : public Noninteractuable
{
public:
  explicit Tree();
  explicit Tree(const QVector2D &);
  explicit Tree(const QVector2D &, int);

  void draw(QPainter &) override;
  Object_Type get_type() override;
};

# endif
