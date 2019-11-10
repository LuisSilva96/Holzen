# ifndef INTERACTUABLE_CLASS
# define INTERACTUABLE_CLASS

# include <object.hh>

class Interactuable : public Object
{
private:
	QPixmap * sprites;
	int current_sprite;
		
public:
  explicit Interactuable();
  Object_Type get_type() override;
  void behave(Entity &);
  void set_sprites(QPixmap &, QPixmap &);
  int get_current_sprite();
  void set_current_sprite(int);
};

# endif
