#include <Dfg.h>

// crée un arc et le renvoie
Arc_t* new_arc(int del, t_Dep d, Node_dfg *n){
   Arc_t *arc = new Arc_t;
   arc->delai=del;
   arc->dep=d;
   arc->next=n;
   
   return arc;
}

//rend le delay entre 2 instructions pour la dépendance donnée
int get_delay(t_Dep dep, Instruction *from, Instruction *to){
   switch(dep){
   case WAW:
      return WAW_DELAY;
   case WAR:
      return WAR_DELAY;
   case MEMDEP:
      return MEMDEP_DELAY;
   case CONTROL:
      return 0;
   case NONE:
      return 0;
   case RAW:
      int ret=t_delay[from->get_type()][to->get_type()];
      if(ret<1)
        return 1;
      return ret;
   }
   return 0;
}

// A REMPLIR
Dfg::Dfg(Basic_block *bb){
  
  list<Arc_t*>::iterator ita;
  list<Node_dfg*>::iterator itn;

  _bb=bb;
  _index_branch=-1;
  _nb_arc=0;
  _length=bb->get_nb_inst();;
  _read= new int[_length];
  
  bb->comput_pred_succ_dep();

  // Création des noeuds DFG dans la liste list_node_dfg
  for (int i = 0; i < _length; i++) {
      Instruction* inst = bb->get_instruction_at_index(i);
      Node_dfg* nouveau = new Node_dfg(inst);
      list_node_dfg.push_back(nouveau);
      if(inst->is_branch()){
          _index_branch = i;
      }
  }


  for (itn = list_node_dfg.begin(); itn != list_node_dfg.end(); itn++){
      Node_dfg * courant = *itn;
      Instruction * inst = courant->get_instruction();
      // le noeud courant est une racine
      if(inst->get_nb_pred() == 0 && !inst->is_branch()){
          _roots.push_back(courant);
      }
      // le noeud courant est une branche (donc le noeud qui suit est un delayed slot)
      if(inst->is_branch()){
          _delayed_slot.push_back(*(++itn));
          break;
      }

      // parcours des successeurs
      list<dep*>::iterator its;
      for(its = inst->succ_begin(); its != inst->succ_end(); its++) {
          // trouver le noeud DFG correspondant au succ
          Instruction * inst_successeur = (*its)->inst;
          list<Node_dfg*>::iterator itn2;
          Node_dfg * noeud_dfg_succ = NULL;
          for (itn2 = list_node_dfg.begin(); itn2 != list_node_dfg.end(); itn2++){
              noeud_dfg_succ = *itn2;
              if(noeud_dfg_succ->get_instruction() == inst_successeur){
                  break;
              }
          }
          // calcul du delai
          int delay = get_delay((*its)->type, inst, noeud_dfg_succ->get_instruction());

          // ajout de l'arc
          courant->add_arc(new_arc(delay,(*its)->type,noeud_dfg_succ));
          noeud_dfg_succ->add_predecesseur(courant);
          _nb_arc++;
      }
  }
}

// methode auxiliaire pour la construction du Dfg, pas forcément utile, dépend de comment vous envisagez de faire...
void Dfg::build_dfg(Node_dfg*,bool) {

  // A REMPLIR OU NON !
 return;
}

Dfg::~Dfg(){}


void Dfg::display(Node_dfg * node, bool first){
   
   
   list<Node_dfg*>::iterator it;
   it=_roots.begin();

   if(first)	
      for(int i=0; i<_length; i++)	
	 _read[i]=0;  	
   
   for (unsigned int j=0; j<_roots.size();j++ ){ 
      if(first) node = *it;	
			

      if(!_read[node->get_instruction()->get_index()]){
	 _read[node->get_instruction()->get_index()]=1;
	 cout<<"pour i"<<node->get_instruction()->get_index()<<endl;
	 cout<<"l'instruction "<<node->get_instruction()->get_content()<<endl;
			
	 //On affiche ses successeurs s'il en a
	 for(int i=0;i<node->get_nb_arcs();i++){
	    if (node->get_arc(i)){
	       cout<< " -> succ i"
		   << node->get_arc(i)->next->get_instruction()->get_index()
		   << " : "
		   << node->get_arc(i)->next->get_instruction()->get_content()
		   << endl;
	    }
	 }
	 for(int i=0;i<node->get_nb_arcs();i++){
	    if (node->get_arc(i))
	       display(node->get_arc(i)->next, false);
	 }
      }
      it++;

   }
}

#define DEP(x) ((x==NONE)?"":((x==RAW)?"raw":\
				   ((x==WAR)?"war":\
				    ((x==WAW)?"waw": \
				     ((x==MEMDEP)?"mem": "control")))))


//Pour générer le fichier .dot: dot -Tps graph.dot -o graph.ps
void Dfg::restitute(Node_dfg * node, string const filename, bool first){
   if(first)
      remove(filename.c_str());
   ofstream monflux(filename.c_str(), ios::app);
   list<Node_dfg*>::iterator it;
 
   if(first && _length){
     
      for(int i=0; i<_length; i++)
	 _read[i]=0;
      
      it = _delayed_slot.begin();
      
      int index_min = _length;
      
      for(unsigned int i=0; i < _delayed_slot.size(); i++){
	 _read[(*it)->get_instruction()->get_index()] = 1;
	 if (index_min > (*it)->get_instruction()->get_index())
	    index_min = (*it)->get_instruction()->get_index();
	 it++;
      }

      monflux<<"digraph G1 {"<<endl;
      for(int i=0; i<index_min; i++){
	 monflux<<"i"<<i<< ";"<<endl;
	 
      }
   }	
   it=_roots.begin();
   for (unsigned int j=0; j<_roots.size();j++ ){ 		

      if(first) node = *it;
		
      if(monflux){			
	 //monflux.open(filename.c_str(), ios::app);
	 if(!_read[node->get_instruction()->get_index()]){
	    _read[node->get_instruction()->get_index()]=1;
					
	    //On affiche ses successeurs s'il en a
	    for(int i=0; i<node->get_nb_arcs(); i++){
	       if (node->get_arc(i)){
	   
		  monflux<<"i"<<node->get_instruction()->get_index();
		  monflux<<" ->  i" << node->get_arc(i)->next->get_instruction()->get_index();

		  // monflux<<"i"<<node->get_instruction()->get_index()<<"_"<<node->get_weight();
		  // monflux<<" ->  i" << node->get_arc(i)->next->get_instruction()->get_index();
		  // monflux<<"_"<<node->get_arc(i)->next->get_weight();

		  monflux<<" [label= \""<< DEP(node->get_arc(i)->dep) << node->get_arc(i)->delai<<"\"];"<<endl;
	       }
	    }
	    monflux.close();
	
	    for(int i=0;i<node->get_nb_arcs();i++){
	       if (node->get_arc(i))
		  restitute(node->get_arc(i)->next,filename.c_str(),false);	
	    }
	 }
      }
      if((j+1) < _roots.size())	monflux.open(filename.c_str(), ios::app);
      it++;
   }

   if (first && _length){
      monflux.open(filename.c_str(), ios::app);
      monflux<<"}"<<endl;
      monflux.close();
   }
   return;
 
}

bool Dfg::read_test(){
  for(int i=0; i<_length; i++)	if(_read[i]==0)	return true;
  return false;
}


bool contains(list<Node_dfg*>* l, Node_dfg* n){
   list<Node_dfg*>::iterator it;
   
   for(it=l->begin(); it!= l->end(); it++){
      if( (*it)==n ){
	 return true;
      }
   }
   return false;
}


list<Node_dfg*> Dfg::reverse_topological_order() {
    list<Node_dfg*>::iterator it;
    list<Arc_t*>::iterator ita;
    list<Node_dfg*> l;
    list<Node_dfg*> res;

    Node_dfg* current;
    for(it=list_node_dfg.begin(); it!=list_node_dfg.end(); it++){
        current = *it;
        // noeud initiailisé sans successeur
        if(current->get_nb_arcs() == 0){
            l.push_back(current);
            // marque comme traité
            _read[current->get_instruction()->get_index()]=1;
            res.push_back(current);
        }else{
            // marque comme non traité
            _read[current->get_instruction()->get_index()]=0;
        }
    }

    while(!l.empty()){
        current = l.front();
        l.pop_front();
        bool ready = true;

        // parcours des successeurs
        for(ita=current->arcs_begin(); ita!=current->arcs_end(); ita++){
            Arc_t* arc = *ita;

            // si successeur non traité (_read[])
            if(_read[arc->next->get_instruction()->get_index()] == 0){
                // traitement des successeurs
                ready = false;
                l.push_front(current);
                l.push_front(arc->next);
                break;
            }

        }
        // ajout des predecesseurs
        if(ready){
            if(_read[current->get_instruction()->get_index()] == 0){
                res.push_back(current);
            }
            _read[current->get_instruction()->get_index()] = 1;

            for(it=current->pred_begin(); it!=current->pred_end(); it++){
                Node_dfg* predecesseur = *it;
                if(_read[predecesseur->get_instruction()->get_index()] == 0){
                    l.push_back(predecesseur);
                }
            }

        }

    }
    return res;

}
//A FAIRE
void Dfg::comput_critical_path(){

    list<Node_dfg*>::iterator it;
    list<Arc_t*>::iterator ita;

    it=list_node_dfg.begin();
    list<Node_dfg*> lrev = reverse_topological_order();
    Node_dfg* node;

    /*
     * for all noeud (i)
     *      node(i).weight = 0
     */
    for(it=list_node_dfg.begin(); it!=list_node_dfg.end(); it ++){
        node = *it;
        node->set_weight(0);
    }

    /* for all noeud (i) in topological post order */
    for(it=lrev.begin(); it!=lrev.end(); it++){
        node = *it;
        /* if leaf(node(i)) then */
        if(node->get_nb_arcs()==0){
            /* node(i).weight = ExecTime(i) */
            node->set_weight(node->get_instruction()->get_latency());
        }else{
            /*
            *      for all node(j) in succ(node(i))
            *          node(i).weight
            *           = max(node(i).weight,
            *                 delai(node(i),node(j)) +
            *                  node(j).weight)
            *
            */
            for(ita=node->arcs_begin(); ita!=node->arcs_end(); ita++){
                Arc_t * arc=*ita;
                int delay = arc->delai + arc->next->get_weight();
                if(delay > node->get_weight()){
                    node->set_weight(delay);
                }
            }
        }
    }

#ifdef DEBUG
  it=list_node_dfg.begin();
  for(unsigned int k = 0; k < list_node_dfg.size(); k++, it++){
    Node_dfg* node = *it;
    cout << "node inst " << node -> get_instruction() -> get_index() << " poids=" << node->get_weight() << " nb succ=" << node->get_nbr_arc() << endl;
  }
#endif
}



/*
 * get_critical_path()
 * criticalpath=0;
 * for all node in _roots
 *   criticalpath = max (criticalpath,
 *              node.weight);
 */
// A FAIRE
int Dfg::get_critical_path(){
    int criticalpath=0;
    list<Node_dfg*>::iterator it;
    comput_critical_path();
    for(it=_roots.begin(); it!=_roots.end(); it++){
        if(criticalpath < (*it)->get_weight()){
            criticalpath=(*it)->get_weight();
        }
    }
    return criticalpath;
}

/**
 * @brief The sortFrozen class type functor
 */
struct sortFrozen {
  std::list<Node_dfg*> & new_order;
  sortFrozen(std::list<Node_dfg*> & new_order) : new_order(new_order) { }
  bool operator()(Node_dfg* first, Node_dfg* second){
      return nrof_frozen_cycle(first) < nrof_frozen_cycle(second);
  }
  int nrof_frozen_cycle(Node_dfg* np){
      int res = 0;
      // taille de new_order = size = index de l'inst à ajouter
      int size = new_order.size();
      int i = 0;
      list<Node_dfg*>::iterator it_dfg;
      list<Arc_t*>::iterator ita;
      // parcours de ttes les inst dans new_order
      for(it_dfg=new_order.begin(); it_dfg!=new_order.end(); it_dfg ++){
          // parcours de chaque arc (successeurs)
          for(ita=(*it_dfg)->arcs_begin(); ita!=(*it_dfg)->arcs_end(); ita ++){
              Arc_t* a = *ita;
              // si pointe vers np
              if(a->next == np){
                  int delai_minimal = size - i;
                  // si le delai est > à size - i
                  if(a->delai > delai_minimal){
                      // mettre à jour le delai (res) avec un max
                      res=max(res, a->delai);
                  }
              }
          }
          i++;
      }
      // retourner le délai calculé (res)
      return res;
  }
};

bool compare_weight(Node_dfg* first, Node_dfg* second){
   return (first->get_weight() > second->get_weight());
}

bool compare_latency(Node_dfg* first, Node_dfg* second){
   return (first->get_instruction()->get_latency() > second->get_instruction()->get_latency());
}

bool compare_successeurs(Node_dfg* first, Node_dfg* second){
   return (first->get_nb_arcs() > second->get_nb_arcs());
}

bool compare_descendant(Node_dfg* first, Node_dfg* second){
   return (first->get_nb_descendant() > second->get_nb_descendant());
}

bool compare_instructionFirst(Node_dfg* first, Node_dfg* second){
    return (first->get_instruction()->get_index() < second->get_instruction()->get_index());
}


void Dfg::scheduling(){
    list<Node_dfg*> prets;
    list<Node_dfg*>::iterator it;

    for(it= list_node_dfg.begin(); it!=list_node_dfg.end(); it ++){
        (*it)->compute_nb_descendant();
    }

    for(it=_roots.begin(); it!=_roots.end(); it ++){
        prets.push_back(*it);
    }
    while(prets.size() > 0){
        prets.sort(compare_instructionFirst);
        prets.sort(compare_descendant);
        prets.sort(compare_successeurs);
        prets.sort(compare_latency);
        prets.sort(compare_weight);
        prets.sort(sortFrozen(new_order));
        Node_dfg* n = prets.front();
        new_order.push_back(n);
        for (int i = 0; i < n->get_nb_arcs(); i++) {
            Arc_t* a = n->get_arc(i);
            Node_dfg* succ = a->next;
            if (!contains(&prets,succ) && !contains(&new_order, succ)){ //si il est deja pret on fait rien
                prets.push_back(succ);
            }
        }
        prets.pop_front();
    }
}


int nb_cycles(list<Node_dfg*> l){
    int result = 0;
    list <Node_dfg*>::iterator it;
    for(it=l.begin(); boost::next(it)!=l.end(); it++){
        Node_dfg* current = *it;
        Node_dfg* next = *(boost::next(it));
        result += min(1, t_delay[current->get_instruction()->get_type()][next->get_instruction()->get_type()]);
    }
    return result;
}

void Dfg::display_scheduled_instr(){
   list <Node_dfg*>::iterator it;
   Instruction *inst;
   cout<<"displaying scheduled instr"<<endl;
   for(it=new_order.begin(); it!=new_order.end(); it++){
      inst=(*it)->get_instruction();
      cout<<"i"<<inst->get_index()<<": "<<inst->get_content()<<endl;
   }

   cout << "nb cycles normal : " << nb_cycles(list_node_dfg)<< endl;
   cout << "nb cycles ordonnancé : " << nb_cycles(new_order)<< endl;
}


