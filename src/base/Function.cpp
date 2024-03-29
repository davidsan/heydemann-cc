﻿#include <Function.h>

Function::Function(){
  _head = NULL;
  _end = NULL;
}

Function::~Function(){}

void Function::set_head(Node *head){
  _head = head;
}

void Function::set_end(Node *end){
  _end = end;
}

Node* Function::get_head(){
  return _head;
}

Basic_block* Function::get_firstBB(){
   return _myBB.front();
}

Node* Function::get_end(){
  return _end;
}

void Function::display(){
  cout<<"Begin Function"<<endl;
  Node* element = _head;

  if(element == _end)	
    cout << _head->get_lineContent() <<endl;

  while(element != _end){
    cout << element->get_lineContent() <<endl;
		
    if(element->get_next()==_end){
      cout << element->get_next()->get_lineContent() <<endl;
      break;
    }
    else element = element->get_next();

    }
  cout<<"End Function\n\n"<<endl;
	
}

int Function::size(){
  Node* element = _head;
  int lenght=0;
  while(element != _end)
    {
      lenght++;		
      if (element->get_next()==_end)
	break;
      else
	element = element->get_next();
    }
  return lenght;
}	


void Function::restitution(string const filename){
	
  Node* element = _head;
  ofstream monflux(filename.c_str(), ios::app);

  if(monflux){
    monflux<<"Begin"<<endl;
    if(element == _end)	
      monflux << _head->get_line()-> get_content() <<endl;
    while(element != _end)
      {
	if(element->get_line()->isInst() || 
	   element->get_line()->isDirective()) 
	  monflux<<"\t";
	
	monflux << element->get_lineContent() ;
	
	if(element->get_lineContent().compare("nop")) 
	  monflux<<endl;
		
	if(element->get_next()==_end){
	  if(element->get_next()->get_line()->isInst() || 
	     element->get_next()->get_line()->isDirective())
	    monflux<<"\t";
	  monflux << element->get_next()->get_lineContent()<<endl;
	  break;
	}
	else element = element->get_next();

      }
    monflux<<"End\n\n"<<endl;
		
  }

  else {
    cout<<"Error cannot open the file"<<endl;
  }

  monflux.close();
}

void Function::comput_label(){
  Node* element = _head;

  if(element == _end && element->get_line()->isLabel())	
    _list_lab.push_back(dynamic_cast< Label *> (element->get_line()));
  while(element != _end)
    {

      if(element->get_line()->isLabel())	
	_list_lab.push_back(dynamic_cast< Label * > (element->get_line()));

      if(element->get_next()==_end){
	if(element->get_line()->isLabel())	
	  _list_lab.push_back(dynamic_cast< Label * > (element->get_line()));
	break;
      }
      else element = element->get_next();

    }

}

int Function::nbr_label(){
  return _list_lab.size();

}

Label* Function::get_label(int index){

  list<Label*>::iterator it;
  it=_list_lab.begin();

  int size=(int) _list_lab.size();
  if(index< size){
    for (int i=0; i<index;i++ ) it++;
    return *it;	
  }
  else cout<<"Error get_label : index is bigger than the size of the list"<<endl; 
	
  return _list_lab.back();
}

Basic_block *Function::find_label_BB(OPLabel* label){
  //Basic_block *BB = new Basic_block();
   int size=(int)_myBB.size();
   string str;
   for(int i=0; i<size; i++){		
      if(get_BB(i)->is_labeled()){
	 
	 str=get_BB(i)->get_head()->get_lineContent();
	 if(!str.compare(0, (str.size()-1),label->get_op())){
	    return get_BB(i);
	 }
      }
  }
  return NULL;
}

//Calcule la liste des blocs de base : il faut délimiter les BB, en parcourant la liste des lignes/instructions à partir de la premiere, il faut s'arreter à chaque branchement (et prendre en compte le delayed slot qui appartient au meme BB, c'est l'instruction qui suit tout branchement) car il indique la fin d'un BB/une entete qui est l'instruction qui suit l'instruction du delayed slot ou à chaque label (on estime que tout label est utilisé par un saut et donc un label correspond correspond à une entete de BB).
//exemple 
/*
etiq:  <- etiquette => prochaine instruction est une entete
   i1
   i2
   i3
   saut
   i4   <- appartient au même BB que 'saut'
   i5   <- i5 est une entete
   ...

*/ 

void Function::add_BB(Node *debut, Node* fin, int index){
   Basic_block *b=new Basic_block();
   b->set_head(debut);
   b->set_end(fin);
   b->set_index(index);
   _myBB.push_back(b);
}

void Function::comput_basic_block(){
  Node *debut, *current, *prev;
  current=_head;
  debut=_head;
  prev = NULL;
  int ind=0;
  Line *l=NULL;
  Instruction *i=NULL;
  
  cout<<"comput BB"<<endl;

  cout<<"head :"<<_head->get_lineContent()<<endl;
  cout<<"tail :"<<_end->get_lineContent()<<endl;
  
  // faire avancer le pointeur current aprs le label de la fonction
  while(current && current != _end && !current->get_line()->isInst()){
    current=current->get_next();
  }

  // parcours des lignes restantes
  while(current && current != _end){
    l = current->get_line();
    if(l->isDirective()){
      prev = current;
      current = current->get_next();
      continue;
    }
    if(l->isLabel()){
      // on teste si c'tait pas un jump avant
      if(debut < current){
        // le BB s'arrte  la ligne prev
        add_BB(debut,prev,ind);
        // on fait commencer le prochain BB au label
        debut = current;
        
        ind++;
      }
    }
    if(l->isInst()){
      i = (dynamic_cast <Instruction *> (l));
      if(i->get_type() == BR){
        // instruction de type t_Type.BR
        add_BB(debut,current->get_next(),ind);
        get_BB(nbr_BB()-1)->set_branch(current);
        debut=current->get_next()->get_next();
        ind++;
        // on zappe dj le prochain
        prev = current;
        current = current->get_next();
        if(current == NULL){ // ne devrait pas se produire
          break;
        }
      }
    }
    prev = current;
    current = current->get_next();
  }

  // si le dernier BB ajouté n'est pas celui qui commence par début
  // alors il faut ajouter un BB qui se termine jusqu'à la fin
  if((debut == _head || !debut->get_line()->isDirective())
          && ((get_BB(nbr_BB()-1) == NULL) || (get_BB(nbr_BB()-1)->get_head() != debut))){
      add_BB(debut, prev, ind);
  }
  // set the last BB's end to the end
  //get_BB(nbr_BB()-1)->set_end(_end);
  cout<<"end comput BB"<<endl;
}

int Function::nbr_BB(){
   return _myBB.size();
}

Basic_block *Function::get_BB(int index){

  list<Basic_block*>::iterator it;
  it=_myBB.begin();
  int size=(int)_myBB.size();

  if(index< size){
    for (int i=0; i<index;i++ ) it++;
    return *it;	
  }
  else 
    return NULL;
}

list<Basic_block*>::iterator Function::bb_list_begin(){
   return _myBB.begin();
}

list<Basic_block*>::iterator Function::bb_list_end(){
   return _myBB.end();
}

/* comput_pred_succ calcule les successeurs et prédécesseur des BB, pour cela il faut commencer par les successeurs */
/* et itérer sur tous les BB d'une fonction */
/* il faut determiner si un BB a un ou deux successeurs : dépend de si le BB termine avec un saut */
/* si pas de saut ou si saut incontionnel : 1 successeur */
/* si branchement conditionnel : 2 successeurs, il faut trouver le BB cible de saut à partir de l'etiquette */ 


// NB : penser  utiliser la méthode set_link_succ_pred(Basic_block *) de la classe Basic_block  
void Function::comput_succ_pred_BB(){
  
  list<Basic_block*>::iterator it, it2;
  Basic_block *current, *next;
  Instruction *instr;
  Operand* op;
  OPLabel* olb;
  Basic_block *succ=NULL;

  it=_myBB.begin();   //1er BB
  it2=_myBB.begin();   //2eme BB
  it2++;
  //remarque : le dernier block n'a pas de successeurs
  while (it2!=_myBB.end()) {
    current = *it;
    next = *it2;
    Node * n = (current->get_branch());
    if (n!=NULL){
      instr = (dynamic_cast <Instruction *> (n->get_line()));
    }
    if (instr != NULL) {
      // saut conditionnel
      if (instr -> get_format() == I) {
        next->set_predecessor(current);
        current->set_successor2(next);
        op=instr -> get_op3();
        olb=(dynamic_cast <OPLabel *> (op));
        succ = find_label_BB(olb);
        if(succ){
          current->set_successor1(succ);
          succ->set_predecessor(current);
        }
      }else if(instr -> get_format () == J){
        // saut inconditionnel
        op=instr -> get_op1();
        olb=(dynamic_cast <OPLabel *> (op));
        succ = find_label_BB(olb);
        if(succ!=NULL){
          current -> set_successor1(succ);
          succ -> set_predecessor(current);
        }
      }
    }else{
      // pas de saut
      current->set_successor1(next);
      next->set_predecessor(current);
    }
    
    it++;
    it2++;
  }
  
}




/* en implementant la fonction test de la classe BB, permet de tester des choses sur tous les blocs de base d'une fonction par exemple l'affichage de tous les BB d'une fonction ou l'affichage des succ/pred des BBs comme c'est le cas -- voir la classe Basic_block et la méthode test */

void Function::test(){
   int size=(int)_myBB.size();
   for(int i=0;i<size; i++){
    get_BB(i)->test();
  }
}
