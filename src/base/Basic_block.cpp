﻿#include <Basic_block.h>


//static
void Basic_block::show_dependances(Instruction *i1, Instruction *i2){

//   cout<<"test raw"<<endl;
   if(i1->is_dep_RAW(i2))
      cout<<"Dependance i"<<i1->get_index()<<"->i"<<i2->get_index()<<": RAW"<<endl;

//   cout<<"test war"<<endl;
   if(i1->is_dep_WAR(i2))
      cout<<"Dependance i"<<i1->get_index()<<"->i"<<i2->get_index()<<": WAR"<<endl;

//   cout<<"test waw"<<endl;
   if(i1->is_dep_WAW(i2))
      cout<<"Dependance i"<<i1->get_index()<<"->i"<<i2->get_index()<<": WAW"<<endl;

//   cout<<"test mem"<<endl;
   if(i1->is_dep_MEM(i2))
      cout<<"Dependance i"<<i1->get_index()<<"->i"<<i2->get_index()<<": MEM"<<endl;

}

Basic_block::Basic_block(){
   _head = NULL;
   _end = NULL;
   _branch = NULL;
   _index = 0;
   _nb_instr = 0;
   _firstInst=NULL;
   _lastInst=NULL;

   for(int i=0; i<NB_REGISTRES; i++){
      _defs_uses[i]=NULL;
   }
}


Basic_block::~Basic_block(){}


void Basic_block::set_index(int i){
   _index = i;
}

int Basic_block::get_index(){
   return _index;
}

void Basic_block::set_head(Node *head){
   _head = head;
}

void Basic_block::set_end(Node *end){
   _end = end;
}

Node* Basic_block::get_head(){
   return _head;
}

Node* Basic_block::get_end(){
   return _end;
}

void Basic_block::set_successor1(Basic_block *BB){
   _succ.push_front(BB);
}

Basic_block *Basic_block::get_successor1(){
   if (_succ.size()>0)
      return _succ.front();
   else
      return NULL;
}

void Basic_block::set_successor2(Basic_block *BB){
   _succ.push_back(BB);
}

Basic_block *Basic_block::get_successor2(){
   if (_succ.size()> 1)
      return _succ.back();
   else
      return NULL;
}

void Basic_block::set_predecessor(Basic_block *BB){
   _pred.push_back(BB);
}

Basic_block *Basic_block::get_predecessor(int index){

   list<Basic_block*>::iterator it;
   it=_pred.begin();
   int size=(int)_pred.size();
   if(index< size){
      for (int i=0; i<index; i++, it++);
      return *it;
   }
   else cout<<"Error: index is bigger than the size of the list"<<endl;

   return _pred.back();

}

int Basic_block::get_nb_succ(){
   return _succ.size();
}

int Basic_block::get_nb_pred(){
   return _pred.size();
}

void Basic_block::set_branch(Node * br){
   _branch=br;
}

Node* Basic_block::get_branch(){
   return _branch;
}

void Basic_block::display(){
   cout<<"Begin BB"<<endl;
   Node* element = _head;
   int i=0;
   if(element == _end)
      cout << _head->get_lineContent() <<endl;

   while(element != _end->get_next()){
      if(element->get_line()->isInst()){
	 cout<<"i"<<i<<" ";
	 i++;
      }
      if(!element->get_line()->isDirective())
	 cout <<element->get_lineContent() <<endl;

      element = element->get_next();
   }
   cout<<"End BB"<<endl;
}

int Basic_block::size(){
   Node* element = _head;
   int lenght=0;
   while(element != _end){
      lenght++;
      if(element->get_next()==_end)
	 break;
      else
	 element = element->get_next();
   }
   return lenght;
}


void Basic_block::restitution(string const filename){
   Node* element = _head;
   ofstream monflux(filename.c_str(), ios::app);
   if(monflux){
      monflux<<"Begin BB"<<endl;
      if(element == _end)	monflux << _head->get_lineContent() <<endl;
      while(element != _end)
      {
	 if(element->get_line()->isInst())
	    monflux<<"\t";
	 if(!element->get_line()->isDirective())
	    monflux << element->get_lineContent()<<endl ;

	 if(element->get_next()==_end){
	    if(element->get_next()->get_line()->isInst())
	       monflux<<"\t";
	    if(!element->get_line()->isDirective())
	       monflux << element->get_next()->get_lineContent()<<endl;
	    break;
	 }
	 else element = element->get_next();

      }
      monflux<<"End BB\n\n"<<endl;
   }
   else {
      cout<<"Error cannot open the file"<<endl;
   }
   monflux.close();

}

bool Basic_block::is_labeled(){
   if (_head->get_line()->isLabel()){
      return true;
   }
   else return false;
}



int Basic_block::get_nb_inst(){

   if (_nb_instr == 0)
      link_instructions();
   return _nb_instr;

}


Instruction* Basic_block::get_instruction_at_index(int index){
   Instruction *inst;

   if(index >= get_nb_inst()){
      return NULL;
   }

   inst=get_first_instruction();

   for(int i=0; i<index; i++, inst=inst->get_next());

   return inst;
}

Node* Basic_block::get_first_node_instruction(){

   Node *current = _head;

   while(!current->get_line()->isInst()){
      current=current->get_next();
      if(current==_end)
	 return NULL;
   }

   return current;
}

Instruction* Basic_block::get_first_instruction(){
   if(_firstInst==NULL)
      _firstInst=dynamic_cast< Instruction *>(this->get_first_node_instruction()->get_line());
   return _firstInst;
}

Instruction* Basic_block::get_last_instruction(){
   if(_lastInst==NULL)
      this->link_instructions();
   return _lastInst;
}

void Basic_block::link_instructions(){

   int index=0;
   Node *current, *next;
   current=get_first_node_instruction();
   next=current->get_next();

   Instruction *i1 = dynamic_cast< Instruction *> (current->get_line());

   i1->set_index(index);
   index++;
   Instruction *i2;

//Calcul des successeurs
   while(current != _end){

      while(!next->get_line()->isInst()){
	 next=next->get_next();
	 if(next==_end){
	    if(next->get_line()->isInst())
	       break;
	    else{
	       _lastInst = i1;
	       _nb_instr = index;
	       return;
	    }
	 }
      }

      i2 = dynamic_cast< Instruction *> (next->get_line());
      i2->set_index(index);
      index++;
      i1->set_link_succ_pred(i2);

      i1=i2;
      current=next;
      next=next->get_next();
   }
   _lastInst = i1;
   _nb_instr = index;
}

/* ajoute une dépendance dans la liste des dépendances des 2 instructions */
void add_dep_link(Instruction *pred, Instruction* succ, t_Dep type){
   dep *d;
   d=(dep*)malloc(sizeof(dep));
   d->inst=succ;
   d->type=type;
   pred->add_succ_dep(d);

   d=(dep*)malloc(sizeof(dep));
   d->inst=pred;
   d->type=type;
   succ->add_pred_dep(d);
}


void Basic_block::comput_pred_succ_dep(){

    link_instructions();
    Instruction *i_current=this->get_last_instruction();
    Instruction *itmp = NULL;

    /*il faut faire ce qu'il faut pour remplir les listes

   list <dep*> _succ_dep; // instructions qui dépendent de this avec type de dep
   list <dep*> _pred_dep; // instructions dont depend this avec type de dep
   de la classe Instruction pour chacune des instructions du BB

   NB : la fonction add_dep_link ci-dessus peut vous être utile...

   */

    while (i_current && i_current->get_next() != get_first_instruction()) {
        itmp = i_current->get_prev();
        /* reset the booleans */
        bool raw1, raw2, war;
        raw1=false;
        raw2=false;
        war=false;
        while (itmp && itmp->get_next() != get_first_instruction()) {
            if(!raw1 && itmp->is_dep_RAW1(i_current)){
                add_dep_link(itmp, i_current, RAW);
                // cerr<<itmp->get_index() << " " << i_current->get_index() << " RAW1" << endl;
                raw1=true;
            }
            if(!raw2 && itmp->is_dep_RAW2(i_current)){
                add_dep_link(itmp, i_current, RAW);
                // cerr<<itmp->get_index() << " " << i_current->get_index() << " RAW2" << endl;
                raw2=true;
            }
            if(itmp->is_dep_WAR(i_current)){
                add_dep_link(itmp, i_current, WAR);
                // cerr<<itmp->get_index() << " " << i_current->get_index() << " WAR" << endl;
                war=true;
            }
            if(!war && itmp->is_dep_WAW(i_current)){
                add_dep_link(itmp, i_current, WAW);
                // cerr<<itmp->get_index() << " " << i_current->get_index() << " WAW" << endl;
                break;
            }
            itmp = itmp->get_prev();
        }
        i_current = i_current->get_prev();
    }

    //il faut  rattacher toute les instructions sans successeurs(dependances)
    //au saut de fin de BB par une dépendance de controle si le BB se termine par un saut

    i_current = this->get_first_instruction();
    Node * n_branch = get_branch();
    if(n_branch == NULL){
        return;
    }
    Instruction * i_branch = (dynamic_cast <Instruction *> (n_branch->get_line()));

    while (i_current != get_branch()->get_line()) {
        if(i_current->get_nb_succ() == 0){
            add_dep_link(i_current, i_branch, CONTROL);
        }
        i_current = i_current->get_next();
    }

}

void Basic_block::set_link_succ_pred(Basic_block* succ){
   _succ.push_back(succ);
   succ->set_predecessor(this);
}

bool Basic_block::is_delayed_slot(Instruction *i){
   if (get_branch()== NULL)
      return false;
   int j = (dynamic_cast<Instruction *> (get_branch()->get_line()))->get_index();
   // cout << "index saut : " << j << " index instruction " << i-> get_index() << endl;
   return (j < i-> get_index());
}


int Basic_block::nb_cycles(){
    int result = 0;
    Node* courant = get_head();
    Node* end = get_end();
    Node* next;
    while( courant != end ){
         next = courant->get_next();
         result += t_delay[courant->get_line()->get_type()][next->get_line()->get_type()];
         courant = next;
    }
    return result;
}



/* permet de tester des choses sur un bloc de base, par exemple permet d'afficher les BB successeurs et prédécesseurs (commentaire),  là ne fait rien qu'afficher le BB */
void Basic_block::test(){
   cout << "test du BB " << get_index() << endl;
   display();


   cout << "nb de successeur : " << get_nb_succ() << endl;
   int nbsucc = get_nb_succ() ;
   if (nbsucc >= 1 && get_successor1())
      cout << "succ1 : " << get_successor1()-> get_index();
   if (nbsucc >= 2 && get_successor2())
      cout << " succ2 : " << get_successor2()-> get_index();
   cout << endl << "nb de predecesseurs : " << get_nb_pred() << endl ;

   int size=(int)_pred.size();
   for (int i = 0; i < size; i++){
      if (get_predecessor(i) != NULL)
	 cout << "pred "<< i <<  " : " << get_predecessor(i)-> get_index() << "; ";
   }


   cout << endl;
}


void Basic_block::register_rename(list<int> dead_regs){
    int reg_to_use[49];
    for(int i = 0; i < 49; i++){
        reg_to_use[i] = -1;
    }
    int cpt=32;
    Instruction *inst = this->get_last_instruction();
    // parcours de toutes les instructions du BB en partant de la fin
    // ici on calcule le cpt du registre
    inst = this->get_last_instruction();
    while (inst && inst->get_next() != get_first_instruction()) {
        int reg_max=-1;
        if(inst->get_reg_dst() != NULL){
            reg_max = max(reg_max, inst->get_reg_dst()->get_reg());
        }
        if(inst->get_reg_src1() != NULL){
            reg_max = max(reg_max, inst->get_reg_src1()->get_reg());
        }
        if(inst->get_reg_src2() != NULL){
            reg_max = max(reg_max, inst->get_reg_src2()->get_reg());
        }
        cpt = max(reg_max, cpt);
        inst = inst->get_prev();
    }

    // parcours de toutes les instructions du BB en partant de la fin
    // ici on fait du renommage de registres
    inst = this->get_last_instruction();
    while (inst && inst->get_next() != get_first_instruction()) {
        int dst = -1;
        int src1 = -1;
        int src2 = -1;
        // calculer les registres utilisés et les mettre dans les entiers prévus
        if(inst->get_reg_dst() != NULL){
            dst = inst->get_reg_dst()->get_reg();
        }
        if(inst->get_reg_src1() != NULL){
            src1 = inst->get_reg_src1()->get_reg();
        }
        if(inst->get_reg_src2() != NULL){
            src2 = inst->get_reg_src2()->get_reg();
        }

        t_Operator op = inst->get_opcode();
        if(op == sw){
            if(src1 != -1 &&
                    reg_to_use[src1] != -1 &&
                    cpt < 49){
                // il a déjà été utilisé donc on change car sw
                reg_to_use[src1] = cpt;
                cpt++;
            }
        }


        // renommage de registre avec le tableau reg_to_use
        if(inst->get_reg_dst() != NULL){
            if( reg_to_use[dst] == -1 ) {
                reg_to_use[dst] = dst;
            }
            inst->get_reg_dst()->set_reg( reg_to_use[dst] );
        }
        if(inst->get_reg_src1() != NULL){
            if( reg_to_use[src1] == -1 ) {
                reg_to_use[src1] = src1;
            }
            inst->get_reg_src1()->set_reg( reg_to_use[src1] );
        }
        if(inst->get_reg_src2() != NULL){
            if( reg_to_use[src2] == -1 ) {
                reg_to_use[src2] = src2;
            }
            inst->get_reg_src2()->set_reg( reg_to_use[src2] );
        }
        inst = inst->get_prev();
    }
}
