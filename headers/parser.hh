# include <string>
# include <fstream>
# include <iostream>
# include <ahSort.H>
# include <tpl_dynSetTree.H>
# include <utility>
# include <random>
# include <chrono>
# include <scenario.hh>

using namespace std;

using Tuple = tuple<int, int, string, string>;
using my_engine = default_random_engine;
using my_distribution = uniform_int_distribution<int>; 

struct cmp
{
  bool operator()(Tuple fst, Tuple scnd)
  {
    if (get<0>(fst) < get<0>(scnd) or get<1>(fst) < get<1>(scnd))
      return true;

    return false;
  }
};

static const unsigned seed = chrono::system_clock::now().time_since_epoch().count();

class Parser
{
private:
  DynSetTree<Tuple,BinTree,cmp> recorder;
  ofstream writer;
  string filename;
  
public:
  Parser(string);
  ~Parser();

  void load(string);
  void insert_nmo(int, int, string, string);
  void insert_enemy(int, int, int, int, string, string);
  void remove(Tuple);
  bool search(Tuple);
  void build_scenario(Scenario &);
};
