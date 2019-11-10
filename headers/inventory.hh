# ifndef INVENTORY_CLASS
# define INVENTORY_CLASS

# include <inventorybox.hh>

class Inventory
{
  private:
    InventoryBox * inventory[5][5];
    QPixmap background;
    QPixmap select_item;
    QPixmap select_action;
    QPixmap options_box;
    QVector2D position;
    QVector2D selected_position;
    int option_position;
    bool hide;
    bool hide_options;

  public:

    explicit Inventory();
    ~Inventory();

    void set_position(const QVector2D &);
    void set_hide(const bool &);
    void set_hide_options(const bool &);
    QVector2D get_position();
    bool get_hide();
    bool get_hide_options();
    void add_object(InventoryBox *);
    void draw_inventory(QPainter &);
    void draw_numbers(QPainter &, InventoryBox *, int, int);
    void update_selected_position(int &&, int &&);
    void update_selected_options(int &&);
    void selecting_object(int &, int &);
    void behave_options(Entity &);
};

#endif
