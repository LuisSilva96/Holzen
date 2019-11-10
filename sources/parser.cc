# include <parser.hh>

Parser::Parser(string dir)
  : filename(dir)
{
	this->load(dir);
	
  writer.open(dir);

  if (writer.fail())
  {
    writer.clear();
    writer.close();
    writer.open(dir);

  	if (writer.fail())
  	 	throw invalid_argument("Could not open the file");
  }
  
	for(int i = 0; i < Scenario::WIDTH; i+= 62)
   	insert_nmo(i,0,"b","bush");
 	 
  for(int i = 62; i < Scenario::WIDTH - 62; i+= 62)
  	insert_nmo(i,Scenario::HEIGHT - 65,"b","bush");
 	
  for(int i = 0; i < Scenario::HEIGHT - 59; i+= 59) 
  	insert_nmo(0,i,"b","bush");
 		
  for(int i = 0; i < Scenario::HEIGHT - 59; i+= 59)
  	insert_nmo(Scenario::WIDTH - 59,i,"b","bush");
  	
  insert_nmo(62,59,"t","tree");	
  insert_nmo(160,59,"t","tree");
  insert_nmo(326,118,"t","chest");
  insert_nmo(450,59,"t","tree");	
  insert_nmo(553,59,"t","tree");	
  insert_enemy(264,236,264,236,"b","block");
  
  insert_nmo(Scenario::WIDTH - 151,59,"t","tree");	
  insert_nmo(Scenario::WIDTH - 242,59,"t","tree");
  insert_nmo(Scenario::WIDTH - 376,118,"t","chest");
  insert_nmo(Scenario::WIDTH - 538,59,"t","tree");	
  insert_nmo(Scenario::WIDTH - 641,59,"t","tree");
  insert_enemy(Scenario::WIDTH - 301,236,Scenario::WIDTH - 301,236,"b","block");
  
  insert_nmo(62,Scenario::HEIGHT - 259,"t","tree");	
  insert_nmo(160,Scenario::HEIGHT - 259,"t","tree");
  insert_nmo(326,Scenario::HEIGHT - 177,"t","chest");
  insert_nmo(450,Scenario::HEIGHT - 259,"t","tree");	
  insert_nmo(553,Scenario::HEIGHT - 259,"t","tree");	
  insert_enemy(264,Scenario::HEIGHT - 306,264,Scenario::HEIGHT - 306,"b","block");
  
  insert_nmo(Scenario::WIDTH - 151,Scenario::HEIGHT - 259,"t","tree");	
  insert_nmo(Scenario::WIDTH - 242,Scenario::HEIGHT - 259,"t","tree");
  insert_nmo(Scenario::WIDTH - 376,Scenario::HEIGHT - 177,"t","chest");
  insert_nmo(Scenario::WIDTH - 538,Scenario::HEIGHT - 259,"t","tree");	
  insert_nmo(Scenario::WIDTH - 641,Scenario::HEIGHT - 259,"t","tree");
  insert_enemy(Scenario::WIDTH - 301,Scenario::HEIGHT - 306,Scenario::WIDTH - 301,Scenario::HEIGHT - 306,"b","block");
}

Parser::~Parser()
{
  this->writer.clear();
  this->writer.close();
  this->recorder.empty();
}

void Parser::load(string dir)
{
  ifstream reader(dir);
  string fst;
  string scnd;
  int f, s;
  string thrd;
  string frth;
  char ch;
  string trash;
    
  if (reader.fail())
    {
      reader.clear();
      reader.close();
      reader.open(dir);
      if (reader.fail())
				throw  invalid_argument("Could not open file");
    }
  
  	while (not reader.eof())
    {
      reader >> ch;
      switch (ch)
		{
		case '<':
			{
			  getline(reader, fst, ',');
			  getline(reader, scnd, ',');
			  getline(reader, thrd, ',');
			  getline(reader, frth, '>');
			  f = atoi(fst.c_str());
			  s = atoi(scnd.c_str());
			  this->recorder.insert(make_tuple(f,s,thrd,frth));
			 getline(reader, trash);
			 trash.clear();
      	break;
			}
		case '[':
			{
			  getline(reader, fst, ',');
			  getline(reader, scnd, ',');
			  getline(reader, thrd, ',');
			  getline(reader, frth, ']');
			  f = atoi(fst.c_str());
			  s = atoi(scnd.c_str());
			  this->recorder.insert(make_tuple(f,s,thrd,frth));
			 getline(reader, trash);
			  trash.clear();
			  break;
			}
		}
    }
  reader.clear();
  reader.close();
}

void Parser::insert_nmo(int x, int y,	string id, string type)
{
  if (not this->search(make_tuple(x,y,id,type)))
    {
      this->recorder.insert(make_tuple(x,y,id,type));
      this->writer << '<' << x << ',' << y << ',' << id << ',' << type << '>' 
      							<< '\n';
    }
}

void Parser::insert_enemy(int low_x, int low_y,int high_x, int high_y,
													 string id, string type)
{
  my_distribution dist_x{low_x,high_x+1};  
  my_distribution dist_y{low_y,high_y+1};
  my_engine reg{seed};

  Tuple aux;
  
  aux = make_tuple(dist_x(reg),dist_y(reg),id,type);
  
  if (not this->search(aux))
		this->recorder.insert(aux);
  
  this->writer << '[' << get<0>(aux) << ',' << get<1>(aux) << ',' << id << ','
  						 << type << ']' << '\n';
}

void Parser::remove(Tuple t)
{
  this->writer.clear();
  this->writer.close();

  ifstream reader(filename);
  ofstream fout("aux.txt");
  Tuple tu;
  char ch;
  string trash;
  
  while (not reader.eof())
    {
      reader >> ch;
      switch (ch)
	{
	case '<':
	  {
	    reader >> get<0>(tu);
	    reader >> get<1>(tu);
	    reader >> get<2>(tu);
	    reader >> get<3>(tu);
	    getline(reader,trash,'>');
	    if (tu == t)
	      {
		this->recorder.remove(t);
		continue;
	      }
	    fout << '<' << get<0>(tu) << ',' << get<0>(tu) << ',' << trash << '\n';
	  }
	case '[':
	  {
	    reader >> get<0>(tu);
	    reader >> get<1>(tu);
	    reader >> get<2>(tu);
	    reader >> get<3>(tu);
	    getline(reader,trash,']');
	    if (tu == t)
	      {
		this->recorder.remove(t);
		continue;
	      }
	    fout << '[' << get<0>(tu) << ',' << get<0>(tu) << ',' << trash << '\n';
	  }
      }
    }
  fout.close();
  
  std::remove(this->filename.c_str());
  rename("aux.txt",this->filename.c_str());
  writer.open(this->filename);
}
  
bool Parser::search(Tuple t)
{
  return this->recorder.contains(t);
}

void Parser::build_scenario(Scenario &s)
{
	for(auto item : recorder)
	{
		int frst = get<0>(item);
		int scnd = get<1>(item);
		string thrd = get<2>(item);
		string frth = get<3>(item);
		
		if(frth == "smallhealthpotion")
			s.make_consumable(QVector2D(frst,scnd), Object_Type::SMALLHEALTHPOTION);
		else if(frth == "arrow")
			s.make_consumable(QVector2D(frst,scnd), Object_Type::ARROW);
		else if(frth == "bush")
			s.make_background_object(QVector2D(frst,scnd), Object_Type::BUSH);
		else if(frth == "chest")
			s.make_interactuable(QVector2D(frst,scnd), Object_Type::CHEST);
		else if(frth == "block")
			s.make_creature(QVector2D(frst,scnd),Creature_Type::BLOCK);
		else if(frth == "tree")
			s.make_background_object(QVector2D(frst,scnd), Object_Type::TREE);
	}
}
